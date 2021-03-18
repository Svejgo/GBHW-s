#include <cstdint>
#include <string>

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
		Card(Value CardValue = Ace, Suit CardSuit = Clubs)
		:m_Value(CardValue),m_Suit(CardSuit)
		{}
	
	void Flip() { m_FaceUp == 0 ? m_FaceUp = 1 : m_FaceUp = 0; }
	int32_t GetValue() const { return m_Value; }
};
