/*
 *题目描述
给出一个队列和要查找的数值，找出数值在队列中的位置，队列位置从1开始

要求使用折半查找算法

输入
第一行输入n，表示队列有n个数据
第二行输入n个数据，都是正整数，用空格隔开
第三行输入t，表示有t个要查找的数值
第四行起，输入t个数值，输入t行

输出
每行输出一个要查找的数值在队列的位置，如果查找不成功，输出字符串error

样例输入
8
11 22 33 44 55 66 77 88
3
22
88
99
样例输出
2
8
error
*/
#include <iostream>
using namespace std;

const int MaxLen = 20;

class Array
{
private:
	int array[MaxLen];
	int length;
public:
	Array(int Length);
	void setArray(int Array[MaxLen]);
	int find(int item);
};

int Array::find(int item)
{
	int low,high,mid;
	low=1;
	high = length;
	while(low<=high)
	{
		mid = (low+high)/2;
		if(item==array[mid])
			return mid;
		else if(item<array[mid])
			high=mid-1;
		else
			low = mid+1;
	}
	return 0;
}


void Array::setArray(int Array[20])
{
	for(int i=1;i<=length;i++)
		array[i] = Array[i-1];
}

Array::Array(int Length)
{
	length = Length;
	for(int i=0;i<MaxLen;i++)
		array[i] = 0;
}

int main()
{
	int n;
	cin>>n;
	int matrix[MaxLen];
	int i;
	for(i=0;i<MaxLen;i++)
		matrix[i]=0;
	for(i=0;i<n;i++)
		cin>>matrix[i];
	Array a(n);
	a.setArray(matrix);
	int t;
	cin>>t;
	while(t--)
	{
		int item;
		cin>>item;
		if(a.find(item)!=0)
			cout<<a.find(item)<<endl;
		else
			cout<<"error"<<endl;
	}
}
