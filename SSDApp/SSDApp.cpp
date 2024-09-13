//#include <iostream>
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

int main() {
    std::string s, h;
    int LBA;
    while (1) {
        s = "";
        h = "";
        std::cout << "명령어를 입력하세요: ";
        std::cin >> s;

        if (s == "write") {
            //if (!(std::cin >> LBA)) {
            //   std::cout << "LBA값을 입력하지 않았습니다. 다시 입력해주세요." << std::endl;
            //   std::cin.clear(); // 입력 상태를 초기화
            //   std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // 입력 버퍼 비우기
            //   continue;
            //}

            //// 16진수 값 입력 받기
            //if (!(std::cin >> h)) {
            //   std::cout << "16진수 값을 입력하지 않았습니다. 다시 입력해주세요." << std::endl;
            //   std::cin.clear();
            //   std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            //   continue;
            //}
            std::cin >> LBA;
            std::cin >> h;
            if (isLBA(LBA) == 0) {
                std::cout << "LBA범위 오류" << std::endl;
                continue;
            }

            if (isHexadecimal(h) == 0) {
                std::cout << "16진수 입력 값 오류" << std::endl;
                continue;
            }
            // TO-DO exec이용해서 실행파일 사용
        }

            if (s == "fullwrite") {
                std::cin >> h;
                if (isHexadecimal(h) == 0) {
                    std::cout << "16진수 입력 값 오류" << std::endl;
                    continue;
                }

                /*
                for (int i = 0; i < 100; i++) {
                   // TO-DO exec이용해서 실행파일 사용
                }
                */
            }

        if (s == "help") {
            std::cout << std::flush; // 출력버퍼 비우기
            std::cout << "====명령어 사용 방법======" << std::endl;
            std::cout << "write: LBA에 입력\n ex) write LBA번호 입력값" << std::endl;
            std::cout << "read: 화면출력\n ex) write LBA번호" << std::endl;
            std::cout << "exit: Shell 종료\n ex) exit" << std::endl;
            std::cout << "help: 명령어 사용방법 출력\n ex) help" << std::endl;
            std::cout << "fullwrite: LBA 0번부터 99번까지 입력\n ex) fullwrite 입력값" << std::endl;
            std::cout << "fullread: LBA 0번부터 99번까지 출력\nex) fullwrite" << std::endl;
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