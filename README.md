# embree-cpp

My tiny embree wrapper

## usage

```cpp
rtc::Device device;
// RTCDevice device = rtcNewDevice(NULL);

rtc::Geometry geom{ device, rtc::GeometryType::Triangle };
// RTCGeometry geom = rtcNewGeometry(device, RTC_GEOMETRY_TYPE_TRIANGLE);

rtc::IntersectContext context;
// struct RTCIntersectContext context;
// rtcInitIntersectContext(&context);

scene.intersect1(context, rayhit);
// rtcIntersect1(scene, &context, &rayhit);
```
