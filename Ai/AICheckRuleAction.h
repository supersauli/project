#ifndef _AI_CHECK_RULE_ACTION_H__
#define _AI_CHECK_RULE_ACTION_H__
#include "AIDefine.h"
#include "XmlFile.h"
#include "AINode.h"
#include "CompareRule.h"
/**
 * @brief ai执行动作检查
 */
class CheckRuleAction:public AINodeBase
{
public:
	virtual bool  Update(Obj *obj) {
		return true;
	}
};

class CheckHp:public CheckRuleAction
{
	public:
		virtual bool Update(Obj*obj){
			int value = obj->_hp;
			return _cmp(value,_objValue);
		};
		void Load(xmlNodePtr node){
			 XmlFile::GetNodeValue(node,"hp",_objValue);
			 std::string cmpStr;
			 XmlFile::GetNodeValue(node,"cmp",cmpStr);
			 _cmp = CompareRule<int>::GetCompareRuleFunc(cmpStr);
		};

	private:
		CompareRule<int>::CompareRuleFunc _cmp{ CompareRule<int>::None};
		//DEF_VALUE(int,_objValue);
		int _objValue;
};

class CheckMp:public CheckRuleAction
{

	public:
		virtual bool Update(Obj*obj)
		{
			int value = obj->_mp;
			if(value >= _objValue)
			{
				return true;
			}
			return false;	
		}

		void Load(xmlNodePtr node){
			 XmlFile::GetNodeValue(node,"mp",_objValue);
		};

	private:
		//DEF_VALUE(int,_objValue);
		int _objValue;
};

#endif
