// header guard
#ifndef CUTILITIES_MULTITYPE_H
#define CUTILITIES_MULTITYPE_H

#include <stdint.h>

typedef union U_Multitype Multitype;
typedef enum  E_Multitype_Type Multitype_Type;

typedef int8_t   int8;
typedef int16_t  int16;
typedef int32_t  int32;
typedef int64_t  int64;
typedef uint8_t  uint8;
typedef uint16_t uint16;
typedef uint32_t uint32;
typedef uint64_t uint64;

typedef float  		float32;
typedef double 		float64;
typedef long double floatX;

typedef void * Handle;
typedef char * RawString;

#ifndef NULL
    #define NULL ((void *)0)
#endif

void storeInteger(Multitype * mt, Multitype_Type type, const Handle value);
void storeFloat(Multitype * mt, Multitype_Type type, const Handle value);
void storePointer(Multitype * mt, Multitype_Type type, const Handle value);

int64   readInteger(const Multitype * const mt);
uint64  readUInteger(const Multitype * const mt);
float32 readFloat32(const Multitype * const mt);
float64 readFloat64(const Multitype * const mt);
floatX  readFloatX(const Multitype * const mt);
Handle  readPointer(const Multitype * const mt);

Multitype * newMultitype(void);
void deleteMultitype(Multitype ** mt); 

#endif // CUTILITIES_MULTITYPE_H
