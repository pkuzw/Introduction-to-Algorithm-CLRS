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
    if (list_sentinel->next == list_sentinel && list_sentinel->prev == list_sentinel)
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

///@brief 在哨兵结点后插入新结点
///@param list_sentinel 双向循环链表的哨兵结点
///@param new_node  待插入的新结点
///@return 如果插入成功，返回哨兵结点；否则返回空指针
///@author zhaowei
///@date 2014.08.27
///@version 1.0
listNode* ListInsertAtHead(listNode* list_sentinel, listNode* new_node)
{
    if(new_node == nullptr)
    {
        return nullptr;
    }
    
    //新结点的next指针指向原链表首部结点
    new_node->next = list_sentinel->next;
    
    //哨兵结点的next指针指向新结点
    list_sentinel->next = new_node;
    
    //新结点的prev指针指向哨兵结点
    new_node->prev = list_sentinel;
    
    //原链表的首部结点prev指针指向新结点
    new_node->next->prev = new_node;
    
    return list_sentinel;
}

///@brief 在指定结点前插入新结点
///@param list_sentinel 哨兵结点指针
///@param new_node 待插入的新结点指针
///@param nominated_node 指定位置的结点指针
///@return 如果插入成功，返回哨兵结点；否则返回空指针
///@author zhaowei
///@date 2014.08.27
///@version 1.0
listNode* ListInsertBeforeNode(listNode* list_sentinel, listNode* new_node, listNode* nominated_node)
{
    //如果指定结点为空指针，则说明链表中不包括该结点，返回空指针
    if(nominated_node == nullptr)
    {
        return nullptr;
    }
    
    nominated_node->prev->next = new_node;
    new_node->next = nominated_node;
    
    new_node->prev = nominated_node->prev;
    nominated_node->prev = new_node;
    
    return list_sentinel;
}

///@brief 删除双向循环链表中的指定结点
///@param list_sentinel 哨兵结点
///@param delete_node 待删除结点
///@return 如果删除结点成功，返回哨兵结点；否则返回空指针
///@author zhaowei
///@date 2014.08.27
///@version 1.0
listNode* ListDelete(listNode* list_sentinel, listNode* delete_node)
{
    //如果待删除结点为空结点，则说明链表中不包含此结点，返回空指针
    if(delete_node == nullptr)
        return nullptr;
    
    //如果链表只包含哨兵结点，说明链表为空，返回空指针
    else if(list_sentinel->next == list_sentinel && list_sentinel->prev == list_sentinel)
        return nullptr;
    
    delete_node->prev->next = delete_node->next;
    delete_node->next->prev = delete_node->prev;
    return list_sentinel;
}

int main()
{
    listNode* list_sentinel = new listNode;
    list_sentinel->next = list_sentinel;
    list_sentinel->prev = list_sentinel;
    list_sentinel->val = INT32_MAX;
    
    //用于记录查找、删除和插入等操作时的返回结果
    listNode* rtrn = new listNode;
    
    cout << "请选择添加结点（1）或者删除结点（2）：";
    int op_insert_delete = 0;
    
    while(cin >> op_insert_delete)
    {
        //添加结点
        if(op_insert_delete == 1)
        {
            cout << "请选择在链表首部（1）或者指定结点前（2）添加结点：";
            int op_insert_head_or_node = 0;
            
            //为新结点申请内存空间并初始化
            listNode* new_node = new listNode;
            new_node->val = 0;
            new_node->next = nullptr;
            new_node->prev = nullptr;
            
            while(cin >> op_insert_head_or_node)
            {
                //在首部添加结点
                if(op_insert_head_or_node == 1)
                {
                    cout << "请输入新结点的键值：";
                    cin >> new_node->val;
                    rtrn = ListInsertAtHead(list_sentinel, new_node);
                    if(rtrn == nullptr)
                    {
                        cout << "插入结点失败。有可能是哨兵结点未初始化。" << endl;
                        break;
                    }
                    else
                    {
                        cout << "插入结点成功。" << endl;
                        break;
                    }
                }
                
                //在指定结点前添加结点
                if(op_insert_head_or_node == 2)
                {
                    cout << "请输入新结点的键值：";
                    cin >> new_node->val;
                    
                    cout << "请输入位置结点的键值：";
                    int insert_place_key = 0;
                    listNode* insert_place_node = nullptr;
                    
                    while(cin >> insert_place_key)
                    {
                        listNode* nominated_node = new listNode;
                        nominated_node->val = insert_place_key;
                        nominated_node->next = nullptr;
                        nominated_node->prev = nullptr;
                        
                        nominated_node = ListSearch(list_sentinel, nominated_node->val);
                        if(nominated_node == nullptr)
                        {
                            cout << "位置结点不在链表中，请重新输入位置结点的键值：" << endl;
                            continue;
                        }
                        else
                        {
                            insert_place_node = nominated_node;
                            break;
                        }
                    }
                    
                    rtrn = ListInsertBeforeNode(list_sentinel, new_node, insert_place_node);
                    if(rtrn == nullptr)
                    {
                        cout << "插入结点失败。有可能是哨兵结点未初始化。" << endl;
                        break;
                    }
                    else
                    {
                        cout << "插入结点成功。" << endl;
                        break;
                    }
                }
                
                //对非法选项进行处理
                else
                {
                    cout << "输入选项有误，请重新选择。在链表首部插入请选择1，在指定结点前插入请选择2: ";
                    continue;
                }
            }
            
        }
        
        //删除结点
        else if (op_insert_delete == 2)
        {
            cout << "请输入待删除结点待键值：";
            int delete_key = 0;
            listNode* delete_node_ = nullptr;
            while(cin >> delete_key)
            {
                listNode* delete_node = new listNode;
                delete_node->val = delete_key;
                delete_node->prev = nullptr;
                delete_node->next = nullptr;

                delete_node = ListSearch(list_sentinel, delete_node->val);
                if(delete_node == nullptr)
                {
                    cout << "待删除结点不在链表中。请重新选择待删除结点：";
                }
                else
                {
                    cout << "删除结点成功。" << endl;
                    delete_node_ = delete_node;
                    break;
                }
            }
            rtrn = ListDelete(list_sentinel, delete_node_);
            if(rtrn == nullptr)
            {
                cout << "删除结点失败。可能原因是哨兵结点未初始化。" << endl;
            }
            else
                delete delete_node_;
        }
        
        //显示当前链表中包含的结点
        listNode* list_index = list_sentinel->next;
        
        cout << "当前链表中所含结点为：";
        while(list_index != list_sentinel)
        {
            cout << list_index->val << " ";
            list_index = list_index->next;
        }
        cout << endl;
        cout << "----------------------------------------------------------" << endl;
        
        //处理非法选项
        if(op_insert_delete < 1 || op_insert_delete > 2)
        {
            
            cout << "输入选项有误，请重新选择。插入结点请选择1，删除结点请选择2: ";
            continue;
        }
        
        cout << "请选择添加结点（1）或者删除结点（2）：";
    }
    
    
    return 0;
}




































