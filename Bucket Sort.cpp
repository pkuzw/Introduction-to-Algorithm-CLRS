///@file 桶排序
///@auhtor zhaowei
///@date 2014.08.04
///@version 1.0

#include <iostream>
using namespace std;

///@brief 双向链表结点类
class BucketNode
{
private:
	BucketNode* prev;	//头指针指向前一个结点
	BucketNode* next;	//尾指针指向后一个结点
	double value;		//该结点中的数值

public:
	BucketNode()
	{
		prev = NULL;
		next = NULL;
		value = -1;
	}

	//获取结点数值
	double GetValue()
	{
		return value;
	}

	//设置结点数值
	void SetValue(const double val)
	{
		if(val < 0)
			return;
		value = val;
	}

	//获取下一结点指针
	BucketNode* GetNextNode()
	{
		return next;
	}

	//设置下一结点指针
	void SetNextNode(BucketNode* next_bucket)
	{
		if(next_bucket == NULL)
			return;
		next = next_bucket;
	}

	//获取前一个结点
	BucketNode* GetPrevNode()
	{

		return prev;
	}

	//设置前一个结点
	void SetPrevNode(BucketNode* prev_bucket)
	{
		if(prev_bucket == NULL)
			return;
		prev = prev_bucket;
	}

	//添加下一个结点
	void AddNextNode(BucketNode* new_node)
	{
		if(next == NULL)
		{
			this->SetNextNode(new_node);
		}
		else
		{
			new_node->SetNextNode(next);
			next->SetPrevNode(new_node);

			this->SetNextNode(new_node);			
		}
		new_node->SetPrevNode(this);
	}

	//添加前一个结点
	void AddPrevNode(BucketNode* new_node)
	{
		if(prev == NULL)
			this->SetPrevNode(new_node);
		else
		{
			new_node->SetPrevNode(prev);
			prev->SetNextNode(new_node);

			this->SetPrevNode(new_node);
		}
		new_node->SetNextNode(this);
	}
};

///@brief 对待排序数组进行桶排序
///@param dbl_arr 待排序的double型数组，该数组中的元素都为[0, 1）区间上的小数
///@param arr_len 数组长度
///@param bucket_num 桶数目
///@return 返回桶排序后的数组
///@author zhaowei
///@date 2014.08.04
///@version 1.0
double* BucketSort(double* dbl_arr, const int arr_len, const int bucket_num)
{
	BucketNode** buckets = new BucketNode*[bucket_num];

	
	for(int i = 0; i < bucket_num; i++)
	{		
		buckets[i] = new BucketNode;	//将每个桶链表中第一个元素初始化
	}
	
	for(int i = 0; i < arr_len; i++)
	{
		//根据元素值大小放入相应桶中
		for(int j = 0; j < bucket_num; j++)
		{
			double j_t = j;
			double bn_t = bucket_num;
			double low_bound = (j_t/bn_t);
			double up_bound = (j_t+1)/bn_t;
			if(dbl_arr[i] >= low_bound && dbl_arr[i] < up_bound)
			{
				BucketNode* crnt_node_ptr = buckets[j];
				BucketNode* new_node = new BucketNode;
				new_node->SetValue(dbl_arr[i]);
				bool flag = false;
				while(new_node->GetValue() >= crnt_node_ptr->GetValue())
				{
					if(crnt_node_ptr->GetNextNode() != NULL)
						crnt_node_ptr = crnt_node_ptr->GetNextNode();
					else
					{
						crnt_node_ptr->AddNextNode(new_node);
						crnt_node_ptr = crnt_node_ptr->GetNextNode();
						flag = true;
						break;	//已找到相应的链表插入位置，结束while循环
					}
				}
				if(!flag)	// 当第一次插入链表时，不允许在头元素之前再插入元素
					crnt_node_ptr->AddPrevNode(new_node);
				break;	//已找到相应桶，结束内层循环
			}
		}		
	}

	double* sorted_arr = new double[arr_len];
	int k = 0;
	for(int i = 0; i < bucket_num; i++)
	{
		BucketNode* cur_node_ptr = buckets[i];
		while(cur_node_ptr->GetNextNode() != NULL && cur_node_ptr->GetNextNode()->GetValue() != -1)
		{
			sorted_arr[k++] = cur_node_ptr->GetNextNode()->GetValue();	//因为首结点是头节点，不含实际数据
			cur_node_ptr = cur_node_ptr->GetNextNode();
		}		
		if(cur_node_ptr->GetValue() != -1)
			sorted_arr[k] = cur_node_ptr->GetValue();
	}

	return sorted_arr;
}

int main()
{
	int arr_len = 0;
	cout << "输入待排序数组大小： ";
	cin >> arr_len;

	double* arr = new double[arr_len];

	cout << "输入待排序数组（每个元素值应大于等于0，小于1）： ";
	for(int i = 0; i < arr_len; i++)
		cin >> arr[i];

	//测试样例 0.78 0.17 0.39 0.26 0.72 0.94 0.21 0.12 0.23 0.68
	int bucket_cnt = 0;
	cout << "输入桶排序的桶数目： ";
	cin >> bucket_cnt;

	double* rslt = BucketSort(arr, arr_len, bucket_cnt);

	cout << "输出桶排序后的数组： ";
	for(int i = 0; i < arr_len; i++)
		cout << rslt[i] << " ";
	cout << endl;
	delete []arr;
	return 0;
}