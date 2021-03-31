#include <iostream>
#include <cstdint>
#include <memory>

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

int main()
{
	
	std::unique_ptr<Date> today(new Date);
	std::unique_ptr<Date> date;

	today->setDay(31);
	today->setMonth(03);
	today->setYear(2021);
	
	print(today);
	print(date);

	date = std::move(today);

	print(today);
	print(date);

	return 1;
}