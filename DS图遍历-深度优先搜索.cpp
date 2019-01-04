/*
给出一个图的邻接矩阵，对图进行深度优先搜索，从顶点0开始

注意：图n个顶点编号从0到n-1

输入
第一行输入t，表示有t个测试实例

第二行输入n，表示第1个图有n个结点

第三行起，每行输入邻接矩阵的一行，以此类推输入n行

第i个结点与其他结点如果相连则为1，无连接则为0，数据之间用空格隔开

以此类推输入下一个示例

输出
每行输出一个图的深度优先搜索结果，结点编号之间用空格隔开

样例输入
2
4
0 0 1 1
0 0 1 1
1 1 0 1
1 1 1 0
5
0 0 0 1 1
0 0 1 0 0
0 1 0 1 1
1 0 1 0 0
1 0 1 0 0
样例输出
0 2 1 3 
0 3 2 1 4 
*/
#include <iostream>
using namespace std;

const int MaxLen = 20;

class Map{
private:
	bool Visit[MaxLen];
	int Matrix[MaxLen][MaxLen];
	int Vexnum;
	void DFS(int v);
public:
	void SetMatrix(int vnum,int mx[MaxLen][MaxLen]);
	void DFSTraverse();
};
void Map::SetMatrix(int vnum, int mx[20][20])
{
	int i,j;
	Vexnum = vnum;
	for(i=0;i<MaxLen;i++)
		for(j=0;j<MaxLen;j++)
			Matrix[i][j] = 0;
	for(i=0;i<Vexnum;i++)
		for(j=0;j<Vexnum;j++)
			Matrix[i][j]=mx[i][j];
}
void Map::DFSTraverse()
{
	int v;
	for(v=0;v<Vexnum;v++)
		Visit[v]=false;
	for(v=0;v<Vexnum;v++)
	{
		if(!Visit[v])
			DFS(v);
	}
	cout<<endl;
}
void Map::DFS(int v)
{
	int w,i,k;
	Visit[v] = true;
	cout<<v<<" ";
	int *Adjvex = new int[Vexnum];
	for(w=0;w<Vexnum;w++)
		Adjvex[w]=-1;
	k=0;
	for(w=0;w<Vexnum;w++)
	{
		if(Matrix[v][w]==1)
			Adjvex[k++]=w;
	}
	i=0;
	for(w=Adjvex[i];w>=0;w=Adjvex[++i])
	{
		if(!Visit[w])
			DFS(w);
	}
	delete Adjvex;
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int matrix[MaxLen][MaxLen];
		for(int i=0;i<MaxLen;i++)
		{
			for(int j=0;j<MaxLen;j++)
				matrix[i][j]=0;
		}
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				cin>>matrix[i][j];

		Map m;
		m.SetMatrix(n,matrix);
		m.DFSTraverse();
	}
}
