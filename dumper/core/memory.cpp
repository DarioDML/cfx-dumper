#include "memory.hpp"
#include "utilities/memory/all.hpp"

memorys::memorys()
{
	memory::pattern_batch main_batch;

	main_batch.add(("gta get device"), ("41 B8 07 00 00 00 48 8B F1 E8"), [this](memory::handle ptr)
	{
		m_get_device = ptr.add(-0x1F).as<get_device_t>();
	});

	main_batch.run(memory::module(nullptr));
}