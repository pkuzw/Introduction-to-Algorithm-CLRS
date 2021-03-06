///@brief  P22 练习2.3-2 
///        改写MERGE过程，使之不使用哨兵元素，而是在一旦数组L或R中的所有元素都被复制回数组A后，就立即停止，
///        再将另一个数组中余下的元素复制回数组A中。
///@author zhaowei
///@date 2014.04.29


#include <iostream>
using namespace std;

void Merge(int* array_int, int p, int q, int r)
{
	int n1 = q - p + 1;
	int n2 = r - q;
	int * array_l = new int[n1];
	int * array_r = new int[n2];
	int i, j, k, m1, m2;
	for(i = 0; i < n1; i++)
	{
		array_l[i] = array_int[p + i];	//此处和《算法导论》P17伪代码有所不同
	}

	for(j = 0; j < n2; j++)
	{
		array_r[j] = array_int[q + j + 1];//此处和《算法导论》P17伪代码有所不同
	}

	i = 0;
	j = 0;

	for(k = p; k < r; k++)
	{
		if(array_l[i] <= array_r[j])
		{
			array_int[k] = array_l[i];
			i++;
			// 将剩余元素复制回原数组
			if(i >= n1)
			{			
				for(m1 = j; m1 < n2; m1++)
				{
					array_int[++k] = array_r[m1];
				}
				break;
			}
		}
		else
		{
			array_int[k] = array_r[j];
			j++;
			// 将剩余元素复制回原数组
			if(j >= n2)
			{
				for(m2 = i; m2 < n1; m2++)
				{
					array_int[++k] = array_l[m2];
				}
				break;
			}
		}
	}
	delete []array_l;
	delete []array_r;
}

void MergeSort(int * array_int, int p, int r)
{
	if(p < r)
	{
		int q = (p+r)/2;
		MergeSort(array_int, p, q);
		MergeSort(array_int, q+1, r);
		Merge(array_int, p, q, r);
	}
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

	MergeSort(array_i, 0, array_count-1);

	cout << "输出排好序后的数组： ";
	for(int i = 0; i < array_count; i++)
		cout << array_i[i] << " ";
	cout << endl;

	delete []array_i;
	return 0;
}
