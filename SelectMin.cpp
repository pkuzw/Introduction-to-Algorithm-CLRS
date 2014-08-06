///@file 找出数组中的最小值
///@author zhaowei
///@date 2014.08.06
///@version 1.0

#include <iostream>
using namespace std;

///@brief 找出数组中的最小值
///@param arr 数组指针
///@param arr_len 数组长度
///@return 返回数组中的最小值
///@version 1.0
///@author zhaowei
///@date 2014.08.06
int SelectMin(int* arr, const int arr_len)
{
	int min = 2147483647;
	for(int i = 0; i < arr_len; i++)
	{
		if(min > arr[i])
			min = arr[i];
	}
	return min;
}

int main()
{
	cout << "输入数组的大小： ";
	int arr_len = 0;
	cin >> arr_len;

	cout << "输入数组： ";
	int* arr = new int[arr_len];
	for(int i = 0; i < arr_len; i++)
	{
		cin >> arr[i];
	}

	cout << "数组中的最小数： ";
	cout << SelectMin(arr, arr_len) << endl;
	delete []arr;
	return 0;
}