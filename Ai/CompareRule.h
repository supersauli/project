#ifndef _COMPARE_RULE_H__
#define _COMPARE_RULE_H__
#include<string>
#include<iostream>
template<typename T>
class CompareRule
{
	public:

		static bool More(T t1,T t2){return t1 > t2;}
		static bool Less(T t1,T t2){return t1 < t2;}
		static bool Equal(T t1,T t2){return t1 == t2;}
		static bool Not(T t1,T t2){return t1 != t2;}
		static bool MoreEqule(T t1,T t2){return t1 >= t2;}
		static bool LessEqule(T t1,T t2){return t1 <= t2;}
		static bool None(T t1,T t2){return false;};
		typedef bool (*CompareRuleFunc)(T t1,T t2);

		bool Compare(std::string ruleName,T t1,T t2){
			auto it = GetCompareRuleFunc(ruleName);
			if(it != nullptr)
			{
				it(t1,t2);
			}
		};


		static CompareRuleFunc GetCompareRuleFunc(std::string ruleName){

			if(strcmp(ruleName.c_str(),">") == 0)
			{
				return More;	
			}
			else if(strcmp(ruleName.c_str(),">=") == 0)
			{
				return MoreEqule;	
			}

			else if(strcmp(ruleName.c_str(),"<") == 0)
			{
				return Less;	
			}

			else if(strcmp(ruleName.c_str(),"<=") == 0)
			{
				return LessEqule;
			}

			else if(strcmp(ruleName.c_str(),"==") == 0)
			{
				return Equal;	
			}
			else if(strcmp(ruleName.c_str(),"!=") == 0)
			{
				return Not;	
			}

			return None;
		};

};

















































#endif

