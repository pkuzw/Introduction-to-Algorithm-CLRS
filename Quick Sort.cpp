///@brief 实现快速排序
///@author zhaowei
///@date 2014.07.15

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

///@brief 将数组分割，使其左半部分的元素都比返回值小，右半部分的元素都比返回值大。
///@param arr 数组指针
///@param p	数组起始下标
///@param r 数组终止下标
///@return 返回分割后数组的中轴值
///@author zhaowei
///@date 2014.07.15
int Partition(int* arr, const int p, const int r)
{
	int x = arr[r];
	int i = p-1;
	for(int j = p; j < r; j++)
	{
		if(arr[j] <= x)
		{
			i++;
			swap(arr[j], arr[i]);
		}		
	}
	swap(arr[i+1], arr[r]);
	return i+1;
}

///@brief 用递归实现快速排序
///@param arr 数组指针
///@param p	数组起始下标
///@param r 数组终止下标
///@author zhaowei
///@date 2014.07.15
void QuickSort(int* arr, const int p, const int r)
{
	if(p < r)
	{
		int q = Partition(arr, p, r);
		QuickSort(arr, p, q-1);
		QuickSort(arr, q+1, r);
	}
	return;
}

int main()
{
	int array_size = 0;
	cout << "输入数组大小：	";
	cin >> array_size;

	int* array_int = new int[array_size];
	cout << "输入数组元素：	";
	for(int i = 0; i < array_size; i++)
		cin >> array_int[i];

	QuickSort(array_int, 0, array_size-1);

	cout << "排序后的数组：	";
	for(int i = 0; i < array_size; i++)
		cout << array_int[i] << " ";
	cout << endl;
	return 0;
}
