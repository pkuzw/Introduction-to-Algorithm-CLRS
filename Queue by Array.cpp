///@file 用整型数组模拟队列的操作
///@author zhaowei
///@date 2014.08.15
///@version 1.0


#include <iostream>
using namespace std;

///@brief 队列元素结构体，利用数组维护一个循环队列
///@author zhaowei
///@date 2014.08.15
///@version 1.0
struct queue
{
	int* que;		//保存元素的数组指针
	int capacity;	//队列容量，实际申请时多申请一个整型变量的内存空间
	int head;		//队首下标，指向队列中下一个将要出队的元素
	int tail;		//队尾后一个元素的下标，指向将要入队的下标位置
};

///@brief 向队列加入新元素
///@param q 队列指针
///@param val 待加入元素
///@return 如果队列未满，则将元素加入队尾，并返回true；否则返回false
///@author zhaowei
///@date 2014.08.15
///@version 1.0
bool PushQueue(queue* q, int val)
{
	//如果队列已满，则直接返回false
	//队列最后不存放数据，这样就能通过head ?= tail + 1来判断队列是否已满；通过head ?= tail来判断队列是否为空
	if(q->head == (q->tail + 1) % (q->capacity + 1))
		return false;

	q->que[q->tail] = val;
	if(q->tail == q->capacity)
		q->tail = 0;
	else
		q->tail++;
	return true;
}

///@brief 从队列弹出元素
///@param q 队列指针
///@param val 取出后的元素
///@return 如果队列不为空，则通过参数将队首元素取出，并返回true；否则返回false
///@author zhaowei
///@date 2014.08.15
///@version 1.0
bool PopQueue(queue* q, int& val)
{
	//如果队列为空，则返回false
	//通过head ?= tail来判断队列是否为空
	if(q->head == q->tail)
		return false;

	val = q->que[q->head];
	if(q->head == q->capacity)
		q->head = 0;
	else
		q->head++;
	return true;
}

int main()
{
	cout << "输入队列大小： ";
	int queue_size = 0;
	cin >> queue_size;

	queue* q = new queue;
	int* arr = new int[queue_size + 1];
	for(int k = 0; k < queue_size + 1; k++)
		arr[k] = 0;

	q->capacity = queue_size;
	q->head = 0;
	q->tail = 0;
	q->que = arr;

	int val_in = 0;
	int i = 1;
	do 
	{
		//如果队列元素已满，则不再继续输入
		if(i > queue_size)
			break;

		cout << "输入第" << i++ << "个入队元素： ";
		cin >> val_in;
	} while (PushQueue(q, val_in));

	cout << "----------------------------------------------------" << endl;

	int val_out = 0;
	int j = 1;
	while(PopQueue(q, val_out))
	{
		cout << "输出第" << j++ << "个出队元素： ";
		cout << val_out << endl;
	}

	delete []arr;
	delete q;
}