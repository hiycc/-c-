/*
 *假设图用邻接矩阵存储。输入图的顶点信息和边信息，完成邻接矩阵的设置，并计算各顶点的入度、出度和度，并输出图中的孤立点（度为0的顶点）

--程序要求--
若使用C++只能include一个头文件iostream；若使用C语言只能include一个头文件stdio
程序中若include多过一个头文件，不看代码，作0分处理
不允许使用第三方对象或函数实现本题的要求
输入
测试次数T，每组测试数据格式如下：

图类型  顶点数 （D—有向图，U—无向图）

顶点信息

边数

每行一条边（顶点1 顶点2）或弧（弧尾 弧头）信息

输出
每组测试数据输出如下信息（具体输出格式见样例）：

图的邻接矩阵

按顶点信息输出各顶点的度（无向图）或各顶点的出度  入度  度（有向图）。孤立点的度信息不输出。

图的孤立点。若没有孤立点，不输出任何信息。

样例输入
2
D 5
V1 V2 V3 V4 V5
7
V1 V2
V1 V4
V2 V3
V3 V1
V3 V5
V4 V3
V4 V5
U 5
A B C D E
5
A B
A C
B D
D C
A D
样例输出
0 1 0 1 0
0 0 1 0 0
1 0 0 0 1
0 0 1 0 1
0 0 0 0 0
V1: 2 1 3
V2: 1 1 2
V3: 2 2 4
V4: 2 1 3
V5: 0 2 2
0 1 1 1 0
1 0 0 1 0
1 0 0 1 0
1 1 1 0 0
0 0 0 0 0
A: 3
B: 2
C: 2
D: 3
E
 *
 *
 *
*/

#include <iostream>
#include <string>
using namespace std;

const int MaxLen=20;
class Map
{
private:
	int Vexnum;
	string data[MaxLen];
	int Matrix[MaxLen][MaxLen];
public:
	void setdata(int vnum,string Data[]);
	void link_D(string item1,string item2);
	void link_U(string item1,string item2);
	void display_matrix();
	void display_D_du();
	void display_U_du();
};
void Map::display_U_du()
{
	int i,j;
	int d;
	for(i=0;i<Vexnum;i++)
	{
		d=0;
		for(j=0;j<Vexnum;j++)
		{
			if(Matrix[i][j]==1)
				d++;
		}
		if(d!=0)
			cout<<data[i]<<":"<<d<<endl;
		else
			cout<<data[i]<<endl;
	}
}


void Map::display_D_du()
{
	int i,j,k;
	for(i=0;i<Vexnum;i++)
	{
		int in,out;
		in=0;
		out=0;
		for(j=0;j<Vexnum;j++)
		{
			if(Matrix[i][j]==1)
				out++;
		}
		for(j=0;j<Vexnum;j++)
		{
			if(Matrix[j][i]==1)
				in++;
		}
		if((in+out)==0)
			cout<<data[i]<<endl;
		else
			cout<<data[i]<<":"<<out<<" "<<in<<" "<<in+out<<endl;
	}
}

void Map::display_matrix()
{
	int i,j;
	for(i=0;i<Vexnum;i++)
	{
		for(j=0;j<Vexnum;j++)
		{
			cout<<Matrix[i][j];
			if(j!=Vexnum-1)
				cout<<" ";
		}
		cout<<endl;
	}
}


void Map::setdata(int vnum,string Data[])
{
	Vexnum = vnum;
	for(int i=0;i<MaxLen;i++)
		data[i]="";
	for(int i=0;i<Vexnum;i++)
		data[i]=Data[i];
	for(int i=0;i<MaxLen;i++)
		for(int j=0;j<MaxLen;j++)
			Matrix[i][j]=0;
}

void Map::link_U(string item1, string item2)
{
	int i,j;
	for(i=0;i<Vexnum;i++)
	{
		if(data[i]==item1)
		{
			for(j=0;j<Vexnum;j++)
			{
				if(data[j]==item2)
				{
					Matrix[i][j]=1;
					Matrix[j][i]=1;
				}
			}
		}
	}
}

void Map::link_D(string item1, string item2)
{
	int i,j;
	for(i=0;i<Vexnum;i++)
	{
		if(data[i]==item1)
		{
			for(j=0;j<Vexnum;j++)
			{
				if(data[j]==item2)
					Matrix[i][j]=1;
			}
		}
	}
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		char c;
		cin>>c;
		int n;
		cin>>n;
		string Data[MaxLen];
		string flag;
		for(int i =0;i<n;i++)
		{
			cin>>flag;
			Data[i]=flag;
		}
		Map m;
		if(c=='D')
		{
			m.setdata(n,Data);
			int l;
			cin>>l;
			while(l--)
			{
				string item1,item2;
				cin>>item1;
				cin>>item2;
				m.link_D(item1,item2);
			}
			m.display_matrix();
			m.display_D_du();
		}
		else
		{
			m.setdata(n,Data);
			int l;
			cin>>l;
			while(l--)
			{
				string item1,item2;
				cin>>item1>>item2;
				m.link_U(item1,item2);
			}
			m.display_matrix();
			m.display_U_du();
		}
	}
}
