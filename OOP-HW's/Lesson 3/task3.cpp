#include <iostream>
#include <cstdint>
#include <string>


class Fraction
{
	private:
		int32_t m_Numerator{};
		int32_t m_Denominator{};
		
	public:
		Fraction(int32_t Numerator = 1, int32_t Denominator = 1)
		{
			m_Numerator = Numerator;
			if(Denominator == 0)
			{
				std::cout << "Denominator cannot be equal 0!" << std::endl;
			}
			else
			m_Denominator = Denominator;
			
		}
		~Fraction(){}
		
		int32_t GetNumerator() const {return m_Numerator;}
		int32_t GetDenominator() const {return m_Denominator;}
		void GetFraction() const {std::cout <<  m_Numerator << "/" << m_Denominator;}
};

Fraction operator+(const Fraction& fr1, const Fraction& fr2)
{
	int32_t Fr1Num = fr1.GetNumerator();
	int32_t Fr1Den = fr1.GetDenominator();
	int32_t Fr2Num = fr2.GetNumerator();
	int32_t Fr2Den = fr2.GetDenominator();
	
	int32_t FrSumNum = (Fr1Num*Fr2Den + Fr2Num*Fr1Den);
	int32_t FrSumDen = Fr1Den*Fr2Den;
	
	return Fraction(FrSumNum,FrSumDen);
}

Fraction operator-(const Fraction& fr1, const Fraction& fr2)
{
	int32_t Fr1Num = fr1.GetNumerator();
	int32_t Fr1Den = fr1.GetDenominator();
	int32_t Fr2Num = fr2.GetNumerator();
	int32_t Fr2Den = fr2.GetDenominator();
	
	int32_t FrSubNum = (Fr1Num*Fr2Den - Fr2Num*Fr1Den);
	int32_t FrSubDen = Fr1Den*Fr2Den;
	
	return Fraction(FrSubNum,FrSubDen);
}

Fraction operator*(const Fraction& fr1, const Fraction& fr2)
{
	int32_t FrMulNum = fr1.GetNumerator() * fr2.GetNumerator();
	int32_t FrMulDen = fr1.GetDenominator() * fr2.GetDenominator();
	
	return Fraction(FrMulNum,FrMulDen);
}

Fraction operator/(const Fraction& fr1, const Fraction& fr2)
{
	int32_t FrDivNum = fr1.GetNumerator() * fr2.GetDenominator();
	int32_t FrDivDen = fr1.GetDenominator() * fr2.GetNumerator();
	
	return Fraction(FrDivNum,FrDivDen);
}

Fraction operator- (const Fraction& fr)
{
	return Fraction(-fr.GetNumerator(),fr.GetDenominator());
}

bool operator== (const Fraction& fr1, const Fraction fr2)
{
	int32_t Fr1Num = fr1.GetNumerator() * fr2.GetDenominator();
	int32_t Fr2Num = fr2.GetNumerator() * fr1.GetDenominator();
	if(Fr1Num == Fr2Num)
	{
		return 1;
	}
	else 
	{
		return 0;
	}
}

bool operator != (const Fraction& fr1, const Fraction fr2)
{
	int32_t Fr1Num = fr1.GetNumerator() * fr2.GetDenominator();
	int32_t Fr2Num = fr2.GetNumerator() * fr1.GetDenominator();
	if(Fr1Num != Fr2Num)
	{
		return 1;
	}
	else
	{
		return 0;
	}
	
	
}

bool operator< (const Fraction& fr1, const Fraction fr2)
{
	int32_t Fr1Num = fr1.GetNumerator() * fr2.GetDenominator();
	int32_t Fr2Num = fr2.GetNumerator() * fr1.GetDenominator();
	if(Fr1Num < Fr2Num)
	{
		return 1;
	}
	else
	{
		return 0;
	}
	
	
}

bool operator>= (const Fraction& fr1, const Fraction fr2)
{
	if(!(fr1 < fr2))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}


int main()
{
	Fraction fr1(1,5);
	Fraction fr2(1,7);
	Fraction fr3(2,10);
	std::cout << "Fraction 1: ";
	fr1.GetFraction();
	std::cout << "\nFraction 2: ";
	fr2.GetFraction();
	
	//Sum
	Fraction frSum = fr1 + fr2;
	std::cout << "\nSum of fractions: ";
	frSum.GetFraction();
	
	//Substraction
	Fraction frSub = fr1 - fr2;
	std::cout << "\nSub of fractions: ";
	frSub.GetFraction();
	
	//Multiply
	Fraction frMul = fr1 * fr2;
	std::cout << "\nFractions multiply: ";
    frMul.GetFraction();
	
	//Divide
	Fraction frDiv = fr1 / fr2;
	std::cout << "\nFractions divide: ";
	frDiv.GetFraction();
	
	// "-"
	Fraction MinusFr = -fr1;
	std::cout << "\nNegative fraction: ";
	MinusFr.GetFraction();
	std::cout << std::endl;
	
	// ==, !=
	
	if (fr1 == fr3)
	{
		fr1.GetFraction();
		std::cout << " == ";
		fr3.GetFraction();
		std::cout << std::endl;
	}
	
	if (fr1 != fr2)
	{
		fr1.GetFraction();
		std::cout << " != ";
		fr2.GetFraction();
		std::cout << std::endl;
	}
	
	//<, >=
	if(fr1 < fr2)
	{
		fr1.GetFraction();
		std::cout << " < ";
		fr2.GetFraction();
		std::cout << std::endl;
	}
	
	if(fr1 >= fr2)
	{
		fr1.GetFraction();
		std::cout << " >= ";
		fr2.GetFraction();
		std::cout << std::endl;
	}
	
	
	
  return 0;

}

