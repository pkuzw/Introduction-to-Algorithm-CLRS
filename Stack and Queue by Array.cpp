///@file 用整型数组模拟栈和队列的操作
///@author zhaowei
///@date 2014.08.14
///@version 1.0

#include <iostream>
using namespace std;

struct stack
{
	int* stck;		//模拟栈的数组指针
	int capacity;	//栈容量。栈容量为动态申请数组stck[capacity + 1]，stck[0]不存放数据
	int top;		//栈顶元素的下标
};


///@brief 将元素压入栈顶
///@param stk 接收元素的栈类型指针
///@param val 入栈元素
///@return 如果元素入栈后未超过栈容量，则说明入栈成功，返回true；否则返回false
///@author zhaowei
///@date 2014.08.14
///@version 1.0
bool PushStack(stack* stk, int val)
{
	//如果栈已满，则返回false
	if(stk->top = stk->capacity)
		return false;

	stk->top++;
	stk->stck[stk->top] = val;
	
	return true;
}

///@brief 弹出栈顶元素
///@param stk 栈指针
///@param val 获取的栈顶元素
///@return 如果栈为空，则返回false；否则返回true，具体的栈顶元素值通过参数传出
///@author zhaowei
///@date 2014.08.14
///@version 1.0
bool PopStack(stack* stk, int& val)
{
	//如果栈为空，则返回false
	if(stk->top == 0)
		return false;

	val = stk->stck[stk->top];
	stk->top--;
	return true;
}