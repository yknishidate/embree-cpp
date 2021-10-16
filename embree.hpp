#pragma once
#include <embree3/rtcore.h>
#include <vector>

namespace rtc
{
	// forward declaration
	class Device;
	class Scene;
	class Geometry;
	class IntersectContext;

	// rtcore_common.h
	enum class Format
	{
		Undefined = RTC_FORMAT_UNDEFINED,

		Uchar = RTC_FORMAT_UCHAR,
		Uchar2 = RTC_FORMAT_UCHAR2,
		Uchar3 = RTC_FORMAT_UCHAR3,
		Uchar4 = RTC_FORMAT_UCHAR4,

		Char = RTC_FORMAT_CHAR,
		Char2 = RTC_FORMAT_CHAR2,
		Char3 = RTC_FORMAT_CHAR3,
		Char4 = RTC_FORMAT_CHAR4,

		Ushort = RTC_FORMAT_USHORT,
		Ushort2 = RTC_FORMAT_USHORT2,
		Ushort3 = RTC_FORMAT_USHORT3,
		Ushort4 = RTC_FORMAT_USHORT4,

		Short = RTC_FORMAT_SHORT,
		Short2 = RTC_FORMAT_SHORT2,
		Short3 = RTC_FORMAT_SHORT3,
		Short4 = RTC_FORMAT_SHORT4,

		Uint = RTC_FORMAT_UINT,
		Uint2 = RTC_FORMAT_UINT2,
		Uint3 = RTC_FORMAT_UINT3,
		Uint4 = RTC_FORMAT_UINT4,

		Int = RTC_FORMAT_INT,
		Int2 = RTC_FORMAT_INT2,
		Int3 = RTC_FORMAT_INT3,
		Int4 = RTC_FORMAT_INT4,

		Ullong = RTC_FORMAT_ULLONG,
		Ullong2 = RTC_FORMAT_ULLONG2,
		Ullong3 = RTC_FORMAT_ULLONG3,
		Ullong4 = RTC_FORMAT_ULLONG4,

		Llong = RTC_FORMAT_LLONG,
		Llong2 = RTC_FORMAT_LLONG2,
		Llong3 = RTC_FORMAT_LLONG3,
		Llong4 = RTC_FORMAT_LLONG4,

		Float = RTC_FORMAT_FLOAT,
		Float2 = RTC_FORMAT_FLOAT2,
		Float3 = RTC_FORMAT_FLOAT3,
		Float4 = RTC_FORMAT_FLOAT4,
		Float5 = RTC_FORMAT_FLOAT5,
		Float6 = RTC_FORMAT_FLOAT6,
		Float7 = RTC_FORMAT_FLOAT7,
		Float8 = RTC_FORMAT_FLOAT8,
		Float9 = RTC_FORMAT_FLOAT9,
		Float10 = RTC_FORMAT_FLOAT10,
		Float11 = RTC_FORMAT_FLOAT11,
		Float12 = RTC_FORMAT_FLOAT12,
		Float13 = RTC_FORMAT_FLOAT13,
		Float14 = RTC_FORMAT_FLOAT14,
		Float15 = RTC_FORMAT_FLOAT15,
		Float16 = RTC_FORMAT_FLOAT16,

		Float2x2RowMajor = RTC_FORMAT_FLOAT2X2_ROW_MAJOR,
		Float2x3RowMajor = RTC_FORMAT_FLOAT2X3_ROW_MAJOR,
		Float2x4RowMajor = RTC_FORMAT_FLOAT2X4_ROW_MAJOR,
		Float3x2RowMajor = RTC_FORMAT_FLOAT3X2_ROW_MAJOR,
		Float3x3RowMajor = RTC_FORMAT_FLOAT3X3_ROW_MAJOR,
		Float3x4RowMajor = RTC_FORMAT_FLOAT3X4_ROW_MAJOR,
		Float4x2RowMajor = RTC_FORMAT_FLOAT4X2_ROW_MAJOR,
		Float4x3RowMajor = RTC_FORMAT_FLOAT4X3_ROW_MAJOR,
		Float4x4RowMajor = RTC_FORMAT_FLOAT4X4_ROW_MAJOR,

