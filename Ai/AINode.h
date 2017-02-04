#ifndef __AI_NODE_H__
#define __AI_NODE_H__
#include <vector>
#include <list>
//#include "AISystem.h"
#include "Hero.h"
#include "XmlFile.h"
typedef Hero Obj;

class AINodeBase{
public:
	virtual bool  Update(Obj *obj) = 0;

	virtual void  Load(xmlNodePtr node){};
	
};

typedef std::list<AINodeBase*>  AINodeGroup ;

/**
 * @brief 基类
 */
class AINode:public AINodeBase
{
public:
	
	AINodeGroup _nodeGroupAction;
};



/**
 * @brief SelectorNode有一个成功就直接返回成功，否则返回失败
 */
class SelectorNode:public AINode
{
public:
	 bool Update(Obj *obj);
};

/**
 * @brief 有一个返回失败就直接返回失败，否则返回成功
 */
class SequenceNode:public AINode
{
public:
	 bool Update(Obj *obj);

};

/**
 * @brief 执行所有update
 */
class ParallelNode:public AINode
{
public:
	 bool Update(Obj *obj);
};

/**
 * @brief 固定数量的成功或失败返回ture
 */
class ParallelHybirdNode:public AINode
{
public:
	bool Update(Obj *obj);
//private:
	/**
	 * @brief 需要的ture还是false
	 */
	bool _needReturnFlag;

	/**
	 * @brief 需要的数量
	 */
	int  _needReturnFlagNum;

	AINodeGroup _parallelGroup;

};





#endif
