#pragma once

template<typename T>
void FilesWalk(const char *file_mask, T cb)
{
	HANDLE hSearch = NULL;
	WIN32_FIND_DATA wfd;
	memset(&wfd, 0, sizeof(WIN32_FIND_DATA));

	if((hSearch = FindFirstFile(file_mask, &wfd)) == INVALID_HANDLE_VALUE) return;
	
	do
	{
		if (!(wfd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)) cb(wfd.cFileName);
	}
	while(FindNextFile(hSearch, &wfd));

	FindClose(hSearch);
}