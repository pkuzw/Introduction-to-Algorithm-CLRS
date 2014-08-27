///@file 练习双向循环链表
///@author zhaowei
///@date 2014.08.27
///@version 1.0

#include <iostream>
using namespace std;

///@brief 双向循环链表的结点结构体
///@author zhaowei
///@date 2014.08.27
///@version 1.0
struct listNode
{
    listNode* prev;
    listNode* next;
    int val;
};

///@brief 在链表中查找指定结点
///@param list_sentinel
///@param key 待查找的结点键值
///@return 如果在链表中成功找到该结点，则返回该结点的指针；否则返回空指针
///@author zhaowei
///@date 2014.08.27
///@version 1.0
listNode* ListSearch(listNode* list_sentinel, int key)
{
    //如果双向循环链表只有一个哨兵结点，则返回空指针
    if (list_sentinel->next == list_sentinel->prev)
    {
        return nullptr;
    }
    
    listNode* list_index = list_sentinel->next;
    while (list_index != list_sentinel && list_index->val != key)
    {
        list_index = list_index->next;
    }
    
    //如果遍历链表后未找到键值匹配的结点，游标指针回到哨兵指针，返回空指针
    if (list_index == list_sentinel)
        return nullptr;
    
    else
        return list_index;
}

///@brief 

int main()
{
    return 0;
}
