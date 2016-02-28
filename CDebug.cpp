#include "stdafx.h"
#include "CDebug.h"

CDebug Debug;

void Error(const char *szStr)
{
	MessageBox(nullptr, szStr, "CLEO error", MB_ICONERROR | MB_OK);
	TRACE("[Error] Exiting with error: %s", szStr);
	//exit(1);
}

void Warning(const char *szStr)
{
	MessageBox(nullptr, szStr, "CLEO warning", MB_ICONWARNING | MB_OK);
	TRACE("[Warning] %s", szStr);
	//exit(1);
}