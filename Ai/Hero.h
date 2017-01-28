#ifndef _HERO_H__
#define _HERO_H__
#include <iostream>
class Hero
{
	public:
		int GetHp(){return _hp;}
		int GetMp(){return _mp;}
		void SetHp(int hp){_hp=hp;std::cout<<"hpNow"<<_hp<<std::endl;}
		void SetMp(int mp){_mp=mp;}






	int _hp{1500};
	int _mp{1500};
};












#endif // _HERO_H__




