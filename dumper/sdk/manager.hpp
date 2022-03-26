#pragma once
#include "common.hpp"
#include "stream.hpp"
#include "core/memory.hpp"

namespace vfs
{
	Stream* OpenRead(const std::string& path)
	{
		auto device = g_memory->m_get_device(path.c_str(), true);

		if (device)
		{
			auto handle = device->Open(path.c_str(), true);

			if (handle != INVALID_DEVICE_HANDLE)
			{
				return new Stream(device, handle);
			}
		}

		return nullptr;
	}
}
