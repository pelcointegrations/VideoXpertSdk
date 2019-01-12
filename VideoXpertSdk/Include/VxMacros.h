#ifndef VxMacros_h__
#define VxMacros_h__

#include <cstring>

#ifdef __cplusplus
#define EXTERN_C extern "C"
#else
#define EXTERN_C
#endif

#if defined(_WIN32)
#ifdef _EXPORTING
#define VXAPI __declspec(dllexport)
#else
#define VXAPI __declspec(dllimport)
#endif
#else
#define VXAPI __attribute__((visibility("default")))
#define strncpy_s(dest, destsz, source, count)    strncpy( (dest), (source), (count) )
#define localtime_s(time, result)                 localtime( (result) )
#define gmtime_s(time, result)                    gmtime( (result) )
#endif

#define VxZeroArray(src) memset(src, 0, sizeof(src));

#endif // VxMacros_h__
