/*
 *给定一个图的邻接矩阵，请判断该图是否是连通图。连通图：任意两个顶点之间都有路径。
--程序要求--
若使用C++只能include一个头文件iostream；若使用C语言只能include一个头文件stdio
程序中若include多过一个头文件，不看代码，作0分处理
不允许使用第三方对象或函数实现本题的要求
输入
第1行输入一个整数k，表示有k个测试数据
第2行输入一个整数n，表示有n个结点
从第3行起到第n+2行输入一个邻接矩阵，其中Matrix[i,j]=1表示第i，j个结点之间有边，否则不存在边。
接下来是第2到第k个测试数据的结点数和邻接矩阵
输出
输出Yes or No表示图是否是强连通图
样例输入
2
4
0 1 1 1 
1 0 1 1 
1 1 0 1 
1 1 1 0 
7
0 1 0 0 0 0 0 
0 0 1 1 0 0 0 
1 0 0 0 0 0 0 
1 0 1 0 0 0 0 
0 0 0 0 0 1 1 
0 1 0 0 0 0 0 
0 0 0 1 0 1 0 
样例输出
Yes
No
*/

#include <iostream>
using namespace std;

const int MaxLen = 20;

class Map
{
private:
	int Matrix[MaxLen][MaxLen];
	int Vexnum;
	bool Visit_U[MaxLen];
	bool Visit_D[MaxLen][MaxLen];
	bool isD;
public:
	int count;
	void SetMatrix(int vnum,int matrix[MaxLen][MaxLen]);
	void DFS_U(int i);
	void DFS_D(int i);
	int judge();
};
int Map::judge()
{
	if(isD==true)
	{
		DFS_D(0);
		int i,j;
		for(i=0;i<Vexnum;i++)
			for(j=0;j<Vexnum;j++)
				if(Visit_D[i][j]==0)
					return 0;
		return 1;
	}
	else
	{
		DFS_U(0);
		if(count==Vexnum-1)
			return 1;
		else
			return 0;
	}
}

void Map::DFS_D(int i)
{
	for(int j=0;j<Vexnum;j++)
	{
		if(Matrix[i][j]==1&&Visit_D[i][j]==false)
		{
			Visit_D[i][j]=true;
			DFS_D(j);
		}
	}
}


void Map::DFS_U(int i)
{
	Visit_U[i]=true;
	for(int j=0;j<Vexnum;j++)
	{
		if(Matrix[i][j]==1&&Visit_U[j]==false)
		{
			count++;
			DFS_U(j);
		}
	}
}


void Map::SetMatrix(int vnum,int matrix[MaxLen][MaxLen])
{
	Vexnum = vnum;
	count = 0;
	int i,j;
	for(i=0;i<MaxLen;i++)
		Visit_U[i]=false;
	for(i=0;i<MaxLen;i++)
		for(j=0;j<MaxLen;j++)
		{
			if(i==j)
				Visit_D[i][j]=1;
			else
				Visit_D[i][j]=0;
		}
	for(i=0;i<MaxLen;i++)
		for(j=0;j<MaxLen;j++)
			Matrix[i][j]=0;
	for(i=0;i<Vexnum;i++)
		for(j=0;j<Vexnum;j++)
			Matrix[i][j] = matrix[i][j];
	for(i=0;i<Vexnum;i++)
		for(j=0;j<Vexnum;j++)
			if(Matrix[i][j]!=Matrix[j][i])
				isD=true;
			else
				isD=false;
}

int main()
{
	int k;
	cin>>k;
	while(k--)
	{
		int n;
		cin>>n;
		int matrix[MaxLen][MaxLen];
		int i,j;
		for(i=0;i<MaxLen;i++)
			for(j=0;j<MaxLen;j++)
				matrix[i][j]=0;
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				cin>>matrix[i][j];
		Map m;
		m.SetMatrix(n,matrix);
		if(m.judge()==1)
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl;
	}
}
