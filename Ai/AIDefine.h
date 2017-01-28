#ifndef __AI_BASE_DEFINE_H__
#define __AI_BASE_DEFINE_H__
class BaseAction{};
class BaseCheck{};

#define DEF_VALUE(Type,Name)\
	private: \
	Type Name;\
	public: \
	Type Get#Name(){return Name;}\
	void Set#Name(Type value){Name=value;}



#endif
