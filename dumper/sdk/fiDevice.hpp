#pragma once
#include <array>

namespace rage
{
	class sysUseAllocator
	{
	public:
		void* operator new(size_t size);

		inline void* operator new[](size_t size)
		{
			return sysUseAllocator::operator new(size);
		}

		void operator delete(void* memory);

		inline void operator delete[](void* memory)
		{
			return sysUseAllocator::operator delete(memory);
		}
	};

	struct fiFindData
	{
		char fileName[256];
		uint64_t fileSize;
		FILETIME lastWriteTime;
		DWORD fileAttributes;
	};

	struct ResourceFlags
	{
		// TODO: figure out which is physical and which is virtual
		uint32_t flag1;
		uint32_t flag2;
	};

	class  __declspec(novtable) fiDevice : public rage::sysUseAllocator
	{
	public:
		static fiDevice* GetDevice(const char* path, bool allowRoot);

		static bool MountGlobal(const char* mountPoint, fiDevice* device, bool allowRoot);

		static void Unmount(const char* rootPath);

		static void Unmount(fiDevice const& device);

		//static fwEvent<> OnInitialMount;

	public:
		virtual ~fiDevice() = 0;

		virtual uint64_t Open(const char* fileName, bool readOnly) = 0;

		virtual uint64_t OpenBulk(const char* fileName, uint64_t* ptr) = 0;

		virtual uint64_t OpenBulkWrap(const char* fileName, uint64_t* ptr, void*) = 0;

		virtual uint64_t CreateLocal(const char* fileName) = 0;

		virtual uint64_t Create(const char* fileName) = 0;

		virtual uint32_t Read(uint64_t handle, void* buffer, uint32_t toRead) = 0;

		virtual uint32_t ReadBulk(uint64_t handle, uint64_t ptr, void* buffer, uint32_t toRead) = 0;

		virtual uint32_t WriteBulk(uint64_t, int, int, int, int) = 0;

		virtual uint32_t Write(uint64_t, void*, int) = 0;

		virtual uint32_t Seek(uint64_t handle, int32_t distance, uint32_t method) = 0;

		virtual uint64_t SeekLong(uint64_t handle, int64_t distance, uint32_t method) = 0;

		virtual int32_t Close(uint64_t handle) = 0;

		virtual int32_t CloseBulk(uint64_t handle) = 0;

		virtual int GetFileLength(uint64_t handle) = 0;

		virtual uint64_t GetFileLengthUInt64(uint64_t handle) = 0;

		// dummy!
		virtual int m_40(int) = 0;

		virtual bool RemoveFile(const char* file) = 0;
		virtual int RenameFile(const char* from, const char* to) = 0;
		virtual int CreateDirectory(const char* dir) = 0;

		virtual int RemoveDirectory(const char * dir) = 0;

		virtual void m_xx() = 0;

		virtual uint64_t GetFileLengthLong(const char* fileName) = 0;

		virtual uint64_t GetFileTime(const char* file) = 0;
		virtual bool SetFileTime(const char* file, FILETIME fileTime) = 0;

		virtual uint64_t FindFirst(const char* path, fiFindData* findData) = 0;
		virtual bool FindNext(uint64_t handle, fiFindData* findData) = 0;
		virtual int FindClose(uint64_t handle) = 0;

		virtual rage::fiDevice* GetUnkDevice() = 0;

		virtual void* m_xy(void*, int, void*) = 0;

		virtual bool Truncate(uint64_t handle) = 0;

		virtual uint32_t GetFileAttributes(const char* path) = 0;

		virtual bool m_xz() = 0;

		virtual bool SetFileAttributes(const char* file, uint32_t FileAttributes) = 0;

		virtual int m_yx() = 0;

		// read even if read() returns less than length
		virtual bool ReadFull(uint64_t handle, void* buffer, uint32_t length) = 0;

		virtual bool WriteFull(uint64_t handle, void* buffer, uint32_t length) = 0;

		virtual int32_t GetResourceVersion(const char* fileName, ResourceFlags* flags) = 0;

		virtual int32_t m_yy() = 0;

		virtual int32_t m_yz(void*) = 0;

		virtual int32_t m_zx(void*) = 0; // return 0x40000000

		virtual bool IsCollection() = 0;

		virtual bool m_addedIn1290() = 0;

		virtual fiDevice* GetCollection() = 0; // return this

		virtual bool m_ax() = 0;

		virtual int32_t GetCollectionId() = 0;

		virtual const char* GetName() = 0;

		/*virtual uint64_t m_84(int a1) = 0;

		virtual uint32_t m_88(int a1) = 0;

		virtual bool m_8C() = 0;

		virtual int m_90() = 0;

		virtual const char* getName() = 0;

		virtual rage::fiDevice* getUnkDevice() = 0;

		virtual int m_9C(int, int, int) = 0;

		virtual void acquireLock() = 0;
		virtual void releaseLock() = 0;*/
	};

}
