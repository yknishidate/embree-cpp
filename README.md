# embree-cpp

My tiny embree wrapper

## usage

### constructor & default arg

```cpp
// original
RTCDevice device = rtcNewDevice(NULL);

// embree-cpp
rtc::Device device;
```

### scoped enum

```cpp
// original
RTCGeometry geom = rtcNewGeometry(device, RTC_GEOMETRY_TYPE_TRIANGLE);

// embree-cpp
rtc::Geometry geom{ device, rtc::GeometryType::Triangle };
```

### member func & reference arg(not pointer)

```cpp
// original
rtcIntersect1(scene, &context, &rayhit);

// embree-cpp
scene.intersect1(context, rayhit);
```

### std::vector arg

```cpp
std::vector<Vertex> vertices{ /* data */ };

// original
rtcSetSharedGeometryBuffer(geom, RTC_BUFFER_TYPE_VERTEX, 0,
                           RTC_FORMAT_FLOAT3, vertices.data(), 0,
                           sizeof(Vertex), vertices.size());

// embree-cpp
geom.setSharedBuffer(rtc::BufferType::Vertex, 0, rtc::Format::Float3, vertices);
```
