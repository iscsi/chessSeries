#pragma once

#include "types.h"
#ifdef WIN32
	#include <intrin.h>
#endif

const uint32_t BitTable[64] = {
	63, 30,  3, 32, 25, 41, 22, 33,
	15, 50, 42, 13, 11, 53, 19, 34,
	61, 29,  2, 51, 21, 43, 45, 10,
	18, 47,  1, 54,  9, 57,  0, 35,
	62, 31, 40,  4, 49,  5, 52, 26,
	60,  6, 23, 44, 46, 27, 56, 16,
	 7, 39, 48, 24, 59, 14, 12, 55,
	38, 28, 58, 20, 37, 17, 36,  8 
};

//https://stackoverflow.com/questions/355967/how-to-use-msvc-intrinsics-to-get-the-equivalent-of-this-gcc-code
//return the least signicant bit index & pop that
//https://www.felixcloutier.com/x86/bsf
//https://www.felixcloutier.com/x86/lzcnt
//https://www.felixcloutier.com/x86/tzcnt

uint32_t lzcnt(uint64_t b)
{
#ifdef WIN32
	return __lzcnt64(b);
#endif
}


uint32_t popBit(uint64_t* bb)
{
	uint32_t res = lzcnt(*bb);
	*bb &= (*bb - 1);
	return res;

//original
// 	uint64_t b = *bb ^ (*bb - 1);
// 	uint32_t fold = static_cast<uint32_t>((b & 0xffff'ffff) ^ (b >> 32));
// 	*bb &= (*bb - 1);
// 	return BitTable[(fold * 0x783a'9b23) >> 26];
}

uint32_t popCount(uint64_t b)
{
	int res = 0;
	while (b)
	{
		++res;
		b &= b - 1;
	}
	return res;
}

//TODO check is it faster to store the masks?!
uint64_t setBit(uint64_t a, uint32_t index) 
{
	return a |= static_cast<uint64_t>(1) << index;
}

uint64_t clearBit(uint64_t a, uint32_t index)
{
	return a &= ~(static_cast<uint64_t>(1) << index);
}