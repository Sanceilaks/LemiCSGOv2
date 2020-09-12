#pragma once
#include <cstdint>


class VClientEntityList
{
public:
	virtual void init() = 0;
	virtual void unused_1() = 0;
	virtual void unused_2() = 0;
	virtual void* get_entity_by_index(int index) = 0;
	virtual void* get_entity_by_handel(uintptr_t handle) = 0;
};