#include "XmlFile.h"

bool XmlFile::InitXml(const char *fileName)
{

	if(fileName == nullptr){
		return false;
	}

	if(_doc != NULL){
		xmlFreeDoc(_doc);
	}
	_doc = xmlParseFile(fileName);

	if(_doc == nullptr){
		return false;
	}
	xmlKeepBlanksDefault(0);
	return true;
};

bool XmlFile::Parse(const char*buf,int size)
{

	if(_doc != NULL){
		xmlFreeDoc(_doc);
	}
	if (size == -1){
		size = strlen(buf);	
	}

	_doc = xmlParseMemory(buf,size);
	if(_doc == nullptr){
		return false;
	}

	return  true;
}

xmlNodePtr XmlFile::GetRootElement()
{
	CHECK_NULL_RETURN(_doc);
	return xmlDocGetRootElement(_doc);
}

xmlNodePtr XmlFile::GetChildNode(const xmlNodePtr node,const char* name)
{
	if(node == nullptr){
		return nullptr;
	}
	auto cur = node->xmlChildrenNode;
	do{
		if(cur == nullptr){
			break;
		}
	
		if(!xmlStrcmp(cur->name,reinterpret_cast<const xmlChar*>(name)))	
		{
			return cur;	
		}
	
		cur = cur->next;
	
	}while(true);

	return nullptr;

}

xmlNodePtr XmlFile::GetChildNode(const xmlNodePtr node)
{
	xmlNodePtr childrenNode = nullptr;		
	if(node != nullptr)
	{
		childrenNode = node->xmlChildrenNode;
		if(childrenNode != nullptr)
		{
			if(childrenNode->type != XML_ELEMENT_NODE){
				childrenNode = GetNext(childrenNode);
			}
		}
	}

	return childrenNode;
}

const char* XmlFile::GetNodeName(const xmlNodePtr node)
{
	return reinterpret_cast<const char*>(node->name);
}






xmlNodePtr XmlFile::GetRootElement(const char* name)
{

		CHECK_NULL_RETURN(_doc);
		_cur = xmlDocGetRootElement(_doc);
		CHECK_NULL_RETURN(_cur);
		
		do
		{
			if(!xmlStrcmp(_cur->name, reinterpret_cast <const xmlChar*>(name))){
					return _cur;
			}
			 _cur = _cur->xmlChildrenNode;

			 if(_cur == nullptr){
				 break;
			 }
		}while(true);


	return nullptr;
}


xmlNodePtr XmlFile::GetNode(const xmlNodePtr node,const char*name)
{
	xmlNodePtr cur = node;

	do{
		if(cur == nullptr){
			break;
		}

		if(!xmlStrcmp(cur->name,reinterpret_cast<const xmlChar*>(name))){
			return cur;
		}
	cur = cur->next;	
	}while(true);

	return nullptr;

}




const char* XmlFile::GetNodeAttrStr(const xmlNodePtr node,const char*attrName)
{

	auto attrPtr = node->properties;
	while (attrPtr != nullptr)
	{
		if (!xmlStrcmp(attrPtr->name,BAD_CAST attrName))
		{
			return (char*) (xmlGetProp(node, BAD_CAST attrName));
		}
		attrPtr = attrPtr->next;
	}


	return nullptr;
}

void XmlFile::GetNodeValue(const xmlNodePtr node,const char*name,DWORD&value,DWORD defaultValue )
{

	auto rValue = GetNodeAttrStr(node,name);
	if(rValue != nullptr){
		value = atoi(rValue);
	}
	else{
		value = defaultValue;
	}

}



void XmlFile::GetNodeValue(const xmlNodePtr node,const char*name,std::string&value,const char* defaultValue)
{

	auto rValue = GetNodeAttrStr(node,name);
	if(rValue != nullptr){
		value = reinterpret_cast<const char*>(rValue);
	}
	else{
		value = defaultValue;
	}

}

