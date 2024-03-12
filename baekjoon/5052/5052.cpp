#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <algorithm>

class Trial
{
	class Node;
public:

	Trial()
	{
		Root = new Node();
	}

	~Trial()
	{
		if (nullptr != Root)
		{
			delete Root;
			Root = nullptr;
		}
	}
	void insert(std::string _word)
	{
		Node* curIter = Root;
		for (char _ch : _word)
		{
			if (curIter->child.end() == curIter->child.find(_ch))
			{
				curIter->child[_ch] = new Node();
			}
			curIter = curIter->child[_ch];
		}
		curIter->is_end = true;
	}

	bool SearchWith(std::string _word)
	{
		Node* curIter = Root;
		for (char _ch : _word)
		{
			if (curIter->child.end() == curIter->child.find(_ch))
			{
				return false;
			}
			curIter = curIter->child[_ch];
		}
		return true;
	}
private:
	class Node
	{
	public:
		Node()
			:is_end(false)
		{
		};

		~Node()
		{
			std::unordered_map<char, Node*>::iterator startit = child.begin();
			std::unordered_map<char, Node*>::iterator endit = child.end();
			for (; startit != endit; ++startit)
			{
				if (nullptr != startit->second)
				{
					delete startit->second;
					startit->second = nullptr;
				}
			}
			child.clear();
		}
		bool is_end;
		std::unordered_map<char, Node*> child;
	};

	Node* Root;
};
int main()
{
	int t;
	std::cin >> t;
	std::vector<std::string> answer;

	for (int i = 0; i < t; ++i)
	{
		int n;
		std::cin >> n;
		int ans = true;
		std::vector<std::string> num_list;
		for (int j = 0; j < n; ++j)
		{
			std::string cur;
			std::cin >> cur;
			num_list.push_back(cur);
		}

		std::sort(num_list.begin(), num_list.end(), [](const std::string& a, const std::string& b) {
			return a.length() > b.length(); });
		Trial* struc_trial = new Trial();

		for (const std::string& num : num_list)
		{
			if (true == struc_trial->SearchWith(num))
			{
				ans = false;
			}
			struc_trial->insert(num);
		}
		if (true == ans)
		{
			answer.push_back("YES");
		}
		else
		{
			answer.push_back("NO");
		}

	}

	for (const std::string& _ans : answer)
	{
		std::cout << _ans << '\n';
	}
	return 0;
}