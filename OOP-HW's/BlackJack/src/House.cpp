#include <iostream>
#include <cstdint>
#include <string>
#include <cctype>
#include "GenericPlayer.cpp"


class House : public GenericPlayer
{
public: 
	House(std::string name = "Dealer")
	:GenericPlayer(name)
	{}


	virtual bool IsHitting() const 
	{
		if (House::GetValue() < 17)
		{
			return 1;
		}
		else
			return 0;
		
	}



	void FlipFirstCard()
	{
		Card& card = *House::m_Hand[0];
		card.Flip();
	}

};


//int main()
//{
//	House house;
//	
//	
//	return 1;
//}