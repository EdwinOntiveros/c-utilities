#include <assert.h>
#include "../include/cutypes.h"
#include "../include/cutypes_test_internal.h"

/* store operations */
int8 test_cutypes_store_i8(MultiType * mt, int8 val)
{
	assert(mt);	
	cutypes_store_integer(&val, mt, TT_INT8); 
	return mt->Integers.i8;	
}

uint8 test_cutypes_store_ui8(MultiType * mt, uint8 val)
{
	assert(mt);	
	cutypes_store_integer(&val, mt, TT_UINT8); 
	return mt->Integers.ui8;	
}

int16 test_cutypes_store_i16(MultiType * mt, int16 val)
{
	assert(mt);	
	cutypes_store_integer(&val, mt, TT_INT16); 
	return mt->Integers.i16;	
}

uint16 test_cutypes_store_ui16(MultiType * mt, uint16 val)
{
	assert(mt);	
	cutypes_store_integer(&val, mt, TT_UINT16); 
	return mt->Integers.ui16;	
}

int32 test_cutypes_store_i32(MultiType * mt, int32 val)
{
	assert(mt);	
	cutypes_store_integer(&val, mt, TT_INT32); 
	return mt->Integers.i32;	
}

uint32 test_cutypes_store_ui32(MultiType * mt, uint32 val)
{
	assert(mt);	
	cutypes_store_integer(&val, mt, TT_UINT32); 
	return mt->Integers.ui32;	
}

#if defined(OS_ARCH) && OS_ARCH == 64
int64 test_cutypes_store_i64(MultiType * mt, int64 val)
{
	assert(mt);	
	cutypes_store_integer(&val, mt, TT_INT64); 
	return mt->Integers.i64;	
}

uint64 test_cutypes_store_ui64(MultiType * mt, uint64 val)
{
	assert(mt);	
	cutypes_store_integer(&val, mt, TT_UINT64); 
	test_cutypes_store_ui64(mt, val);
	return mt->Integers.ui64;	
}

#endif // OS_ARCH

Handle test_cutypes_store_pointer(MultiType * mt, Handle ptr)
{
	assert(mt);	
	cutypes_store_integer(ptr, mt, TT_POINTER); 
	return mt->Pointer.ptr;	
}

char * test_cutypes_store_string(MultiType * mt, char * str)
{
	assert(mt);	
	cutypes_store_integer(str, mt, TT_STRING); 
	return mt->Pointer.str;	
}


float test_cutypes_store_float(MultiType * mt, float val)
{
	assert(mt);	
	cutypes_store_integer(&val, mt, TT_FLOAT); 
	return mt->Integers.ui8;	
}

double test_cutypes_store_double(MultiType * mt, double val)
{
	assert(mt);	
	cutypes_store_integer(&val, mt, TT_DOUBLE);
	return mt->Integers.ui8;
}

long double	test_cutypes_store_long_double(MultiType * mt, double val)
{
	assert(mt);	
	cutypes_store_integer(&val, mt, TT_LONG_DOUBLE);
	return mt->Integers.ui8;	
}

/* raw storing */


