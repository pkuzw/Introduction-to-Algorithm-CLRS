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
void ListInsert(listNode* list_head, listNode* new_node)
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

///@brief 删除链表中的结点
///@param list_head 链表指针
///@param delete_node 待删除的结点
///@author zhaowei
///@date 2014.08.16
///@version 1.0
void ListDelete(listNode* list_head, listNode* delete_node)
{

}