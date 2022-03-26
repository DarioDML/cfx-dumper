#include "common.hpp"
#include "stream.hpp"

namespace vfs
{
	Stream::Stream(rage::fiDevice* device, THandle handle)
		: m_device(device), m_handle(handle)
	{

	}

	Stream::~Stream()
	{
		Close();
	}

	size_t Stream::Read(void* buffer, size_t length)
	{
		return m_device->Read(m_handle, buffer, length);
	}

	std::vector<uint8_t> Stream::Read(size_t length)
	{
		std::vector<uint8_t> retval(length);
		length = Read(retval);

		retval.resize(length);

		return retval;
	}

	size_t Stream::Write(const void* buffer, size_t length)
	{
		return m_device->Write(m_handle,(void*)buffer, length);
	}

	uint64_t Stream::GetLength()
	{
		return m_device->GetFileLength(m_handle);
	}

	size_t Stream::Seek(intptr_t offset, int seekType)
	{
		return m_device->Seek(m_handle, offset, seekType);
	}

	void Stream::Close()
	{
		if (m_handle != INVALID_DEVICE_HANDLE)
		{
			m_device->Close(m_handle);
			m_handle = INVALID_DEVICE_HANDLE;
		}
	}

	std::vector<uint8_t> Stream::ReadToEnd()
	{
		size_t fileLength = m_device->GetFileLength(m_handle);
		size_t curSize = Seek(0, SEEK_CUR);
	
		if (fileLength - curSize == 0)
			return std::vector<uint8_t>();

		return Read(fileLength - curSize);
	}
}