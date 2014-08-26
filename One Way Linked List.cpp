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
        while (list_index->next != nominated_node && list_index->next != nullptr)
        {
            list_index = list_index->next;
        }
        new_node->next = nominated_node;
        if(list_index == nominated_node)
            list_head = new_node;
        else
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
    listNode* delete_node = ListSearch(list_head, node_key);
    if(delete_node == nullptr)
    {
        return nullptr;
    }
    else
    {
        listNode* list_index = list_head;
        if(list_head == delete_node)
        {
            list_head = list_head->next;
        }
        else
        {
            while (list_index->next != delete_node && list_index->next != nullptr)
            {
                list_index = list_index->next;
            }
            list_index->next = delete_node->next;
        }
        return list_head;
    }
}

#include <iostream>
using namespace std;

int main()
{
    listNode* list_head = nullptr;
    
    cout << "请选择插入结点或者删除结点（0:插入结点；1:删除结点）：";
    int insert_delete = 0;
    while(cin >> insert_delete)
    {
        if(insert_delete == 0)
        {
            listNode* new_node = new listNode;
            new_node->next = nullptr;
            new_node->val = -1;

            int before_key_or_head = 0;
            cout << "请选择是在链表首部插入结点或者在指定结点前插入结点（0:首部插入；1:指定插入）：";
            while(cin >> before_key_or_head)
            {
                if(before_key_or_head > 1 || before_key_or_head < 0)
                {
                    cout << "输入无效选项，请重新输入。" << endl;
                    cout << "请选择是在链表首部插入结点或者在指定结点前插入结点（0:首部插入；1:指定插入）：";
                    continue;
                }
                else
                {
                    cout << "请输入新结点的键值：";
                    int new_node_key = -1;
                    cin >> new_node_key;
                    new_node->val = new_node_key;
                    
                    if(before_key_or_head == 0)
                    {
                       list_head = ListInsertBeforeHead(list_head, new_node);
                        break;  //成功插入后应该跳出询问在链表首部还是指定结点前插入的循环
                    }
                    else if(before_key_or_head == 1)
                    {
                        cout << "请选择要插入的位置：";
                        int key_val = -1;
                        
                        while(cin >> key_val)
                        {
                            listNode* is_exist = ListSearch(list_head, key_val);
                            if (is_exist == nullptr)
                            {
                                cout << "该结点不存在，请重新选择插入位置：";
                            }
                            else
                            {
                                list_head = ListInsertBeforeNode(list_head, new_node, key_val);
                                break;
                            }
                        }
                        break;  //成功插入后应该跳出询问在链表首部还是指定结点前插入的循环
                        
                    }

                }
            }
        }
        
        else if(insert_delete == 1)
        {
            cout << "请选择删除结点的键值：";
            int delete_key = -1;
            
            while(cin >> delete_key)
            {
                listNode* is_exist = ListSearch(list_head, delete_key);
                if (is_exist == nullptr)
                {
                    cout << "该结点不存在，请重新选择要删除的结点：";
                }
                else
                {
                    list_head = ListDelete(list_head, delete_key);
                    break;
                }
            }
        }
        else
        {
            cout << "输入无效选项，请重新输入。" << endl;
            cout << "----------------------------------------------" << endl;
            cout << "请选择插入结点或者删除结点（0:插入结点；1:删除结点）：";
            continue;
        }
        
        cout << "目前链表中所含元素：";
        listNode* list_index = list_head;
        
        if(list_index == nullptr)
            cout << "null" << endl;
        
        else
        {
        
            while(list_index->next != nullptr)
            {
                cout << list_index->val << " ";
                list_index = list_index->next;
            }
            cout << list_index-> val << endl;
        }
        cout << "----------------------------------------------" << endl;
        cout << "请选择插入结点或者删除结点（0:插入结点；1:删除结点）：";
    }
    
    
	return 0;
}

































