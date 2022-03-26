#include "common.hpp"
#include "core/memory.hpp"
#include "sdk/manager.hpp"

DWORD WINAPI OnDllAttach()
{
	g_memory = std::make_unique<memorys>();

	{
		auto stream = vfs::OpenRead("resources:/spawnmanager/fxmanifest.lua");
		auto data = stream->ReadToEnd();

		MessageBoxA(0, reinterpret_cast<const char*>(data.data()), 0, 0);
	}

	return TRUE;
}

BOOL WINAPI DllMain(HINSTANCE hmod, DWORD reason, LPVOID reversed)
{
	switch (reason)
	{
	case DLL_PROCESS_ATTACH: OnDllAttach(); break;
	case DLL_PROCESS_DETACH: break;
	}
	return TRUE;
}
