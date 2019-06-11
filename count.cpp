#include "count.h"
#include "general_reduce.h"
#include "built_in.h"

bool TRTC_Count(const DVVectorLike& vec, const DeviceViewable& value, size_t& ret, size_t begin, size_t end)
{
	DVSizeT dvbegin(begin);

	Functor src({ {"vec_in", &vec}, {"eq_value", &value }, {"begin", &dvbegin} }, { "idx" },
		"        return  (vec_in[idx + begin] == (decltype(vec_in)::value_t)eq_value)?1:0;\n");

	Functor op("Plus");

	if (end == (size_t)(-1)) end = vec.size();

	ret = 0;
	if (end - begin < 1) return true;

	ViewBuf buf;
	if (!general_reduce(end - begin, "size_t", src, op, buf)) return false;
	ret = *(size_t*)buf.data();
	return true;
}

bool TRTC_Count_If(const DVVectorLike& vec, const Functor& pred, size_t& ret, size_t begin, size_t end)
{
	DVSizeT dvbegin(begin);

	Functor src({ {"vec_in", &vec}, {"pred", &pred }, {"begin", &dvbegin} }, { "idx" },
		"        return pred(vec_in[idx + begin])?1:0;\n");
	Functor op("Plus");

	if (end == (size_t)(-1)) end = vec.size();

	ret = 0;
	if (end - begin < 1) return true;
	ViewBuf buf;
	if (!general_reduce(end - begin, "size_t", src, op, buf)) return false;
	ret = *(size_t*)buf.data();
	return true;

}