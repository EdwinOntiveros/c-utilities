#include "multitype.h"

enum E_Multitype_types
{
	MULTITYPE_TYPE_INT8,
	MULTITYPE_TYPE_INT16,
	MULTITYPE_TYPE_INT32,
	MULTITYPE_TYPE_INT64,
	MULTITYPE_TYPE_UINT8,
	MULTITYPE_TYPE_UINT16,
	MULTITYPE_TYPE_UINT32,
	MULTITYPE_TYPE_UINT64,

	MULTITYPE_TYPE_FLOAT32,
	MULTITYPE_TYPE_FLOAT64,
	MULTITYPE_TYPE_FLOATX,

	MULTITYPE_TYPE_STRING,
	MULTITYPE_TYPE_HANDLE,

	MULTITYPE_TYPE_COUNT
};

union U_Multitype
{
	struct
	{
		union
		{
			int8 	i8;
			int16 	i16;
			int32 	i32;
			int64 	i64;
			uint8 	ui8;
			uint16 	ui16;
			uint32 	ui32;
			uint64 	ui64;
		};
	} Integer;

	struct
	{
		union
		{
			float32 f32;
			float64 f64;
			floatX  fX;
		};
	} Float;

	struct
	{
		union
		{
			Handle 		handle;
			RawString 	string;
		};
	} Pointer;
};

Multitype * newMultitype(void)
{
	Multitype * multitype = (Multitype *)malloc(sizeof *multitype);

	if (!multitype) { return NULL; }
	multitype = (Multitype *){0};

	return multitype;
}

void deleteMultitype(Multitype ** mt)
{
	if (!mt && !*mt) { return; }
	*mt = (Multitype *){0};
	free(*mt);
	*mt = NULL;
}

void storeInteger(Multitype * mt, Multitype_Type type, const Handle value)
{
	// switch on type enum
	switch (type)
	{
	case MULTITYPE_TYPE_INT8:
		mt->Integer.i8 = *(int8 *) value;
		break;
	case MULTITYPE_TYPE_INT16:
		mt->Integer.i16 = *(int16 *) value;
		break;
	case MULTITYPE_TYPE_INT32:
		mt->Integer.i32 = *(int32 *) value;
		break;
	case MULTITYPE_TYPE_INT64:
		mt->Integer.i64 = *(int64 *) value;
		break;
	case MULTITYPE_TYPE_UINT8:
		mt->Integer.ui8 = *(uint8 *) value;
		break;
	case MULTITYPE_TYPE_UINT16:
		mt->Integer.ui16 = *(uint16 *) value;
		break;
	case MULTITYPE_TYPE_UINT32:
		mt->Integer.ui32 = *(uint32 *) value;
		break;
	default:
	case MULTITYPE_TYPE_UINT64:
		mt->Integer.ui64 = *(uint64 *) value;
		break;
	}
}

void storeFloat(Multitype * mt, Multitype_Type type, const Handle value)
{
	// switch on type enum
	switch (type)
	{
	case MULTITYPE_TYPE_FLOAT32:
		mt->Float.f32 = *(float32 *) value;
		break;
	default:
	case MULTITYPE_TYPE_FLOAT64:
		mt->Float.f64 = *(float64 *) value;
		break;
	case MULTITYPE_TYPE_FLOATX:
		mt->Float.fX = *(floatX *) value;
		break;
	}
}

void storePointer(Multitype * mt, Multitype_Type type, const Handle value)
{
	// switch on type enum
	switch (type)
	{
	case MULTITYPE_TYPE_HANDLE:
		mt->Pointer.handle = value;
		break;
	case MULTITYPE_TYPE_STRING:
		mt->Pointer.string = (RawString *) value;
		break;
	}
}

int64   readInteger(const Multitype * const mt)
{
	return mt->Integer.i64;
}

uint64  readUInteger(const Multitype * const mt)
{
	return mt->Integer.ui64;
}

float32 readFloat32(const Multitype * const mt)
{
	return mt->Float.f32;
}

float64 readFloat64(const Multitype * const mt)
{
	return mt->Float.f64;
}

floatX  readFloatX(const Multitype * const mt)
{
	return mt->Float.fX;
}

Handle  readPointer(const Multitype * const mt)
{
	return mt->Pointer.handle;
}