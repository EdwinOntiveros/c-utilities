#include <assert.h>
#include "cutypes.h"

/* store operations */
int8	test_cutypes_store_i8(MultiType * mt, int8 val);
uint8	test_cutypes_store_ui8(MultiType * mt, uint8 val);
int16	test_cutypes_store_i16(MultiType * mt, int16 val);
uint16	test_cutypes_store_ui16(MultiType * mt, uint16 val);
int32	test_cutypes_store_i32(MultiType * mt, int32 val);
uint32	test_cutypes_store_ui32(MultiType * mt, uint32 val);
#if defined(OS_ARCH) && OS_ARCH == 64
int64	test_cutypes_store_i64(MultiType * mt, int64 val);
uint64	test_cutypes_store_ui64(MultiType * mt, uint64 val);
#endif // OS_ARCH

Handle	test_cutypes_store_pointer(MultiType * mt, Handle ptr);
char *	test_cutypes_store_string(MultiType * mt, char * str);

float		test_cutypes_store_float(MultiType * mt, float val);
double		test_cutypes_store_double(MultiType * mt, double val);
long double	test_cutypes_store_long_double(MultiType * mt, double val);

/* raw storing */


