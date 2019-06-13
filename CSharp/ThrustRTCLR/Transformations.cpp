#include "stdafx.h"
#include "ThrustRTCLR.h"
#include "fill.h"
#include "replace.h"

namespace ThrustRTCLR
{
	template<typename T>
	inline T* just_cast_it(IntPtr p)
	{
		return (T*)(void*)p;
	}

	bool Native::fiil(IntPtr p_vec, IntPtr p_value, size_t begin, size_t end)
	{
		DVVectorLike* vec = just_cast_it<DVVectorLike>(p_vec);
		DeviceViewable* value = just_cast_it<DeviceViewable>(p_value);
		return TRTC_Fill(*vec, *value, begin, end);
	}

	bool Native::replace(IntPtr p_vec, IntPtr p_old_value, IntPtr p_new_value, size_t begin, size_t end)
	{
		DVVectorLike* vec = just_cast_it<DVVectorLike>(p_vec);
		DeviceViewable* old_value = just_cast_it<DeviceViewable>(p_old_value);
		DeviceViewable* new_value = just_cast_it<DeviceViewable>(p_new_value);
		return TRTC_Replace(*vec, *old_value, *new_value, begin, end);
	}

	bool Native::replace_if(IntPtr p_vec, IntPtr p_pred, IntPtr p_new_value, size_t begin, size_t end)
	{
		DVVectorLike* vec = just_cast_it<DVVectorLike>(p_vec);
		Functor* pred = just_cast_it<Functor>(p_pred);
		DeviceViewable* new_value = just_cast_it<DeviceViewable>(p_new_value);
		return TRTC_Replace_If(*vec, *pred, *new_value, begin, end);
	}

	bool Native::replace_copy(IntPtr p_vec_in, IntPtr p_vec_out, IntPtr p_old_value, IntPtr p_new_value, size_t begin_in, size_t end_in, size_t begin_out)
	{
		DVVectorLike* vec_in = just_cast_it<DVVectorLike>(p_vec_in);
		DVVectorLike* vec_out = just_cast_it<DVVectorLike>(p_vec_out);
		DeviceViewable* old_value = just_cast_it<DeviceViewable>(p_old_value);
		DeviceViewable* new_value = just_cast_it<DeviceViewable>(p_new_value);
		return TRTC_Replace_Copy(*vec_in, *vec_out, *old_value, *new_value, begin_in, end_in, begin_out);
	}

	bool Native::replace_copy_if(IntPtr p_vec_in, IntPtr p_vec_out, IntPtr p_pred, IntPtr p_new_value, size_t begin_in, size_t end_in, size_t begin_out)
	{
		DVVectorLike* vec_in = just_cast_it<DVVectorLike>(p_vec_in);
		DVVectorLike* vec_out = just_cast_it<DVVectorLike>(p_vec_out);
		Functor* pred = just_cast_it<Functor>(p_pred);
		DeviceViewable* new_value = just_cast_it<DeviceViewable>(p_new_value);
		return TRTC_Replace_Copy_If(*vec_in, *vec_out, *pred, *new_value, begin_in, end_in, begin_out);
	}
}

