#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include "../include/cutypes.h"
#include "../include/cutypes_test_internal.h"

#define MASK_U8	 (0xFF)
#define MASK_U16 (0xFFFF)
#define MASK_U32 (0xFFFFFFFF)

#define MASK_8	(0x7F)
#define MASK_16 (0x7FFF)
#define MASK_32 (0x7FFFFFFF)

#if defined(OS_ARCH) && OS_ARCH == 64
#define MASK_U64 (0xFFFFFFFFFFFFFFFF)
#define MASK_64 (0x7FFFFFFFFFFFFFFF)
#endif 

#define tostr(x) #x

#if defined(OS_ARCH) && OS_ARCH == 64
#	define SIGNED_VALUE int64 signed_test_value = MASK_64
#	define USIGNED_VALUE uint64 usigned_test_value = MASK_U64
#else
#	define SIGNED_VALUE int32 signed_test_value = MASK_32
#	define USIGNED_VALUE uint32 usigned_test_value = MASK_U32
#endif // test values

bool test_cutypes_store_signed_integers(void)
{
	//LOG(begin)
	SIGNED_VALUE;
	MultiType mt = {0};

	if(test_cutypes_store_i8(&mt,signed_test_value)!=(signed_test_value & MASK_8))
	{
		//LOG()
		return false;
	}
	if(test_cutypes_store_i16(&mt,signed_test_value)!=(signed_test_value & MASK_32))
	{
		//LOG()
		return false;
	}
	if(test_cutypes_store_i32(&mt,signed_test_value)!=(signed_test_value & MASK_32))
	{
		//LOG()
		return false;
	}
#if defined(OS_ARCH) && OS_ARCH == 64
	if(test_cutypes_store_i64(&mt,signed_test_value)!=signed_test_value)
	{
		//LOG()
		return false;
	}
#endif // 64 bit test

	return true;
}

bool test_cutypes_store_usigned_integers(void)
{
	//LOG(begin)
	USIGNED_VALUE;
	MultiType mt = {0};

	if(test_cutypes_store_ui8(&mt,usigned_test_value)!=(usigned_test_value & MASK_U8))
	{
		//LOG()
		return false;
	}
	if(test_cutypes_store_ui16(&mt,usigned_test_value)!=(usigned_test_value & MASK_U32))
	{
		//LOG()
		return false;
	}
	if(test_cutypes_store_ui32(&mt,usigned_test_value)!=(usigned_test_value & MASK_U32))
	{
		//LOG()
		return false;
	}
#if defined(OS_ARCH) && OS_ARCH == 64
	if(test_cutypes_store_ui64(&mt,usigned_test_value)!=usigned_test_value)
	{
		//LOG()
		return false;
	}
#endif // 64 bit test

	return true;
}

int main(int argc, char * argv[])
{
	//run_tests();
	return 0;
}

#undef SIGNED_VALUE
#undef USIGNED_VALUE
#undef tostr
#undef MASK_8
#undef MASK_16
#undef MASK_32
#undef MASK_U8
#undef MASK_U16
#undef MASK_U32
#if defined(OS_ARCH) && OS_ARCH == 64
#undef MASK_U64
#undef MASK_64
#endif 

