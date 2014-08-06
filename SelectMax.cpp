///@file 找数组中的最大元素
///@author zhaowei
///@date 2014.08.06

#include<iostream>
using namespace std;
 
///@brief 找出数组中的最大元素
///@param arr 数组指针
///@param arr_len 数组长度
///@return 返回数组中的最大元素
///@version 1.0
int SelectMax(int* arr, const int arr_len)
{
	int max = 0;
	for(int i = 0; i < arr_len; i++)
	{
		if(arr[i] > max)
			max = arr[i];
	}
	return max;
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

	cout << "数组中的最大数： ";
	cout << SelectMax(arr, arr_len) << endl;
	delete []arr;

	return 0;
}