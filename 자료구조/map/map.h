#pragma once

// 설명 :
class map
{
	class BinTreeNode;
public:
	//pair
	class pair
	{
	public:
		int key;
		int value;
	};

	//iter
	class iterator
	{
		friend map;

	private:
		BinTreeNode* CurNode;

	public:

		iterator()
			:CurNode(nullptr)
		{
		};

		iterator(BinTreeNode* _CurNode)
			:CurNode(_CurNode)
		{
		};

		bool operator==(const iterator& _Other)
		{
			return _Other.CurNode == CurNode;
		}

		bool operator!=(const iterator& _Other)
		{
			return _Other.CurNode != CurNode;
		}


		pair* operator->()
		{
			if (nullptr == CurNode)
			{
				return nullptr;
			}

			return &CurNode->NodePair;
		}


		iterator& operator++()
		{
			CurNode = CurNode->NextNode();
			return *this;
		}
	};



	// constrcuter destructer
	map()
		:RootNode(nullptr)
	{
	};

	~map()
	{

	};

	// delete Function

	//insert
	void insert(const pair& in)
	{
		if (nullptr == RootNode)
		{
			RootNode = new BinTreeNode();
			RootNode->NodePair = in;
			return;
		}
		RootNode->insert(in);
	};
	//erase
	void erase(int _key)
	{
		iterator find_iter = find(_key);
		if (nullptr == find_iter.CurNode)
		{
			return;
		}
	};
	//find
	iterator find(const int& _Key)
	{
		if (nullptr == RootNode)
		{
			return iterator(nullptr);
		}
		return iterator(RootNode->FindNode(_Key));
	};

	iterator begin()
	{
		return iterator(RootNode->MinNode());
	}
	
	iterator end()
	{
		return iterator(nullptr);
	}

protected:

private:
	class BinTreeNode
	{
	public:

		BinTreeNode* parent_node = nullptr;
		BinTreeNode* left_child = nullptr;
		BinTreeNode* right_child = nullptr;
		
		pair NodePair;

		// 현재 노드 기준으로 왼쪽 끝
		BinTreeNode* MinNode()
		{
			if (nullptr != left_child)
			{
				return left_child->MinNode();
			}
			return this;
		}

		// 현재 노드 기준으로 오른쪽 끝
		BinTreeNode* MaxNode()
		{
			if (nullptr != right_child)
			{
				return right_child->MaxNode();
			}
			return this;
		}


		// 다음 노드
		BinTreeNode* NextNode()
		{
			if (nullptr != right_child)
			{
				return right_child->MinNode();
			}
			else if (nullptr != parent_node)
			{
				// 왼쪽 노드인경우
				if (NodePair.key < parent_node->NodePair.key)
				{
					return parent_node;
				}
				//오른쪽 노드인경우
				else
				{
					return NextParentNode(NodePair.key);
				}
			}
			return nullptr;
		}

		//key 보다 큰  부모 노드
		BinTreeNode* NextParentNode(const int& _key)
		{
			if (NodePair.key > _key)
			{
				return this;
			}
			if (nullptr != parent_node)
			{
				return parent_node->NextParentNode(_key);
			}
			return nullptr;
		};

		BinTreeNode* FindNode(const int& _key)
		{
			if (_key == NodePair.key)
			{
				return this;
			}
			else if (_key < NodePair.key)
			{
				if (nullptr == left_child)
				{
					return nullptr;
				}
				return left_child->FindNode(_key);
			}
			else
			{
				if (nullptr == right_child)
				{
					return nullptr;
				}
				return right_child->FindNode(_key);
			}
		};

		void insert(const pair& in)
		{
			if (NodePair.key < in.key)
			{
				if (nullptr == right_child)
				{
					// 만들어
					BinTreeNode* insertNd = new BinTreeNode();
					insertNd->NodePair = in;
					insertNd->parent_node = this;
					right_child = insertNd;
					return;
				}
				right_child->insert(in);
			}
			else if (NodePair.key > in.key)
			{
				if (nullptr == left_child)
				{
					// 만들어
					BinTreeNode* insertNd = new BinTreeNode();
					insertNd->NodePair = in;
					insertNd->parent_node = this;
					left_child = insertNd; 
					return;
				}
				left_child->insert(in);
			}
			else
			{
				// 이미 존재하는 키
				return;
			}
		};
	};

	BinTreeNode* RootNode;
};

