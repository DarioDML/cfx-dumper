#pragma once
#include "fiDevice.hpp"

typedef uintptr_t THandle;
static const THandle InvalidHandle = -1;

#define INVALID_DEVICE_HANDLE (InvalidHandle)

namespace vfs
{
class Stream
{
private:
	rage::fiDevice* m_device;
	THandle m_handle;

public:
	Stream(rage::fiDevice* device, THandle handle);

	virtual ~Stream();

	std::vector<uint8_t> Read(size_t length);

	size_t Read(void* buffer, size_t length);

	template<typename TAlloc>
	inline size_t Read(std::vector<uint8_t, TAlloc>& buffer)
	{
		return Read(&buffer[0], buffer.size());
	}

	size_t Write(const void* buffer, size_t length);

	template<typename TAlloc>
	inline size_t Write(const std::vector<uint8_t, TAlloc>& buffer)
	{
		return Write(&buffer[0], buffer.size());
	}

	void Close();

	uint64_t GetLength();

	size_t Seek(intptr_t offset, int seekType);

	std::vector<uint8_t> ReadToEnd();

	inline THandle GetHandle()
	{
		return m_handle;
	}
};
}
