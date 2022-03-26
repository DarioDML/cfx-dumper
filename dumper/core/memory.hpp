#pragma once
#include "common.hpp"
#include "sdk/fiDevice.hpp"

using get_device_t = rage::fiDevice* (*)(const char* path, bool allowRoot);

class memorys
{
public:
	memorys();
public:
	get_device_t m_get_device;
};

inline std::unique_ptr< memorys > g_memory;