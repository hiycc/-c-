/*
 *题目描述
给出一个数据序列，建立二叉排序树，并实现插入功能

对二叉排序树进行中序遍历，可以得到有序的数据序列

输入
第一行输入t，表示有t个数据序列

第二行输入n，表示首个序列包含n个数据

第三行输入n个数据，都是自然数且互不相同，数据之间用空格隔开

第四行输入m，表示要插入m个数据

从第五行起，输入m行，每行一个要插入的数据，都是自然数且和前面的数据不等

以此类推输入下一个示例

输出
第一行输出有序的数据序列，对二叉排序树进行中序遍历可以得到

从第二行起，输出插入第m个数据后的有序序列，输出m行

以此类推输出下一个示例的结果


样例输入
1
6
22 33 55 66 11 44
3
77
50
10
样例输出
11 22 33 44 55 66 
11 22 33 44 55 66 77 
11 22 33 44 50 55 66 77 
10 11 22 33 44 50 55 66 77 
*/

#include<iostream>
using namespace std;

class BiTreeNode
{
public:
	int data;
	BiTreeNode *Lc;
	BiTreeNode *Rc;
	BiTreeNode(){Lc=NULL;Rc=NULL;}
	~BiTreeNode(){}
};

class BiTree
{
private:
	
	int arr[20];
	int len;
public:
	BiTree(){Root= NULL;}
	BiTreeNode *Root;
	void CreatTree(int Len,int Arr[20]);
	void insert(int item);
	void display(BiTreeNode *t);
};

void BiTree::display(BiTreeNode *t)
{
	if(t!=NULL)
	{
		display(t->Lc);
		cout<<t->data<<" ";
		display(t->Rc);
	}
}


void BiTree::insert(int item)
{
	BiTreeNode *t,*p;
	p = NULL;
	t = Root;
	while(t!=NULL)
	{
		p = t;
		if(t->data<item)
			t = t->Rc;
		else
			t= t->Lc;
	}
	t = new BiTreeNode();
	t->data = item;
	if(p==NULL)
	{
		Root = t;
	}
	else
	{
		if(item>p->data)
			p->Rc = t;
		else
			p->Lc = t;
	}
}



void BiTree::CreatTree(int Len,int Arr[20])
{
	len = Len;
	for(int i=0;i<20;i++)
		arr[i]=0;
	for(int i =0; i<len;i++)
		arr[i]=Arr[i];
	int i=0;
	while(arr[i]!=0)
	{
		insert(arr[i]);
		i++;
	}
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int *arr;
		arr = new int[20];
		for(int i=0;i<20;i++)
			arr[i]=0;
		for(int i=0;i<n;i++)
		{
			cin>>arr[i];
		}
		BiTree b;
		b.CreatTree(n,arr);
		b.display(b.Root);
		cout<<endl;
		int m;
		cin>>m;
		while(m--)
		{
			int item;
			cin>>item;
			b.insert(item);
			b.display(b.Root);
			cout<<endl;
		}
	}
}

