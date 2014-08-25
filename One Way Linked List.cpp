///@file 创建单链表，包括单链表结点的插入、删除和查找
///@author zhaowei
///@date 2014.08.22
///@version 1.0

///@brief 链表结点的结构体。单链表结点由键值和指向下一结点的指针组成。链表的尾结点的指向下一结点的指针为空；链表通过指向链表首部的指针list_head来遍历整个链表
///@author zhaowei
///@date 2014.08.25
///@version 1.0
struct listNode
{
    listNode* next;
    int val;
};

///@brief 查找给定值到结点
///@param list_head 链表首结点
///@param key 待查找待结点键值
///@return 如果找到相应待结点，则返回该结点的指针；否则返回空指针
///@author zhaowei
///@date 2014.08.25
///@version 1.0
listNode* ListSearch(listNode* list_head, int key)
{
    listNode* list_index = list_head;
    while(list_index != nullptr && list_index->val != key)
    {
        list_index = list_index->next;
    }
    return list_index;
}

///@brief 在链表首部插入新结点
///@param list_head 链表首结点
///@param new_node 新插入的结点
///@return 返回插入新结点后的链表首部
///@author zhaowei
///@date 2014.08.25
///@version 1.0
listNode* ListInsertBeforeHead(listNode* list_head, listNode* new_node)
{
    new_node->next = list_head;
    list_head = new_node;
    return list_head;
}

///@brief 在指定结点前插入新结点
///@param list_head 链表首部指针
///@param new_node 新结点
///@param node_key 待插入结点后一个结点的键值
///@return 如果插入新结点成功，返回链表的首指针；否则返回空指针
///@author zhaowei
///@date 2014.08.25
///@version 1.0
listNode* ListInsertBeforeNode(listNode* list_head, listNode* new_node, int node_key)
{
    listNode* nominated_node = ListSearch(list_head, node_key);
    if (nominated_node == nullptr)
    {
        return nullptr;
    }
    else
    {
        listNode* list_index = list_head;
        while (list_index->next != nominated_node)
        {
            list_index = list_index->next;
        }
        new_node->next = nominated_node;
        list_index->next = new_node;
        return list_head;
    }
}

///@brief 删除链表中的指定结点
///@param list_head 链表的首部指针
///@param node_key 待删除结点待键值
///@return 如果删除成功，则返回链表待首指针；否则返回空指针
///@author zhaowei
///@date 2014.08.25
///@version 1.0
listNode* ListDelete(listNode* list_head, int node_key)
{
    
}

#include <iostream>
using namespace std;

int main()
{
	return 0;
}

































