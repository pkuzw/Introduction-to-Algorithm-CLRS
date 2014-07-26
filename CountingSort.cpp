///@brief 实现计数排序伪代码
///@author zhaowei
///@date 2014.07.26
#include<iostream>
using namespace std;

///@brief 计数排序
///@param a 待排序数组
///@param b 排好序后的数组
///@param a_size 待排序数组的大小
///@param k 临时数组的最大元素下标，该值等于待排序数组中最大元素的值
void CountingSort(int* a, int* b, const int a_size, int k)
{
	//申请动态临时数组，用于保存待排序数组中每个元素及比它小的元素出现的数量
	int* c = new int[k+1];

	//将临时数组中的元素初始化为零
	for(int i = 0; i < k+1; i++)
		c[i] = 0;

	//统计待排序数组中每个元素出现的数量
	for(int j = 0; j < a_size; j++)
		c[a[j]]++;

	//统计待排序中每个元素及比它小的元素出现数量
	for(int i = 1; i < k+1; i++)
		c[i] += c[i-1];
	
	//按照临时数组c中统计的小于等于i元素数量，将a数组中的元素放入b数组
	for(int j = a_size-1; j >= 0; j--)
	{
		b[c[a[j]] - 1] = a[j];	//注意：c[a[j]] - 1是因为数组b的起始下标为0.在《算法导论》中数组的起始下标为1
		c[a[j]]--;	//为了避免出现重复出现的元素放入同一位置，每次放入b数组后将其在临时数组中的计数值自减1
	}

	delete []c;
	return ;
}

int GetMaximum(int* a, const int a_size)
{
	int max = 0;
	for(int i = 0; i < a_size; i++)
	{
		if(a[i] > max)
			max = a[i];
	}
	return max;
}

int main()
{
	cout << "输入待排序数组大小： ";
	int arr_size = 0;
	cin >> arr_size;

	cout << "输入待排序数组： ";
	int *arr_input = new int[arr_size];
	for(int i = 0; i < arr_size; i++)
	{
		cin >> arr_input[i];
	}

	int* arr_rslt = new int[arr_size];
	int max = GetMaximum(arr_input, arr_size);
	CountingSort(arr_input, arr_rslt, arr_size, max);

	cout << "计数排序后数组： ";
	for(int i = 0; i < arr_size; i++)
		cout << arr_rslt[i] << " ";
	cout << endl;

	delete []arr_input;
	delete []arr_rslt;
	return 0;
}