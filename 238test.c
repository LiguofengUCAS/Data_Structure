#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXOP 100
//#define BUFSIZE 100
//char buf[BUFSIZE];
//int bufp=0;

typedef struct node{
	struct node *pre;
	int data;
	int freq;
	int order;
	struct node *next;
}*Node;

Node mac(void);
Node build_node(int len);
Node locate(Node ps,int x,int len,int times);
Node sort(Node ps,int len);
void print_node(Node ps,int len);
void swap(int *a,int *b);
Node correct(Node ps,int len);
//int getch(void);
//void ungetch(int c);
int getop(char s[]);


int main(){
	Node ps,p,pl;
	char s[100];
	int n,i,x,t;
	t=1;
	printf("input n:");
	scanf("%d",&n);
	printf("input the linked list: ");
	ps=build_node(n);
	while((x=getop(s))!=EOF){
		ps=locate(ps,x,n,t);
		t++;
	}
	ps=sort(ps,n);
	print_node(ps,n);
	return 0;
}

Node mac(void){
	return (Node)malloc(sizeof(Node));
}

Node build_node(int len){
	Node ps,p,plast;
	int i;
	for(i=1;i<=len;i++){
		if(i==1){
			p=mac();
			scanf("%d",&p->data);
			p->freq=0;
			p->order=0;
			ps=p;
			p->pre=plast;
			plast=p;
		}else{
			p=mac();
			scanf("%d",&p->data);
			p->freq=0;
			p->order=0;
			p->pre=plast;
			plast->next=p;
			plast=p;
		}
	}
	plast->next=ps;
	ps->pre=plast;
}

void print_node(Node ps,int len){
	int i;
	printf("the linked list:");
	for(i=1;i<=len;i++){
		printf("%d%s",ps->data,(i==len)?"":" ");
		ps=ps->next;
	}
}

Node locate(Node ps,int x,int len,int times){
	int i;
	Node p,pn,pr;
	p=ps;
	for(i=1;i<=len;i++){
		pr=p->pre;
		pn=p->next;
		if(p->data==x){
			if(p->order==0)
				p->order=times;
			p->freq+=1;
			return ps;
		}
		p=p->next;
	}
	printf("no such x=%d, please input again\n",x);
	return ps;
}

Node sort(Node ps,int len){
	Node p;
	p=ps;
	int i;
	int q;
	int temp_data,temp_freq;
	for(i=1;i<len;i++){
		if(p->freq < p->next->freq){
			swap(&p->data,&p->next->data);
			swap(&p->freq,&p->next->freq);
			swap(&p->order,&p->next->order);
			p=ps;
			goto out;
		}
		if(p->next->next==ps){
			ps=correct(ps,len);
			return ps;
		}
		p=p->next;
		out:i=0;
	}
}

void swap(int *a,int *b){
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}

Node correct(Node ps,int len){
	int i;
	Node p;
	p=ps;
	for(i=1;i<len;i++){
		if(p->freq==p->next->freq){
			if(p->order>p->next->order){
				swap(&p->data,&p->next->data);
				swap(&p->freq,&p->next->freq);
				swap(&p->order,&p->next->order);
				p=ps;
				goto out;
			}
		}
		if(p->next->next==ps)
			return ps;
		p=p->next;
		out:i=0;
	}
}




