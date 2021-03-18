#ifndef ARRAYINT_H
#define ARRAYINT_H
#include <iostream>
#include <cassert>

//добавить в контейнерный класс, который был написан в этом уроке, методы:
//для удаления последнего элемента массива (аналог функции pop_back() в векторах)
//для удаления первого элемента массива (pop_front)
//для вывода на экран элементов


class ArrayInt
{
private:
    int m_length;
    int *m_data;

public:
    ArrayInt(): m_length(0), m_data(nullptr)
    { }

    ArrayInt(int length):
    m_length(length)
    {
        assert(length >= 0);

        if (length > 0)
            m_data = new int[length];
        else
            m_data = nullptr;
    }

   int& operator[](int index)
    {
        assert(index >= 0 && index < m_length);
        return m_data[index];
    }

	void insertBefore(int value, int index)
    {
       
        assert(index >= 0 && index <= m_length);
        int *data = new int[m_length+1];

        for (int before=0; before < index; ++before)
            data[before] = m_data[before];

        data [index] = value;

        for (int after=index; after < m_length; ++after)
        data[after+1] = m_data[after];

        delete[] m_data;
        m_data = data;
        ++m_length;
    }
 	
 	void push_back(int value) { insertBefore(value, m_length); }
 	
 	
 	void pop_back() 
 	{
 		int *popback = new int[m_length-1];
	 	for(int i = 0; i < m_length-1; i++)
	 	{
	 		popback[i] = m_data[i];
		}
	 	delete[] m_data;
	 	m_data = popback;
	 	--m_length;
	}
	
	void pop_front()
	{
		int *popfront = new int[m_length -1];
		for(int i = 0; i < m_length - 1; i++)
		{
			popfront[i] = m_data[i+1];
		}
		delete[] m_data;
	 	m_data = popfront;
	 	--m_length;
	}

	void print()
	{
		for(int i = 0; i < m_length; i++)
		{
			std::cout << m_data[i] << " ";
		}
		std::cout << std::endl;
	}

    ~ArrayInt()
    {
        delete[] m_data;
    }
    
    void sort()
    {
    int counter = 0;
    do
	{
		for(int i = 0; i < m_length - 1; i++)	
    	{
			if(m_data[i] > m_data[i+1])
    			{
    				m_data[i] = m_data[i] ^ m_data[i+1];
	    			m_data[i + 1] = m_data[i] ^ m_data[i+1];
	    			m_data[i] = m_data[i] ^ m_data[i+1];
	    			counter++;
				}
		}
		counter--;
	}
	while(counter > 0);
	}
};

int main()
{
	ArrayInt arr;
	arr.push_back(44);
	arr.push_back(31);
	arr.push_back(5);
	arr.push_back(73);
	arr.push_back(3);
	arr.push_back(5);
	arr.push_back(17);
	arr.push_back(7);
	arr.push_back(3);
	arr.push_back(25);
	arr.push_back(7);
	arr.print();
	arr.pop_back();
	arr.print();
	arr.pop_front();
	arr.print();
	arr.sort();
	arr.print();
	
	return 0;
}

#endif
