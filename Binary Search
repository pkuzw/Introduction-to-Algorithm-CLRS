///@brief 二分查找
///@author zhaowei
///@date 2014.04.29

#include <iostream>
using namespace std;

///@brief 二分查找函数
///@param array_int 排好序的数组
///@param p 数组的起始下标
///@param r 数组的终止下标
///@param v 待查找的值
///@return 如果在数组中找到v值，则返回该值所在下标；否则返回-1
int BinarySearch(int* array_int, int p, int r, int v)
{
	if(p > r)/* || v < array_int[p] || v > array_int[r])*/
		return -1;
	int q = (p + r) / 2;
	if(v == array_int[q])
		return q;
	else if(v < array_int[q])
		BinarySearch(array_int, p, q-1, v);
	else 
		BinarySearch(array_int, q+1, r, v);
}

int main()
{
	int array_i[10] = {11,21,31,42,54,66,73,87,96,140};
	cout << "已排好序的数组： ";
	for (int i = 0; i < 10; i++)
		cout << array_i[i] << ' ';
	cout << endl;
	cout << "输入待查找的元素值： ";
	int value = 0;
	cin >> value;
	cout << "输出该元素在数组中的下标（不存在时输出-1）： ";
	int rslt = BinarySearch(array_i, 0, 9, value);
	cout << rslt << endl;

	return 0;
}
