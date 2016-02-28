#pragma once

template<typename T, typename U>
inline void MemWrite(U p, const T v)					{*(T*)p = v;}
template<typename T, typename U>
inline void MemWrite(U p, const T v, int n)				{memcpy((void*)p, &v, n);}
template<typename T, typename U>
inline T MemRead(U p)									{return *(T*)p;}
template<typename T, typename U>
inline void MemFill(U p, T v, int n)					{memset((void*)p, v, n);}
template<typename T, typename U>
inline void MemCopy(U p, const T v)						{memcpy((void*)p, &v, sizeof(T));}
template<typename T, typename U>
inline void MemCopy(U p, const T v, int n)				{memcpy((void*)p, &v, n);}
template<typename T, typename U>
inline void MemCopy(U p, const T* v)					{memcpy((void*)p, v, sizeof(T));}
template<typename T, typename U>
inline void MemCopy(U p, const T* v, int n)				{memcpy((void*)p, v, n);}

// Write a jump to v to the address at p and copy the replaced call address to r
template<typename T, typename U>
inline void MemJump(U p, const T v, T *r = nullptr)
{
	MemWrite<BYTE>(p++, OP_JMP);
	if(r) *r = (T)(MemRead<DWORD>(p) + p + 4);
	MemWrite<DWORD>(p, ((DWORD)v - (DWORD)p) - 4);
}

// Write a call to v to the address at p and copy the replaced call address to r
template<typename T, typename U>
inline void MemCall(U p, const T v, T *r = nullptr)
{
	MemWrite<BYTE>(p++, OP_CALL);
	if(r) *r = (T)(MemRead<DWORD>(p) + p + 4);
	MemWrite<DWORD>(p, (DWORD)v - (DWORD)p - 4);
}

// Read and convert a relative offset to full
template<typename T, typename U>
T MemReadOffsetPtr(U p)
{
	return (T)((size_t)MemRead<T>(p) + p + sizeof(T));
}