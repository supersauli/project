#ifndef __AI_SYSTEM_H__
#define __AI_SYSTEM_H__
#include "AIExecuteRuleAction.h"
#include "AICheckRuleAction.h"
#include "AINode.h"
#include<map>
#include<vector>
#include<list>
#include <algorithm>
#include "XmlFile.h"
class AINode;
//class BaseAction
//{};

//class Obj
//{};
/**
 * @brief 判断当前行为
 */
class JudgeAction
{
	public:
		bool Check(Obj *obj);
		bool Execute(Obj*obj);
		std::vector<CheckRuleAction*> _checkRuleAction;
		std::vector<ExecuteRuleAction*> _executeRuleAction;
};


class StateMachine
{
	public:
		bool Run(Obj *obj);
	private:
		std::vector<JudgeAction*>  _judgeAction;
};

class AISystem
{

	public:
		bool Init();
		bool LoadRes();
		void Update(int id,Obj*obj);
		bool ParseNode(xmlNodePtr node,AINodeGroup& nodeGroup);
		void Update(Hero*hero);

	private:
		typedef AINodeBase *(createAINode)() ;
		std::map<int,AINode*> _stateMachineMap;
		XmlFile _xmlFile;
		AINodeGroup _AINodeGroup;
		std::map<std::string,createAINode*> _AINodeFunction;

};















#endif
