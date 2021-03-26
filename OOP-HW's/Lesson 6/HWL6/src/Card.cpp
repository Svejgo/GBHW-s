#include <iostream>
#include <cstdint>
#include <string>
#include "../Card.h"


enum Value;
enum Suit;

Card::Card(Value CardValue = Ace, Suit CardSuit = Clubs)
{
	m_Value = CardValue;
	m_Suit = CardSuit;
	m_FaceUp = 0;

}

void Card::Flip() { m_FaceUp == 0 ? m_FaceUp = 1 : m_FaceUp = 0; }
bool Card::IsFlipped() const { return m_FaceUp; }
int32_t Card::GetValue() const { return m_Value; }

std::ostream& operator<< (std::ostream& out, const Card& card)
{
	if (card.IsFlipped())
	{
		out << card.m_Value << " " << card.m_Suit << '\n';
		return out;
	}
	else
	{
		out << "XX\n";
		return out;
	}
}

