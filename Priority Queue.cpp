///@breif 用最大堆思想实现最大值优先队列
///@author zhaowei
///@date 2014.07.18


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

///@brief 计算父节点下标
///@pram i 结点下标
///@return 父结点下标
///@author zhaowei
///@date 2014.07.20
int Parent(int i)
{
	return (i - 1)/2;
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

///@brief 返回最大值
///@param arr 数组指针
///@return 返回优先队列中的最大key值元素
///@author zhaowei
///@date 2014.07.18
int Maximum(int* arr)
{
	return arr[0];
}

///@brief 去掉并返回队列中具有最大key值的元素
///@param arr 数组指针
///@param heap_size
///@return 返回队列中具有最大key值的元素值
///@author zhaowei
///@date 2014.07.20
int HeapExtractMax(int* arr, int heap_size)
{
	if(heap_size < 0)
		return -1;

	int max = arr[0];
	arr[0] = arr[heap_size-2];
	heap_size--;
	MaxHeapify(arr, heap_size, 0);
	return max;
}

///@brief 将下标为i的元素key值增加到'key'，并维护优先级队列
///@param arr 数组指针
///@param heap_size 数组大小
///@param i 要修改的结点下标
///@param key 将结点的key值增大到指定值
///@return 如果成功修改并维护队列，则返回true；否则返回false.
///@author zhaowei
///@date 2014.07.20
bool HeapIncreaseKey(int* arr, int heap_size, int i, const int key)
{
	if(key < arr[i])
		return false;
	arr[i] = key;
	while(i >= 1 && arr[Parent(i)] < arr[i])
	{
		swap(arr[i], arr[Parent(i)]);
		i = Parent(i);
	}
	return true;
}

///@brief 向最大值优先队列中插入元素
///@param arr 数组指针
///@param key 新插入元素的key值
///@param heap_size 堆大小
///@author zhaowei
///@date 2014.07.20
void MaxHeapInsert(int* arr, int& heap_size, const int key)
{
	heap_size++;
	arr[heap_size-1] = -2147483647;
	HeapIncreaseKey(arr, heap_size, heap_size-1, key);
	return;
}

int main()
{
	int heap_size = 0;
	int arr_count = 0;
	cout << "输入最大值优先队列大小： ";
	cin >> arr_count;

	int *arr = new int[arr_count];
	cout << "依次输入数组元素： " ;
	for(int i = 0; i < arr_count; i++)
	{
		cin >> arr[i];
		MaxHeapInsert(arr, heap_size, arr[i]);
	}

	cout << "输出最大值优先队列的元素： ";
	for(int i = 0; i < arr_count; i++)
		cout << arr[i] << " ";
	cout << endl;
	delete []arr;
	return 0;
}



