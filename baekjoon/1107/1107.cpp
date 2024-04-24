// 1107.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <set>
#include <string>

std::set<int> remainbtn;

int destint;
std::string deststring;
int ans;

void DFS(std::string _str)
{
    if (_str.size() > deststring.size())
    {
        int tmp = std::stoi(_str);
        if (abs(tmp - destint) + _str.size() < abs(ans - destint) + std::to_string(ans).size())
        {
            ans = tmp;
        }
        return;
    }
    else if (_str.size() == deststring.size()-1 || _str.size() == deststring.size())
    {
        if(_str.size()>0)
        {
            int tmp = std::stoi(_str);
            if (abs(tmp - destint) + _str.size() < abs(ans - destint) + std::to_string(ans).size())
            {
                ans = tmp;
            }
        }
        
    }
    int index = _str.size();

    if(index < deststring.size())
    {
        if (remainbtn.size() > 0)
        {
            auto it = remainbtn.lower_bound(deststring[index] - '0');
            if (remainbtn.end() != it)
            {
                DFS(_str + std::to_string(*it));
            }
            else
            {
                auto nextit = remainbtn.begin();
				if (_str.size() == 0 && *nextit == 0 && remainbtn.size() > 1)
                {
                    nextit++;
                }
                DFS(_str + std::to_string(*nextit));
            }


            if (remainbtn.begin() != it)
            {
                it--;
                DFS(_str + std::to_string(*it));
            }
            else
            {
                it = remainbtn.end();
                it--;
                DFS(_str + std::to_string(*it));
            }
        }
    }
    else
    {
        DFS(_str + std::to_string(*remainbtn.begin()));
    }
    
    return;
}

int main()
{
    std::cin >> destint;
    deststring = std::to_string(destint);
    int m;
    std::cin >> m;
    ans = 100;
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
    int answer = abs(destint - 100);
    int comp = abs(ans - destint) + std::to_string(ans).size();
    answer = std::min(answer, comp);

    std::cout << answer;
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