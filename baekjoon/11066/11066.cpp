// 11066.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <algorithm>
#include <vector>

int main()
{
    int n;
    std::cin >> n;
    while(n--)
    {
        int t;
        std::cin >> t;
        std::vector<int> arr;
        std::vector<int> dp;
        arr.resize(t+1);
        dp.resize(t+1);

        for (int i = 1; i <= t; ++i)
        {
            std::cin >> arr[i];
        }
		//std::sort(arr.begin(), arr.end());
        for (int i = 1; i <= t; ++i)
        {
            dp[i] = arr[i] + dp[i - 1];
        }

        int interval = 2;
        int answer = 0;
        while (interval < arr.size())
        {
			int index = interval;
            while (true)
            {
                answer += (dp[index] - dp[index -interval]);
                if (index+ interval >= arr.size())
                {
                    answer += dp[arr.size() - 1] - dp[index];
                    break;
                }
                index += interval;
            }
            //for (int i = interval; i < dp.size(); i += interval)
            //{
            //    answer += (dp[i] - dp[i-interval]);
            //    std::cout << i << ' ';
            //}
            interval *= 2;
        }
        std::cout << answer<<'\n';
    }

    return 0;
}

// 1 21 3 4 5 35 5 4 3 5 98 21 14 17 32
//              
// 1 3 3 4 4 5 5 5 14 17 21 21 32 35 98
// 4   7   9   10  31  42  67 98
// 11 19  73 165
// 30  238
// 268
// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
