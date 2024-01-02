#include <iostream>
#include <crtdbg.h>

//template <typename T>
class list
{
private:

	class Node
	{
	public:

		Node()
			:Prev(nullptr), Next(nullptr), m_value(0)
		{
		}

		Node(Node* _Prev)
		{
			Prev = _Prev;
			Prev->Next = this;
			Next = nullptr;
			m_value = 0;
		}

		Node(Node* _Prev, Node* _Next)
		{
			Prev = _Prev;
			Prev->Next = this;

			Next = _Next;
			Next->Prev = this;

			m_value = 0;
		}
		~Node()
		{
			if (nullptr != Next)
			{
				Next->Prev = nullptr;
				Next = nullptr;
			}
			if (nullptr != Prev)
			{
				Prev->Next = nullptr;
				Prev = nullptr;
			}
		}
		Node* Prev;
		Node* Next;
		int m_value;
	};
private:
	int m_size;
	Node* m_head;
	Node* m_tail;

public:
	class iterator {	
		friend class list;
		Node* iterNode;
	public:

		iterator() 
		{
			iterNode = new Node;
		}
		iterator(list* _list,Node* _node) : iterNode(_node)
		{
		};		

		~iterator() 
		{
			iterNode = nullptr;
		}

		iterator& operator++() {					
			iterNode = iterNode->Next;
			return *this;
		}

		iterator& operator--() {					
			iterNode = iterNode->Prev;
			return *this;
		}

		int operator*() {		
			if (nullptr == iterNode)
			{
				return 0;
			}
			return iterNode->m_value;
		}

		bool operator !=(const iterator& other) {		
			return iterNode != other.iterNode;
		}

		bool operator ==(const iterator& other) {	
			return iterNode == other.iterNode;
		}
		Node* operator&() {							
			return iterNode;
		}

		//iterator erase(iterator pos) {			//건네받은 iterator값 삭제하고 그다읍값 반환
		//	Node* node = &pos;
		//	Node* preNode = node->Prev;
		//	Node* nextNode = node->Next;
		//	delete node;
		//	preNode->Prev = nextNode;
		//	nextNode->Next = preNode;
		//	m_size--;

		//	return iterator(nextNode);
		//}
	};


	// 생성자 
	list(int temp = 0) 
	{
		m_size = 0;
		m_head = new Node();
		m_tail = new Node(m_head);

		resize(temp);
	}
	list(int temp = 0, int val)
	{
		m_size = 0;
		m_head = new Node();
		m_tail = new Node(m_head);

		resize(temp, val);
	}

	// 소멸자
	~list() {
		clear();

		delete m_head;
		m_head = nullptr;

		delete m_tail;
		m_tail = nullptr;
	}



	//T& operator[](size_t index)
	//{
	//	Node* check_iter = m_head->Next;
	//	for (int i = 0; i < index; ++i)
	//	{
	//		if (nullptr != check_iter->Next)
	//		{
	//			check_iter = check_iter->Next;
	//		}
	//	}
	//	
	//	return check_iter->m_value;
	//}

	void push_back(int num)
	{
		m_tail->m_value = num;
		new Node(m_tail);
		m_tail = m_tail->Next;
		m_size++;
	}

	void pop_back()
	{
		m_tail = m_tail->Prev;
		delete m_tail->Next;
		m_size--;
	}

	void Push_front(int num)
	{
		m_head->m_value = num;
		new Node(nullptr, m_head);
		m_head = m_head->Prev;
		m_size++;
	}

	void pop_front()
	{
		m_head = m_head->Next;
		delete m_head->Prev;
		m_size--;
	}


	iterator begin() {						
		return iterator(this, m_head->Next);
	}
	iterator end() {						
		return iterator(this, m_tail);
	}
	bool empty()
	{
		return 0 == m_size;
	}

	int front() const
	{
		if (0 < m_size)
		{
			return m_head->Next->m_value;
		}
		else
		{
			return -1;
		}
	}

	int back() const
	{
		if (0 < m_size)
		{
			return m_tail->Prev->m_value;
		}
		else
		{
			return -1;
		}
	}

	void resize(const size_t n, int val = 0)
	{
		if (m_size < n)
		{
			return;
		}

		Node* cur_iter = m_tail->Prev;
		for (; m_size <= n; ++m_size)
		{
			Node* l_prev = cur_iter;
			Node* l_next = cur_iter->Next;
			new Node(l_prev, l_next);
			cur_iter = cur_iter->Next;
			cur_iter->m_value = val;
		}
	}



	//vector.size()
	size_t size()
	{
		return m_size;
	}


	void clear()
	{
		Node* cur_iter = m_head->Next;
		while (true)
		{
			if (cur_iter == m_tail)
			{
				break;
			}
			cur_iter = cur_iter->Next;
			delete cur_iter->Prev;
		}
		m_head->Next = m_tail;
		m_tail->Prev = m_head;
		m_size = 0;
	}

	


};




int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	int* a = new int(); // 릭 확인용

	list Tmpvec(5,7);

	
	Tmpvec.push_back(7);

	
	std::cout << '\n';

	

	list::iterator it = Tmpvec.begin();
	list ::iterator endit = Tmpvec.end();

	for (; it != endit; ++it)
	{
		std::cout << *it << std::endl;
	}


	std::cout << '\n';

	return 0;
}