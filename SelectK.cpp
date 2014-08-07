///@file 利用RandomPartition方法实现平均情况下O(n)的在数组中找出第k大的元素
///@author zhaowei
///@date 2014.08.07
///@version 1.0

#include <iostream>
#include <ctime>
#include <cstdlib>

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

///@brief 选取数组中第k大的元素
///@param arr 数组指针
///@param p 数组起始下标
///@param r 数组终止下标
///@param k 想要获取的元素排序大小
///@return 返回数组中第k大的元素
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

int main()
{
	int arr_len = 0;
	cout << "输入数组长度： ";
	cin >> arr_len;

	int* arr = new int[arr_len];
	cout << "输入数组元素： ";
	for(int i = 0; i < arr_len; i++)
	{
		cin >> arr[i];
	}

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


		cout << "数组中第" << k << "大的元素是： " << SelectKthNumber(arr, 0, arr_len-1, k) << endl;
		cout << endl;
	}
	delete []arr;
	return 0;
}