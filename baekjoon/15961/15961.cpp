#include <iostream>
#include <vector>


int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n, d, k, c;
    std::cin >> n >> d >> k >> c;
    std::vector<int> arr;
    arr.resize(n + k);
    for (int i = 0;i < n;++i)
    {
        std::cin >> arr[i];
    }
    for (int j = n;j < n + k;j++)
    {
        arr[j] = arr[j - n];
    }

    std::vector<int> cnt;
    cnt.resize(d + 1);


    cnt[c]++;
    int curcnt = 1;
    for (int i = 0;i < k;++i)
    {
        if (0 == cnt[arr[i]])
        {
            curcnt++;
        }
        cnt[arr[i]]++;
    }
    int last = k;
    int answer = curcnt;


    for (int i = 0;i < n;++i)
    {
        //check
        if (answer <= curcnt)
        {
            answer = curcnt;

            if (k + 1 == answer)
            {
                break;
            }
        }

        //sliding
        if (0 == --cnt[arr[i]])
        {
            curcnt--;
        }
        if (0 == cnt[arr[k]])
        {
            curcnt++;
        }
        cnt[arr[k++]]++;
    }

    std::cout << answer;
    return 0;
}