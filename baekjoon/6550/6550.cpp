#include <iostream>
#include <string>

void Solution(const std::string& s, const std::string& t)
{
	int n_s = s.size();
	int n_t = t.size();

	int sindex = 0;
	for (int i = 0; i < n_t; ++i)
	{
		if (t[i] == s[sindex])
		{
			sindex++;
		}
	}
	if (sindex == n_s)
	{
		std::cout << "Yes\n";
	}
	else
	{
		std::cout << "No\n";
	}
}

int main()
{
	std::string s, t; // ab abcd
	while (std::cin >> s >> t)
	{
		Solution(s, t);
	}
	return 0;
}
