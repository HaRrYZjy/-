#include <bits/stdc++.h>
using namespace std;

typedef struct LNode{
	int data;
	struct LNode* next;
	
}Node,*LinkList;

void creatlist(LinkList &head,int n);//��������
void showlist(LinkList head);//չʾ����
void my_get(int n2,LinkList head);//������ָ��λ������
bool my_transform(LinkList &head,int n2,int data);//������ָ������
bool my_delete(int n3,LinkList &head);//ɾ������ָ������
bool my_insert(LinkList &head,int n3,int n4);//ָ������λ���������
/////////////////////////////////////////////////////


int main(void)
{
	int n;
	cout<<"�����봴�������ȣ�";
	cin>>n;
	LinkList head;
	creatlist(head,n);
	int m;
	string s;
	cout<<"��������Ҫ�Ĳ���������insert��ɾ��delete���ģ�transform���飺get����";
	while(cin>>s&&s!="exit"){
		if(s=="get"){
			int n2;
			cout<<"��������Ҫ��ȡ���ݵ�λ�ã�";
			cin>>n2;
			my_get(n2,head);
		}
		else if(s=="delete"){
			int n1;
			cout<<"��������Ҫɾ�����ݵ�λ�ã�";
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
			cout<<"��������Ҫ�������ݵ�λ���Լ�����ֵ��";
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
			cout<<"��������Ҫ���ĵ�����λ���Լ����ĺ������ֵ��";
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

//��������
void creatlist(LinkList &head,int n){
	LinkList p2,tail;
	int dt;
	p2=(LinkList)malloc(sizeof(LNode));
	cout<<"���������ݣ�";
	cin>>dt;
	p2->data=dt;
	p2->next=NULL;
	head=p2;
	tail=head;
	for(int i=1;i<n;i++){
		p2=(LinkList)malloc(sizeof(LNode));
		cout<<"���������ݣ�";
		cin>>dt;
		p2->data=dt;
		p2->next=NULL;
		tail->next=p2;
		tail=p2;
	}
}

//չʾ����
void showlist(LinkList head){
	LinkList tail=head;
	while(tail){
		cout<<tail->data<<" ";
		tail=tail->next;
	}
	cout<<endl;
}

//������ָ��λ������
void my_get(int n2,LinkList head){
	LinkList p1=head;
	for(int i=1;i<n2;i++){
		if(!p1->next){
			cout<<"get fail"<<endl;
			return;
		}
		p1=p1->next;
	}
	cout<<"�鵽������ֵΪ��"<<p1->data<<endl;
	
}

//������ָ������
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

//ɾ������ָ������
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

//ָ������λ���������
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



