///@file 对给定的自然数数组进行选择排序
///@author zhaowei
///@date 2014.08.08
///@version 1.0
#include <iostream>
using namespace std;

///@brief 交换数组中的两个元素
///@param a 待交换的元素a
///@param b 待交换的元素b
///@author zhaowei
///@date 2014.08.08
///@version 1.0
void Swap(int& a, int& b)
{
	int tmp = a;
	a = b;
	b = tmp;

	return;
}


///@brief 选取数组中的最小值
///@param arr 数组指针
///@param p 数组起始下标
///@param r 数组终止下标
///@return 返回数组最小值下标
///@author zhaowei
///@date 2014.08.08
///@version 1.0
int SelectMin(int* arr, int p, int r)
{
	int min = arr[p];
	int min_index = p;
	for(int i = p; i <= r; i++)
	{
		if(arr[i] < min)
		{
			min = arr[i];
			min_index = i;
		}
	}
	return min_index;
}

///@brief 选择排序，每次选择数组中的最小值放入未排序元素的首部
///@param arr 数组指针
///@param p 数组起始下标
///@param r 数组终止下标
///@author zhaowei
///@date 2014.08.08
///@version 1.0
void SelectionSort(int* arr, int p, int r)
{
	int i = 0;
	while(p < r)
	{
		int min_cur = SelectMin(arr, p++, r);
		Swap(arr[min_cur], arr[i++]);
	}
	return;
}

int main()
{
	int arr_len = 0;
	cout << "输入待排序数组长度： ";
	cin >> arr_len;
	
	int* arr = new int[arr_len];
	cout << "输入数组元素： ";
	for(int i = 0; i < arr_len; i++)
		cin >> arr[i];

	SelectionSort(arr, 0, arr_len-1);

	cout << "选择排序后的数组： ";
	for(int i = 0; i < arr_len; i++)
		cout << arr[i] << " ";
	cout << endl;

	delete []arr;

	return 0;
}