///@file 桶排序
///@auhtor zhaowei
///@date 2014.08.04
///@version 1.0

#include <iostream>
using namespace std;

///@brief 链表结点类
class BucketNode
{
private:
	BucketNode* prev;
	BucketNode* next;
	double value;

public:
	double GetValue()
	{
		return value;
	}

	void SetValue(const double val)
	{
		value = val;
	}

	BucketNode* GetNextNode()
	{
		return next;
	}

	void SetNextNode(BucketNode* next_bucket)
	{
		next = next_bucket;
	}

	BucketNode* GetPrevNode()
	{
		return prev;
	}

	void SetPrevNode(BucketNode* prev_bucket)
	{
		prev = prev_bucket;
	}

	void AddNode(BucketNode* new_node)
	{
		SetNextNode(new_node);
		new_node->SetPrevNode(this);
	}
};

///@brief 对待排序数组进行桶排序
///@param dbl_arr 待排序的double型数组，该数组中的元素都为[0, 1]区间上的小数
///@param arr_len 数组长度
///@param bucket_num 桶数目
///@author zhaowei
///@date 2014.08.04
///@version 1.0
void BucketSort(double* dbl_arr, const int arr_len, const int bucket_num)
{
	BucketNode** buckets = new BucketNode*[bucket_num];
	for(int i = 0; i < bucket_num; i++)
	{		
		buckets[i]->SetPrevNode(NULL);	//将每个桶链表中第一个元素的头指针设为空
	}
	for(int i = 0; i < arr_len; i++)
	{
		if(dbl_arr[i] >= 0 && dbl_arr[i] < 1/bucket_num)
		{
			
		}
	}

}

int main()
{
	return 0;
}