		Float2x2ColumnMajor = RTC_FORMAT_FLOAT2X2_COLUMN_MAJOR,
		Float2x3ColumnMajor = RTC_FORMAT_FLOAT2X3_COLUMN_MAJOR,
		Float2x4ColumnMajor = RTC_FORMAT_FLOAT2X4_COLUMN_MAJOR,
		Float3x2ColumnMajor = RTC_FORMAT_FLOAT3X2_COLUMN_MAJOR,
		Float3x3ColumnMajor = RTC_FORMAT_FLOAT3X3_COLUMN_MAJOR,
		Float3x4ColumnMajor = RTC_FORMAT_FLOAT3X4_COLUMN_MAJOR,
		Float4x2ColumnMajor = RTC_FORMAT_FLOAT4X2_COLUMN_MAJOR,
		Float4x3ColumnMajor = RTC_FORMAT_FLOAT4X3_COLUMN_MAJOR,
		Float4x4ColumnMajor = RTC_FORMAT_FLOAT4X4_COLUMN_MAJOR,

		Grid = RTC_FORMAT_GRID,
	};

	enum class BuildQuality
	{
		Low = RTC_BUILD_QUALITY_LOW,
		Medium = RTC_BUILD_QUALITY_MEDIUM,
		High = RTC_BUILD_QUALITY_HIGH,
		Refit = RTC_BUILD_QUALITY_REFIT,
	};

	using Bounds = RTCBounds;

	enum class IntersectContextFlags
	{
		None = RTC_INTERSECT_CONTEXT_FLAG_NONE,
		Incoherent = RTC_INTERSECT_CONTEXT_FLAG_INCOHERENT,
		Coherent = RTC_INTERSECT_CONTEXT_FLAG_COHERENT,
	};

	using FilterFunctionNArguments = RTCFilterFunctionNArguments;

	class IntersectContext
	{
	public:
		IntersectContext();

		RTCIntersectContext& get();

	private:
		RTCIntersectContext context;
	};

	using PointQuery = RTCPointQuery;
	using PointQuery4 = RTCPointQuery4;
	using PointQuery8 = RTCPointQuery8;
	using PointQuery16 = RTCPointQuery16;
	using PointQueryN = RTCPointQueryN;

	class PointQueryContext
	{
	public:
		PointQueryContext();

		RTCPointQueryContext& get();

	private:
		RTCPointQueryContext context;
	};

	using PointQueryFunctionArguments = RTCPointQueryFunctionArguments;

	// rtcore_device.h
	enum class DeviceProperty
	{
		Version = RTC_DEVICE_PROPERTY_VERSION,
		VersionMajor = RTC_DEVICE_PROPERTY_VERSION_MAJOR,
		VersionMinor = RTC_DEVICE_PROPERTY_VERSION_MINOR,
		VersionPatch = RTC_DEVICE_PROPERTY_VERSION_PATCH,

		NativeRay4Supported = RTC_DEVICE_PROPERTY_NATIVE_RAY4_SUPPORTED,
		NativeRay8Supported = RTC_DEVICE_PROPERTY_NATIVE_RAY8_SUPPORTED,
		NativeRay16Supported = RTC_DEVICE_PROPERTY_NATIVE_RAY16_SUPPORTED,
		RayStreamSupported = RTC_DEVICE_PROPERTY_RAY_STREAM_SUPPORTED,

		BackfaceCullingCurvesEnabled = RTC_DEVICE_PROPERTY_BACKFACE_CULLING_CURVES_ENABLED,
		RayMaskSupported = RTC_DEVICE_PROPERTY_RAY_MASK_SUPPORTED,
		BackfaceCullingEnabled = RTC_DEVICE_PROPERTY_BACKFACE_CULLING_ENABLED,
		FilterFunctionSupported = RTC_DEVICE_PROPERTY_FILTER_FUNCTION_SUPPORTED,
		IgnoreInvalidRaysEnabled = RTC_DEVICE_PROPERTY_IGNORE_INVALID_RAYS_ENABLED,
		CompactPolysEnabled = RTC_DEVICE_PROPERTY_COMPACT_POLYS_ENABLED,

		TriangleGeometryEnabled = RTC_DEVICE_PROPERTY_TRIANGLE_GEOMETRY_SUPPORTED,
		QuadGeometryEnabled = RTC_DEVICE_PROPERTY_QUAD_GEOMETRY_SUPPORTED,
		SubdivisionGeometryEnabled = RTC_DEVICE_PROPERTY_SUBDIVISION_GEOMETRY_SUPPORTED,
		CurveGeometryEnabled = RTC_DEVICE_PROPERTY_CURVE_GEOMETRY_SUPPORTED,
		UserGeometryEnabled = RTC_DEVICE_PROPERTY_USER_GEOMETRY_SUPPORTED,
		PointGeometryEnabled = RTC_DEVICE_PROPERTY_POINT_GEOMETRY_SUPPORTED,

