# embree-cpp

Header only embree wrapper

## Features

- Constructor
- Default args
- Scoped enum
- Member funcs
- Reference args(not pointer)
- std::vector args

### Constructor & Default args

```cpp
// original
RTCDevice device = rtcNewDevice(NULL);

// embree-cpp
rtc::Device device;
```

### Scoped enum

```cpp
// original
RTCGeometry geom = rtcNewGeometry(device, RTC_GEOMETRY_TYPE_TRIANGLE);

// embree-cpp
rtc::Geometry geom{ device, rtc::GeometryType::Triangle };
```

### Member funcs & Reference args(not pointer)

```cpp
// original
rtcIntersect1(scene, &context, &rayhit);

// embree-cpp
scene.intersect1(context, rayhit);
```

### std::vector args

```cpp
std::vector<Vertex> vertices{ /* data */ };

// original
rtcSetSharedGeometryBuffer(geom, RTC_BUFFER_TYPE_VERTEX, 0,
                           RTC_FORMAT_FLOAT3, vertices.data(), 0,
                           sizeof(Vertex), vertices.size());

// embree-cpp
geom.setSharedBuffer(rtc::BufferType::Vertex, 0, rtc::Format::Float3, vertices);
```
