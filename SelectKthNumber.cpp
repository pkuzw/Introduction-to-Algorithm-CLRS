///@file 利用RandomPartition方法实现平均情况下O(n)的在数组中找出第K小的元素
///@author zhaowei
///@date 2014.08.07
///@version 1.0

///@file 添加迭代版的随机化选择第K小的数的方法
///@author zhaowei
///@date 2014.08.09
///@version 1.1

///@file 在划分子数组时，确保选择的是5个一组的子数组的中位数的中位数，这样在最坏情况下，算法的时间复杂度不超过O(n)
//       这个程序实现目前还有问题，不能正常运行。会循环递归直至Stack Overflow.
///@author zhaowei
///@date 2014.08.11
///@version 1.2

#include <iostream>
#include <ctime>
#include <cstdlib>
#include "SelectKthNumber.h"

using namespace std;

///@brief 交换两个元素
///@param a, b 交换的两个元素
///@author zhaowei
///@date 2014.08.07
///@version 1.0
void Swap(int& a, int& b)
{
	int tmp = 0;
	
	tmp = b;
	b = a;
	a = tmp;

	return;
}

///@brief 快速排序中的划分函数
///@param arr 数组指针
///@param p 数组起始下标
///@param r 数组终止下标
///@return 返回数组中的主元素下标
///@author zhaowei
///@date 2014.08.07
///@version 1.0
int Partition(int* arr, int p, int r)
{
	int x = arr[r];
	int i = p-1;
	for(int j = p; j <= r-1; j++)
	{
		if(arr[j] <= x)
		{
			i++;
			Swap(arr[i], arr[j]);
		}
	}
	Swap(arr[i+1], arr[r]);
	return i+1;
}

///@brief 获取在[p, r]范围内的随机数
///@param seed 随机种子
///@param p 随机数范围的下限
///@param r 随机数范围的上限
///@return 返回范围在[p, r]之间的随机数
///@author zhaowei
///@date 2014.08.07
///@version 1.0
int Random(int seed, int p, int r)
{
	srand(seed);
	int mod = r - p + 1;

	int rand_num = (rand() % mod) + p;

	return rand_num;
}

///@brief 随机Partition
///@param arr 数组元素
///@param p 数组起始元素下标
///@param r 数组终止元素下标
///@author zhaowei
///@date 2014.08.07
///@version 1.0
int RandomPartion(int* arr, int p, int r)
{
	int i = Random((int)(time(0)), p, r);
	Swap(arr[i], arr[r]);

	return Partition(arr, p, r);
}

///@brief 选取数组中第K小的元素
///@param arr 数组指针
///@param p 数组起始下标
///@param r 数组终止下标
///@param i 想要获取的元素排序大小
///@return 返回数组中第K小的元素
///@author zhaowei
///@date 2014.08.07
///@version 1.0
int SelectKthNumber(int* arr, int p, int r, int i)
{
	if(p == r)
		return arr[p];

	int q = RandomPartion(arr, p, r);

	int k = q-p+1;

	if(i == k)
		return arr[q];

	else if(i < k)
		return SelectKthNumber(arr, p, q-1, i);

	else
		return SelectKthNumber(arr, q+1, r, i-k);
}

///@brief 迭代版选取第K小的数
///@param arr 数组指针
///@param p 数组起始下标
///@param r 数组终止下标
///@param i 想要选取的数组中第K小的数
///@author zhaowei
///@date 2014.08.09
///@version 1.0
int SelectKthNumberIter(int* arr, int p, int r, int i)
{
	int q = 0;
	while(p < r)
	{
		q = RandomPartion(arr, p, r);
		int k = q - p + 1;

		if(i == k)
			return arr[q];

		else if(i < k)
			r = q - 1;	//调低上限，元素排位不变

		else
		{
			p = q + 1;	//调高下限
			i = i - k;	//相应调整在新子数组中的元素排位
		}
	}
	return arr[p];
}



///@brief 将一个ArrayElem变量的值赋给另一个ArrayElem变量
///@param a 赋值的ArrayElem变量
///@param b 被赋值的ArrayElem变量
///@author zhaowei
///@date 2014.08.11
///@version 1.0
void AssignArrayElem(ArrayElem& a, ArrayElem& b)
{
	b.value = a.value;
	b.index = a.index;
}

///@brief 对ArrayElem结构体类型的数组进行插入排序，比较的键值是原始数组中的值大小
///@param arr_struct
///@param p 数组起始下标
///@param r 数组终止下标
///@author zhaowei
///@date 2014.08.11
///@version 1.0
void InsertionSort(ArrayElem* arr_struct, int p, int r)
{
	for(int j = p+1; j <= r; j++)
	{
		int i = j-1;
		ArrayElem tmp;
		AssignArrayElem(arr_struct[j], tmp);
		while(i >= p && arr_struct[i].value > tmp.value)
		{
			AssignArrayElem(arr_struct[i], arr_struct[i+1]);
			i--;
		}
		AssignArrayElem(tmp, arr_struct[i+1]);
	}
	return;
}


