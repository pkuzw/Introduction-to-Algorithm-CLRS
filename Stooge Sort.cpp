///@file Stooge Sort.cpp
///@brief 实现《算法导论》P95思考题7-3中的算法
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

///@brief 递归实现Stooge排序算法
///@param arr 数组指针
///@param p 数组起始下标
///@param r 数组终止下标
///@author zhaowei
///@date 2014.07.29
///@version 1.0
void StoogeSort(int* arr, const int p, const int r)
{
	if(arr[p] > arr[r])
		swap(arr[p], arr[r]);

	if(p + 1 >= r)
		return;

	//将arr三等分
	int k = (r - p + 1)/3;
	
	StoogeSort(arr, p, r-k);	//先递归处理前三分之二
	StoogeSort(arr, p+k, r);	//后递归处理后三分之二
	StoogeSort(arr, p, r-k);	//再递归处理前三分之二

	return ;
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

	//测试Stooge排序升序输出
	StoogeSort(array_int, 0, array_size-1);

	cout << "Ascendingly Stooge sorted array: ";
	for(int i = 0; i < array_size; i++)
		cout << array_int[i] << " ";
	cout << endl;	

	delete []array_int;
	return 0;
}
