#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

typedef struct NODE{
	int n;
	int power;
	struct NODE* pre;
	struct NODE* next;
}NODE;

void PiCreateAndInitial(NODE* head,int m) {
//创建双向循环链表，并且初始化链表 
	int tempx=m;
	NODE* temp = head;
	for (;m>=0;m--){
		NODE* p = (NODE*)malloc(sizeof(NODE));
		if (p) {
			if(m==tempx){
				p->n=1;
			}else{
				p->n=0;
			}
			p->power=m-tempx;
			temp->next = p;
			p->pre=temp;
			temp = p;
		}
	}
	temp->next=head;
	head->pre=temp;
}
 
void PiOutput(NODE* head,int m) {
//链表的遍历 
	char s[520]={0};
	char *sp=s;
	NODE* p = head->next;
	while ((m--)>=0) {
		*sp=(p->n)+48;
		sp=sp+1;
		if((p->power)==0){
			*sp='.';
			sp=sp+1;
		}
		p = p->next;
	}
	printf("%s\n",s);
}
 
void PiMultiply(NODE* head,int n){
//大数乘一个整数 
	int Cin=0;
	NODE* p=head->pre;
	while(p!=head){
		p->n=(p->n)*n+Cin;
		Cin=(p->n)/10;
		p->n=(p->n)%10;
		p=p->pre;
	}
}
 
void PiDivide(NODE* head,int n){
//大数除一个整数 
	int temp=0;
	NODE* p=head->next;
	while(p!=head){
		temp=(p->n)%n;
		p->n=(p->n)/n;
		(p->next)->n=(p->next)->n+10*temp;
		p=p->next;
	}
}
 
void PiAdd(NODE* head1,NODE* head2){
//把累加的结果保存下来 
	NODE* p1=head1->pre;
	NODE* p2=head2->pre;
	int Cin=0;
	while(p1!=head1){
		p2->n=(p2->n)+(p1->n)+Cin;
		Cin=(p2->n)/10;
		p2->n=(p2->n)%10;
		p1=p1->pre;
		p2=p2->pre;
	}
}

int main(){
	int m;
	scanf("%d",&m);
    //完成题目的唯一输入要求 
	
	NODE* head1=(NODE*)malloc(sizeof(NODE));
	NODE* head2=(NODE*)malloc(sizeof(NODE));

	head1->next=head1->pre=NULL;
	head2->next=head2->pre=NULL;

	if(head1&&head2){
		PiCreateAndInitial(head1,750);
		PiCreateAndInitial(head2,750);
		for(int n=1;n<=5000;n++){
	    	int temp=2*n+1;
    		PiDivide(head1,temp);
	    	PiMultiply(head1,n);
    		PiAdd(head1,head2);
    	}
    	PiMultiply(head2,2);
    	PiOutput(head2,m);
    }
    system("pause");
	return 0;
}