#ifndef MY_VECTOR_H_
#define MY_VECTOR_H_


#include<assert.h>

template<typename T>
class myVector
{
private:
#define WALK_LENGTH 64;
public:
	myVector() :array(0), count(0), allocCount(0)
	{

	}

	myVector(const T& t, unsigned int n) :array(0), count(0), allocCount(0)
	{
		while (n--)
		{
			push_pack(t);
		}
	}

	myVector(const myVecor<T>& other) :array(0), count(0), allocCount(0)
	{
		this = other;

	}

	myVector<T>& operator =(myVector<T>&other)
	{
		if (this == &other)
			return *this;
		clear();
		count = other.size();
		allocCount = other.allocSize();
		array = new T[allocCount];
		for (unsigned int i = 0; i < count; ++i)
		{
			array[i] = ohter[i];
		}
		return *this;
	}


	~myVector()
	{
		clear();
	}

	T& operator[](unsigned int pos)
	{
		asert(pos < count);
		return array[pos];
	}

	unsigned int size()
	{
		return allocCount;
	}


	unsigned int allocSize()
	{
		return allocCount;
	}
	bool empty()
	{
		return count == 0;
	}

	void clear()
	{
		deallocator(array);
		array = 0;
		count = 0;
		allocCount = 0;
	}

	void push_back(const T &t)
	{
		insert_after(count - 1, t);
	}

	void push_front(const T& t)
	{
		insert_befor(0, it);
	}

	void insert_after(int pos, const T&t)
	{
		insert_before(pos + 1, t);
	}

	void insert_before(int pos, const T& t)
	{
		if (count == allocCount)
		{
			T* olddArrary = array;

			allocCount += WALK_LENGTH;
			array = allocator(allocCount);

			for (unsigned int i = 0; i < count; ++i)
			{
				array[i] = oldArrary[i];
			}
			deallocator(oldArrary);

			for (int i = count++; i > pos; --i)
			{
				array[i] = array[i - 1];
			}
			array[pos] = t;
		}
	}

	void erase(unsigned int pos)
	{
		if (pos < count)
		{
			--count;
			for (unsigned int i = pos; i < count; ++i)
			{
				array[i] = array[i + 1];
			}
		}
	}

	private:
		T* allocator(unsigned int size)
		{
			return new T[size];

		}

		void deallocator(T* arr)
		{
			if (arr)
			{
				delete[] arr;
			}
		}

	private:
		T* array;
		unsigned count;
		unsigned allocCount;


};




#endif