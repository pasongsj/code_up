#pragma once

// ���� :
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

		// ���� ��� �������� ���� ��
		BinTreeNode* MinNode()
		{
			if (nullptr != left_child)
			{
				return left_child->MinNode();
			}
			return this;
		}

		// ���� ��� �������� ������ ��
		BinTreeNode* MaxNode()
		{
			if (nullptr != right_child)
			{
				return right_child->MaxNode();
			}
			return this;
		}


		// ���� ���
		BinTreeNode* NextNode()
		{
			if (nullptr != right_child)
			{
				return right_child->MinNode();
			}
			else if (nullptr != parent_node)
			{
				// ���� ����ΰ��
				if (NodePair.key < parent_node->NodePair.key)
				{
					return parent_node;
				}
				//������ ����ΰ��
				else
				{
					return NextParentNode(NodePair.key);
				}
			}
			return nullptr;
		}

		//key ���� ū  �θ� ���
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
					// �����
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
					// �����
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
				// �̹� �����ϴ� Ű
				return;
			}
		};
	};

	BinTreeNode* RootNode;
};

