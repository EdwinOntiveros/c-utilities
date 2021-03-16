#pragma once
#ifndef CUTYPES_CUTYPES_H
#define CUTYPES_CUTYPES_H 1

#include <stdint.h>

#if defined(OS_ARCH)
#	undef OS_ARCH
#	define OS_ARCH 32
#endif // OS_ARCH

#if defined(__gnu_linux__) || defined(__linux) || defined(__linux__)
#	if defined(__x86_64) || defined(__x86_64__)
#		if defined(OS_ARCH)
#			undef OS_ARCH
#			define OS_ARCH 32
#		endif // OS_ARCH
#	endif // x86_64
#elif defined(_WIN64) || defined(__WIN64) || defined(_WIN32) || defined(__WIN32)
#	if defined(_WIN64) || defined(__WIN64)
#		undef OS_ARCH
#		define OS_ARCH 64
#	endif // win_64
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
typedef intptr_t	intptr;
typedef uintptr_t	uintptr;
#endif // 64 bit ints

#else

typedef	char			int8;
typedef unsigned char	uint8;
typedef short			int16;
typedef unsigned short	uint16;
typedef int				int32;
typedef unsigned int	uint32;
typedef int				*intptr;
typedef unsigned int	*uintptr;
#if defined(OS_ARCH) && OS_ARCH == 64
typedef long long int			int64;
typedef unsigned long long int	uint64;
#endif // 64 bit ints

#endif //_STDINT_H_

/* types */
typedef void * Handle;
typedef union U_MultiType
{
	union
	{
		union
		{
			int8	i8;	 uint8	ui8;
			int16	i16; uint16	ui16;
			int32	i32; uint32	ui32;
#if defined(OS_ARCH) && OS_ARCH == 64
			int64	i64; uint64	i64;	
#endif //
		};
#if defined(OS_ARCH) && OS_ARCH == 64
			int64	raw_i; uint64 raw_ui;
#else
			int32	raw_i; uint32 raw_ui;
#endif //
	} Integers;

	union
	{
		union
		{
			float		f;
			double		d;
			long double ld;
		};
		long double raw;
	} FloatingPoint;

	union
	{
		union
		{
			Handle ptr;
			char * str;
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
	TT_NULL,
	TT_COUNT
} TypeTag;

/* -------- functions -------------*/
void	cutypes_store_integer(const Handle value, MultiType * mt, TypeTag t);
void	cutypes_store_floating_point(const Handle value, MultiType * mt, TypeTag t);
void	cutypes_store_pointer(const Handle value, MultiType * mt, TypeTag t);
#if defined(OS_ARCH) && OS_ARCH == 64
int64	cutypes_raw_integer(MultiType * mt);
uint64	cutypes_raw_uinteger(MultiType * mt);
#else
int32	cutypes_raw_integer(MultiType * mt);
uint32	cutypes_raw_uinteger(MultiType * mt);
#endif // OS_ARCH for raw integer retreieval
long double	cutypes_raw_floating_point(MultiType * mt);
Handle		cutypes_raw_pointer(MultiType * mt);

#endif // CUTYPES_CUTYPES_H

