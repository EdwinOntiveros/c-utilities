#include <assert.h>
#include <stdint.h>
#include "../include/cutypes.h"

void cutypes_store_integer(const Handle val, MultiType * mt, TypeTag t)
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

void cutypes_store_floating_point(const Handle val, MultiType * mt, TypeTag t)
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

void cutypes_store_pointer(const Handle val, MultiType * mt, TypeTag t)
{
	assert(val);
	assert(mt);

	switch(t)
	{
		default: case TT_POINTER:
			mt->Pointer.ptr = val;
			break;
		case TT_STRING:
			mt->Pointer.str = (char *)val;
			break;
	}
}

#if defined(OS_ARCH) && OS_ARCH == 64
int64 cutypes_raw_integer(MultiType * mt)
{
	assert(mt);
	return mt->Integers.raw_i;
}

uint64 cutypes_raw_uinteger(MultiType * mt)
{
	assert(mt);
	return mt->Integers.raw_ui;
}
#else
int32 cutypes_raw_integer(MultiType * mt)
{
	assert(mt);
	return mt->Integers.raw_i;
}

uint32 cutypes_raw_uinteger(MultiType * mt)
{
	assert(mt);
	return mt->Integers.raw_ui;
}
#endif // raw integer retreieval

long double cutypes_raw_floating_point(MultiType * mt)
{
	assert(mt);
	return mt->FloatingPoint.raw;
}

Handle cutypes_raw_pointer(MultiType * mt)
{
	assert(mt);
	return mt->Pointer.raw;
}

