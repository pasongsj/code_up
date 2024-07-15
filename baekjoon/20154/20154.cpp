// 20154.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>


int main()
{
    std::map<char, int> chartoint = { {'A',3},{'B',2},{'C',1},{'D',2},
        {'E',3},{'F',3},{'G',3},{'H',3},{'I',1},{'J',1},{'K',3},
        {'L',1},{'M',3},{'N',3},{'O',1},{'P',2},{'Q',2},{'R',2},{'S',1},
        {'T',2},{'U',1},{'V',1},{'W',2},{'X',2},{'Y',2},{'Z',1} };
    std::string input;
    std::cin >> input;
    std::vector<int> inputvec;
    std::vector<int> tmpvec;

    std::queue<int> curq;


    // char to string
    for (char _ch : input)
    {
        curq.push(chartoint[_ch]);
    }

    while (curq.size()>1)
    {
        int qsize = curq.size();
        int bef = 0;
        for (int i = 0; i < qsize; ++i)
        {
            bef += curq.front();
            curq.pop();
			if (i % 2 == 1 || qsize - 1 == i)
			{
                curq.push(bef);
				bef = 0;
			}
        }

    }
    if (curq.front() % 2 == 0)
    {
        std::cout << "You're the winner?";
    }
    else
    {
        std::cout << "I'm a winner!";

    }
    return 0;

}

