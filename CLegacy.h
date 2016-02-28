#pragma once
#include "CCodeInjector.h"
#include "CGameVersionManager.h"

namespace CLEO
{
	class CLegacy
	{
		DWORD FUNC_fopen;
		DWORD FUNC_fclose;

		CLegacy();
	};

	extern CLegacy Legacy;
};