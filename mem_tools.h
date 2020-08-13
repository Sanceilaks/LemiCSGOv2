#pragma once
#include <Windows.h>
#include <vector>
#include <iostream>

typedef void* (*Interface)(const char* Name_, int Ret_);
typedef void* abstract_interface;

class CMemTools
{
public:
	static abstract_interface getInterface(const char* _module, const char* _interface);
	static std::uint8_t* patternScaner(const char* module_name, const char* signature) noexcept;
};