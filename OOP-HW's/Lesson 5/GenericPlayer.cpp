#include <iostream>
#include <cstdint>
#include <string>
#include "Hand.cpp"


//Согласно иерархии классов, которая представлена в методичке к уроку 3, от класса Hand наследует класс GenericPlayer, 
//который обобщенно представляет игрока, ведь у нас будет два типа игроков - человек и компьютер.Создать класс GenericPlayer, в который добавить поле name - имя игрока.Также добавить 3 метода:
//IsHitting() - чисто виртуальная функция, возвращает информацию, нужна ли игроку еще одна карта.
//IsBoosted() - возвращает bool значение, есть ли у игрока перебор
//Bust() - выводит на экран имя игрока и объявляет, что у него перебор.

class GenericPlayer : public Hand
{
private:
	std::string m_Name{};
public:
	GenericPlayer(std::string Name = "Player")
		:m_Name(Name)
	{}
	


	virtual bool IsHitting(bool Need)
	{
		if (Need && GenericPlayer::GetValue() <= 21)
			return 1;
		else 
			return 0;
	}
	bool IsBoosted()
	{
		if (GenericPlayer::GetValue() > 21)
		{
			return 1;
		}
		else
			return 0;
	}
	void Bust()
	{
		if(IsBoosted())
		{
			std::cout << m_Name << " is boosted!" << std::endl;
		}
	}

};


int main()
{
	GenericPlayer Pl1;
	Card card(Jack,Diamonds);
	Pl1.Add(card);
	Pl1.Add(card);
	Pl1.Add(card);
	std::cout << Pl1.GetValue() << std::endl;
	std::cout << Pl1.IsBoosted() << std::endl;
	Pl1.Bust();

	return 1;
}