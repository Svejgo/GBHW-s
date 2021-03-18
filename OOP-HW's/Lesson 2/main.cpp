#include <iostream>
#include <cstdint>

//task1
class Person
{
	protected: 
	std::string m_name;
	uint32_t m_age;
	std::string m_sex;
	uint32_t m_weight;
	public:
		Person(std::string name = "", uint32_t age = 0, std::string sex = 0)
		:m_name(name),m_age(age),m_sex(sex)
		{}
		
		void SetName(std::string name) { m_name = name;	}
		std::string GetName() const { return m_name; }
		
		void SetAge(uint32_t age) { m_age = age; }
		
		void SetWeight(uint32_t weight) { m_weight = weight; }
		uint32_t GetWeight() const { return m_weight; }

};



class Student : public Person
{
	private: 
	int32_t m_StudyYear{};
	uint32_t m_StudentKeyID{};
	public:
		Student(std::string name = "", uint32_t age = 16, std::string sex = "", int32_t StudyYear = 2000)
		:Person(name,age,sex), m_StudyYear(StudyYear)
		{SetStudentKeyID();}
		
	void SetStudentKeyID() 
	{
		m_StudentKeyID += 1;
	}
	
	void SetStudyYear(int32_t year){ m_StudyYear = year; }
	void RiseStudyYear(int32_t value = 1){ m_StudyYear = m_StudyYear + value; }
	int32_t GetStudyYear() const { return m_StudyYear; }
	
	void GetStudentInfo() const
	{
		std::cout <<"Name: " << m_name << ", age: " << m_age << ", study year: " << m_StudyYear << '\n';
	}
	int32_t GetStudentKeyID() const { return m_StudentKeyID; }
	
	
};


//task2

class Fruit
{
	protected:
		std::string m_FruitName{};
		std::string m_FruitColor{};
	public:
		Fruit(std::string color = "",std::string name = "")
		:m_FruitColor(color),m_FruitName(name)
		{}
	
	void SetName(std::string name){ m_FruitName = name; }
	std::string GetName() const  { return m_FruitName; }
	
	void SetColor(std::string color) { m_FruitColor = color; }
	std::string GetColor() const { return m_FruitColor; }	
};

class Banana : public Fruit
{
	private:
		std::string m_BananaName = " banana";
	public:
		Banana(std::string color ="yellow", std::string name = "")
		{
			m_FruitColor = color;
			m_FruitName = name + m_BananaName;
		}				
			
};

class Apple : public Fruit
{
	protected:
		std::string m_AppleName = " apple";
	public:
		Apple(std::string color = "red", std::string name = "")
		{
			m_FruitColor = color;
			m_FruitName = name + m_AppleName;
		
		}

};

class GrannySmith : public Apple
{
	private:
		std::string m_GrannySmithName = "Granny Smith";
		std::string m_GrannySmithColor = "green";
	public:
	GrannySmith()
	{
		m_FruitName = m_GrannySmithName + m_AppleName;
		m_FruitColor = m_GrannySmithColor;
	}
	
	std::string GetGrannySmithColor() const { return m_GrannySmithColor; }
	void SetGrannySmithColor(std::string color) { m_GrannySmithColor = color; }
	
	std::string GetGrannySmithName() const { return m_GrannySmithName; }
	void SetGrannySmithName(std::string name) { m_GrannySmithName = name; }

	
};


int main()
{
	//task1
Student std1("Ivan",16,"m",2000);
Student std2("Iv",16,"m",2000);
std1.GetStudentInfo();
std2.GetStudentInfo();
std::cout << std1.GetStudentKeyID() << std::endl;
std::cout << std2.GetStudentKeyID() << std::endl;




	//task2
Apple a("red");
Banana b;
GrannySmith c;

std::cout << "My " << a.GetName() << " is " << a.GetColor() << "\n";
std::cout << "My " << b.GetName() << " is " << b.GetColor() << "\n";
std::cout << "My " << c.GetName() << " is " << c.GetColor() << "\n";



	return 0;
}
