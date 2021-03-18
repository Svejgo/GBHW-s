#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <numeric>
#include <algorithm>

class Game 
{
	private:
		int32_t m_CasinoCash = 10000;
		int32_t m_CroupierCheck = 17;
		std::vector<int32_t> m_CroupierHand {};
		int32_t m_CroupierHandScore = 0;
	protected:
		int32_t m_PlayerCash = 0;
	public:
		Game()
		{
		}
		int32_t CroupierTurn(int32_t card)
		{
			m_CroupierHand.push_back(card);
			m_CroupierHandScore = accumulate(m_CroupierHand.begin(),m_CroupierHand.end(),0);
			return m_CroupierHandScore;
		}
		
		int32_t GetCroupierHandScore() const { return m_CroupierHandScore; }
		int32_t GetCroupierCheck() const { return m_CroupierCheck; }
		int32_t SetcroupierCheck(int32_t check) { m_CroupierCheck = check; }
		
		int32_t GetPlayerCash() const { return m_PlayerCash; }
		int32_t GetCasinoCash() const { return m_CasinoCash; }
		
		void ShowCroupierHand() 
	{		
		uint32_t CroupierHandScore{};
		if(m_CroupierHand.size() == 0) { std::cout << "Hand is empty!\n"; }
		else
		{
			std::cout << "Croupier hand: \n";
			for(uint32_t i = 0; i < m_CroupierHand.size(); i++)
			{
				std::cout << m_CroupierHand[i] << " ";
			}
			std::cout << '\n' << "Hand score: " << m_CroupierHandScore << '\n';
		}
	}
		void ShowCroupierFirstCard()
		{
			std::cout << "Croupier hand: " << m_CroupierHand[0] << "[*]" << '\n';
		}
		void ResetCroupierHand() 
		{ 
			std::vector<int32_t> Empty{};
			m_CroupierHand = Empty;	
		}
};

class Player : public Game
{
	private: 
	std::string m_Name{};
	int32_t m_Cash = 100;
	int32_t m_HandScore {};
	std::vector<int32_t> m_Hand{};
	public:
		Player(std::string name)
		:m_Name(name)
		{}
		
	int32_t GetPlayerHandScore() const { return m_HandScore; }
	
	void SetCashAmount(int32_t amount) 
	{ 
		m_Cash = m_Cash + amount;
		m_PlayerCash = m_Cash;
	}
	
	void PushCardToHand(int32_t card) 
	{
		m_Hand.push_back(card);
	}
	void ResetPlayerHand() 
	{ 
	std::vector<int32_t> EmptyHand{};
	m_Hand = EmptyHand;	
	}
	void ShowHand() 
	{		
		if(m_Hand.size() == 0) { std::cout << "Hand is empty!\n"; }
		else
		{
			std::cout << "\nYour hand: " << '\n';
			for(uint32_t i = 0; i < m_Hand.size(); i++)
			{
				std::cout << m_Hand[i] << " ";
			}
			m_HandScore = accumulate(m_Hand.begin(),m_Hand.end(),0);
			std::cout << '\n' << "Hand score: " << m_HandScore << "\n\n";
		}
	}
		
};

class Deck
{
	private:
		std::vector<int32_t> m_Deck{};
		const	std::vector<int32_t> m_DeckTemplate{2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10, 11};
		int32_t m_DeckAmount {1};
		int32_t m_CardCounter {0};
	public:
		Deck(int32_t DeckAmount = 1)
		{
			m_DeckAmount = 4 * DeckAmount;
			
			std::vector<int32_t> TempDeck{};
			for(int32_t i = 0; i < m_DeckAmount; i++)
			{
			TempDeck.reserve(TempDeck.size()+m_DeckTemplate.size());
			TempDeck.insert(TempDeck.end(),m_DeckTemplate.begin(),m_DeckTemplate.end());
			}
			m_Deck = TempDeck;
					
		}
		
		void ShowDeck()
		{
			for(uint32_t i = 0; i < m_Deck.size();i++)
			{
				std::cout << m_Deck[i] << " ";
			}
			std::cout << '\n';
		}
		
		int32_t GetCard()
		{
			m_CardCounter++;
			return m_Deck[m_CardCounter - 1];
			
		}	
		
