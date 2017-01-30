#ifndef __XML_FILE_H__
#define __XML_FILE_H__
#include "sDefine.h"
#include <libxml/tree.h>
#include <libxml/parser.h>
#include <string>
#include <string.h>
class XmlFile
{

	public:
		~XmlFile(){
			if(_doc != nullptr){
				xmlFreeDoc(_doc);
			}

		};

		/**
		 * @brief xml文件初始化
		 *
		 * @param fileName 文件名
		 *
		 * @return 
		 */
		bool InitXml(const char *fileName);

		/**
		 * @brief 
		 *
		 * @param buf
		 *
		 * @return 
		 */
		bool Parse(const char*buf,int size = -1);

		/**
		 * @brief 获得根节点
		 *
		 * @return 
		 */
		xmlNodePtr GetRootElement();
		/**
		 * @brief 获得当前名字的根节点
		 *
		 * @param name
		 *
		 * @return 
		 */
		xmlNodePtr GetRootElement(const char* name);

		/**
		 * @brief 获得子节点
		 *
		 * @param node
		 * @param name
		 *
		 * @return 
		 */
		xmlNodePtr GetChildNode(const xmlNodePtr node,const char* name);

		
		/**
		 * @brief 获得子节点
		 *
		 * @param node
		 *
		 * @return 
		 */
		xmlNodePtr GetChildNode(const xmlNodePtr node);


		/**
		 * @brief 获得当今节点名字
		 *
		 * @param node
		 *
		 * @return 
		 */
		static const char* GetNodeName(const xmlNodePtr node);

		/**
		 * @brief 获取节点
		 *
		 * @param node
		 * @param name 节点名称
		 *
		 * @return 
		 */
		xmlNodePtr GetNode(const xmlNodePtr node,const char*name);



		/**
		 * @brief 获得属性值 
		 *
		 * @param node
		 * @param attrName
		 *
		 * @return 
		 */
		static const char* GetNodeAttrStr(const xmlNodePtr node,const char*attrName);

		/**
		 * @brief 过得根节点数据
		 *
		 * @param node
		 * @param name
		 * @param value
		 * @param defaultValue
		 */
		static void GetNodeValue(const xmlNodePtr node,const char*name,DWORD&value,DWORD defaultValue = 0 );

		/**
		 * @brief 获得根节点数据
		 *
		 * @param node
		 * @param name
		 * @param value
		 * @param defaultValue
		 */
		static void GetNodeValue(const xmlNodePtr node,const char*name,std::string&value,const char* defaultValue = "");

		/**
		 * @brief 获得根节点数据
		 *
		 * @param node
		 * @param name
		 * @param value
		 * @param defaultValue
		 */

		static void GetNodeValue(const xmlNodePtr node,const char*name,float &value,float defaultValue = 0.0f);

		/**
		 * @brief 获得根节点数据
		 *
		 * @param node
		 * @param name
		 * @param value
		 * @param defaultValue
		 */
		static void GetNodeValue(const xmlNodePtr node,const char*name,DOUBLE &value,DOUBLE defaultValue = 0.0);

		/**
		 * @brief 获得根节点数据
		 *
		 * @param node
		 * @param name
		 * @param value
		 * @param defaultValue
		 */
		static void GetNodeValue(const xmlNodePtr node,const char*name,int &value,DOUBLE defaultValue = 0.0);

		/**
		 * @brief 获得节点文本 
		 *
		 * @param node
		 *
		 * @return 
		 */
		std::string GetNodeContent(const xmlNodePtr node);


		/**
		 * @brief 保存到buff
		 *
		 * @param node 
		 * @param out
		 * @param len
		 * @param format 0 表示不格式化 1表示格式化
		 * @param encoding
		 *
		 * @return 
		 */
		int saveToString(xmlDocPtr node,std::string &out,const char*encoding=nullptr,int format = 1);

		/**
		 * @brief 保存节点内容到文件 
		 *
		 * @param fileName
		 * @param cur
		 * @param format 0 表示不格式化 1表示格式化
		 * @param encoding
		 *
		 * @return 
		 */
		bool saveToFile(const char*fileName,xmlDocPtr node,const char*encoding=nullptr,int format = 1);

			

		/**
		 * @brief 获得下一个节点 
		 *
		 * @param node
		 *
		 * @return 
		 */
		static xmlNodePtr GetNext(xmlNodePtr node);

		

		/**
		 * @brief 创建xml文档
		 *
		 * @return 
		 */
		xmlDocPtr Create();


		/**
		 * @brief 创建新节点
		 *
		 * @param node
		 * @param name
		 *
		 * @return 
		 */
		xmlNodePtr CreateNode(const char* name);

		/**
		 * @brief 创建子节点
		 *
		 * @param node
		 * @param name
		 * @param content
		 *
		 * @return 
		 */
		xmlNodePtr CreateChild(xmlNodePtr node,const char*name,const char*content);


		/**
		 * @brief 给指定节点添加节点
		 *
		 * @param parent
		 * @param cur
		 *
		 * @return 
		 */
		xmlNodePtr AddChild(xmlNodePtr parent,xmlNodePtr cur);
		/**
		 * @brief 添加后一个兄弟节点
		 *
		 * @param parent
		 * @param cur
		 *
		 * @return 
		 */
		xmlNodePtr AddNextSibling(xmlNodePtr cur,xmlNodePtr elem);
		/**
		 * @brief 添加前一个兄弟节点
		 *
		 * @param parent
		 * @param cur
		 *
		 * @return 
		 */
		xmlNodePtr AddPrevSibling(xmlNodePtr cur,xmlNodePtr elem);
		/**
		 * @brief 添加兄弟节点
		 *
		 * @param parent
		 * @param cur
		 *
		 * @return 
		 */
		xmlNodePtr AddSibling(xmlNodePtr cur,xmlNodePtr elem);

			
		/**
		 * @brief 释放文档
		 *
		 * @param node
		 */
		void Free(xmlDocPtr node);

		/**
		 * @brief设置节点内容 
		 *
		 * @param node
		 * @param content
		 * @param len
		 */
		void SetNodeContent(xmlNodePtr node,const char* content,int len=-1);

	private:

		xmlDocPtr _doc{nullptr};
		xmlNodePtr _cur{nullptr};

};


#endif
