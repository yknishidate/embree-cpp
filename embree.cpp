#include "embree.hpp"

// rtcore_common.h
rtc::IntersectContext::IntersectContext()
{
	rtcInitIntersectContext(&context);
}

RTCIntersectContext& rtc::IntersectContext::get()
{
	return context;
}

rtc::PointQueryContext::PointQueryContext()
{
	rtcInitPointQueryContext(&context);
}

RTCPointQueryContext& rtc::PointQueryContext::get()
{
	return context;
}

// rtcore_device.h
rtc::Device::Device(const char* config)
{
	device = rtcNewDevice(config);
}

rtc::Device::Device(RTCDevice device)
	: device(device)
{
}

rtc::Device::~Device()
{
	rtcReleaseDevice(device);
}

void rtc::Device::retain()
{
	rtcRetainDevice(device);
}

ssize_t rtc::Device::getProperty(DeviceProperty prop) const
{
	return rtcGetDeviceProperty(device, static_cast<RTCDeviceProperty>(prop));
}

void rtc::Device::setProperty(DeviceProperty prop, ssize_t value) const
{
	rtcSetDeviceProperty(device, static_cast<RTCDeviceProperty>(prop), value);
}

rtc::Error rtc::Device::getError() const
{
	return static_cast<Error>(rtcGetDeviceError(device));
}

const RTCDevice& rtc::Device::get() const
{
	return device;
}

// rtcore_buffer.h
rtc::Buffer::Buffer(const Device& device, size_t byteSize)
{
	buffer = rtcNewBuffer(device.get(), byteSize);
}

rtc::Buffer::Buffer(const Device& device, void* ptr, size_t byteSize)
{
	buffer = rtcNewSharedBuffer(device.get(), ptr, byteSize);
}

rtc::Buffer::~Buffer()
{
	rtcReleaseBuffer(buffer);
}

void* rtc::Buffer::getData() const
{
	return rtcGetBufferData(buffer);
}

void rtc::Buffer::retain()
{
	rtcRetainBuffer(buffer);
}

RTCBuffer& rtc::Buffer::get()
{
	return buffer;
}

rtc::Geometry::Geometry(RTCGeometry geom)
	: geom(geom)
{

}

// rtcore_geometry.h
rtc::Geometry::Geometry(const Device& device, GeometryType type)
{
	geom = rtcNewGeometry(device.get(), static_cast<RTCGeometryType>(type));
}

rtc::Geometry::~Geometry()
{
	rtcReleaseGeometry(geom);
}

void rtc::Geometry::retain() const
{
	rtcRetainGeometry(geom);
}

void rtc::Geometry::commit() const
{
	rtcCommitGeometry(geom);
}

void rtc::Geometry::enable() const
{
	rtcEnableGeometry(geom);
}

void rtc::Geometry::disable() const
{
	rtcDisableGeometry(geom);
}

void rtc::Geometry::setBuffer(BufferType type, unsigned int slot, Format format, Buffer buffer, size_t byteOffset, size_t byteStride, size_t itemCount)
{
	auto rtcType = static_cast<RTCBufferType>(type);
	auto rtcFormat = static_cast<RTCFormat>(format);
	rtcSetGeometryBuffer(geom, rtcType, slot, rtcFormat, buffer.get(),
						 byteOffset, byteStride, itemCount);
}

void rtc::Geometry::setSharedBuffer(BufferType type, unsigned int slot, Format format, const void* ptr, size_t byteOffset, size_t byteStride, size_t itemCount)
{
	auto rtcType = static_cast<RTCBufferType>(type);
	auto rtcFormat = static_cast<RTCFormat>(format);
	rtcSetSharedGeometryBuffer(geom, rtcType, slot, rtcFormat, ptr,
							   byteOffset, byteStride, itemCount);
}

void* rtc::Geometry::setNewBuffer(BufferType type, unsigned int slot, Format format, size_t byteStride, size_t itemCount)
{
	auto rtcType = static_cast<RTCBufferType>(type);
	auto rtcFormat = static_cast<RTCFormat>(format);
	return rtcSetNewGeometryBuffer(geom, rtcType, slot, rtcFormat, byteStride, itemCount);
}

const RTCGeometry& rtc::Geometry::get() const
{
	return geom;
}

// rtcore_scene.h
rtc::Scene::Scene(const Device& device)
{
	scene = rtcNewScene(device.get());
}

rtc::Scene::~Scene()
{
	rtcReleaseScene(scene);
}

rtc::Device rtc::Scene::getDevice() const
{
	return Device{ rtcGetSceneDevice(scene) };
}

void rtc::Scene::retain() const
{
	rtcRetainScene(scene);
}

unsigned int rtc::Scene::attachGeometry(const Geometry& geom) const
{
	return rtcAttachGeometry(scene, geom.get());
}

void rtc::Scene::attachGeometryByID(const Geometry& geom, unsigned int geomID) const
{
	rtcAttachGeometryByID(scene, geom.get(), geomID);
}

void rtc::Scene::detachGeometry(unsigned int geomID) const
{
	rtcDetachGeometry(scene, geomID);
}

rtc::Geometry rtc::Scene::getGeometry(unsigned int geomID) const
{
	return Geometry{ rtcGetGeometry(scene, geomID) };
}

void rtc::Scene::commit() const
{
	rtcCommitScene(scene);
}

void rtc::Scene::joinCommit() const
{
	rtcCommitScene(scene);
}

void rtc::Scene::intersect1(IntersectContext& context, RayHit& rayhit)
{
	rtcIntersect1(scene, &context.get(), &rayhit);
}

const RTCScene& rtc::Scene::get() const
{
	return scene;
}

// rtcore_builder.h
rtc::BVH::BVH(const Device& device)
{
	bvh = rtcNewBVH(device.get());
}

rtc::BVH::~BVH()
{
	rtcReleaseBVH(bvh);
}

void* rtc::BVH::build(const BuildArguments& args) const
{
	return rtcBuildBVH(&args);
}

void rtc::BVH::retain() const
{
	rtcRetainBVH(bvh);
}

// rtcore_quaternion.h
rtc::QuaternionDecomposition::QuaternionDecomposition()
{
	rtcInitQuaternionDecomposition(&qdecomp);
}

void rtc::QuaternionDecomposition::setQuaternion(float r, float i, float j, float k)
{
	rtcQuaternionDecompositionSetQuaternion(&qdecomp, r, i, j, k);
}

void rtc::QuaternionDecomposition::setScale(float scale_x, float scale_y, float scale_z)
{
	rtcQuaternionDecompositionSetScale(&qdecomp, scale_x, scale_y, scale_z);
}

void rtc::QuaternionDecomposition::setSkew(float skew_xy, float skew_xz, float skew_yz)
{
	rtcQuaternionDecompositionSetSkew(&qdecomp, skew_xy, skew_xz, skew_yz);
}

void rtc::QuaternionDecomposition::setShift(float shift_x, float shift_y, float shift_z)
{
	rtcQuaternionDecompositionSetShift(&qdecomp, shift_x, shift_y, shift_z);
}

void rtc::QuaternionDecomposition::setTranslation(float trans_x, float trans_y, float trans_z)
{
	rtcQuaternionDecompositionSetTranslation(&qdecomp, trans_x, trans_y, trans_z);
}
