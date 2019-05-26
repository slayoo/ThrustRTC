from . import PyThrustRTC as native

def Find(ctx, vec, value, begin = 0, end = -1):
	return native.n_find(ctx.m_cptr, vec.m_cptr, value.m_cptr, begin, end)

def Find_If(ctx, vec, pred, begin = 0, end = -1):
	return native.n_find_if(ctx.m_cptr, vec.m_cptr, pred.m_cptr, begin, end)

def Find_If_Not(ctx, vec, pred, begin = 0, end = -1):
	return native.n_find_if_not(ctx.m_cptr, vec.m_cptr, pred.m_cptr, begin, end)