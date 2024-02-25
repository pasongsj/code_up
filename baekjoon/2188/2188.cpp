#include <iostream>
#include <vector>
#include <map>

int main()
{
	int n, m;
	std::cin >> n >> m;
	std::map<int, std::vector<int>> want_sheds;
	
	for (int i = 1; i <= n; ++i)
	{
		int cnt;
		std::cin >> cnt;
		for (int j = 0; j < cnt; ++j)
		{
			int shed;
			std::cin >> shed;
			want_sheds[i].push_back(shed);
		}
	}

	for(int i)
}