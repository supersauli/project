#include "AINode.h"
#include <algorithm>
bool SelectorNode::Update(Obj *obj)
{
	for (auto it :_nodeGroupAction)
	{
		if(it->Update(obj))
		{
			return true;
		}
	};

	return false;
};


bool  SequenceNode::Update(Obj *obj)
{
	for (auto it:_nodeGroupAction)
	{
		if(!it->Update(obj))
		{
			return false;	
		}

	}
	return true;
};


bool  ParallelNode::Update(Obj *obj)
{

	for (auto it:_nodeGroupAction)
	{
		it->Update(obj);
	}
	return true;
};



bool ParallelHybirdNode::Update(Obj *obj)
{
	int returnFlagNum{0};
	for(auto it:_nodeGroupAction)
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
