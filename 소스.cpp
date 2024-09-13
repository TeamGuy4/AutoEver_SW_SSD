//#include <iostream>
//#include <string>
//#include <fstream>
//
//int main() {
//	std::ifstream readFile;//�б�����
//	readFile.open("result.txt"); //���� ����
//	std::string line;
//	if(readFile.is_open()) {
//		while(!readFile.eof()){
//			getline(readFile, line);
//			std::cout << line << std::endl;
//		}
//	}
//	readFile.close();
//}

#include <iostream>
#include <cctype>

bool isHexadecimal(const std::string& input) {
	// �Է� ���ڿ��� �� ���ڿ����� �˻�
	if (input.empty()) return false;

	// 0x �Ǵ� 0X�� �����ϸ� �̸� ���� (16���� ǥ���)
	size_t startIndex = 0;
	if (input.length() > 2 && (input[0] == '0') && (input[1] == 'x' || input[1] == 'X')) {
		startIndex = 2;
	}

	// ���� ���ڰ� ��� 16���� ������ �˻�
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

int main() {
	std::string s, h;
	int LBA;
	while (1) {
		s = "";
		h = "";
		std::cout << "��ɾ �Է��ϼ���: ";
		std::cin >> s;

		if (s == "write") {
			//if (!(std::cin >> LBA)) {
			//	std::cout << "LBA���� �Է����� �ʾҽ��ϴ�. �ٽ� �Է����ּ���." << std::endl;
			//	std::cin.clear(); // �Է� ���¸� �ʱ�ȭ
			//	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // �Է� ���� ����
			//	continue;
			//}

			//// 16���� �� �Է� �ޱ�
			//if (!(std::cin >> h)) {
			//	std::cout << "16���� ���� �Է����� �ʾҽ��ϴ�. �ٽ� �Է����ּ���." << std::endl;
			//	std::cin.clear();
			//	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			//	continue;
			//}
			std::cin >> LBA;
			std::cin >> h;
			if (isLBA(LBA) == 0) {
				std::cout << "LBA���� ����" << std::endl;
				continue;
			}

			if (isHexadecimal(h) == 0) {
				std::cout << "16���� �Է� �� ����" << std::endl;
				continue;
			}
			// TO-DO exec�̿��ؼ� �������� ���
		}2

			if (s == "fullwrite") {
				std::cin >> h;
				if (isHexadecimal(h) == 0) {
					std::cout << "16���� �Է� �� ����" << std::endl;
					continue;
				}

				/*
				for (int i = 0; i < 100; i++) {
					// TO-DO exec�̿��ؼ� �������� ���
				}
				*/
			}

		if (s == "help") {
			std::cout << std::flush; // ��¹��� ����
			std::cout << "====��ɾ� ��� ���======" << std::endl;
			std::cout << "write: LBA�� �Է�\n ex) write LBA��ȣ �Է°�" << std::endl;
			std::cout << "read: ȭ�����\n ex) write LBA��ȣ" << std::endl;
			std::cout << "exit: Shell ����\n ex) exit" << std::endl;
			std::cout << "help: ��ɾ� ����� ���\n ex) help" << std::endl;
			std::cout << "fullwrite: LBA 0������ 99������ �Է�\n ex) fullwrite �Է°�" << std::endl;
			std::cout << "fullread: LBA 0������ 99������ ���\nex) fullwrite" << std::endl;
		}

		if (s == "exit") break;
	}

	return 0;
}

//#include <iostream>
//#include <stdio.h>
//#include <process.h>
//
//int main() {
//    const char* program = "C:\\Users\\USER\\source\\repos\\Project1\\x64\\Release\\Project1.exe";  // ������ ���α׷�
//    const char* args[] = { program, NULL };
//
//    // _spawn �Լ��� ���μ��� ���� �� ����
//    int result = _spawnvp(_P_NOWAIT, program, args); // _P_WAIT
//
//    if (result == -1) {
//        std::cerr << "���μ��� ���࿡ �����߽��ϴ�!" << std::endl;
//    }
//    else {
//        std::cout << "���μ����� ���������� ����Ǿ����ϴ�!" << std::endl;
//    }
//
//    return 0;
//}