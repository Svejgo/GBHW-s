#include <iostream>
#include <cstdint>
#include <vector>


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


class Hand
{
	private:
		std::vector<Card*> m_Hand{};
	public:
		Hand(){std::cout << "Hand constructor" << std::endl;}
		~Hand(){std::cout << "hand destructor" << std::endl;}
		void Clear()
		{
			std::vector<Card*> EmptyHand{};
			m_Hand = EmptyHand;
		}
		void Add(Card& card)
		{
			m_Hand.push_back(&card);
		}
				
		int32_t GetValue()
		{
			if(m_Hand.size() == 0)
			{
				return 0;
			}
			else
			{
				int32_t SumValue = 0;
				Card TempCard;
				
				for(uint32_t i = 0; i < m_Hand.size(); i++)
				{
					TempCard = *m_Hand[i];
					int32_t AceValue;
					if(TempCard.GetValue() == Ace)
					{
						do{
						std::cout << "You have Ace on hand, choose his value: \n1. 1\n2. 11\n";
						std::cin >> AceValue;
						switch(AceValue)
							{
							case 1:
								SumValue += 1;
								break;
							case 2:
								SumValue += 11;
								break;
							default:
								std::cout << "Wrong choice, choose ";
								break;
							}
						}
						while(AceValue > 2 || AceValue < 1);
							
					}
					else
						{
							SumValue += static_cast<int32_t>(TempCard.GetValue());
						}
				}
				return SumValue;
			}
		}
		
		void PrintHand()
		{
			if(m_Hand.size() == 0)
			{
				std::cout << "Hand is empty!" << std::endl;
			}
			else
			{
				Card temp;
				for(uint32_t i = 0; i < m_Hand.size(); i++)
				{
					temp = *m_Hand[i];					
					std::cout << temp.GetValue() <<" ";
				}
				std::cout << std::endl;
			}
		}
};

int main()
{
	Card card;
	Card card1(Jack, Diamonds);
	Card card2(Eight, Clubs);
	Hand hand;
	hand.PrintHand();

	hand.Add(card);
	hand.PrintHand();

	hand.Add(card1);
	hand.PrintHand();

	hand.Add(card2);
	hand.PrintHand();
	std::cout << "Hand value: " << hand.GetValue() << std::endl;
	hand.Clear();
	hand.PrintHand();
	

	
	return 0;
}
