#include "SSD.h"

bool SSD::Write(uint32_t address, std::string value)
{
	buf[address] = value;

}
std::string SSD::Read(uint32_t address)
{
	return buf[address];

}