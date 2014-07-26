///@brief 测试随机数生成函数
///@author zhaowei
///@date 2014.07.24

#include <iostream>
#include <cstdlib>	//包含随机数函数的头文件
#include <ctime>	//包含有系统时间调用接口的头文件

using namespace std;

///@brief  生成指定范围的随机数，且保证每次调用产生的随机数不一样
///@param seed 随机种子
///@param p 随机数范围下限
///@param r 随机数范围上限
///@return 返回产生的随机数
///@author zhaowei
///@date 2014.07.24
int Random(int seed, const int p, const int r)
{
	//设置随机数种子
	srand(seed);

	int mod = r - p + 1;
	int rdm = (rand() % mod) + p;

	return rdm;
}

int main()
{
	for(int i = 0; i < 10; i++)
	{
		cout << "random number " << i << ": " << Random((int)time(0), 0, 100) << endl;

		// 添加一个for循环，以增大两次调用取系统时间方法的间隔
		for(int j= 0; j < 1000000000; j++)
		{
			int k = 0;
			k++;
		}
	}
	return 0;
}