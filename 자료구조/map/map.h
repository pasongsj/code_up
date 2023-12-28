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
		find_iter.CurNode->erase();
		delete find_iter.CurNode;
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

		void erase()
		{
			//if (nullptr == left_child && nullptr == right_child)
			//{
			//	if (nullptr != parent_node)
			//	{
			//		if (this == parent_node->right_child)
			//		{
			//			parent_node->right_child = nullptr;
			//		}
			//		else if (this == parent_node->left_child)
			//		{
			//			parent_node->left_child = nullptr;
			//		}
			//	}
			//}
			//if (nullptr != right_child)
			//{
			//	swap(right_child->MinNode());
			//	return;
			//}
			//else if (nullptr != left_child)
			//{
			//	swap(left_child->MaxNode());
			//}
		}

		void swap(BinTreeNode* other)
		{
			BinTreeNode* tmpa_parent =	this->parent_node;
			BinTreeNode* tmpa_left =	this->left_child;
			BinTreeNode* tmpa_right =	this->right_child;

			BinTreeNode* tmpb_parent = other->parent_node;
			BinTreeNode* tmpb_left = other->left_child;
			BinTreeNode* tmpb_right = other->right_child;
			
			if (nullptr != tmpa_parent)
			{
				if (tmpa_parent->NodePair.key < this->NodePair.key) // 오른쪽자식
				{
					tmpa_parent->right_child = other;
				}
				else
				{
					tmpa_parent->left_child = other;
				}
			}
			
			if(nullptr != tmpa_left)
			{
				tmpa_left->parent_node = other;
			}
			if (nullptr != tmpa_right)
			{
				tmpa_right->parent_node = other;
			}

			if (nullptr != tmpb_parent)
			{
				if (tmpb_parent->NodePair.key < other->NodePair.key) // 오른쪽자식
				{
					tmpb_parent->right_child = this;
				}
				else
				{
					tmpb_parent->left_child = this;
				}
			}
			if (nullptr != tmpb_left)
			{
				tmpb_left->parent_node = this;
			}
			if (nullptr != tmpb_right)
			{
				tmpb_right->parent_node = this;
			}


			this->parent_node = tmpb_parent;
			this->left_child = tmpb_left;
			this->right_child = tmpb_right;



			other->parent_node = tmpa_parent;
			other->left_child = tmpa_left;
			other->right_child = tmpa_right;
		}
	};

	BinTreeNode* RootNode;
};

