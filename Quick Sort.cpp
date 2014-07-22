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

///@brief 添加如果数组元素全部一致，则返回中间那个元素下标。以前的代码会返回最后一个元素下表。
///@author zhaowei
///@date 2014.07.22
int Partition(int* arr, const int p, const int r)
{
	//添加判断数组元素是否全部一致的代码
	int count = 1;
	for(int k = p; k < r; k++)
	{
		if(arr[k] == arr[k + 1])
			count++;
	}
	if(count == r - p + 1)
		return (p + r) / 2;

	//原代码
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

///@brief 非増序版Partition函数
///@param arr 数组指针
///@param p 起始元素下标
///@param r 终止元素下标
///@return 轴值元素下标，其左侧元素均大于等于它，右侧元素均小于它
///@author zhaowei
///@date 2014.07.22
int PartitionDesc(int* arr, const int p, const int r)
{
	int count = 1;
	for(int k = p; k < r; k++)
	{
		if(arr[k] ==  arr[k+1])
			count++;
	}
	if(count == r - p + 1)
		return (p + r)/2;

	int x = arr[r];
	int i = p - 1;
	for(int j = p; j < r; j++)
	{
		if(arr[j] >= x)
		{
			i++;
			swap(arr[i], arr[j]);
		}
	}
	swap(arr[i+1], arr[r]);
	return i + 1;
}

///@brief 递归实现非降序快速排序
///@param arr 数组指针
///@param p 数组起始下标
///@param r 数组终止下标
///@return 
///@authro zhaowei
///@date 2014.07.22
void QuickSortDesc(int* arr, const int p, const int r)
{
	if(p < r)
	{
		int q = PartitionDesc(arr, p, r);
		QuickSortDesc(arr, p, q-1);
		QuickSortDesc(arr, q+1, r);
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

	QuickSort(array_int, 0, array_size-1);

	cout << "Ascendingly sorted array: ";
	for(int i = 0; i < array_size; i++)
		cout << array_int[i] << " ";
	cout << endl;
	
	
	QuickSortDesc(array_int, 0, array_size-1);

	cout << "Descendingly sorted array : ";
	for(int i = 0; i < array_size; i++)
		cout << array_int[i] << " ";
	cout << endl;
	delete []array_int;
	return 0;
}
