// 2983.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
#include  <map>
#include  <set>
#include <tuple>
#include <climits>

std::map<int, std::set<int>> plants_p;
std::map<int, std::set<int>> plants_m;

int GetDist(int a, int b, int c, int d)
{
    return (a - c)* (a - c) + (b - d) * (b - d);
}

std::pair<int, int> CalMoving(std::pair<int, int> _frog, char dir)
{
    std::pair<int, int> Res = std::make_pair(-1, -1);
    int cx, cy;
    std::tie(cx, cy) = _frog;
    int nx = -1, ny = -1;
    int max_dir = INT_MAX;
    switch (dir)
    {
    case 'A':
    {
        auto itx = plants_p.upper_bound(cx);
        if (itx == plants_p.end())
        {
            return Res;
        }
        else
        {
            for (; itx != plants_p.end(); itx++)
            {
				auto ity = itx->second.upper_bound(cy);
				if (ity == itx->second.end())
				{
                    continue;
				}
				else
				{
					int tmpx = itx->first;
					int tmpy = *ity;
                    int tmpdir = GetDist(cx, cy, tmpx, tmpy);
                    if (max_dir > tmpdir)
                    {
                        nx = tmpx;
                        ny = tmpy;
                        max_dir = tmpdir;
                    }

				}
            }
        }
        break;
    }
    case 'B'://+-
    {
        auto itx = plants_m.upper_bound(cx);
        if (itx == plants_m.end())
        {
            return Res;
        }
        else
        {
            for (; itx != plants_m.end(); itx++)
            {
                auto ity = itx->second.upper_bound(-cy);
                if (ity == itx->second.end())
                {
                    continue;
                }
                else
                {
                    int tmpx = itx->first;
                    int tmpy = -*ity;
                    int tmpdir = GetDist(cx, cy, tmpx, tmpy);
                    if (max_dir > tmpdir)
                    {
                        nx = tmpx;
                        ny = tmpy;
                        max_dir = tmpdir;
                    }

                }
            }
        }
        break;
    }
    case 'C'://-+
    {
        auto itx = plants_p.lower_bound(cx);
        if (itx == plants_p.end() || itx == plants_p.begin())
        {
            return Res;
        }
        else
        {
            while (true)
            {
				itx--;


                auto ity = itx->second.upper_bound(cy);
                if (ity == itx->second.end())
                {
                    if (itx == plants_p.begin())
                    {
                        break;
                    }
                    continue;
                }
                else
                {
                    int tmpx = itx->first;
                    int tmpy = *ity;
                    int tmpdir = GetDist(cx, cy, tmpx, tmpy);
                    if (max_dir > tmpdir)
                    {
                        nx = tmpx;
                        ny = tmpy;
                        max_dir = tmpdir;
                    }

                }
                if (itx == plants_p.begin())
                {
                    break;
                }

            }

        }
        break;
    }
    case 'D':
    {
        auto itx = plants_m.lower_bound(cx);
        if (itx == plants_m.end() || itx == plants_m.begin())
        {
            return Res;
        }
        else
        {
            while (true)
            {
                itx--;
                auto ity = itx->second.upper_bound(-cy);
                if (ity == itx->second.end())
                {
                    if (itx == plants_m.begin())
                    {
                        break;
                    }
                    continue;
                }
                else
                {
                    int tmpx = itx->first;
                    int tmpy = -*ity;
                    int tmpdir = GetDist(cx, cy, tmpx, tmpy);
                    if (max_dir > tmpdir)
                    {
                        nx = tmpx;
                        ny = tmpy;
                        max_dir = tmpdir;
                    }

                }
                if (itx == plants_m.begin())
                {
                    break;
                }

            }

        }
        break;
    }
    default:
        break;
    }

    Res.first = nx;
    Res.second = ny;
    int a = 0;
    return Res;
}
// A + +
// B + -
// C - +
// D - - 
int main()
{
    int n, k;
    std::cin >> n >> k;
    std::string _moving;
    std::cin >> _moving;

    std::pair<int, int> frog;
    for (int i = 0; i < n; ++i)
    {
        int x, y;
        std::cin >> x >> y;
        if (i == 0)
        {
            frog.first = x;
            frog.second = y;
        }

		plants_p[x].insert(y);
		plants_m[x].insert(-y);
        
    }

    for (char mov : _moving)
    {
        int lenx, leny;
        std::pair<int,int> NextP = CalMoving(frog, mov);
        if(NextP.first != -1)
        {
            plants_p[frog.first].erase(frog.second);
            plants_m[frog.first].erase(-frog.second);
            frog = NextP;
        }

    }

	std::cout << frog.first << ' ' << frog.second ;

    return 0;
}


// 
// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
