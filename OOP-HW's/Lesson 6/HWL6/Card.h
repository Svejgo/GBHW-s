#include <cstdint>
#include <string>
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
private:
	Value m_Value{};
	Suit m_Suit{};
	bool m_FaceUp = 0;
public:
	Card(Value CardValue = Ace, Suit CardSuit = Clubs);

	void Flip() {}
	bool IsFlipped()const {}
	int32_t GetValue()const {}
	friend std::ostream& operator<< (std::ostream& out, const Card& card);
};

