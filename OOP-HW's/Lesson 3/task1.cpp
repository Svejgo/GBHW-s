#include <iostream>
#include <cstdint>
#include <math.h>
#define PI 3.14159265

//task1
class Figure
{
	public:
	virtual double Area(){}
	virtual ~Figure(){}
};

class Circle : public Figure
{
	private:
		int32_t m_Radius{};
	public:
		Circle(int32_t Radius)
		:m_Radius(Radius)
		{ }
		double Area()override
		{
			return PI*pow(m_Radius,2);
		}
};

class Parallelogram : public Figure
{
	protected:
		int32_t m_Height{};
		int32_t m_Width{};
		double m_Angle{};
	public:
		Parallelogram(int32_t Height, int32_t Width = 0, double Angle = 90.0)
		{
			m_Height = Height;
			m_Angle = Angle;
			if(Width == 0)
			{
				m_Width = Height;
			}
			else
			{
				m_Width = Width;
			}
		}
		
		void SetAngle(int32_t Angle){ m_Angle = Angle; }
				
		double Area()override
		{
		 return (m_Height * m_Width) * sin(m_Angle*PI/180);
		}

};

class Rectangle : public Parallelogram
{
	public:
		Rectangle(int32_t Height, int32_t Width)
		:Parallelogram(Height,Width)
		{}
		
		double Area()override
		{
			return m_Height * m_Width;
		}
};

class Square : public Parallelogram
{
	public:
		Square(int32_t Height)
		:Parallelogram(Height)
		{}
		
		double Area()override
		{
			return pow(m_Height,2);
		}
};

class Rhombus : public Parallelogram
{
	public:
		Rhombus(int32_t Height, double Angle)
		:Parallelogram(Height,0,Angle)
		{}
		double Area()override
		{
			return pow(m_Height,2) * sin(m_Angle*PI/180);
		}
};

double Area(Figure& figure)
{
	return figure.Area();
}

int main()
{
	Parallelogram prg(20,30,30);
	Rectangle rct(30,20);
	Square sqr(30);
	Circle crcl(15);
	Rhombus rhmb(15,30);
	
	std::cout << "Parallelogram S=" << Area(prg) << std::endl;
	std::cout << "Rectangle S=" << Area(rct) << std::endl;
	std::cout << "Square S=" << Area(sqr) << std::endl;
	std::cout << "Circle S=" << Area(crcl) << std::endl;
	std::cout << "Rhombus S=" << Area(rhmb) << std::endl;
		
	
	return 0;
	
}
