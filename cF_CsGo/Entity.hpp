#pragma once
#include <windows.h>
#include <iostream>
#include <thread>

#include "Offsets.hpp"

class Entity
{
public:
	std::int32_t& FlashDuration() { return *reinterpret_cast<std::int32_t*>(this + FlashDuration_Offset); }
	std::int32_t& TeamNumber() { return *reinterpret_cast<std::int32_t*>(this + TeamNumber_Offset); }
	std::uintptr_t& GlowIndex() { return *reinterpret_cast<std::uintptr_t*>(this + GlowIndex_Offset); }
	bool Dormant() { return *reinterpret_cast<bool*>(this + Dormant_Offset); }
}; 