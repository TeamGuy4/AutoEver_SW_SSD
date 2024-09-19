#pragma once

class Storage {
public:
	virtual void Write(uint32_t address, std::string value) = 0;
	virtual std::string  Read(uint32_t address) = 0;
};

