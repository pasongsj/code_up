

// 6 

// 1 2 4 8
// 0 1 1
// 110 + 110 = 1100
// 1100 + 110 = 10010
#include <iostream>
#include <vector>
std::vector<int> answer;

bool Find(std::string num, int n, int index)
{
	if(stoi(num))
}

int main()
{

	int n;
	std::cin >> n;
	std::vector<int> arr;

	arr.resize(n);
	answer.resize(n);

	for (int i = 0; i < n; ++i)
	{
		std::cin >> arr[i];
		Find("1", arr[i], i);
	}

	return 0;
}


// 999 = 9 x 11 
// 11 x 3 x 3
//  21
// 3 * 37 = 111
// 11 * 111 * 111