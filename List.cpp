///@file 编写链表的基本操作。包括借点查找、插入结点、删除结点
///@author zhaowei
///@date 2014.08.18
///@version 1.2

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
///@param list_head	链表指针
///@param new_node 新插入结点
///@return 返回插入后的链表首部指针
///@author zhaowei
///@date 2014.08.18
///@version 1.1
listNode* ListInsertToHead(listNode* list_head, listNode* new_node)
{
	if(list_head != nullptr)
	{
		new_node->next = list_head;
		list_head->prev = new_node;		
	}
	list_head = new_node;	
	new_node->prev = nullptr;
	
	return list_head;
}

///@brief 在指定结点前插入新结点
///@param list_head 链表指针
///@param new_node 新结点指针
///@param key 插入位置之后的结点键值，如果有多个相同键值的结点，则认为是最靠近链表首部的结点
///@return 返回插入后的链表首部指针
///@author zhaowei
///@date 2014.08.18
///@version 1.1
listNode* ListInsert(listNode* list_head, listNode* new_node, int key)
{
	listNode* x = list_head;
	while(x != nullptr && key != x->val)
		x = x->next;
	
	if(x == nullptr)
		return list_head;

	else
	{
		new_node->next = x;
		new_node->prev = x->prev;

		x->prev = new_node;
		new_node->prev->next = new_node;
		return list_head;
	}

}

///@brief 删除链表中的结点
///@param list_head 链表指针
///@param delete_node 待删除的结点
///@return 返回插入后的链表首部指针
///@author zhaowei
///@date 2014.08.18
///@version 1.1
listNode* ListDelete(listNode* list_head, listNode* delete_node)
{
	if(delete_node == nullptr)
		return list_head;
	else
	{
		if(delete_node->prev != nullptr)
			delete_node->prev->next = delete_node->next;

		else
			list_head = delete_node->next;

		if(delete_node->next != nullptr)
			delete_node->next->prev = delete_node->prev;

		return list_head;
	}

}

int main()
{	
	listNode* list_head = nullptr;

	int insert_or_delete = 0;
	cout << "请选择插入结点或者删除结点（0：插入节点；1：删除结点）： ";
	while(cin >> insert_or_delete)
	{
		if(insert_or_delete == 0)
		{
			cout << "输入想要插入的结点键值： ";
			int insert_val = 0;
			cin >> insert_val;

			listNode* new_node = new listNode;
			new_node->val = insert_val;
			new_node->prev = nullptr;
			new_node->next = nullptr;

			int insert_method = 0;
			cout << "选择插入的方法（0：插入链表最前端；1：插入指定键值结点的前端）： ";
			cin >> insert_method;
						
			if(insert_method == 0)
				list_head = ListInsertToHead(list_head, new_node);
			else
			{
				int key = 0;
				cout << "输入指定结点的键值： ";
				cin >> key;
				list_head = ListInsert(list_head, new_node, key);
			}

			cout << "当前链表中包含的结点： ";

			listNode* list_index = list_head;
			while(list_index != nullptr)
			{
				cout << list_index->val << " ";
				list_index = list_index->next;
			}
			cout << endl;
			cout << "--------------------------------------------------------------" << endl;
			cout << endl;
		}

		else
		{
			cout << "输入想要删除的结点键值： ";
			int delete_val = 0;
			cin >> delete_val;

			if(list_head == nullptr)
			{
				cout << "此链表为空。" << endl;
				cout << "--------------------------------------------------------------" << endl;
				cout << endl;
				cout << "请选择插入结点或者删除结点（0：插入节点；1：删除结点）： ";
				continue;
			}

			listNode* delete_node = ListSearch(list_head, delete_val);

			if(delete_node == nullptr)
				cout << "链表中不含此节点，请重新输入想要删除的结点。" << endl;
			list_head = ListDelete(list_head, delete_node);

			cout << "当前链表中包含的结点： ";

			listNode* list_index = list_head;
			while(list_index != nullptr)
			{
				cout << list_index->val << " ";
				list_index = list_index->next;
			}
			cout << endl;
			cout << "--------------------------------------------------------------" << endl;
			cout << endl;
		}
		cout << "请选择插入结点或者删除结点（0：插入节点；1：删除结点）： ";
	}
	return 0;
}