#include <iostream>
#include <cmath>
#include <cstdint>
#include <cstring>

class  Power //Task1
{
	private: 
	int32_t m_variable;
	int32_t m_pow;
	
	public:
		void SetVariable(int32_t variable) { m_variable = variable; }
		int32_t GetVariable() { return m_variable; }
		
		void SetPow(int pow) {m_pow = pow; }
		int32_t GetPow(){ return m_pow; }
		
		void calculate() 
		{
			std::cout << pow(m_variable, m_pow) << std::endl;
		}
};

class RGBA //Task2
{
	private:
		uint8_t m_red = 0;
		uint8_t m_green = 0;
		uint8_t m_blue = 0;
		uint8_t m_alpha = 255;
	
	public:
		RGBA(uint8_t red, uint16_t green, uint16_t blue, uint16_t alpha)
		: m_red(red), m_green(green), m_blue(blue), m_alpha(alpha)
		{
		}
		
	void Print()
	{
		std::cout 
		<< "R - " << static_cast<uint16_t>(m_red) 
		<< " G - " << static_cast<uint16_t>(m_green) 
		<< " B - " << static_cast<uint16_t>(m_blue)
		<< " Alpha - " << static_cast<uint16_t>(m_alpha) 
		<< std::endl;
	}
};


class Stack //Task3
{
	private:
		int32_t m_Arr[10]{};
		uint32_t m_ArrLength = sizeof(m_Arr)/sizeof(m_Arr[0]);
		uint32_t m_Counter = 0;
	
	public:
		void reset()
		{ 
		memset(m_Arr, 0, m_ArrLength);
		m_Counter = 0;
		}
	
		void push(int32_t value)
		{  
			if(m_Counter == m_ArrLength)
			{
				std::cout << "false, stack is full!" << std::endl;
			}
			else
			{
				m_Arr[m_Counter] = value;
				m_Counter++;
			}
		}
	
		void pop()
		{
			if(m_Counter == 0)
			{
				std::cout << "false, stack is empty!" << std::endl;
			}
			else
			{
				m_Counter--;
				m_Arr[m_Counter] = 0;
			}
		}
		
		void print()
		{
			std::cout << "(";
			
			for(uint32_t i = 0; i < m_ArrLength; i++)
			{
				if(m_Arr[i] == 0)
				{
					
				}
				else
				{
					std::cout << " " << m_Arr[i] << " ";
				}
			}
			
			std::cout << ")" << std::endl;
		}
	uint32_t GetCounter() const {return m_Counter;}
};

int main ()
{
	//Task1
	Power PowVariable;
	
	PowVariable.SetVariable(5);
	std::cout << PowVariable.GetVariable() << std::endl;
	
	PowVariable.SetPow(3);
	std::cout << PowVariable.GetPow() << std::endl;
	
	
	PowVariable.calculate();
	
	std::cout << "\n\n";
	
	//Task2
	RGBA color(255, 5, 4, 12);
	color.Print();
	
	std::cout << "\n\n";
		
	//Task3
	
	Stack stack;
    stack.reset();
    stack.print();
    
    stack.push(3);
    std::cout << stack.GetCounter() << std::endl;
    stack.push(7);
    std::cout << stack.GetCounter() << std::endl;
    stack.push(5);
    std::cout << stack.GetCounter() << std::endl;
    stack.print();
    
    stack.pop();
    stack.print();
    
    stack.pop();
    stack.pop();
    stack.print();

	
	
	return 0;
}
