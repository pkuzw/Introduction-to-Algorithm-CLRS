///@brief 堆排序
///@author zhaowei
///@date 2014.07.14

#include<iostream>
using namespace std;

///@brief 计算左孩子下标
///@param i 结点下标
///@return 左孩子下标
///@author zhaowei
///@date 2014.07.14
int Left(int i)
{
	return 2 * i + 1;
}

///@brief 计算右孩子下标
///@param i 结点下标
///@return 右孩子下标
///@author zhaowei
///@date 2014.07.14
int Right(int i)
{
	return 2 * i + 2;
}

///@brief 交换两个整型变量
///@param a, b 两个待交换的整型变量
///@author zhaowei
///@date 2014.07.14
void swap(int& a, int& b)
{
	int tmp = 0;
	tmp = a;
	a = b;
	b = tmp;
	return;
}

///@brief 维护最大堆
///@param arr 待维护的数组指针
///@param heap_size 堆大小(堆中最后一个元素的下标。在伪代码中是n，在c++中是n-1，因为数组从0开始计数)
///@param i 开始维护的起点坐标
void MaxHeapify(int* arr, int heap_size, const int i)
{
	int largest = 0;
	int l = Left(i);
	int r = Right(i);
	if(l <= heap_size && arr[l] > arr[i])
		largest = l;
	else
		largest = i;
	if(r <= heap_size && arr[r] > arr[largest])
		largest = r;
	if(i != largest)
	{
		swap(arr[i], arr[largest]);
		MaxHeapify(arr, heap_size, largest);
	}
	return;
}

///@brief 建立最大堆
///@param arr 数组指针
///@param heap_size 堆大小(堆中最后一个元素的下标。在伪代码中是n，在c++中是n-1，因为数组从0开始计数)
///@author zhaowei
///@date 2014.07.14
void BuildMaxHeap(int* arr, int heap_size)
{
	for(int i = heap_size/2; i >= 0; i--)
	{
		MaxHeapify(arr, heap_size, i);
	}
	return;
}

///@brief 堆排序
///@param arr 数组指针
///@param heap_size 堆大小(堆中最后一个元素的下标。在伪代码中是n，在c++中是n-1，因为数组从0开始计数)
///@author zhaowei
///@date 2014.07.14
void HeapSort(int* arr, int heap_size)
{
	BuildMaxHeap(arr, heap_size);
	for(int i = heap_size; i > 0; i--)
	{
		swap(arr[0], arr[i]);
		heap_size--;
		MaxHeapify(arr, heap_size, 0);
	}
	return;
}

int main()
{
	int array_count = 0;
	cout << "输入待排序数组的元素个数： ";
	cin >> array_count;
	int * array_i = new int[array_count];
	cout << "输入待排序数组： ";
	for(int i = 0; i < array_count; i++)
		cin >> array_i[i];

	HeapSort(array_i, array_count-1);

	cout << "输出排好序后的数组： ";
	for(int i = 0; i < array_count; i++)
		cout << array_i[i] << " ";
	cout << endl;

	delete []array_i;
	return 0;
}
