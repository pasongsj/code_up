// 11663.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	int n, m;
	std::cin >> n >> m;
	std::vector<int> arr;
	arr.resize(n);
	for (int i = 0; i < n; ++i)
	{
		std::cin >> arr[i];
	}

	std::sort(arr.begin(), arr.end());

	std::vector<int> answer;
	for (int j = 0; j < m; ++j)
	{
		// 1 과 10 구간
		int s_b, e_b;
		std::cin >> s_b >> e_b;

		int start = 0, end = n - 1;
		int answer1 = 0;
		// 10보다 작은 수 중 최대 인덱스 값
		if (arr[n - 1] < s_b || arr[0] > e_b)
		{
			answer.push_back(0);
			continue;
		}
		while (start <= end)
		{
			int mid = (start + end) / 2;
			if (arr[mid] <= e_b)
			{
				start = mid + 1;
				answer1 = mid;
			}
			else
			{
				end = mid - 1;
			}
		}
		start = 0, end = n - 1;
		int answer0 = 0;
		while (start <= end)
		{
			int mid = (start + end) / 2;
			if (s_b <= arr[mid])
			{
				answer0 = mid;
				end = mid - 1;
			}
			else
			{
				start = mid + 1;
			}
		}
		answer.push_back(answer1 - answer0 + 1);
	}

	for (int num : answer)
	{
		std::cout << num << '\n';
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
