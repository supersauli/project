#include<stdio.h>
#include <map>
#include <pthread.h>
#include <thread>
#include "AISystem.h"
#include <time.h>
#include <unistd.h>
#include <map>
#include <iostream>
//#include <hash_map>
//#include "json/json.h"
#include "XmlFile.h"
#include <stdlib.h>

using namespace std;











class A
{
	struct Create_Help
	{
		//explicit Create_Help(int){}
	};

public:
	explicit A(const Create_Help&){};
	static shared_ptr<A> crate()
	{
		return make_shared<A>(Create_Help());
	}
protected:
	
	A(const A&) =delete;
	const A& operator = (const A&)=delete;
};





int main()
{

	Hero hero;
	AISystem ai;
	ai.Init();
	ai.LoadRes();
	int i = 100;
	do
	{
	 ai.Update(&hero);
	}while(--i);




	//auto a = A::crate();

	 


  	  //Json::Value root;
	//hash_map<int,int> a;

	//std::thread thread1([](){count<<"thread"<<endl;});
	// std::thread thread1(f1);
	// cout<<"step 1"<<endl;
	// thread1.start();
	// cout<<"step 2"<<endl;

	// AISystem ai;
	// ai.LoadRes();








	
	return 0;
}
