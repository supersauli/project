#ifndef __AI_NODE_H__
#define __AI_NODE_H__
#include <vector>
#include <list>
//#include "AISystem.h"
#include "Hero.h"
#include "XmlFile.h"
typedef Hero Obj;


/**
 * @brief 基类
 */
class AINode
{
public:

	virtual bool  Update(Obj *obj){
		return true;
	};
	
	virtual void Load(xmlNodePtr node){};

};


typedef std::list<AINode*>  NodeGroup ;

/**
 * @brief SelectorNode有一个成功就直接返回成功，否则返回失败
 */
class SelectorNode:public AINode
{
public:
	 bool Update(Obj *obj);
     void AddNode(AINode*node);
 //private:
	 NodeGroup _selectGroup;
};

/**
 * @brief 有一个返回失败就直接返回失败，否则返回成功
 */
class SequenceNode:public AINode
{
public:
	 bool Update(Obj *obj);
     void AddNode(AINode* node);
//private:
	NodeGroup  _sequenceGroup;

};

/**
 * @brief 执行所有update
 */
class ParallelNode:public AINode
{
public:
	 bool Update(Obj *obj);
     void AddNode(AINode* node);
//private:
	NodeGroup  _parallelGroup;

};

/**
 * @brief 固定数量的成功或失败返回ture
 */
class ParallelHybirdNode:public AINode
{
public:
	bool Update(Obj *obj);
	void AddNode(AINode* node);
//private:
	/**
	 * @brief 需要的ture还是false
	 */
	bool _needReturnFlag;

	/**
	 * @brief 需要的数量
	 */
	int  _needReturnFlagNum;

	NodeGroup _parallelGroup;

};





#endif