		void ShuffleDeck()
		{
			srand(time(0));
			int32_t Shuffler = 0;
			for(int32_t i = 0; i < m_Deck.size(); i++)
			{
				Shuffler = (i + rand()) % (m_Deck.size() - i);
				std::swap (m_Deck[i],m_Deck[Shuffler]);
			}			
				
		}
};



void StartGame(Deck& deck, Player& player, Game& croupier)
{
	player.ResetPlayerHand();
	croupier.ResetCroupierHand();	
	deck.ShuffleDeck();
	player.PushCardToHand(deck.GetCard());
	player.PushCardToHand(deck.GetCard());
	croupier.CroupierTurn(deck.GetCard());
	croupier.CroupierTurn(deck.GetCard());
	
	player.ShowHand();
	croupier.ShowCroupierFirstCard();
}
void PlayerTurn(Deck& deck, Player& player)
{
	int32_t PlayerChoice = 0;
	if(player.GetPlayerHandScore() <= 21)
	{
	std::cout << "\nDo you need a card?\n" <<"1. Yes\n" <<"2. No\n";
	std::cin >> PlayerChoice;
		
		while(PlayerChoice == 1)
		{
			player.PushCardToHand(deck.GetCard());
			player.ShowHand();
			if(player.GetPlayerHandScore() > 21)
				{
					std::cout << "You overdraw, wait croupier turn!\n";
					PlayerChoice = 2;
					
				}
			else if(player.GetPlayerHandScore() <= 21)
				{	
					std::cout << "Need another card?\n" << "1. Yes\n" << "2. No\n";
					std::cin >> PlayerChoice;
				
				}
		}
	}
	else
	{
		std::cout << "You overdraw, wait croupier turn!\n";
		PlayerChoice = 2;
	}
}
bool ContinueOrExit()
{
	int32_t Answer = 3;
	while(Answer > 2)
	{
	std::cout << "\nDo you want to continue?\n" <<"1. Yes\n" << "2. No\n";
	std::cin >> Answer;
	}
	
	return (Answer == 1) ? 1 : 0;
	
}

void CroupierTurn(Deck& deck, Game& game)
{
while(game.GetCroupierHandScore() < game.GetCroupierCheck())
	{
		game.CroupierTurn(deck.GetCard());
	}
}

int main()
{

Player P1("Player1");
Player& PlayerPointer = P1;

Game BJ;
Game& GamePointer = BJ;

Deck deck(1);
Deck& DeckPointer = deck;

bool PlayerCheck21 = 0;
bool CroupierCheck21 = 0;
do
{
	StartGame(DeckPointer, PlayerPointer, GamePointer);
	PlayerTurn(DeckPointer,PlayerPointer);

	P1.ShowHand();

	CroupierTurn(DeckPointer, GamePointer);
	BJ.ShowCroupierHand();

	PlayerCheck21 = (P1.GetPlayerHandScore() > 21) ? 1 : 0;
	CroupierCheck21 = (BJ.GetCroupierHandScore() > 21) ? 1 : 0;

		if(PlayerCheck21)
		{
			std::cout << "You get over 21 points, croupier get less 21! you lose!\n";
		}
		else if (PlayerCheck21 && P1.GetPlayerHandScore() == BJ.GetCroupierHandScore())
		{
			std::cout << "Draw!\n";
		}
		else if (PlayerCheck21 && CroupierCheck21)
		{
			std::cout << "Draw!\n";
		}
		else if(!PlayerCheck21 && P1.GetPlayerHandScore() > BJ.GetCroupierHandScore())
		{
			std::cout << "You win!\n" << "You obtain " << P1.GetPlayerHandScore() << " points, casino obtain " << BJ.GetCroupierHandScore() << " points!\n";
		}
		else if (!CroupierCheck21 && P1.GetPlayerHandScore() < BJ.GetCroupierHandScore())
		{
			std::cout << "You lose!\n" << "You obtain " << P1.GetPlayerHandScore() << " points, casino obtain " << BJ.GetCroupierHandScore() << " points!\n";
		}
		else if (!PlayerCheck21 && CroupierCheck21)
		{
			std::cout << "Casino overdraw, you win!\n" << "You obtain " << P1.GetPlayerHandScore() << " points, casino obtain " << BJ.GetCroupierHandScore() << " points!\n";
		}

	
}
while(ContinueOrExit());
  
  
  return 0;

}

