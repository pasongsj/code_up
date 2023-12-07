#include <iostream>
#include <vector>
#include <set>
#include <queue>

int n;
std::vector<int> arr;
std::vector<int> answer;
std::vector<std::set<int>> afterarr;
//std::vector<bool> ischecked;
//
//std::set<int> getallprev(int n)
//{
//	if (true == ischecked[n])
//	{
//		return prevarr[n];
//	}
//	ischecked[n] = true;
//	std::set<int> res;
//	if (prevarr[n].size() == 0)
//	{
//		return res;
//	}
//	auto startit = prevarr[n].begin();
//	auto endit = prevarr[n].end();
//	for (;startit != endit; ++startit)
//	{
//		int prevnum = *startit;
//		for (int m : getallprev(prevnum))
//		{
//			res.insert(m);
//		}
//	}
//	for (int m : res)
//	{
//		prevarr[n].insert(m);
//	}
//	return prevarr[n];
//}

std::vector<int> degree;
int main()
{
	std::cin >> n;
	arr.resize(n + 1);
	answer.resize(n + 1);

	afterarr.resize(n + 1);
	degree.resize(n + 1);


	std::queue <int> q;
	for (int i = 1;i <= n;++i)
	{
		//ischecked[i] = false;
		std::cin >> arr[i];
		answer[i] = arr[i];
		while (true)
		{
			int prev;
			std::cin >> prev;
			if (prev == -1)
			{
				break;
			}
			degree[i]++;
			afterarr[prev].insert(i);
		}
		if (0 == degree[i])
		{
			q.push(i);
		}
	}


	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		
		for (int next : afterarr[cur])
		{
			degree[next]--;
			if (degree[next] == 0)
			{
				q.push(next);
			}
			answer[next] = std::max(answer[next], answer[cur] + arr[next]);
		}
	}
	for (int i = 1;i <= n;++i)
	{
		std::cout << answer[i] << '\n';
	}
	return 0;
}