///@brief 选择第K大的元素
///@param arr 数组指针
///@param p 数组起始下标
///@param r 数组终止下标
///@param sub_arr_size 子数组大小
///@param i 想要选择的元素的排位
///@return 返回第K大元素
///@author zhaowei
///@date 2014.08.11
///@version 1.0
ArrayElem SelectKthElement(ArrayElem* arr, int p, int r, int sub_arr_size, int i)
{
	if(p == r)
		return arr[p];
	ArrayElem median = SelectMedian(arr, p, r, sub_arr_size);
	int k = median.index - arr[p].index + 1;	//问题在这里，递归时元素的下标已经改变了.
	if(i == k)
		return median;
	else if(i < k)
		return SelectKthElement(arr, p, median.index - 1, sub_arr_size, i);
	else
		return SelectKthElement(arr, median.index + 1, r, sub_arr_size, i - k);
}

///@brief 选出若干子数组的中位数的中位数
///@param arr 数组指针
///@param p 数组起始下标
///@param r 数组终止下标
///@param sub_arr_size 子数组大小
///@return 返回子数组的中位数的中位数的下标
///@author zhaowei
///@date 2014.08.11
///@version 1.0
ArrayElem SelectMedian(ArrayElem* arr, int p, int r, int sub_arr_size)
{
	//将原数组的值连通其数组下标一起保存在临时结构体数组中，便于最后返回中位数的中位数在原始数组中的下标
	int arr_len = r - p + 1;
	
	ArrayElem* arr_struct = new ArrayElem[arr_len];
	
	for(int i = 0; i < arr_len; i++)
	{
		AssignArrayElem(arr[p + i], arr_struct[i]);
	}
	
	//先对按照sub_arr_size划分好的若干子数组进行插入排序
	int sub_arr_num = 0;
	if(arr_len % sub_arr_size == 0)
		sub_arr_num = arr_len / sub_arr_size;
	else
		sub_arr_num = arr_len / sub_arr_size + 1;
	for(int i = 0; i < sub_arr_num - 1; i++)
	{
		InsertionSort(arr_struct, p + i * sub_arr_size, p + (i + 1) * sub_arr_size - 1);
	}
	//处理最后一个子数组，分为两种情况：能够被子数组大小整除和不能够被子数组大小整除
	int last_sub_arr_len = arr_len % sub_arr_size;

	if(last_sub_arr_len == 0)
		InsertionSort(arr_struct, r - sub_arr_size + 1, r);
	else
		InsertionSort(arr_struct, r - last_sub_arr_len + 1, r);

	//将子数组的中位数放入新开辟的动态数组arr_median
	ArrayElem* arr_median = new ArrayElem[sub_arr_num];
	for(int i = 0; i < sub_arr_num - 1; i++)
		arr_median[i] = arr_struct[p + i * sub_arr_size + (sub_arr_size - 1) / 2];

	if(last_sub_arr_len == 0)
		arr_median[sub_arr_num - 1] = arr_struct[r - sub_arr_size / 2];
	else
		arr_median[sub_arr_num - 1] = arr_struct[r - last_sub_arr_len / 2];
	
	//递归调用选取第K大元素方法，来选出中位数数组的中位数
	return SelectKthElement(arr_median, 0, sub_arr_num - 1, sub_arr_size, (sub_arr_num - 1) / 2);
}




int main()
{
	int arr_len = 0;
	cout << "输入数组长度： ";
	cin >> arr_len;

	int* arr = new int[arr_len];
	ArrayElem* arr_arr_elem = new ArrayElem[arr_len];
	cout << "输入数组元素： ";
	for(int i = 0; i < arr_len; i++)
	{
		cin >> arr[i];
		arr_arr_elem[i].value = arr[i];
		arr_arr_elem[i].index = i;
	}

	int sub_arr_size = 0;
	cout << "输入子数组的大小： ";
	cin >> sub_arr_size;

	while(1)
	{
		cout << "输入想要获取的元素排位（从1开始）： ";
		int k = 0;
		cin >> k;

		while(k < 1 || k > arr_len)
		{
			cout << "想要获取的元素排位超出了数组长度范围，请重新输入： ";
			cin >> k;
		}


		cout << "用递归版选择函数后，数组中第";
		cout << k << "小的元素是： " << SelectKthNumber(arr, 0, arr_len-1, k) << endl;
		cout << endl;

		cout << "用迭代版选择函数后，数组中第";
		cout << k << "小的元素是： " << SelectKthNumberIter(arr, 0, arr_len-1, k) << endl;		
		cout << endl;

// 		ArrayElem rslt = SelectKthElement(arr_arr_elem, 0, arr_len-1, sub_arr_size, k);
// 		cout << "用选中位数的中位数方法分割子数组，数组中第";
// 		cout << k << "小的元素是： " << rslt.value << "。它在原始数组中的下标是： " << rslt.index << endl;		
// 		cout << endl;



	}
	delete []arr;
	return 0;
}