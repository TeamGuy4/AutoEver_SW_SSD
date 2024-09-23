#pragma once

class Storage {
public:
	virtual void Write_LiiNi(uint32_t address, std::string value) = 0;
	virtual std::string Read_LiiNi(uint32_t address) = 0;
};

