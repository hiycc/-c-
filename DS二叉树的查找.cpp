/**
 *
 *题目描述
给出一个数据序列，建立二叉排序树，并实现查找功能

对二叉排序树进行中序遍历，可以得到有序的数据序列

输入
第一行输入t，表示有t个数据序列

第二行输入n，表示首个序列包含n个数据

第三行输入n个数据，都是自然数且互不相同，数据之间用空格隔开

第四行输入m，表示要查找m个数据

从第五行起，输入m行，每行一个要查找的数据，都是自然数

以此类推输入下一个示例

输出
第一行输出有序的数据序列，对二叉排序树进行中序遍历可以得到

从第二行起，输出查找结果，如果查找成功输出查找次数，如果查找失败输出-1

以此类推输出下一个示例的结果

样例输入
1
6
22 33 55 66 11 44
7
11
22
33
44
55
66
77
样例输出
11 22 33 44 55 66 
2
1
2
4
3
4
-1
 */

#include <iostream>
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
	BiTreeNode *Root;
public:
	BiTree(){Root =NULL;}
	~BiTree(){};
	void CreatTree(int l,int Arr[20]);
	void insert(int item);
	int search(int item);
	void display(BiTreeNode *t);
	BiTreeNode* getroot();
};

BiTreeNode* BiTree::getroot()
{
	return Root;
}


void BiTree::display(BiTreeNode* t)
{
	if(t!=NULL)
	{
		display(t->Lc);
		cout<<t->data<<" ";
		display(t->Rc);
	}
}


int BiTree::search(int item)
{
	int flag;
	flag =0;
	BiTreeNode *t;
	t = Root;
	while(t!=NULL)
	{
		flag++;
		if(t->data==item)
			return flag;
		else if(t->data>item)
			t = t->Lc;
		else
			t= t->Rc;
	}
	return -1;
}


void BiTree::insert(int item)
{
	BiTreeNode *t,*p;
	t = Root;
	p = NULL;
	while(t!=NULL)
	{
		p = t;
		if(t->data>item)
			t = t->Lc;
		else
			t = t->Rc;
	}
	t = new BiTreeNode();
	t->data = item;
	if(p==NULL)
		Root = t;
	else
	{
		if(p->data>item)
			p->Lc = t;
		else
			p->Rc = t;
	}
}

void BiTree::CreatTree(int l,int Arr[20])
{
	len = l;
	for(int i=0;i<20;i++)
		arr[i]=0;
	for(int i=0;i<len;i++)
		arr[i]=Arr[i];
	int i;
	i=0;
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
		int Arr[20];
		for(int i=0;i<20;i++)
			Arr[i]=0;
		for(int i=0;i<n;i++)
			cin>>Arr[i];
		BiTree b;
		b.CreatTree(n,Arr);
		b.display(b.getroot());
		cout<<endl;
		int m;
		cin>>m;
		while(m--)
		{
			int item;
			cin>>item;
			cout<<b.search(item)<<endl;
		}

	}
}

