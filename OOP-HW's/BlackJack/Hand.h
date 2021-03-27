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

	void Flip() { m_FaceUp == 0 ? m_FaceUp = 1 : m_FaceUp = 0; }
	bool IsFlipped() const { return m_FaceUp; }
	int32_t GetValue() const { return m_Value; }

	friend std::ostream& operator<< (std::ostream& out, const Card& card);
};
