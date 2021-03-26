#include <iostream>
#include <cstdint>
#include <string>
#include <cctype>
#include "../HWL6/src/GenericPlayer.cpp"


class Player : public GenericPlayer
{
public:
	Player(std::string name = "Player")
	:GenericPlayer(name)
	{}
	virtual bool IsHitting() const 
	{
		char Choice{};
		while (true)
		{
			std::cout << "Do you need one more card?[y/n]" << std::endl;
			std::cin >> Choice;
			Choice = tolower(Choice);
			switch (Choice)
			{
			case 'y': 
				return 1;
			case 'n':
				return 0;
			default:
				break;
			}
		}
		return Choice;
	}
	void Win() const { std::cout << Player::GetName() << ", you win!\n"; }
	void Lose() const { std::cout << Player::GetName() << ", you lose!\n"; }
	void Push() const { std::cout << Player::GetName() << ", draw!\n"; }
	
	

};


//int main()
//{
//	Player player;
//	std::cout << player.IsHitting();
//	player.Win();
//	player.Lose();
//	player.Push();
//
//
//	return 1;
//}