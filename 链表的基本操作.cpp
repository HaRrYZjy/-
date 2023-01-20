#include <bits/stdc++.h>
using namespace std;

typedef struct LNode{
	int data;
	struct LNode* next;
	
}Node,*LinkList;

void creatlist(LinkList &head,int n);//创建链表
void showlist(LinkList head);//展示链表
void my_get(int n2,LinkList head);//查链表指定位置数据
bool my_transform(LinkList &head,int n2,int data);//改链表指定数据
bool my_delete(int n3,LinkList &head);//删除链表指定数据
bool my_insert(LinkList &head,int n3,int n4);//指定链表位置添加数据
/////////////////////////////////////////////////////


int main(void)
{
	int n;
	cout<<"请输入创建链表长度：";
	cin>>n;
	LinkList head;
	creatlist(head,n);
	int m;
	string s;
	cout<<"请输入需要的操作（增：insert；删：delete；改：transform；查：get;显示整个链表数据；退出：exit）：";
	while(cin>>s&&s!="exit"){
		if(s=="get"){
			int n2;
			cout<<"请输入需要查取数据的位置：";
			cin>>n2;
			my_get(n2,head);
		}
		else if(s=="delete"){
			int n1;
			cout<<"请输入需要删除数据的位置：";
			cin>>n1;
			if(my_delete(n1,head)){
				cout<<"delete OK!"<<endl;
			}
			else{
				cout<<"delete fail."<<endl;
			}
			
		}
		else if(s=="insert"){
			int n3,n4;
			cout<<"请输入需要增添数据的位置以及数据值：";
			cin>>n3>>n4;
			if(my_insert(head,n3,n4)){
				cout<<"insert OK!"<<endl;
			}
			else{
				cout<<"insert fail."<<endl;
			}
		}
		else if(s=="show"){
			showlist(head);
		}
		else if(s=="transform"){
			int n5,n6;
			cout<<"请输入需要更改的数据位置以及更改后的数据值：";
			cin>>n5>>n6;
			if(my_transform(head,n5,n6)){
				cout<<"transform OK!"<<endl;
			}
			else{
				cout<<"transform fail."<<endl;
			}
		}
	}
	return 0;
	
}

///////////////////////////////////////////////////////////

//创建链表
void creatlist(LinkList &head,int n){
	LinkList p2,tail;
	int dt;
	p2=(LinkList)malloc(sizeof(LNode));
	cout<<"请输入数据：";
	cin>>dt;
	p2->data=dt;
	p2->next=NULL;
	head=p2;
	tail=head;
	for(int i=1;i<n;i++){
		p2=(LinkList)malloc(sizeof(LNode));
		cout<<"请输入数据：";
		cin>>dt;
		p2->data=dt;
		p2->next=NULL;
		tail->next=p2;
		tail=p2;
	}
}

//展示链表
void showlist(LinkList head){
	LinkList tail=head;
	while(tail){
		cout<<tail->data<<" ";
		tail=tail->next;
	}
	cout<<endl;
}

//查链表指定位置数据
void my_get(int n2,LinkList head){
	LinkList p1=head;
	for(int i=1;i<n2;i++){
		if(!p1->next){
			cout<<"get fail"<<endl;
			return;
		}
		p1=p1->next;
	}
	cout<<"查到的数据值为："<<p1->data<<endl;
	
}

//改链表指定数据
bool my_transform(LinkList &head,int n2,int data){
	LinkList p1=head;
	for(int i=1;i<n2;i++){
		if(!p1->next){
			return 0;
		}
		p1=p1->next;
	}
	p1->data=data;
	return 1;
	
}

//删除链表指定数据
bool my_delete(int n3,LinkList &head){
	LinkList p1=head,p2=NULL;
	if(n3==1){
		head=head->next;
		free(p1);
		return 1;
	}
	int j=1;
	while(j<n3-1&&p1->next){
		p1=p1->next;
		++j;
	}
	if(!(p1->next)||j>n3-1){
		return 0;
	}
	p2=p1->next;
	p1->next=p2->next;
	p2->next=NULL;
	return 1;
}

//指定链表位置添加数据
bool my_insert(LinkList &head,int n3,int n4){
	LinkList p1=head,p2;
	p2=(LinkList)malloc(sizeof(Node));
	p2->data=n4;
	if(n3==1){
		p2->next=head;
		head=p2;
		return 1;
	}
		int j=1;
		while(j<n3-1&&p1->next){
			p1=p1->next;
			++j;
		}
		if(!(p1->next)||j>n3-1){
			return 0;
		}
		p2->next=p1->next;
		p1->next=p2;
		return 1;
}



