#include <iostream>
#include <cstdint>
#include <vector>
#include "../Card.h"


class Hand
{
	protected:
		std::vector<Card*> m_Hand{};
	public:
		Hand() { m_Hand.clear(); }
		~Hand(){}
		void Clear()
		{
			std::vector<Card*> EmptyHand{};
			m_Hand = EmptyHand;
			EmptyHand.clear();
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
				bool AceCheck = false;
				int32_t AceCounter = 0;
				
				for(uint32_t i = 0; i < m_Hand.size(); i++)
				{
					TempCard = *m_Hand[i];
					SumValue += static_cast<int32_t>(TempCard.GetValue());
					if(TempCard.GetValue() == Ace)
					{
						AceCheck = true;
						++AceCounter; 
					}
				}
				if(AceCheck && SumValue > 21)
				{
					SumValue -= 10*AceCounter;
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

