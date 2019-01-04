/*
 *题目描述
假设某校有20间宿舍，宿舍编号101，102，...,120。每间只住一名学生。初始部分宿舍已用。用两个链表（已用宿舍链表和可用宿舍链表）维护宿舍的管理，实现宿舍分配、宿舍交回。

约定已用宿舍链表按宿舍号升序链接。初始可用宿舍链表也按宿舍号升序链接。

宿舍分配从可用宿舍链表中摘取第一间宿舍分配给学生。学生交回的宿舍挂在可用宿舍链表最后。

备注：使用list容器或静态链表。不用考虑宿舍分配和交回不成功的情况。

输入
初始宿舍状态，第一行输入n，表示已用宿舍n间

后跟n行数据，每行格式为：宿舍号 学生姓名

操作次数m，后跟m行操作，操作格式如下：

assign 学生  //为学生分配宿舍，从可用宿舍链表头摘取一间宿舍，

                    //按宿舍号升序挂在已用宿舍链表中。

return  宿舍号   //学生退宿舍，删除已用宿舍链表中对应结点，

                         //挂在可用宿舍链表尾部。

display_free   //输出可用宿舍链表信息。

display_used   //输出已用宿舍链表信息。



输出
 display_free依次输出当前可用宿舍链表中的宿舍号，具体格式见样例。

 display_used依次输出当前已用宿舍链表中的学生和宿舍号，具体格式见样例。

样例输入
5
李明  103
张三  106
王五  107
钱伟  112
章立  118
8
assign 李四
assign 赵六
return 118
return 101
assign 马山
display_used
assign 林立
display_free
样例输出
赵六(102)-李明(103)-马山(104)-张三(106)-王五(107)-钱伟(112)
108-109-110-111-113-114-115-116-117-119-120-118-101
*/


#include <iostream>
#include <string>
using namespace std;
class ListNode
{
public:
	string name;
	int num;
	ListNode *next;
	ListNode(){next=NULL;}
	~ListNode(){}
};

class List
{
private:
	ListNode *head;
	ListNode* CreatList(int n);
public:
	List()
	{
		head=new ListNode;
		head->next=NULL;
	}
	~List(){};
	void CreatList();
	void initlist(List &free,string name,int num);
	void assign(List&used,string name);
	void rb(List &free,int N);
	void display_free();
	void display_used();
};
void List::rb(List &free,int N)
{
	ListNode *p,*q;
	p = head;
	q = head->next;
	while(q->num!=N)
	{
		q = q->next;
		p = p->next;
	}
	p->next = p->next->next;
	q->name = "";
	q->next = NULL;
	ListNode *s;
	s = free.head;
	while(s->next!=NULL)
		s = s->next;
	s->next = q;
}

void List::display_used()
{
	ListNode *t;
	t = head;
	while(t->next!=NULL)
	{
		cout<<t->next->name<<"("<<t->next->num<<")";
		if(t->next->next!=NULL)
			cout<<"-";
		t = t->next;
	}
	cout<<endl;
}


void List::display_free()
{
	ListNode *t;
	t = head;
	while(t->next!=NULL)
	{
		cout<<t->next->num;
		if(t->next->next!=NULL)
			cout<<"-";
		t = t->next;
	}
	cout<<endl;
}


void List::assign(List &used,string Name)
{
	ListNode *q,*j;
	q = head;
	j = head->next;
	q->next = q->next->next;
	j->name = Name;
	ListNode *k,*v;
	k = used.head;
	v = k->next;
	while(v!=NULL)
	{
		if((v->num)>(j->num))
			break;
		else
		{
			k = k->next;
			v = v->next;
		}
	}
	j->next = v;
	k->next = j;
}

void List::initlist(List&free,string n,int N)
{
	ListNode *p,*q;
	p = free.head;
	q = p->next;
	while(q->num!=N)
	{
		q = q->next;
		p = p->next;
	}
	p->next = p->next->next;
	q->name = n;
	q->next = NULL;
	ListNode *s,*t;
	s = head;
	while(s->next!=NULL)
	{
		s = s->next;
	}
	s->next = q;

}

ListNode* List::CreatList(int n)
{
	if(n<=120)
	{
		ListNode *t;
		t = new ListNode();
		t->num = n;
		t->next = CreatList(n+1);
		return t;
	}
	else return NULL;
}

void List::CreatList()
{
	head->next = CreatList(101);
}

int main()
{
	List free;
	free.CreatList();
	List used;
	int n;
	cin>>n;
	while(n--)
	{
		string name;
		int num;
		cin>>name;
		cin>>num;
		used.initlist(free,name,num);
	}
	int t;
	cin>>t;
	while(t--)
	{
		string act;
		cin>>act;
		if(act=="assign")
		{
			string name;
			cin>>name;
			free.assign(used,name);
		}
		else if(act=="return")
		{
			int num;
			cin>>num;
			used.rb(free,num);
		}
		else if(act=="display_used")
		{
			used.display_used();
		}
		else
		{
			free.display_free();
		}
	}
}
