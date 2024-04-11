#include <vector>
#include <set>
#include <string>
#include <map>

std::vector<int> result;
std::vector<int> starting_0;

std::vector<int> CurComb;
int sum;

std::map<int, int> matching = { {2,1},{3,1},{4,1},{5,3},{6,3},{7,1} };

int limit;
//	dp[2] = 1;
//  dp[3] = 1;
//  dp[4] = 1;
//  dp[5] = 3;
//  dp[6] = 3;
//  dp[7] = 1;
void MakeComb(int len)
{
	if (sum > limit || CurComb.size() > limit)
	{
		return;
	}
	if (len == CurComb.size())
	{
		if (sum == 11 && CurComb.size()>0 && CurComb[0] ==5)
		{
			int a = 0;
		}
		int tmp = 1;
		for (int i = 0; i < CurComb.size(); ++i)
		{
			//if (i == 0 && CurComb[i] == 5)
			//{
			//	tmp *= 2;
			//	continue;
			//}
			tmp *= matching[CurComb[i]];
		}

		result[sum] += tmp;
		if (CurComb.size()>2 && CurComb[0] == 5 && CurComb[1] == 5)
		{
			result[sum]--;
		}
		return;
	}
	for (int i = 2; i <= 7; ++i)
	{
		sum += i;
		CurComb.push_back(i);
		MakeComb(len);
		sum -= i;
		CurComb.pop_back();
	}
}

int main()
{
	//std::vector<std::set<std::string>> dp;
	//dp.resize(51);
	//dp[6].insert("0");
	//dp[2].insert("1");
	//dp[5].insert("2");
	//dp[5].insert("3");
	//dp[4].insert("4");
	//dp[5].insert("5");
	//dp[6].insert("6");
	//dp[3].insert("7");
	//dp[7].insert("8");
	//dp[6].insert("9");
	//for (int i = 4; i <= 11; ++i)
	//{
	//	for (int j = 2; j <= 7; ++j)
	//	{
	//		if (i - j < 2)
	//		{
	//			continue;
	//		}
	//		for (const std::string num1 : dp[j])
	//		{
	//			for (const std::string num2 : dp[i - j])
	//			{
	//				dp[i].insert(num1 + num2);
	//			}
	//		}
	//	}
	//}
	//int answer = dp[11].size();
	//for (const std::string& num : dp[11])
	//{
	//	if (num[0] == '0')
	//	{
	//		answer--;
	//	}
	//}
	//int a = 0;

	limit = 11;
	result.resize((limit < 7 ? 7 : limit)+1);
	starting_0.resize((limit < 7 ? 7 : limit)+1);
	for (int i = 1; i <= limit; ++i)
	{
		sum = 0;
		MakeComb(i);
	}
	int a = 0;
	return 0;
	
}


//	dp[2] = 1;
//  dp[3] = 1;
//  dp[4] = 1;
//  dp[5] = 3;
//  dp[6] = 3;
//  dp[7] = 1;

//4 = 2 + 2;
//4 = 4
//
//5 = 2 + 3
//5 = 3 + 2
//5 = 5
//
//6 = 2 + 4 
//6 = 2 + 2 + 2
//6 = 3 + 3
//6 = 4 + 2
//6 = 6
// 0 6
// 1 2
// 2 5
// 3 5
// 4 4
// 5 5
// 6 6
// 7 3
// 8 7
// 9 6