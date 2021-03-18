#include <iostream>
#include <cstdint>
#include <math.h>
#include <string>

class Car
{
	protected:
		std::string m_Company{};
		std::string m_Model{};
	public:
		Car(std::string Company = "", std::string Model = "")
		:m_Company(Company),m_Model(Model)
		{ 
			std::cout << "Car constructor" << std::endl;
		}
		virtual ~Car(){std::cout << "Car destructor" << std::endl;}
};

class PassengerCar :public Car
{
	public:
		PassengerCar(std::string Company= "", std::string Model = "")
		: Car(Company,Model)
		{
			std::cout << "PassengerCar constructor" << std::endl;
			std::cout << "PassengerCar " << m_Company << " " << m_Model << std::endl;
		}
		~PassengerCar()
		{
			std::cout << "PassengerCar destructor" << std::endl;
		}
};
class Bus : public Car
{
	public:
		Bus(std::string Company = "", std::string Model = "")
		:Car(Company,Model)
		{
			std::cout << "Bus constructor" << std::endl;
			std::cout << "Bus " << m_Company << " " << m_Model << std::endl;
		}
		~Bus()
		{
			std::cout << "Bus destructor" << std::endl;
		}
};
class Minivan : public PassengerCar, Bus
{
	public:
	Minivan(std::string Company = "", std::string Model = "")
	:PassengerCar(Company,Model)
	{
		std::cout << "Minivan constructor" << std::endl;
		std::cout << "Minivan " << Company << Model << std::endl;  
		//когда попыталс€ тут сделать m_Company\m_Model, компил€тор ругалс€ на то, что они неопределенно вызываютс€, надо лекцию пересмотреть, € помню вы рассказывали про это :)
	}
	~Minivan()
	{
		std::cout << "Minivan destructor" << std::endl;
	}
};

int main()
{

PassengerCar pc("Scoda", "Octavia");
Bus bus("Icarus","B-52");
Minivan minivan("Pobeda","Ario");

  return 0;

}

