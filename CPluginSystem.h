#pragma once
#include <list>
#include <algorithm>
#include <windows.h>
#include "FileEnumerator.h"
#include "CDebug.h"

namespace CLEO
{
	class CPluginSystem
	{
		std::list<HMODULE> plugins;

	public:
		CPluginSystem()
		{
			TRACE("Unloading plugins...");
			FilesWalk("cleo/*.cleo", [this](const char *libName){
				char libPath[MAX_PATH] = "cleo/";
				strcat(libPath, libName);
				TRACE("Loading plugin %s", libPath);
				HMODULE hlib = LoadLibrary(libPath);
				if(!hlib)
				{
					char message[MAX_PATH + 40];
					sprintf(message, "Error loading plugin %s", libPath);
					Warning(message);
				}
				else plugins.push_back(hlib);
			});
		}

		~CPluginSystem()
		{
			std::for_each(plugins.begin(), plugins.end(), FreeLibrary);
		}

		inline size_t		GetNumPlugins()				{return plugins.size();}
	};
}