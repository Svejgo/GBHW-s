#if !defined CARD_H
#define CARD_H
#include <cstdint>
#pragma once 

	enum Value
	{
		Ace = 1,
		Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten,
		Jack = 10, Queen = 10, King = 10			
	};
	enum Suit
	{
		Clubs, Heart, Diamonds, Spades
	};


class Card
{
	public:
	Card(Value CardValue = Ace, Suit CardSuit = Clubs);
	void Flip(); 
	int32_t GetValue(); 
};




#endif
