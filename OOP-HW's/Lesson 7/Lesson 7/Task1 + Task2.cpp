#include <iostream>
#include <cstdint>
#include <memory>
#pragma once 

class Date
{
private: 
	int32_t m_day{};
	int32_t m_month{};
	int32_t m_year{};
public:
	Date(int32_t Day = 1, int32_t Month = 1, int32_t Year = 1)
		:m_day(Day),m_month(Month),m_year(Year)
	{}
	~Date(){}

	int32_t getDay() const { return m_day; }
	void setDay(int32_t Day) { m_day = Day; }

	int32_t getMonth() const { return m_month; }
	void setMonth(int32_t Month) { m_month = Month; }

	int32_t getYear() const { return m_year; }
	void setYear(int32_t Year) { m_year = Year; }

	friend std::ostream& operator<< (std::ostream& stream, const Date& date);
};

std::ostream& operator<< (std::ostream& out, const Date& date)
{
	out << "Date: " << date.m_day << "." << date.m_month << "." << date.m_year << "\n";
	return out;
}

void print(std::unique_ptr<Date>& date)
{
	if (date)
		std::cout << *date;
	else
		std::cout << "Date is null!" << std::endl;
}

//task2
std::unique_ptr<Date>& DateEqual(std::unique_ptr<Date>& date1, std::unique_ptr<Date>& date2)
{
	bool YearEqual = (date1->getYear() > date2->getYear());
	bool MonthEqual = (date1->getMonth() > date2->getMonth());
	bool DayEqual = (date1->getDay() > date2->getDay());

	if (YearEqual)
	{
		return date1;
	}
	else if (MonthEqual)
	{
		return date1;
	}
	else if (DayEqual)
	{
		return date1;
	}
	else
		return date2;
}

void Swap(std::unique_ptr<Date>& date1, std::unique_ptr<Date>& date2)
{
	date1.swap(date2);
}

int main()
{
	//Task1
	//std::unique_ptr<Date> today(new Date);
	//std::unique_ptr<Date> date;
	//today->setDay(31);
	//today->setMonth(03);
	//today->setYear(2021);
	//
	//print(today);
	//print(date);
	//date = std::move(today);
	//print(today);
	//print(date);


	//Task2
	std::unique_ptr<Date> date1(new Date(17,11,2020));
	std::unique_ptr<Date> date2(new Date(11,17,2019));
	print(date1);
	print(date2);
	std::cout << std::endl;
	print(DateEqual(date1, date2));
	std::cout << std::endl;
	Swap(date1, date2);
	print(date1);
	print(date2);

	return 1;
}