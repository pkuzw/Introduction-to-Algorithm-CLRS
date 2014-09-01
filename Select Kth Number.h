///@brief 保存数组下标和数组值的临时结构体
///@author zhaowei
///@date 2014.08.11
///@version 1.0
struct ArrayElem
{
	int value;
	int index;
};

void AssignArrayElem(ArrayElem& a, ArrayElem& b);
void InsertionSort(ArrayElem* arr_struct, int p, int r);
ArrayElem SelectKthElement(ArrayElem* arr, int p, int r, int sub_arr_size, int i);
ArrayElem SelectMedian(ArrayElem* arr, int p, int r, int sub_arr_size);
