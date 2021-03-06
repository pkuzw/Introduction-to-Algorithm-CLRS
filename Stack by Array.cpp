﻿///@file 用整型数组模拟栈的操作
///@author zhaowei
///@date 2014.08.14
///@version 1.0

///@file 修改主函数，能够在每次操作（PushStack/PopStack）后显示栈内元素情况。这样更便于观察和理解栈的性质
///@author zhaowei
///@date 2014.08.14
///@version 1.1

#include <iostream>
using namespace std;

///@brief 栈结构体，利用数组维护一个栈
///@author zhaowei
///@date 2014.08.15
///@version 1.0
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
	if(stk->top == stk->capacity)
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

///@brief 判断栈是否已满
///@param stk 栈指针
///@return 如果栈已满，则返回true；否则返回false
///@author zhaowei
///@date 2014.08.14
///@version 1.0
bool IsFullStack(stack* stk)
{
	//如果栈已满，则返回true
	if(stk->top == stk->capacity)
		return true;
	else
		return false;
}

///@brief 判断栈是否为空
///@param stk 栈指针
///@return 如果栈为空，则返回true；否则返回false
///@author zhaowei
///@date 2014.08.14
///@version 1.0
bool IsEmptyStack(stack* stk)
{
	//如果栈为空，则返回true
	if(stk->top == 0)
		return true;
	else
		return false;
}

int main()
{
	cout << "输入栈大小： ";
	int stk_size = 0;
	cin >> stk_size;
	cout << "------------------------------------------------------------" << endl;

	stack* stk = new stack;
	int* arr = new int[stk_size + 1];	//stack[0]不存放数据，这样就能够通过top ?= 0来判断栈是否为空，因此多申请一个整型变量的内存空间
	for(int k = 0; k < stk_size+1; k++)
	{
		arr[k] = 0;
	}

	stk->top = 0;
	stk->capacity = stk_size;
	stk->stck = arr;

	/*
	int val_in = 0;
	int i = 1;
	do 
	{
		if(i > stk_size)	//如果超过了栈大小，则不再进行输入。否则继续下一个元素的入栈
			break;

		cout << "输入第" << i++ << "个入栈元素： ";
		cin >> val_in;
	} while (PushStack(stk, val_in));

	cout << "----------------------------------------------------" << endl;

	int val_out = 0;
	int j = 1;
	while (PopStack(stk, val_out))
	{
		cout << "输出第" << j++ << "个出栈元素： ";
		cout << val_out << endl;
	}
	*/

	int push_or_pop = 0;	//如果push_or_pop == 0，则压栈；如果push_or_pop == 1，则弹栈
	cout << "压栈还是弹栈？ 请输入（0：压栈；1：弹栈）： ";
	while(cin >> push_or_pop)
	{
		if(push_or_pop == 0)
		{
			if(IsFullStack(stk))
			{
				cout << "栈已满，无法压栈。" << endl;
			}
			else
			{
				int input = 0;
				cout << "输入压栈元素： ";
				cin >> input;
				PushStack(stk, input);
			}
		}
		else
		{
			if(IsEmptyStack(stk))
			{
				cout << "栈已空，无法弹栈。" << endl;
			}
			else
			{
				int output = 0;
				PopStack(stk, output);
				cout << "弹栈元素为： " << output << endl;
			}
		}

		int stk_index = 1;	//stck[0]不存放数据，循环变量应从1开始
		cout << "当前栈中所含元素为： ";
		while (stk_index != stk->top + 1)
		{
			cout << stk->stck[stk_index++] << " ";
		}
		cout << endl;
		cout << "------------------------------------------------------------" << endl;
		cout << "压栈还是弹栈？ 请输入（0：压栈；1：弹栈）： ";
	}

	delete []arr;
	delete stk;
	return 0;
}