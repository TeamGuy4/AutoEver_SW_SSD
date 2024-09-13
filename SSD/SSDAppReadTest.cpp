#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <cctype>
#include <iomanip>


bool isLBA(const int& input) {
	if (input >= 0 && input < 100) return true;
	else return false;
}


int cmdInput() {	//명령어 입력
	std::string comm;
	std::string read = { "read" };
	std::string fread = { "fullread" };

	getline(std::cin, comm);
	if (comm == read) {
		return 1;
	}
	else if (comm == fread) {
		return 2;
	}
	else {
		std::cout << "INVALID COMMAND" << std::endl;
		return 0;
	}


}

void fileRead(std::vector<std::string>& vec) {	//read 기능
	std::ifstream readFile("result.txt");
	std::string line;

	if (!readFile) {
		std::cout << "file error!" << std::endl;
		return;
	}

	while (getline(readFile, line))	//파일 읽어와 vector에 저장
		vec.push_back(line);

	readFile.close();
}
void search(std::vector<std::string>& vec) {	//읽어온 내용 중 필요한 부분 탐색
	int word;

	std::cout << "input to access LBA : ";
	std::cin >> word;
	if (isLBA(word) == 0) {
		std::cout << "LBA range fault" << std::endl;
	}
	else {
		std::string sWord = std::to_string(word);
		if (sWord.length() < 2) { 	//현재는 한 자리 단위 표시를 0n으로 해둔 상태(추후 수정)
			sWord = "0" + sWord;
		}

		for (int i = 0; i < vec.size(); i++) {	//저장된 내용의 각 줄 앞 두 자리에 위치한 LBA값 탐색 후 해당 줄 출력
			if (vec[i].substr(0, 2) == sWord) {
				std::cout << vec[i] << std::endl;
				return;
			}
		}
	}
}

void fullRead() {	//파일 전체 출력
	std::ifstream readFile("result.txt");
	std::string str;

	if (readFile.is_open()) {
		readFile.seekg(0, std::ios::end);
		int fSize = readFile.tellg();
		str.resize(fSize);
		readFile.seekg(0, std::ios::beg);

		readFile.read(&str[0], fSize);
		std::cout << str << std::endl;
	}
	else {
		std::cout << "file not found!" << std::endl;
	}

	readFile.close();
}

int main() {
	int menu = 0;
	std::vector<std::string> vec;

	menu = cmdInput();

	while (true) {
		switch (menu) {
		case 0:
			std::cout << "input command";
			break;
		case 1:
			fileRead(vec);
			search(vec);
			break;
		case 2:
			fullRead();
		}
	}


	return (0);
}