		TaskingSystem = RTC_DEVICE_PROPERTY_TASKING_SYSTEM,
		JoinCommitSupported = RTC_DEVICE_PROPERTY_JOIN_COMMIT_SUPPORTED,
		ParallelCommitSupported = RTC_DEVICE_PROPERTY_PARALLEL_COMMIT_SUPPORTED,
	};

	enum class Error
	{
		None = RTC_ERROR_NONE,
		Unknown = RTC_ERROR_UNKNOWN,
		InvalidArgument = RTC_ERROR_INVALID_ARGUMENT,
		InvalidOperation = RTC_ERROR_INVALID_OPERATION,
		OutOfMemory = RTC_ERROR_OUT_OF_MEMORY,
		UnsupportedCPU = RTC_ERROR_UNSUPPORTED_CPU,
		Cancelled = RTC_ERROR_CANCELLED,
	};

	class Device
	{
	public:
		Device(const char* config = nullptr);

		explicit Device(RTCDevice device);

		~Device();

		void retain();

		ssize_t getProperty(DeviceProperty prop) const;

		void setProperty(DeviceProperty prop, ssize_t value) const;

		Error getError() const;

		// TODO: support callback

		const RTCDevice& get() const;

	private:
		RTCDevice device;
	};

	// rtcore_buffer.h
	enum class BufferType
	{
		Index = RTC_BUFFER_TYPE_INDEX,
		Vertex = RTC_BUFFER_TYPE_VERTEX,
		VertexAttribute = RTC_BUFFER_TYPE_VERTEX_ATTRIBUTE,
		Normal = RTC_BUFFER_TYPE_NORMAL,
		Tangent = RTC_BUFFER_TYPE_TANGENT,
		NormalDerivative = RTC_BUFFER_TYPE_NORMAL_DERIVATIVE,

		Grid = RTC_BUFFER_TYPE_GRID,

		Face = RTC_BUFFER_TYPE_FACE,
		Level = RTC_BUFFER_TYPE_LEVEL,
		EdgeCreaseIndex = RTC_BUFFER_TYPE_EDGE_CREASE_INDEX,
		EdgeCreaseWeight = RTC_BUFFER_TYPE_EDGE_CREASE_WEIGHT,
		VertexCreaseIndex = RTC_BUFFER_TYPE_VERTEX_CREASE_INDEX,
		VertexCreaseWeight = RTC_BUFFER_TYPE_VERTEX_CREASE_WEIGHT,
		Hole = RTC_BUFFER_TYPE_HOLE,

		Flags = RTC_BUFFER_TYPE_FLAGS,
	};

	class Buffer
	{
	public:
		Buffer() = default;

		Buffer(const Device& device, size_t byteSize);

		Buffer(const Device& device, void* ptr, size_t byteSize);

		~Buffer();

		void* getData() const;

		void retain();

		RTCBuffer& get();

	private:
		RTCBuffer buffer;
	};

	// rtcore_ray.h
	using Ray = RTCRay;
	using Hit = RTCHit;
	using RayHit = RTCRayHit;

	using Ray4 = RTCRay4;
	using Hit4 = RTCHit4;
	using RayHit4 = RTCRayHit4;

	using Ray8 = RTCRay8;
	using Hit8 = RTCHit8;
	using RayHit8 = RTCRayHit8;

	using Ray16 = RTCRay16;
	using Hit16 = RTCHit16;
	using RayHit16 = RTCRayHit16;

	using RayNp = RTCRayNp;
	using HitNp = RTCHitNp;
	using RayHitNp = RTCRayHitNp;

	using RayN = RTCRayN;
	using HitN = RTCHitN;
	using RayHitN = RTCRayHitN;

	// TODO: helper funcs

	// rtcore_geometry.h
	enum class GeometryType
	{
		Triangle = RTC_GEOMETRY_TYPE_TRIANGLE,
		Quad = RTC_GEOMETRY_TYPE_QUAD,
		Grid = RTC_GEOMETRY_TYPE_GRID,
		// TODO: add others
	};

	enum class SubdivisionMode
	{
		NoBoundary = RTC_SUBDIVISION_MODE_NO_BOUNDARY,
		SmoothBoundary = RTC_SUBDIVISION_MODE_SMOOTH_BOUNDARY,
		PinCorners = RTC_SUBDIVISION_MODE_PIN_CORNERS,
		PinBoundary = RTC_SUBDIVISION_MODE_PIN_BOUNDARY,
		PinAll = RTC_SUBDIVISION_MODE_PIN_ALL,
	};

