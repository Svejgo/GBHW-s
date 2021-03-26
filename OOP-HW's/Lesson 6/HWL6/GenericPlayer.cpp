#include <iostream>
#include <cstdint>
#include <string>
#include "Hand.cpp"

class GenericPlayer : public Hand
{
private:
	std::string m_Name{};
public:
	GenericPlayer(std::string Name = "")
		:m_Name(Name)
	{}
	
	std::string GetName() const { return m_Name; }

	virtual void IsHitting(){}

	bool IsBoosted()
	{
		if (GenericPlayer::GetValue() > 21)
		{
			return 1;
		}
		else
			return 0;
	}
	void Bust()
	{
		if(IsBoosted())
		{
			std::cout << m_Name << " is boosted!" << std::endl;
		}
	}

};

