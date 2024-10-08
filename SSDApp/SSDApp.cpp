﻿//#include <iostream>
//#include <string>
//#include <fstream>
//
//int main() {
//   std::ifstream readFile;//읽기전용
//   readFile.open("result.txt"); //파일 열기
//   std::string line;
//   if(readFile.is_open()) {
//      while(!readFile.eof()){
//         getline(readFile, line);
//         std::cout << line << std::endl;
//      }
//   }
//   readFile.close();
//}

#include <iostream>
#include <cctype>
#include "SSD.h"

bool isHexadecimal(const std::string& input) {
    // 입력 문자열이 빈 문자열인지 검사
    if (input.empty()) return false;

    // 0x 또는 0X로 시작하면 이를 무시 (16진수 표기법)
    size_t startIndex = 0;
    if (input.length() > 2 && (input[0] == '0') && (input[1] == 'x' || input[1] == 'X')) {
        startIndex = 2;
    }

    // 남은 문자가 모두 16진수 값인지 검사
    for (size_t i = startIndex; i < input.length(); ++i) {
        if (!std::isxdigit(input[i])) {
            return false;
        }
    }
    return true;
}


bool isLBA(const int& input) {
    if (input >= 0 && input < 100) return true;
    else return false;
}

bool Testapp1(SSD& a_ssd)
{
	for (int i = 0; i < 100; i++) {
		// TO-DO exec이용해서 실행파일 사용
		a_ssd.Write(i, "0xABCDFFFF");
	}

	for (uint32_t i = 0; i <= 99; i++) {
		if (a_ssd.Read(i) != "0xABCDFFFF")
		{
			return false;
		}
	}

	return true;

}
bool Testapp2(SSD& a_ssd)
{
	for (int cnt = 0; cnt < 30; cnt++)
	{
		for (int i = 0; i <= 5; i++)
		{
			a_ssd.Write(i, "0xAAAABBBB");
		}
	}

	for (int i = 0; i <= 5; i++)
	{
		if (a_ssd.Read(i) != "0xAAAABBBB")
		{
			return false;
		}
	}

	for (int i = 0; i <= 5; i++)
	{
		a_ssd.Write(i, "0x12345678");
	}

	for (int i = 0; i <= 5; i++)
	{
		if (a_ssd.Read(i) != "0x12345678")
		{
			std::cout << "testapp2 FAIL" << '\n';
			return false;
		}
	}

	return true;

}
int main() {
	std::string s, s_LBA, h;
	int LBA;
	SSD a_ssd;

	while (1) {
		s = "";
		h = "";
		std::cout << "명령어를 입력하세요: ";
		std::cin >> s;

		if (s == "write") {
			std::cout << "값을 저장할 LBA를 입력하세요: ";
			std::cin >> s_LBA;
			try {
				LBA = std::stoi(s_LBA);
			}
			catch (std::invalid_argument&) {
				std::cout << "LBA 형식이 잘못됐습니다." << std::endl;
				continue;
			}
			if (isLBA(LBA) == 0) {
				std::cout << "LBA범위 오류" << std::endl;
				continue;
			}

			std::cout << "16진수 값을 입력하세요: ";
			std::cin >> h;
			if (isHexadecimal(h) == 0) {
				std::cout << "16진수 입력 값 오류" << std::endl;
				continue;
			}
			// TO-DO exec이용해서 실행파일 사용
			a_ssd.Write(LBA, h);
		}

		else if (s == "fullwrite") {
			std::cout << "저장할 16진수 값을 입력하세요: ";
			std::cin >> h;
			if (isHexadecimal(h) == 0) {
				std::cout << "16진수 입력 값 오류" << std::endl;
				continue;
			}

			
			for (int i = 0; i < 100; i++) {
				// TO-DO exec이용해서 실행파일 사용
				a_ssd.Write(i, h);
			}
			
		}

		else if (s == "read") {
			uint32_t address;

			std::cout << "출력할 LBA 값을 입력하세요: ";
			std::cin >> address;
			try {
				LBA = address;
			}
			catch (std::invalid_argument&) {
				std::cout << "LBA 형식이 잘못됐습니다." << std::endl;
				continue;
			}
			if (isLBA(LBA) == 0) {
				std::cout << "LBA범위 오류" << std::endl;
				continue;
			}

			std::string rLine = a_ssd.Read(address);
			std::cout << rLine << std::endl;

		}

		else if (s == "fullread") {
			a_ssd.fullRead();
		}

		else if (s == "testapp1")
		{
			if(Testapp1(a_ssd)) std::cout << "testapp1 Succsess" << '\n';
			else std::cout << "testapp1 FAIL" << '\n';
		}
		else if (s == "testapp2")
		{
			if (Testapp2(a_ssd)) std::cout << "testapp2 Succsess" << '\n';
			else std::cout << "testapp2 FAIL" << '\n';
		}
		else if (s == "help") {
			std::cout << std::flush; // 출력버퍼 비우기
			std::cout << "====명령어 사용 방법======" << std::endl;
			std::cout << "write: LBA에 입력\n ex) write LBA번호 입력값" << std::endl;
			std::cout << "read: 화면출력\n ex) write LBA번호" << std::endl;
			std::cout << "exit: Shell 종료\n ex) exit" << std::endl;
			std::cout << "help: 명령어 사용방법 출력\n ex) help" << std::endl;
			std::cout << "fullwrite: LBA 0번부터 99번까지 입력\n ex) fullwrite 입력값" << std::endl;
			std::cout << "fullread: LBA 0번부터 99번까지 출력\nex) fullwrite" << std::endl;
		}

		else if (s == "exit") break;
	}

	return 0;
}

//#include <iostream>
//#include <stdio.h>
//#include <process.h>
//
//int main() {
//    const char* program = "C:\\Users\\USER\\source\\repos\\Project1\\x64\\Release\\Project1.exe";  // 실행할 프로그램
//    const char* args[] = { program, NULL };
//
//    // _spawn 함수로 프로세스 생성 및 실행
//    int result = _spawnvp(_P_NOWAIT, program, args); // _P_WAIT
//
//    if (result == -1) {
//        std::cerr << "프로세스 실행에 실패했습니다!" << std::endl;
//    }
//    else {
//        std::cout << "프로세스가 성공적으로 실행되었습니다!" << std::endl;
//    }
//
//    return 0;
//}