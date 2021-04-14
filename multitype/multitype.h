#pragma once
#ifndef CUTILITIES_MULTITYPE_H
#define CUTILITIES_MULTITYPE_H 1

#include <stdint.h>

#ifdef OS_ARCH
#	undef OS_ARCH
#endif

#if defined(__gnu_linux__) || defined(__linux) || defined(__linux__)
#	if defined(__x86_64) || defined(__x86_64__)
#			define OS_ARCH 64
#	endif // x86_64
#elif defined(_WIN64) || defined(__WIN64) || defined(_WIN32) || defined(__WIN32)
#	if defined(_WIN64) || defined(__WIN64)
#		define OS_ARCH 64
#	endif // win_64
#else
#	define OS_ARCH 32
#endif  // determine os arch

#if defined(_STDINT_H)

typedef	int8_t		int8;
typedef uint8_t		uint8;
typedef int16_t		int16;
typedef uint16_t	uint16;
typedef int32_t		int32;
typedef uint32_t	uint32;
#if defined(OS_ARCH) && OS_ARCH == 64
typedef int64_t		int64;
typedef uint64_t	uint64;
#endif // 64 bit ints

#else

typedef	char			int8;
typedef unsigned char	uint8;
typedef short			int16;
typedef unsigned short	uint16;
typedef int				int32;
typedef unsigned int	uint32;
#if defined(OS_ARCH) && OS_ARCH == 64
typedef long long int			int64;
typedef unsigned long long int	uint64;
#endif // 64 bit ints

#endif //_STDINT_H_

/* types */
typedef void * Handle;
typedef union U_MultiType
{
	struct
	{
		union
		{
			int8  i8;  uint8  ui8;
			int16 i16; uint16 ui16;
			int32 i32; uint32 ui32;
#if defined(OS_ARCH) && OS_ARCH == 64
			int64 i64; uint64 ui64;	
#endif //
		};
#if defined(OS_ARCH) && OS_ARCH == 64
			int64 raw_i; uint64 raw_ui;
#else
			int32 raw_i; uint32 raw_ui;
#endif //
	} Integers;

	struct
	{
		union
		{
			float  f;
			double d;
			long double ld;
		};
		long double raw;
	} FloatingPoint;

	struct
	{
		union
		{
			Handle pointer;
			char * string;
		};
		Handle raw;
	} Pointer;
} MultiType;

typedef enum E_TypeTag
{
	TT_INT8,	
	TT_UINT8,	
	TT_INT16,	
	TT_UINT16,	
	TT_INT32,	
	TT_UINT32,	
#if defined(OS_ARCH) && OS_ARCH == 64
	TT_INT64,
	TT_UINT64,
#endif //64 bit types
	TT_POINTER,
	TT_STRING,
	TT_FLOAT,
	TT_DOUBLE,
	TT_LONG_DOUBLE,
	TT_COUNT,
	TT_NULL,
} TypeTag;

/* -------- functions -------------*/

#if defined(__cplusplus)
extern "C" {
#endif // __cplusplus

void store_integer(const Handle value, MultiType * mt, TypeTag t);
void store_floating_point(const Handle value, MultiType * mt, TypeTag t);
void store_pointer(const Handle value, MultiType * mt, TypeTag t);

#if defined(OS_ARCH) && OS_ARCH == 64
int64  read_raw_integer(const MultiType * const mt);
uint64 read_raw_uinteger(const MultiType * const mt);
#else
int32  read_raw_integer(const MultiType * const mt);
uint32 read_raw_uinteger(const MultiType * const  mt);
#endif // OS_ARCH for raw integer retreieval

long double read_raw_floating_point(const MultiType * const mt);
Handle read_raw_pointer(const MultiType * const mt);

/* internal functions */
void internal_print_multitype_layout(const MultiType * const mt);

#if defined(__cplusplus)
}
#endif // __cplusplus

#endif // CUTILITIES_MULTITYPE_H

