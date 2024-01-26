#include <iostream>
#include <unordered_map>
#include <memory>
#include <string>
#include <algorithm>

class TrialNode : public std::enable_shared_from_this< TrialNode>
{
public:
	bool Insert(std::string_view _str)
	{
		bool Is_new_ = false;
		std::shared_ptr<TrialNode> cur_node = shared_from_this();
		for (char _c : _str)
		{
			if (cur_node->next_char.end() ==  cur_node->next_char.find(_c))
			{
				cur_node->next_char[_c] = std::make_shared<TrialNode>();
				Is_new_ = true;
			}
			cur_node = cur_node->next_char[_c];
		}
		return Is_new_;
	}

	std::unordered_map<char, std::shared_ptr<TrialNode>> next_char;

private:
};

int main()
{
	int n;
	std::cin >> n;

	std::vector<std::string> str_list;

	str_list.resize(n);
	for (int i = 0; i < n; ++i)
	{
		std::cin >> str_list[i];
	}

	std::sort(str_list.begin(), str_list.end(), [](const std::string& a, const std::string& b)
		{
			return a.length() > b.length();
		});


	int answer = 0;
	std::shared_ptr<TrialNode> RootNode = std::make_shared<TrialNode>();
	for (const std::string& _str : str_list)
	{
		if (true == RootNode->Insert(_str))
		{
			answer++;
		}
	}
	std::cout << answer;
	return 0;
}