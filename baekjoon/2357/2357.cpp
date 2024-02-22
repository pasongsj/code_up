#include <iostream>
#include <vector>
#include <algorithm>
//#include <crtdbg.h>
std::vector<int> arr;



class SegTree
{
public:
	SegTree()
		:start(-1),end(-1), v_max(0),v_min(1000000001)
	{
	}
	SegTree(int _s, int _e)
		:start(_s), end(_e), v_max(0), v_min(1000000001)
	{
	}
	SegTree(int _s,int _e,int _mi,int _ma)
		:start(_s), end(_e), v_min(_mi), v_max(_ma)
	{
	}

	~SegTree()
	{
	}

	int start;
	int end;
	int v_min;
	int v_max;

	std::pair<int, int> GetMinMax()
	{
		return std::make_pair(v_min, v_max);
	}

	static std::vector<SegTree*> AllTree;

	static std::pair<int,int> MakeTree(int start, int end, int index, const std::vector<int>& arr)
	{
		if (start <= 0 || end >= arr.size())
		{
			return std::make_pair(1000000001,0);
		}

		if (start == end)
		{
			SegTree* nTree = new SegTree(start, start, arr[start], arr[start]);
			AllTree[index] = nTree;
			return nTree->GetMinMax();
		}

		SegTree* nTree = new SegTree(start,end);

		int mid = (start + end) / 2;
		std::pair<int, int> leftnode = MakeTree(start, mid, index * 2, arr);
		std::pair<int, int> rightnode = MakeTree(mid + 1, end, index * 2 + 1, arr);

		nTree->v_min = std::min(leftnode.first, rightnode.first);
		nTree->v_max = std::max(leftnode.second, rightnode.second);
		AllTree[index] = nTree;

		return nTree->GetMinMax();
	}

	static std::pair<int, int> GetSegment(int node, int start, int end)
	{
		if (AllTree.size() <= node || nullptr == AllTree[node] ||
			AllTree[node]->end < start || AllTree[node]->start > end)
		{
			return std::make_pair(1000000001, 0);
		}
		if (start <= AllTree[node]->start && AllTree[node]->end <= end)
		{
			return AllTree[node]->GetMinMax();
		}

		std::pair<int, int> left = GetSegment(node * 2, start, end);
		std::pair<int, int> right = GetSegment(node * 2 + 1, start, end);
		
		return std::make_pair(std::min(left.first, right.first), std::max(left.second, right.second));
	}

	static void Release()
	{
		for (SegTree* node : AllTree)
		{
			delete node;
			node = nullptr;
		}
		AllTree.clear();
	}
};

std::vector<SegTree*> SegTree::AllTree;


int main()
{
	//_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	int n, m;
	std::cin >> n >> m;
	
	arr.resize(n+1);
	for (int i = 1; i <= n; ++i)
	{
		std::cin >> arr[i];
	}
	SegTree::AllTree.resize(4 * n + 1);

	SegTree::MakeTree(1, n, 1, arr);

	std::vector<std::pair<int, int>> answervec;
	for (int j = 0;j < m;++j)
	{
		int s, e;
		std::cin >> s >> e;
		answervec.push_back(SegTree::GetSegment(1,s, e));
	}

	for (const std::pair<int, int>& ans : answervec)
	{
		std::cout << ans.first << ' ' << ans.second << '\n';
	}
	SegTree::Release();
	return 0;
}