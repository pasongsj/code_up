#include<iostream>
#include <vector>
#include <set>

int main()
{
	std::vector<int> arr = { 3,6,7,2,1,10,5,9,8,12,11,4 };
	int coin = 4;

	int paircnt = 0;
	int index = (arr.size() + 1) / 3;
	int sum = arr.size() + 1;


	std::set<int> picked;
	for (int i = 0; i < index; ++i)
	{
		picked.insert(arr[i]);
		if (picked.end() != picked.find(sum - arr[i]))
		{
			paircnt++;
		}
	}

	std::set<int> notpicked;
	int answer = 1;
	int remainpaircnt = 0;
	for (int i = index; i < arr.size(); i+=2)
	{
		//int Fcard = arr[i];
		//int Scard = arr[i+1];
		if (picked.find(sum - arr[i]) != picked.end())
		{
			if (coin > 0)
			{
				paircnt++;
				coin--;
			}
		}
		else 
		{
			if (notpicked.find(sum - arr[i]) != notpicked.end())
			{
				remainpaircnt++;
			}
			notpicked.insert(arr[i]);
		}
		if (picked.find(sum - arr[i+1]) != picked.end())
		{
			if (coin > 0)
			{
				paircnt++;
				coin--;
			}
		}
		else
		{
			if (notpicked.find(sum - arr[i+1]) != notpicked.end())
			{
				remainpaircnt++;
			}
			notpicked.insert(arr[i+1]);
		}

		if (answer > paircnt)
		{
			if (coin >= 2 && remainpaircnt > 0)
			{
				coin -= 2;
				remainpaircnt--;
				paircnt++;
			}
			else
			{

				break;
			}
		}
		++answer;

	}
	int a = 0;


	return 0;
}