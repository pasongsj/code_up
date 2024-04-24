// 12904.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
#include <deque>

class CustomDequeString
{
public:
    bool IsRerverse = false;
    std::deque<char> arr;

    bool Compare(const std::string& _str)
    {
        if (_str.size() != arr.size())
        {
            return false;
        }
        if (true == IsRerverse)
        {
            for (int i = 0; i < _str.size(); ++i)
            {
                if (_str[i] == arr[_str.size() - 1 - i])
                {
                    continue;
                }
                return false;
            }
        }
        else
        {
            for (int i = 0; i < _str.size(); ++i)
            {
                if (_str[i] == arr[i])
                {
                    continue;
                }
                return false;
            }
        }
        return true;
    }

    void DoMethod1()
    {
        if (true == IsRerverse)
        {
            arr.push_front('A');
        }
        else
        {
			arr.push_back('A');
        }
    }

    void UndoMethod1()
    {
        if (true == IsRerverse)
        {
            arr.pop_front();
        }
        else
        {
			arr.pop_back();

        }
    }

    void DoMethod2()
    {
        IsRerverse = !IsRerverse;
        if (true == IsRerverse) // 뒤집힌 상태
        {
            arr.push_front('B');
        }
        else // 정방향
        {
            arr.push_back('B');
        }
    }

    void UndoMethod2()
    {
        if (true == IsRerverse)
        {
            arr.pop_front();
        }
        else
        {
            arr.pop_back();
        }
        IsRerverse = !IsRerverse;
    }

};


int main()
{
    std::string S, T;
    std::cin >> S >> T;

    CustomDequeString CustomT;
    for (int i = 0; i < T.size(); ++i)
    {
        CustomT.arr.push_back(T[i]);
    }
    while (S.size() <  CustomT.arr.size())
    {
        char Last;
        if (true == CustomT.IsRerverse)
        {
            Last = CustomT.arr.front();
        }
        else
        {
            Last = CustomT.arr.back();
        }
        if (Last == 'A')
        {
            CustomT.UndoMethod1();
        }
        else
        {
            CustomT.UndoMethod2();
        }
    }
    if (true == CustomT.Compare(S))
    {
        std::cout << 1;
    }
    else
    {
        std::cout << 0;
    }
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


//B
//B + A
//AB + B
// ABB + A