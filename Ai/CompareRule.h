#ifndef _COMPARE_RULE_H__
#define _COMPARE_RULE_H__

#include <map>

template<typename T>
class CompareRule
{
	public:
		void Init()
		{
			_cmpRuleMap[">"] = More;
			_cmpRuleMap[">="] = MoreEqule;
			_cmpRuleMap["<"] = Less;
			_cmpRuleMap["<="] = LessEqule;
			_cmpRuleMap["=="] = Equal;
			_cmpRuleMap["!="] = Not;


		}


		bool More(T t1,T t2){return t1 > t2;}
		bool Less(T t1,T t2){return t1 < t2;}
		bool Equal(T t1,T t2){return t1 == t2;}
		bool Not(T t1,T t2){return t1 != t2;}
		bool MoreEqule(T t1,T t2){return t1 >= t2;}
		bool LessEqule(T t1,T t2){return t1 <= t2;}


		typedef *(CompareRule)(T t1,T t2);

		//compareRule _cmprule;
		
		bool Compare(std::string ruleName,T t1,T t2){
			auto it = GetCompareRule(ruleName);
			if(it != nullptr)
			{
				it(t1,t2);
			}
		};

		CompareRule *GetCompareRule(std::string ruleName){
			auto it = _cmpRuleMap.find(ruleName);
			if(it != _cmpRuleMap.end())
			{
				return it->second;	
			}
			return nullptr;

		};

		static CompareRule& GetInstance()
		{
			static CompareRule compareRule;
			return compareRule;
		}

	private:
		std::map<std::string,compareRule> _cmpRuleMap;

};

















































#endif

