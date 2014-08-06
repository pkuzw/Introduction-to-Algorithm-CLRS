///@file 同时找出数组中的最大最小数，时间复杂度不超过O(n)，更精确的说不超过3n/2.
///@version 1.0
///@author zhaowei
///@date 2014.08.06

#include <iostream>
using namespace std;

///@brief 同时找出数组中的最大最小数，时间复杂度不超过3n/2
///@param arr 数组指针
///@param arr_len 数组长度
///@param max 最大值
///@param min 最小值
///@version 1.0
///@author zhaowei
///@date 2014.08.06
void SelectMaxMin(int* arr, const int arr_len, int& max, int& min)
{	
	//如果数组长度为偶数，先确定出前两个元素的大小，作为最大最小值的初始值，然后继续两两比较，跟最大最小变量比较即可
	if(arr_len % 2 == 0)
	{
		max = arr[0];
		min = arr[0];
		for(int i = 0; i < arr_len; i += 2)
		{
			if(arr[i] >= arr[i+1])
			{
				if(arr[i] > max)
					max = arr[i];
				if(arr[i+1] < min)
					min = arr[i+1];
			}
			else
			{
				if(arr[i+1] > max)
					max = arr[i];
				if(arr[i] < min)
					min = arr[i];
			}
		}
	}
	//如果数组长度为奇数，将第一个元素作为最大最小值的初始值，然后继续两两比较，跟最大最小变量比较即可
	else
	{
		max = arr[0];
		min = arr[0];
		for(int i = 1; i < arr_len; i += 2)
		{
			if(arr[i] >= arr[i+1])
			{
				if(arr[i] > max)
					max = arr[i];
				if(arr[i+1] < min)
					min = arr[i+1];
			}
			else
			{
				if(arr[i+1] > max)
					max = arr[i];
				if(arr[i] < min)
					min = arr[i];
			}
		}
	}
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

	int min = 0;
	int max = 2147483647;
		SelectMaxMin(arr, arr_len, max, min);
	cout << "数组中的最大数： ";
	cout << max << endl;
	cout << "数组中的最小数： ";
	cout << min << endl;

	delete []arr;
	return 0;
}