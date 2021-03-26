#include <iostream>
#include <cstdint>
#include <string>
#include "Card.h"


enum Value;
enum Suit;

Card::Card(Value CardValue, Suit CardSuit)
{
	m_Value = CardValue;
	m_Suit = CardSuit;
	m_FaceUp = 0;

}


std::ostream& operator<< (std::ostream& out, const Card& card)
{
	if (card.IsFlipped())
	{
		out << card.m_Value << " of " << card.m_Suit << '\n';
		return out;
	}
	else
	{
		out << "XX\n";
		return out;
	}
}

int main()
{
	Card card;
	std::cout << card;
	card.Flip();
	std::cout << card;

	return 1;
}