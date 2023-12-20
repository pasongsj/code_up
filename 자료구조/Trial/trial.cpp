#include <unordered_map>
#include <iostream>
#include <string>
#include <crtdbg.h>

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

	bool Search(std::string _word)
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
		if (true == curIter->is_end)
		{
			return true;
		}
		else
		{
			return false;
		}
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
			for (;startit != endit; ++startit)
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
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	Trial* struc_trial = new Trial();

	struc_trial->insert("apple");


	bool check;
	check = struc_trial->Search("app");
	check = struc_trial->SearchWith("app");

	struc_trial->insert("app");
	check = struc_trial->SearchWith("abce");

	delete struc_trial;
}