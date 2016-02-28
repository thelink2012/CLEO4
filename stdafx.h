#pragma once
#pragma warning(disable:4733)
#define DEBUGIT
#define _USE_MATH_DEFINES
#define WIN32_LEAN_AND_MEAN
#undef UNICODE

#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <memory>
#include <assert.h>
#include <algorithm>
#include <fstream>
#include <direct.h>
#include <list>
#include <set>

enum CLEO_Version
{
	//CLEO_VER_1				= 0x0100,
	//CLEO_VER_2				= 0x0200,
	CLEO_VER_3				= 0x0300,
	CLEO_VER_4_MIN			= 0x0400,
	CLEO_VER_4_2				= 0x0402,
	CLEO_VER_4_3				= 0x0403,
	CLEO_VER_4				= CLEO_VER_4_3,
	
	CLEO_VERSION				= CLEO_VER_4,
};
#define VERSION_LONG		0x04030000
#define VERSION_STRING	"4.3"

#define OP_NOP			0x90
#define OP_RET			0xC3
#define OP_CALL			0xE8
#define OP_JMP			0xE9
#define OP_JMPSHORT		0xEB

#define CPOOL_USE_HANDLE_ACCESS

//#define VALIDATE_SIZE(struc, size)	static_assert(sizeof(struc) == size, #struc " (Invalid Structure Size)")

#include "StdInc.h"
#include "Mem.h"