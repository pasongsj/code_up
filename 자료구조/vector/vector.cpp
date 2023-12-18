#include <iostream>



template <typename T>
class vector
{
public:

	// 생성자 
	vector(const int& temp = 10) {
		arr = new T[temp];
		m_size = 0;
		m_capacity = temp;
	}

	// 소멸자
	~vector() {
		delete[] arr;
		arr = nullptr;
	}


	T& operator[](size_t index)
	{
		if (index >= m_size)
		{
			// 오류메세지
			return nullptr;
		}
		return arr[index];
	}

	void push_back(const T& num)
	{
		if (m_capacity <= m_size) {						//capacity가 size보다 작거나 클때 작업
			reserve(m_size);
			m_capacity *= 2;				
			T* Tmparr = new T[m_capacity];
			memcpy(Tmparr, arr, sizeof(T) * m_size);
			delete[] arr;
			arr = Tmparr;
		}
		arr[m_size++] = num;
	}

	void pop_back()
	{
		m_size--;
	}

	T& end() const
	{
		return arr + m_size;
	}
	
	T& begin() const
	{
		return arr;
	}

	void erase(int* _iter)
	{

	}

	void resize(const size_t n, T val = 0)
	{
		if (n <= m_size)
		{
			return;
		}
		reserve(n);
		for (size_t i = m_size; i < n; ++i)
		{
			arr[m_size++] = val	;
		}
	}

	void reserve(int n)
	{
		if (n <= m_capacity)
			return;

		m_capacity = n;
		T* TmpArr = new T[m_capacity];
		memcpy(TmpArr, arr, sizeof(T) * m_size);
		delete[] arr;
		arr = TmpArr;
	}

	//vector.size()
	size_t size()
	{
		return m_size;
	}

	//vector.capacty()
	size_t capacity() 
	{									
		return m_capacity;
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

	T* arr;
	size_t m_size;
	size_t m_capacity;
};


int main()
{
	vector<int> Tmpvec(5);

	Tmpvec.push_back(7);
	size_t si = Tmpvec.size();
	size_t re = Tmpvec.capacity();

	std::cout << Tmpvec[4];

	return 0;
}