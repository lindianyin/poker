// poker_niuniu.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include <iostream>


enum emPokerType
{
	Spade,	//黑桃   //0-12
	Heart,	//红心   //13-25
	Cube,	//梅花   //26-38
	Diamond,//方块   //39-51
	BlackJoker,//小王 //52
	RedJoker, //大王 //53
};
//get poketype
inline emPokerType getPokerType(int poker)
{
	if(BlackJoker == poker)
	{
		return BlackJoker;
	}
	else if(RedJoker == poker)
	{
		return RedJoker;
	}
	else
	{
		return (emPokerType)(poker / 13 );
	} 
}

inline int getPokerPoint(int poker)
{
	if(BlackJoker == poker || RedJoker == poker)
	{
		return 6;
	}
	else
	{
		int val = poker % 13 +1;
		return  val > 10 ? 10 : val;
	}
}

inline void getNiuPoint(int pokers[])
{
	for (int i=0;i<3;i++)
	{
		for (int j=i+1;j<3+1;j++)
		{
			for (int k=j+1;k<3+1+1;k++)
			{
				if((getPokerPoint(pokers[i]) + getPokerPoint(pokers[j]) + getPokerPoint(pokers[k])) % 10 == 0)
				{
					std::cout << "exits niu" << std::endl;
					int val = 0;
					for (int n=0;n < 5;n++)
					{
						if(n != i && n != j && n != k)
						{
							val += getPokerPoint(pokers[n]);
						}
					}
					std::cout << "niu " << (val % 10) << std::endl;
				}
			}
		}
	}
}

int main(int argc, const char* argv[])
{
	int _pokers[5] = {0,8,10,2,3};//1,9,11,3,4
	getNiuPoint(_pokers);
	system("pause");
	return 0;
}

