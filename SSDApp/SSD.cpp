#include "SSD.h"

void SSD::Write(uint32_t address, std::string value)
{
	std::string str, tmp_address, tmp_value;
	bool found_flag = false;

	nand_file.open("nand.txt");
	std::ofstream temp_file("temp.txt");

	if (!nand_file.is_open() || !temp_file.is_open())
	{
		std::cout << "ERROR" << std::endl;
		return;
	}

	while (std::getline(nand_file, str))
	{
		auto pos = str.find(" ");
		tmp_address = str.substr(0, pos);
		tmp_value = str.substr(pos + 1);
		if (atoi(tmp_address.c_str()) == address)
		{
			temp_file << tmp_address + " " + value + '\n';
			found_flag = true;
		}
		else
		{
			temp_file << str << '\n';
		}
	}

	if (!found_flag) {
		temp_file << address << " " << value << '\n';
	}

	nand_file.close();
	temp_file.close();

	std::remove("nand.txt");
	std::rename("temp.txt", "nand.txt");
}


std::string  SSD::Read(uint32_t address)
{
	bool find_nand_flag = false;
	bool found_result_flag = false;

	nand_file.open("nand.txt");
	result_file.open("result.txt");
	std::ofstream temp_file("temp.txt");

	if (!nand_file.is_open() || !result_file.is_open() || !temp_file.is_open())
	{
		std::cout << "ERROR" << '\n';
		return "ERROR";
	}

	// nand.txt �� ������ �ִ��� Ȯ�� 
	std::string str, nand_address, nand_value;
	while (std::getline(nand_file, str))
	{
		auto pos = str.find(" ");
		if (pos != std::string::npos)
		{
			nand_address = str.substr(0, pos);
			nand_value = str.substr(pos + 1);
			if (atoi(nand_address.c_str()) == address)
			{
				find_nand_flag = true;
				break;
			}
		}
	}

	// result.txt�� ������ �ϴ� ������(nand.txt ���� ������ ������) �� �̹� �����Ѵٸ� --> result.txt�� ������ �ִ� �����ʹ� �����ϰ� nand.txt���� ���� �����ͷ� ��ü 
	// ���࿡ result.txt�� ���ٸ� �׳� �����
	std::string  tmp_address, tmp_value;
	while (std::getline(result_file, str))		//���پ� �б�
	{
		auto pos = str.find(" ");
		tmp_address = str.substr(0, pos);
		tmp_value = str.substr(pos + 1);
		if (atoi(tmp_address.c_str()) == address)
		{

			temp_file << tmp_address + " " + nand_value + '\n';
			found_result_flag = true;
		}
		else
		{
			temp_file << str << '\n';
		}
	}

	if (!find_nand_flag)					// nand.txt ���� ���� ���� �� 0x0000000 ���� 
	{
		temp_file << "0x00000000" << '\n';
	}
	else if (!found_result_flag)
	{
		temp_file << address << " " << nand_value << '\n';
	}

	nand_file.close();
	result_file.close();
	temp_file.close();

	std::remove("result.txt");
	std::rename("temp.txt", "result.txt");

	if (!find_nand_flag) return "0x00000000";
	else return nand_value;
}

void SSD::fullRead() {
	std::string fline;

	result_file.open("result.txt");
	if (!result_file) {
		std::cout << "file error!" << std::endl;
		return;
	}

	result_file.clear();
	result_file.seekg(0, std::ios::beg);

	result_file.seekg(0, std::ios::end);
	std::streampos fSize = result_file.tellg();

	if (fSize <= 0) {
		std::cout << "Fill is empty or File Size Error" << std::endl;
		return;
	}

	fline.clear();
	fline.resize(fSize);
	result_file.seekg(0, std::ios::beg);

	result_file.read(&fline[0], fSize);
	std::cout << fline << std::endl;

	if (result_file.is_open()) {
		result_file.close();
	}
}

