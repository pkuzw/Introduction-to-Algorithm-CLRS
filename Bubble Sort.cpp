///@brief 冒泡排序
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

///@brief 冒泡排序
///@param a 数组指针
///@param arr_len 数组长度
///@author zhaowei
///@date 2014.07.17
void BubbleSort(int* a, int arr_len)
{
	for(int i = 0; i < arr_len; i++)
	{
		for(int j = arr_len-1; j >= i+1; j--)
		{
			if(a[j] < a[j-1])
				swap(a[j], a[j-1]);

		}
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

	BubbleSort(arr, arr_len);

	cout << "输出排序后的数组： ";
	for(int i = 0; i < arr_len; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;

	delete []arr;

	return 0;
}
