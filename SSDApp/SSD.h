#pragma once
#include "Def.h"
#include "Storage.h"

class SSD : public Storage
{
private:
	std::ifstream nand_file;
	std::ifstream result_file;
public:
	void Write(uint32_t address, std::string value);
	std::string Read(uint32_t address);
};