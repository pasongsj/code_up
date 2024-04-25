// 1107.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <set>
#include <string>

std::set<int> remainbtn;

int destint;
std::string deststring;
int anscnt;
std::string inputnumber;

void DFS(std::string _str)
{
    if (_str.size() == deststring.size() - 1 || _str.size() == deststring.size()
        || _str.size() > deststring.size())
    {
        if (_str.size() > 0 && anscnt > abs(destint - std::stoi(_str)) + _str.size())
        {   
            anscnt = abs(destint - std::stoi(_str)) + _str.size();
        }

        if (_str.size() > deststring.size())
        {
            return;
        }
    }
    for (int num : remainbtn)
    {
        DFS(_str + std::to_string(num));
    }
}

int main()
{
    std::cin >> destint;
    deststring = std::to_string(destint);

    anscnt = abs(destint - 100);
    //inputnumber = "100";

    int m;
    std::cin >> m;
    for (int i = 0; i <= 9; ++i)
    {
        remainbtn.insert(i);
    }
    for (int i = 0; i < m; ++i)
    {
        int tmp;
        std::cin >> tmp;
        remainbtn.erase(tmp);
    }

    DFS("");
    std::cout << anscnt;

    //std::cout << answer;
    return 0;
}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.


// 140