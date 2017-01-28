#include "AINode.h"
#include <algorithm>
bool SelectorNode::Update(Obj *obj)
{
	for (auto it :_selectGroup)
	{
		if(it->Update(obj))
		{
			return true;
		}
	};

	return false;
};

void SelectorNode::AddNode(AINode*node)
{
	_selectGroup.push_back(node);
};


bool  SequenceNode::Update(Obj *obj)
{
	for (auto it:_sequenceGroup)
	{
		if(!it->Update(obj))
		{
			return false;	
		}

	}
	return true;
};

void SequenceNode::AddNode(AINode*node)
{
	_sequenceGroup.push_back(node);
};

bool  ParallelNode::Update(Obj *obj)
{

	for (auto it:_parallelGroup)
	{
		it->Update(obj);
	}
	return true;
};

void ParallelNode::AddNode(AINode*node){
	_parallelGroup.push_back(node);
};



bool ParallelHybirdNode::Update(Obj *obj)
{
	int returnFlagNum{0};
	for(auto it:_parallelGroup)
	{
		bool result=it->Update(obj);
		if(result == _needReturnFlag)
		{
			++returnFlagNum;
			if(returnFlagNum>=_needReturnFlagNum)
			{
				return true;	
			}
		}
	}

	return false;

}
