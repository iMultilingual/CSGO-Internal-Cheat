#include "Memory.hpp"
#include "Attributes.hpp"
#include "Configuration.hpp"
#include "Exploit.hpp"

HMODULE Module = nullptr;

DWORD APIENTRY EjectActiveThread(LPVOID Parameter)
{
	FreeLibraryAndExitThread(Module, NULL);
}

std::int32_t Informer()
{
	Console::FormatCyan("CS:GO Internal Started!");
	std::cout << "\n";
	Console::FormatYellow("Version: ");
	std::cout << CSGOInternalVersion << "\n";
	return FALSE;
}

auto Start = []() -> void
{
	Memory Environment;
	Environment.InitiateConsole();
	Informer();
	CSGO::StartExploit();
	FreeConsole();
	CreateThread(nullptr, NULL, reinterpret_cast<LPTHREAD_START_ROUTINE>(EjectActiveThread), Module, NULL, nullptr);
};

BOOL APIENTRY DllMain
(
	_In_ HINSTANCE const Instance,
	_In_ DWORD     const Reason,
	_In_ LPVOID    const Reserved
)
{
	switch (Reason)
	{
	case DLL_PROCESS_ATTACH:
		Module = Instance;
		DisableThreadLibraryCalls(Module);
		std::thread(Start).detach();
		break;
	default:
		break;
	}

	return TRUE;
}