void XmlFile::GetNodeValue(const xmlNodePtr node,const char*name,float &value,float defaultValue)
{
	auto rValue = GetNodeAttrStr(node,name);
	if(rValue != nullptr){
		value = atof(rValue);
	}
	else{
		value = defaultValue;
	}
}

void XmlFile::GetNodeValue(const xmlNodePtr node,const char*name,DOUBLE &value,DOUBLE defaultValue)
{
	auto rValue = GetNodeAttrStr(node,name);
	if(rValue != nullptr){
		value = strtod(rValue,nullptr);
	}
	else{
		value = defaultValue;
	}
}
void XmlFile::GetNodeValue(const xmlNodePtr node,const char*name,int &value,DOUBLE defaultValue)
{
	auto rValue = GetNodeAttrStr(node,name);
	if(rValue != nullptr){
		value = atoi(rValue);
	}
	else{
		value = defaultValue;
	}
}
std::string XmlFile::GetNodeContent(const xmlNodePtr node)
{
	auto content = xmlNodeGetContent(node);
	std::string value = reinterpret_cast<const char*>(content);	
	xmlFree(content);	
	return value;
}

int XmlFile::saveToString(xmlDocPtr node,std::string &out,const char*encoding,int format)
{
	xmlChar* outbuf = nullptr;
	int len = 0;
	xmlDocDumpFormatMemoryEnc(node, &outbuf, &len, encoding, format);
	if(len>0){
		out.append(reinterpret_cast<const char*>(outbuf));
	}
	if(outbuf != nullptr){
		xmlFree(outbuf);
	}
	return len;
}

bool XmlFile::saveToFile(const char*fileName,xmlDocPtr node,const char*encoding,int format)
{
	if(node == nullptr){
		return false;
	}

	if(strlen(fileName) == 0){
		return false;
	}
	return xmlSaveFormatFileEnc(fileName,node,encoding,format)<0?false:true;
}


xmlNodePtr XmlFile::GetNext(xmlNodePtr node)
{
	CHECK_NULL_RETURN(node);
	node = node->next;
	while(node !=nullptr)
	{
		if(node->type == XML_ELEMENT_NODE){
			return node;
		}
		node = node->next;
	}


	return nullptr;

}

xmlDocPtr XmlFile::Create()
{
	return xmlNewDoc((const xmlChar*)"1.0");
}

void XmlFile::Free(xmlDocPtr node)
{
	if(node != nullptr){
		xmlFree(node);	
	}
}

void XmlFile::SetNodeContent(xmlNodePtr node,const char* content,int len)
{
	if(content == nullptr){
		return;
	}
	
	if(len == -1){
		len = strlen(content);
	}
	xmlNodeAddContentLen(node,reinterpret_cast<const xmlChar*> (content),len);
}

xmlNodePtr XmlFile::CreateNode(const char* name)
{
	return xmlNewNode(nullptr,reinterpret_cast<const xmlChar*>(name));
}

xmlNodePtr XmlFile::CreateChild(xmlNodePtr node,const char*name,const char*content)
{
	if(node == nullptr || name == nullptr)	{
		return nullptr;
	}
	return xmlNewChild(node,nullptr,reinterpret_cast<const xmlChar*> (name),reinterpret_cast<const xmlChar*>(content));
}

xmlNodePtr XmlFile::AddChild(xmlNodePtr parent,xmlNodePtr cur)
{
	return xmlAddChild(parent,cur);
}

xmlNodePtr XmlFile::AddNextSibling(xmlNodePtr cur,xmlNodePtr elem)
{
	return xmlAddNextSibling(cur,elem);
}

xmlNodePtr XmlFile::AddPrevSibling(xmlNodePtr cur,xmlNodePtr elem)
{
	return xmlAddPrevSibling (cur,elem);
}

xmlNodePtr AddSibling(xmlNodePtr cur,xmlNodePtr elem)
{
	return xmlAddSibling(cur,elem);
}

	
