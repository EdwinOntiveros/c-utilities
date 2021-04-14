#include <assert.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>

#include "cutypes.h"

void store_integer(const Handle val, MultiType * mt, TypeTag t)
{
	assert(val);
	assert(mt);

	switch(t)
	{
		case TT_INT8:
			mt->Integers.i8 = *((int8 *)val);
			break;
		case TT_UINT8:
			mt->Integers.ui8 = *((uint8 *)val);
			break;
		case TT_INT16:
			mt->Integers.i16 = *((int16 *)val);
			break;
		case TT_UINT16:
			mt->Integers.ui16 = *((uint16 *)val);
			break;
		default: case TT_INT32:
			mt->Integers.i32 = *((int32 *)val);
			break;
		case TT_UINT32:
			mt->Integers.ui32 = *((uint32 *)val);
			break;
#if defined(OS_ARCH) && OS_ARCH == 64
		case TT_INT64:
			mt->Integers.i64 = *((int64 *)val);
			break;
		case TT_UINT64:
			mt->Integers.ui64 = *((uint64 *)val);
			break;
#endif // handle 64 bits
	}
}

void store_floating_point(const Handle val, MultiType * mt, TypeTag t)
{
	assert(val);
	assert(mt);

	switch(t)
	{
		case TT_FLOAT:
			mt->FloatingPoint.f = *((float *)val);
			break;
		case TT_DOUBLE:
			mt->FloatingPoint.d = *((double *)val);
			break;
		default: case TT_LONG_DOUBLE:
			mt->FloatingPoint.ld = *((long double *)val);
			break;
	}
}

void store_pointer(const Handle val, MultiType * mt, TypeTag t)
{
	assert(val);
	assert(mt);

	switch(t)
	{
		default: case TT_POINTER:
			mt->Pointer.pointer = val;
			break;
		case TT_STRING:
			mt->Pointer.string = (char *)val;
			break;
	}
}

int64 read_raw_integer(const MultiType * const mt)
{
	assert(mt);
	return mt->Integers.raw_i;
}

uint64 read_raw_uinteger(const MultiType * const mt)
{
	assert(mt);
	return mt->Integers.raw_ui;
}

long double read_raw_floating_point(const MultiType * const mt)
{
	assert(mt);
	return mt->FloatingPoint.raw;
}

Handle read_raw_pointer(const MultiType * const mt)
{
	assert(mt);
	return mt->Pointer.raw;
}

// internal
void internal_print_multitype_layout(const MultiType * const mt)
{
    printf(
        "Size of mt : %zd\n"
        "Integers:\n"
        "{\n"
        "-    i8: %d    ui8: %d\n"
        "-   i16: %d   ui16: %d\n"
        "-   i32: %d   ui32: %d\n"
#if defined(OS_ARCH) && OS_ARCH == 64
        "-   i64: %ld  ui64: %lu\n"
#endif
        "- raw_i: %ld raw_ui: %lu\n"
        "}\n"
        "offset: %zd\n"
        "address: %p\n\n"
        "Floating point:\n"

        "{\n"
        "-       float: %f\n"
        "-      double: %e\n"
        "- long double: %Le\n"
        "-         raw: %Le\n"
        "}\n"
        "offset: %zd\n"
        "address: %p\n\n"

        "Pointer:\n"
        "{\n"
        "-     pointer: %p\n"
        "-      string: %s\n"
        "-         raw: %p\n"
        "}\n"
        "offset: %zd\n"
        "address: %p\n\n"
        ,

        sizeof(*mt),
// integers
        mt->Integers.i8,    mt->Integers.ui8,
        mt->Integers.i16,   mt->Integers.ui16,
        mt->Integers.i32,   mt->Integers.ui32,
#if defined(OS_ARCH) && OS_ARCH == 64
        mt->Integers.i64,   mt->Integers.ui64,
#endif
        mt->Integers.raw_i, mt->Integers.raw_ui,
        (size_t) offsetof(MultiType,Integers),
        &mt->Integers,

// floating point
        mt->FloatingPoint.f,
        mt->FloatingPoint.d,
        mt->FloatingPoint.ld,
        mt->FloatingPoint.raw,
        (size_t) offsetof(MultiType,FloatingPoint),
        &mt->FloatingPoint,

// pointers
        mt->Pointer.pointer,
        mt->Pointer.string,
        mt->Pointer.raw,
        (size_t) offsetof(MultiType,Pointer),
        &mt->Pointer
    );
}

