#pragma once

// 설명 :
class heap
{
	class BinTreeNode;
public:
	// constrcuter destructer
	heap()
	:RootNode(nullptr),TreeSize(0)
	{
	}

	~heap();

	class iterator
	{
		friend heap;

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

		BinTreeNode* operator&() {
			return CurNode;
		}
	};

	void push(const int& num)
	{
		TreeSize++;
		if (nullptr == RootNode)
		{
			RootNode = new BinTreeNode();
			RootNode->data = num;
			return;
		}
		RootNode->push(num);
	}
	void pop()
	{
		if (0 == TreeSize) {
			return;
		}
		if(1 < TreeSize)
		{
			BinTreeNode* tmplast = RootNode->pop();
			if (tmplast->parent_node != nullptr)
			{
				if (tmplast->parent_node->left_child == tmplast)
				{
					tmplast->parent_node->left_child = nullptr;
				}
				else if (tmplast->parent_node->right_child == tmplast)
				{
					tmplast->parent_node->right_child = nullptr;
				}
			}
			delete tmplast;
			RootNode->SwapChild();
			
		}
		else//1 이면
		{
			delete RootNode;
			RootNode == nullptr;
		}
		TreeSize--;
	}
	int top()
	{
		return RootNode->data;	
	}
	bool empty()
	{
		return 0 == TreeSize;
	}
	size_t size()
	{
		return TreeSize;
	}

protected:

private:
	class BinTreeNode
	{
	public:
		BinTreeNode* parent_node = nullptr;
		BinTreeNode* left_child = nullptr;
		BinTreeNode* right_child = nullptr;
		int data;

		void SwapParent()
		{
			if (nullptr == parent_node)
			{
				return;
			}
			if (data > parent_node->data)
			{
				int tmp = data;
				data = parent_node->data;
				parent_node->data = tmp;
				parent_node->SwapParent();
			}
		}

		void SwapChild()
		{
			if (nullptr != left_child && left_child->data > data)
			{
				int tmp = data;
				data = left_child->data;
				left_child->data = tmp;
				left_child->SwapChild();
			}
			else if (nullptr != right_child && right_child->data > data)
			{
				int tmp = data;
				data = right_child->data;
				right_child->data = tmp;
				right_child->SwapChild();
			}
		}

		void push(const int& num)
		{
			BinTreeNode* tmpnode = make_last_node();
			tmpnode->data = num;
			tmpnode->SwapParent();
		}

		BinTreeNode* pop()
		{
			BinTreeNode* lastnode = find_last_node();
			int tmp = lastnode->data;
			lastnode->data = data;
			data = tmp;
			return lastnode;
		}

		BinTreeNode* find_last_node()
		{
			if (nullptr == left_child && nullptr == right_child)
			{
				return this;
			}
			if (nullptr != left_child)
			{
				return left_child->find_last_node();
			}
			else if (nullptr != right_child)
			{
				return right_child->find_last_node();
			}
		}


		BinTreeNode* make_last_node()
		{
			if (nullptr == left_child)
			{
				left_child = new BinTreeNode();
				left_child->parent_node = this;
				return left_child;
			}
			else if (nullptr == right_child)
			{
				right_child = new BinTreeNode();
				right_child->parent_node = this;
				return right_child;
			}
			else
			{
				return left_child->make_last_node();
			}
		}


	};

	BinTreeNode* RootNode;
	size_t TreeSize;
};

