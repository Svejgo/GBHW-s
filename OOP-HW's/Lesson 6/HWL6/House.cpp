#include <iostream>
#include <cstdint>
#include <string>
#include <cctype>
#include "../HWL6/src/GenericPlayer.cpp"
#include "../HWL6/src/Card.cpp"

class House : public GenericPlayer
{
public: 
	House(std::string name = "Dealer")
	:GenericPlayer(name)
	{}


	virtual bool IsHitting() const //have some problems here, doesn't know how to check dealer hand value
	{
		if (1)
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


int main()
{
	
	return 1;
}