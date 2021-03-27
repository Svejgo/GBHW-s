#include <iostream>
#include <cstdint>
#include <array>
#include "conio.h"

class Robot
{
private:
	std::array<int32_t, 2> m_Position;
	void CheckAvailabilityToMove(int32_t n, int32_t i)
	{
		if ((m_Position[n] + i) > 10 || (m_Position[n] + i) < 0)
		{
			throw "OffTheField";
		}
		else
			m_Position[n] += i;
	}
public:
	Robot()
	{
		m_Position = { 5,5 };
	}

	void Move(const char& ch)
	{
		switch (ch)
		{
		case 'w':
			CheckAvailabilityToMove(0, -1);
			break;
		case 's':
			CheckAvailabilityToMove(0, 1);
			break;
		case 'a':
			CheckAvailabilityToMove(1, -1);
			break;
		case 'd':
			CheckAvailabilityToMove(1, 1);
			break;
		case 0:
			std::cout << "I'm out!" << std::endl;
			break;
		default:
			throw "IllegalCommand";
			break;
		}
	}

	void GetPosition() const 
	{
		std::cout << m_Position[0] << " | " << m_Position[1] << std::endl;

	}

};


int main()
{
	char ch;
	Robot bobot;
	std::cout << "W - up, A - left, S - down, D - right, 0 - exit.\n Current position: ";
	bobot.GetPosition();
	try 
	{
		do
		{
			std::cout << "Input command. " << std::endl;
			std::cin >> ch;
			bobot.Move(ch);
			std::cout << "Current position: ";
			bobot.GetPosition();
		} while (ch != 0);
	}
	catch(const char* a)
	{
		std::cout << "Error: " << a << "\n on position: ";
		bobot.GetPosition();
		std::cout << "When try to " << ch << " command.";
	}

	return 1;
}