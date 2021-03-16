#include "Memory.hpp"
#include "Configuration.hpp"

void Memory::InitiateConsole()
{
	WriteMemory<byte>(FreeConsole, 0xC3, 0x01);
	AllocConsole();
	FILE* Bufferize;
	const auto A = freopen_s(&Bufferize, "conout$", "w", stdout);
	const auto B = freopen_s(&Bufferize, "conin$", "r", stdin);
	ShowWindow(GetConsoleWindow(), 0x05);
	SetConsoleTitle(TEXT(CSGOInternalName));
}