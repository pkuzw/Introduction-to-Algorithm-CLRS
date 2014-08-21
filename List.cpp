///@file 编写链表的基本操作。包括借点查找、插入结点、删除结点
///@author zhaowei
///@date 2014.08.16
///@version 1.0

#include<iostream>
using namespace std;

///@brief 双向链表的结点结构体
///@author zhaowei
///@date 2014.08.16
///@version 1.0
struct listNode
{
	listNode* prev;
	listNode* next;
	int val;
};

///@brief 给定键值，查找相应结点
///@param list_head	链表指针
///@param key 待查结点键值
///@return 如果找到相应结点，其键值与待查键值一致，即返回第一个相同键值的结点指针；否则返回null
///@author zhaowei
///@date 2014.08.16
///@version 1.0
listNode* ListSearch(listNode* list_head, int key)
{
	listNode* x = list_head;
	while(x != nullptr && x->val != key)
	{
		x = x->next;
	}
	return x;
}

///@brief 在链表首部插入结点
///@param list_head 链表指针
///@param new_node 新插入结点
///@author zhaowei
///@date 2014.08.16
///@version 1.0
void ListInsertToHead(listNode* list_head, listNode* new_node)
{
	new_node->next = list_head;
	new_node->prev = nullptr;
	if(list_head != nullptr)
	{
		list_head->prev = new_node;
	}

	list_head = new_node;	
	return ;
}

///@brief 在指定结点前插入新结点
///@param list_head 链表指针
///@param new_node 新结点指针
///@param key 插入位置之后的结点键值，如果有多个相同键值的结点，则认为是最靠近链表首部的结点
///@return 如果链表包含待插入结点的位置（即后一个结点的键值存在），返回true；否则返回false
///@author zhaowei
///@date 2014.08.16
///@version 1.0
bool ListInsert(listNode* list_head, listNode* new_node, int key)
{
	listNode* x = list_head;
	while(x != nullptr && key != x->val)
		x = x->next;
	
	if(x == nullptr)
		return false;

	else
	{
		new_node->next = x;
		new_node->prev = x->prev;

		x->prev = new_node;
		new_node->prev->next = x;
		return true;
	}

}

///@brief 删除链表中的结点
///@param list_head 链表指针
///@param delete_node 待删除的结点
///@author zhaowei
///@date 2014.08.17
///@version 1.0
void ListDelete(listNode* list_head, listNode* delete_node)
{
	if(delete_node->prev != nullptr)
		delete_node->prev->next = delete_node->next;
	
	else
		list_head = delete_node->next;

	if(delete_node->next != nullptr)
		delete_node->next->prev = delete_node->prev;

	return;
}