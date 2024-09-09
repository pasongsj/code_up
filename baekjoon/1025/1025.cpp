// 1025.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <string>
#include <cmath>
int n, m;


bool IsSquare(long long num)
{
	long long sq = static_cast<long long>(std::sqrt(num));

	return sq * sq == num;
}


long long GetNum(int i, int j, int k, int l, const std::vector<std::vector<int>>& arr)
{
	if (k == 0 && l == 0)
	{
		if (true == IsSquare(arr[i][j]))
		{
			return arr[i][j];
		}
		return -1;
	}
	std::string ans = std::to_string(arr[i][j]);

	long long res = -1;
	while (true)
	{
		long long curlongnum = std::stoll(ans);
		if (true == IsSquare(curlongnum))
		{
			res = curlongnum;
		}
		i += k;
		j += l;
		if (0 <= i && i < n && 0 <= j && j < m)
		{
			ans += std::to_string(arr[i][j]);
			continue;
		}
		break;
	}
	return res;
}


int main()
{
	std::cin >> n >> m;


	long long answer = -1;
	std::vector<std::vector<int>>arr;
	arr.resize(n);
	for (int i = 0;i < n;++i)
	{
		arr[i].resize(m);
		std::string line;
		std::cin >> line;
		for (int j = 0;j < m;++j)
		{
			arr[i][j] = line[j]-'0';
		}
	}

	for (int i = 0;i < n;++i)
	{
		for (int j = 0;j < m;++j)
		{

			for (int k = -i;k < n;++k)
			{
				for (int l = -j;l < m;++l)
				{
					long long cur =  GetNum(i, j, k, l, arr);
					if (cur > answer)
					{
						answer = cur;
					}

				}
			}

		}
	}
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
