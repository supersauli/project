#include "AISystem.h"
#include "XmlFile.h"
#include "AICheckRuleAction.h"
#include "AIExecuteRuleAction.h"
#include "Hero.h"


bool JudgeAction::Check(Obj *obj)
{
//	std::for_each(_checkRuleAction.cbegin(),_checkRuleAction.cend() ,
//		[obj](CheckRuleAction* it)
//		 {
//			if(!it->Run(obj))
//			{
//				return false;
//			}
//			return true;
//		});
	return true;
}



bool JudgeAction::Execute(Obj*obj)
{
//	auto result = false;
//	std::for_each(_executeRuleAction.cbegin(),_executeRuleAction.cend(),[&result,obj](ExecuteRuleAction* it){
//		result |= it->Run(obj);	
//	});
	//return result ;
	return true;
}



bool StateMachine::Run(Obj *obj)
{
	// std::for_each(  _judgeAction.cbegin(),_judgeAction.cend(),[obj](JudgeAction* it)
	// {
	// 	if(it->Check(obj))
	// 	{
	// 		return it->Execute(obj);
	// 	}
	// 	return false;
	// });
	// return false;
	return true;
}
void Update(int id,Obj*obj)
{
//	auto it = _stateMachineMap.find(id);
//	if(it !=_stateMachineMap.end() )
//	{
//		it->second.Update(obj);
//	}
}



bool AISystem::LoadRes()
{
//		std::vector<CheckRuleAction> _checkRuleAction;
//		std::vector<ExecuteRuleAction> _executeRuleAction;
	

	if(!_xmlFile.InitXml("AINodeCfg.xml"))
	{
		printf("erro load cfg!");
		return false;		
	}
		

	auto root = _xmlFile.GetRootElement();
	while(root != nullptr)
	{
			
		//auto nodeName = _xmlFile.GetNodeName(root);
		//
		auto children = _xmlFile.GetChildNode(root);
		
		ParseNode(children,_AINodeGroup);






		root = _xmlFile.GetNext(root);	
	
	}




	return true;
};
bool AISystem::Init()
{
	
	_AINodeFunction["CheckHP"] = []()->AINode*{return new CheckHp();};
	_AINodeFunction["CheckMP"] = []()->AINode*{return new CheckMp();};
	_AINodeFunction["Hit"] = []()->AINode*{return new ExecuteHit();};
	_AINodeFunction["Echo"] = []()->AINode*{return new ExecuteEcho();};


	return true;
}


bool AISystem::ParseNode(xmlNodePtr node,AINODEGROUP& nodeGroup)
{
	if(node == nullptr)
	{
		return false;	
	}

	
	{
		auto pNodeNow = node;

		do {
			if(pNodeNow == nullptr){
				break;	
			}
			auto nodeName = _xmlFile.GetNodeName(pNodeNow);	
			if(strcmp(nodeName,"SelectorNode") == 0)
			{
				//nodeGroup.push_back();	
				auto pNode = new SelectorNode();
				//pNode->_selectGroup = nodeGroup;
				//nodeGroup.clear();
				auto children = _xmlFile.GetChildNode(pNodeNow);
				ParseNode(children,pNode->_selectGroup);
				nodeGroup.push_back(pNode);
			}
			else if(strcmp(nodeName,"SequenceNode") == 0)
			{
				auto pNode = new SequenceNode();
				//pNode->_sequenceGroup = nodeGroup;
				//nodeGroup.clear();
				//nodeGroup.push_back(pNode);
				auto children = _xmlFile.GetChildNode(pNodeNow);
				ParseNode(children,pNode->_sequenceGroup);
				nodeGroup.push_back(pNode);

			}
			else 
			{
				auto it = _AINodeFunction.find(nodeName);
				if(it!= _AINodeFunction.end())
				{
					auto pNodeAction =  it->second();
					pNodeAction->Load(pNodeNow);
					nodeGroup.push_back(pNodeAction);
				}
			}
			pNodeNow = XmlFile::GetNext(pNodeNow);
		}while(true);

	}
	return true;
}

void AISystem::Update(Hero*hero)
{
	for(auto it : _AINodeGroup)
	{
		it->Update(hero);	
	}



}

