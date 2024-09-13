#pragma once
#include "Def.h"
#include "Storage.h"

class SSD : public Storage
{
private:
	std::string buf[MEM_SIZE];

public:
	bool Write(uint32_t address, std::string value);
	std::string Read(uint32_t address);
};