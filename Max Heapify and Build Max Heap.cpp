///@brief 练习6.2-5和6.3-1
///@brief 最大堆 
///@param array_int	保存有需要维护的整数数组
///@param i	需要维护的元素下标
///@param heap_size 需要维护的堆大小
///@author zhaowei
///@date 2014.07.12

#include <iostream>
using namespace std;

///@brief 计算下标为i的左孩子
///@param i	输入结点的下标
///@return 返回左孩子的下标
int Left(int i)
{
	return i*2 + 1;
}

///@brief 计算下标为i的右孩子
///@param i 输入结点的下标
///@return 返回右孩子的下标
int Right(int i)
{
	return i*2 + 2;
}

///@brief 计算下标为i的父节点
///@param i 输入结点的下标
///@return 返回父节点的下标
int Parent(int i)
{
	return (i - 1) / 2;
}


///@brief 交换两个int型变量
///@param a b 待交换的两个变量
void swap(int& a, int& b)
{
	int tmp = a;
	a = b;
	b = tmp;

	return;
}

///@brief 维护指定结点，使数组保持最大堆的性质。采用递归实现。
///@param array_int 数组指针
///@param heap_size 堆大小
///@param i 待维护的结点下标
void MaxHeapifyRecur(int* array_int, int heap_size, int i)
{
	int l = Left(i);
	int r = Right(i);
	int largest = 0;
	if(l <= heap_size && array_int[l] > array_int[i])
		largest = l;
	else 
		largest = i;
	if(r <= heap_size && array_int[r] > array_int[largest])
		largest = r;

	if(i != largest)
	{
		swap(array_int[i], array_int[largest]);
		MaxHeapifyRecur(array_int, heap_size, largest);
	}

	return;
}

///@brief 维护指定结点，使数组保持最大堆的性质。采用迭代实现。
///@param array_int 数组指针
///@param heap_size 堆大小
///@param i 待维护的结点下标
void MaxHeapifyIter(int* array_int, int heap_size, int i)
{
	while( i <= (heap_size - 1)/2)
	{
		int l = Left(i);
		int r = Right(i);
		int largest = 0;
		if(l <= heap_size && array_int[l] > array_int[i])
			largest = l;
		else 
			largest = i;
		if(r <= heap_size && array_int[r] > array_int[largest])
			largest = r;

		if(i != largest)
		{
			swap(array_int[i], array_int[largest]);
			i = largest;
		}
	}
	
	return;
}


int main()
{
	int a[8] = {5, 3, 17, 10, 84, 19, 6, 22};
	cout << "整理前的最大堆：	";
	for(int i = 0; i < 8; i++)
	{
		cout << a[i] << ' ';
	}
	cout << endl;

	//MaxHeapifyRecur(a, 14, 2);
	for(int i = 3; i >= 0; i--)
	{
		MaxHeapifyIter(a, 8, i);

		cout << "整理" << 4-i << "次后的最大堆：	";
		for(int j = 0; j < 8; j++)
		{
			cout << a[j] << ' ';
		}
		cout << endl;
	}
	return 0;
}
