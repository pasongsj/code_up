#include <iostream>
#include <crtdbg.h>

template <typename T>
class list
{
public:

	class Node
	{
		friend class list;
	public:
		Node& operator++()
		{
			if (this->Next != nullptr)
			{
				this = this->Next;
				return this;
			}
			return nullptr;
		}

		Node& operator--()
		{
			if (this->Prev != nullptr)
			{
				this = this->Prev;
				return this;
			}
			return nullptr;
		}

		T m_value;

	private:

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
	};



	// 생성자 
	list(int temp = 0) 
	{

		m_size = 0;
		m_begin_iter = m_end_iter = new Node();

		Node* cur_iter = m_begin_iter;
		for (; m_size < temp; ++m_size)
		{
			new Node(cur_iter);
			cur_iter = cur_iter->Next;
		}
		m_end_iter = cur_iter;
	}

	// 소멸자
	~list() {
		Node* tmpiter = m_begin_iter;
		while (nullptr != tmpiter && tmpiter != m_end_iter)
		{
			tmpiter = tmpiter->Next;
			if (nullptr != tmpiter->Prev)
			{
				delete tmpiter->Prev;
			}
		}

		delete m_end_iter;
	}



	T& operator[](size_t index)
	{
		Node* check_iter = m_begin_iter;
		for (int i = 0; i < index; ++i)
		{
			if (nullptr != check_iter->Next)
			{
				check_iter = check_iter->Next;
			}
		}
		
		return check_iter->m_value;
	}

	void push_back(T num)
	{
		m_end_iter->m_value = num;
		m_end_iter = new Node(m_end_iter);
		m_size++;
	}

	void pop_back()
	{
		Node* next_end_iter = m_end_iter->Prev;
		delete m_end_iter;
		m_end_iter = next_end_iter;
		m_size--;
	}

	void Push_front(T num)
	{
		m_end_iter = Node(nullptr, m_end_iter);
		m_end_iter->m_value = num;
		m_size++;
	}

	void pop_front()
	{
		Node* next_begin_iter = m_begin_iter->Next;
		delete m_begin_iter;
		m_begin_iter = next_begin_iter;
		m_size--;
	}

	Node* insert(Node* _iter, T _k)
	{
		if (nullptr == _iter)
		{
			return nullptr;
		}
		if (_iter == m_begin_iter)
		{
			Push_front(_k);
			return m_begin_iter;
		}
		new Node(_iter->Prev, _iter);
		_iter->Prev = _k;
		m_size++;
	}

	Node* begin() const
	{
		return m_begin_iter;
	}


	Node* end() const
	{
		return m_end_iter;
	}

	T front() const
	{
		if (m_size == 0)
		{
			return 0;
		}
		return m_begin_iter->m_value;
	}

	T back() const
	{
		if (m_size == 0)
		{
			return 0;
		}
		return m_end_iter->Prev->m_value;
	}

	Node* erase(Node* _iter)
	{
		if (nullptr == _iter && _iter != m_end_iter)
		{
			return nullptr;
		}
		Node* PrevNode = _iter->Prev;
		Node* NextNode = _iter->Next;
		delete _iter;

		PrevNode->Next = NextNode;
		NextNode->Prev = PrevNode;

		return NextNode;
	}

	void resize(const size_t n, T val = 0)
	{

	}

	void reserve(int n)
	{

	}

	//vector.size()
	size_t size()
	{
		return m_size;
	}


	void clear()
	{
		m_size = 0;
	}

	bool empty()
	{
		return static_cast<bool>(m_size);
	}

private:

	Node* m_begin_iter;
	Node* m_end_iter;
	size_t m_size;
};




int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	int* a = new int(); // 릭 확인용

	list<int> Tmpvec(5);

	for (int i = 0; i < 5; ++i)
	{
		Tmpvec[i] = -i;
	}
	
	Tmpvec.push_back(7);

	for (size_t i = 0; i < Tmpvec.size(); ++i)
	{
		std::cout << Tmpvec[i] << ' ';
	}
	std::cout << '\n';

	Tmpvec[4] = 2;

	for (size_t i = 0; i < Tmpvec.size(); ++i)
	{
		std::cout << Tmpvec[i] << ' ';
	}
	std::cout << '\n';

	list<int>::Node* startiter = Tmpvec.begin();
	list<int>::Node* enditer = Tmpvec.end();

	startiter++;


	for (; startiter != enditer; startiter++)
	{
		std::cout << startiter->m_value << ' ';
	}
	std::cout << '\n';

	return 0;
}