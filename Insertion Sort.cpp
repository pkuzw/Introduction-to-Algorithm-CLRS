///@brief 实现插入排序
///@author zhaowei
///@date 2014.07.17

#include <iostream>
using namespace std;

///@brief 交换两个整型变量
///@param a, b 待交换的两个元素
///@author zhaowei
///@date 2014.07.15
void swap(int& a, int& b)
{
	int t = a;
	a = b;
	b = t;
	return;
}

///@brief 插入排序（非降序）
///@param a 待排序数组指针
///@param arr_len 待排序数组长度
///@author zhaowei
///@date 2014.07.17
void InsertionSort(int* a, const int arr_len)
{
	for(int j = 1; j < arr_len; j++)
	{
		int key = a[j];
		int i = j - 1;
		while(i >= 0 && a[i] > key)
		{
			a[i+1] = a[i];
			i--;
		}
		a[i+1] = key;
	}
}

int main()
{
	cout << "输入数组大小： ";
	int arr_len = 0;
	cin >> arr_len;

	int* arr = new int[arr_len];

	cout << "输入排序前的数组： ";
	for(int i = 0; i < arr_len; i++)
		cin >> arr[i];

	InsertionSort(arr, arr_len);

	cout << "输出排序后的数组： ";
	for(int i = 0; i < arr_len; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;

	delete []arr;

	return 0;
}