	enum class CurveFlags
	{
		NeighborLeft = RTC_CURVE_FLAG_NEIGHBOR_LEFT,
		NeighborRight = RTC_CURVE_FLAG_NEIGHBOR_RIGHT,
	};

	using BoundsFunctionArguments = RTCBoundsFunctionArguments;
	// TODO: support callback

	using IntersectFunctionNArguments = RTCIntersectFunctionNArguments;
	// TODO: support callback

	using OccludedFunctionNArguments = RTCOccludedFunctionNArguments;
	// TODO: support callback

	using DisplacementFunctionNArguments = RTCDisplacementFunctionNArguments;
	// TODO: support callback

	class Geometry
	{
	public:
		Geometry() = default;

		explicit Geometry(RTCGeometry geom);

		Geometry(const Device& device, GeometryType type);

		~Geometry();

		void retain() const;

		void commit() const;

		void enable() const;

		void disable() const;

		// TODO: support funcs

		void setBuffer(BufferType type, unsigned int slot, Format format, Buffer buffer,
					   size_t byteOffset, size_t byteStride, size_t itemCount);

		void setSharedBuffer(BufferType type, unsigned int slot, Format format, const void* ptr,
							 size_t byteOffset, size_t byteStride, size_t itemCount);

		template<typename T>
		void setSharedBuffer(BufferType type, unsigned int slot, Format format,
							 const std::vector<T>& data)
		{
			setSharedBuffer(type, slot, format, data.data(), 0, sizeof(T), data.size());
		}

		void* setNewBuffer(BufferType type, unsigned int slot, Format format,
						   size_t byteStride, size_t itemCount);

		template<typename T>
		T* setNewBuffer(BufferType type, unsigned int slot, Format format, size_t itemCount)
		{
			return static_cast<T*>(setNewBuffer(type, slot, format, sizeof(T), itemCount));
		}

		const RTCGeometry& get() const;

	private:
		RTCGeometry geom;
	};

	// TODO: support interpolation

	using Grid = RTCGrid;

	// rtcore_scene.h
	enum class SceneFlags
	{
		None = RTC_SCENE_FLAG_NONE,
		Dynamic = RTC_SCENE_FLAG_DYNAMIC,
		Compact = RTC_SCENE_FLAG_COMPACT,
		Robust = RTC_SCENE_FLAG_ROBUST,
		ContextFilterFuction = RTC_SCENE_FLAG_CONTEXT_FILTER_FUNCTION,
	};

	class Scene
	{
	public:
		explicit Scene(const Device& device);

		~Scene();

		Device getDevice() const;

		void retain() const;

		unsigned int attachGeometry(const Geometry& geom) const;

		void attachGeometryByID(const Geometry& geom, unsigned int geomID) const;

		void detachGeometry(unsigned int geomID) const;

		Geometry getGeometry(unsigned int geomID) const;

		void commit() const;

		void joinCommit() const;

		// support callback

		// support funcs

		void intersect1(IntersectContext& context, RayHit& rayhit);

		const RTCScene& get() const;

	private:
		RTCScene scene;
	};

	using Collision = RTCCollision;

	// rtcore_builder.h
	using BuildPrimitive = RTCBuildPrimitive;

	class ThreadLocalAllocator
	{
	public:
		void* alloc(size_t bytes, size_t align)
		{
			return rtcThreadLocalAlloc(allocator, bytes, align);
		}

		// support callback

	private:
		RTCThreadLocalAllocator allocator;
	};

	// support callback

	enum class BuildFlags
	{
		None = RTC_BUILD_FLAG_NONE,
		Dynamic = RTC_BUILD_FLAG_DYNAMIC,
	};

	enum class BuildConstants
	{
		MaxPrimitivesPerLeaf = RTC_BUILD_MAX_PRIMITIVES_PER_LEAF,
	};

	using BuildArguments = RTCBuildArguments;

	class BVH
	{
	public:
		explicit BVH(const Device& device);

		~BVH();

		void* build(const BuildArguments& args) const;

		void retain() const;

	private:
		RTCBVH bvh;
	};

	// rtcore_quaternion.h
	class QuaternionDecomposition
	{
	public:
		QuaternionDecomposition();

		void setQuaternion(float r, float i, float j, float k);

		void setScale(float scale_x, float scale_y, float scale_z);

		void setSkew(float skew_xy, float skew_xz, float skew_yz);

		void setShift(float shift_x, float shift_y, float shift_z);

		void setTranslation(float trans_x, float trans_y, float trans_z);

	private:
		RTCQuaternionDecomposition qdecomp;
	};
}
