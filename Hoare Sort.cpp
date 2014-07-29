///@file Hoare Sort.cpp
///@biref 用Hoare划分来进行快速排序
///@author zhaowei
///@date 2014.07.29
///@version 1.0

#include <iostream>
using namespace std;

///@brief 交换两个整型变量
///@param a, b 待交换的两个元素
///@author zhaowei
///@date 2014.07.29
///@version 1.0
void swap(int& a, int& b)
{
	int t = a;
	a = b;
	b = t;
	return;
}

///@brief Hoare划分
///@param arr 数组指针
///@param p 数组起始下标
///@param r 数组终止下标
///@return 返回下标j，使得arr[p..j]中的每个元素都不大于arr[j+1..r]中的任一元素
///@author zhaowei
///@date 2014.07.29
///@version 1.0
int HoarePartition(int* arr, const int p, const int r)
{
	int x = arr[p];
	int i = p - 1;
	int j = r + 1;
	while (1)
	{
		do 
		{
			j--;
		} while (arr[j] > x);

		do 
		{
			i++;
		} while (arr[i] < x);

		if(i < j)
			swap(arr[i], arr[j]);
		else
			return j;
	}
}

///@brief Hoare快速排序
///@param arr 数组指针
///@param p 数组起始下标
///@param r 数组终止下标 
///@author zhaowei
///@date 2014.07.29
///@version 1.0
void HoareQuickSort(int* arr, const int p, const int r)
{
	if(p < r)
	{
		int q = HoarePartition(arr, p, r);
		HoareQuickSort(arr, p, q-1);
		HoareQuickSort(arr, q+1, r);
	}
	return;
}

int main()
{
	int array_size = 0;
	cout << "Output array size: ";
	cin >> array_size;

	int* array_int = new int[array_size];
	cout << "Input integers: ";
	for(int i = 0; i < array_size; i++)
		cin >> array_int[i];

	//测试Hoare快速排序升序输出
	HoareQuickSort(array_int, 0, array_size-1);

	cout << "Ascendingly Hoare quick-sorted array: ";
	for(int i = 0; i < array_size; i++)
		cout << array_int[i] << " ";
	cout << endl;	

	delete []array_int;
	return 0;
}