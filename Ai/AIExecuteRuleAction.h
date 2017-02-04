#ifndef  _AI_EXECUTE_RULE_ACTION_H__
#define _AI_EXECUTE_RULE_ACTION_H__
#include "AIDefine.h"
#include <string>
#include <iostream>
#include "XmlFile.h"
#include "AINode.h"
 
/**
 *@brief ai执行动作检查
 */
class ExecuteRuleAction:public AINodeBase
{

		virtual	bool Update(Obj*obj){
			return true;
		}
};

class ExecuteHit :public ExecuteRuleAction
{
	public:
		virtual	bool Update(Obj*obj)
		{
			int curHp = obj->GetHp();
			obj->SetHp(curHp-_decHp);
			int curMp = obj->GetMp();
			obj->SetMp(curMp - _decMp);
			return true;
		}

		void Load(xmlNodePtr node)
		{
			XmlFile::GetNodeValue(node,"hp",_decHp);
			XmlFile::GetNodeValue(node,"mp",_decMp);
		};


	private:
		int _decHp{0};
		int _decMp{0};
};

class ExecuteEcho :public ExecuteRuleAction
{
	public:
		virtual	bool Update(Obj*obj)
		{
			std::cout<<_info.c_str()<<std::endl;
			return true;
		}

		 void Load(xmlNodePtr node){
			 XmlFile::GetNodeValue(node,"info",_info);
		};
		

	private:

		std::string _info;
};



#endif
