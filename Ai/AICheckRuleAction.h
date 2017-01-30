#ifndef _AI_CHECK_RULE_ACTION_H__
#define _AI_CHECK_RULE_ACTION_H__
#include "AIDefine.h"
#include "XmlFile.h"
#include "AINode.h"
/**
 * @brief ai执行动作检查
 */
class CheckRuleAction:public BaseAction ,public AINodeBase
{
	public:

};

class CheckHp:public CheckRuleAction
{
	public:
		virtual bool Update(Obj*obj){
			int value = obj->_hp;
			if( value>= _objValue)
			{
				return true;	
			}

			return false;
					
		};
		void Load(xmlNodePtr node){
			 XmlFile::GetNodeValue(node,"hp",_objValue);
		};


	private:
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
