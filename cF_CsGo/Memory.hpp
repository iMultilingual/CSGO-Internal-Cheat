#pragma once
#include "Entity.hpp"

class Memory
{
private:
	template<typename Write>
	static void WriteMemory(void* Address, const Write& ToWrite, signed int Length)
	{
		unsigned long OldProtection;
		VirtualProtect(Address, Length, PAGE_EXECUTE_READWRITE, &OldProtection);
		*reinterpret_cast<byte*>(Address) = ToWrite;
		VirtualProtect(Address, Length, OldProtection, &OldProtection);
	};

public:
	void InitiateConsole();
};