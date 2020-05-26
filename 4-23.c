#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef char Element;
typedef struct node{
	Element data;
	struct node *pre;
	struct node *next;
}Node;

Node *mac();
Node *judge(Node *head,Node *tail);

int main(){
	Node *head,*tail;
	Node *p,*pl;
	int c;
	head=mac();
	p=mac();
	head->next=p;
	pl=head;
	while((c=getchar())!=EOF){
		if(c=='\n'){
			tail=pl;
			break;
		}else{
			p->data=c;
			pl->next=p;
			p->pre=pl;
			pl=p;
			p=mac();
		}
	}
	/*for(p=head->next;p!=NULL;p=p->next)
		printf("%c",p->data);*/
	judge(head,tail);
	return 0;
}

Node *mac(){
	return (Node*)malloc(sizeof(Node));
}

Node *judge(Node *head,Node *tail){
	Node *p,*q;
	p=head->next;
	q=tail;
	while(p!=q && q->next!=p){
		//printf("p->data=%c q->data=%c\n",p->data,q->data);
		if(p->data!=q->data){
			printf("No");
			return head;
		}
		p=p->next;
		q=q->pre;
	}
	printf("Yes");
	return head;
}