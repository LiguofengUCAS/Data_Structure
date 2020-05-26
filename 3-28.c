#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int data;
	struct node *next;
}Node;

Node *mac();
Node *build_node(int n);
Node *print_node(Node *pt);

int main(){
	int len;
	Node *tail;
	scanf("%d",&len);
	tail=build_node(len);
	/*printf("%d ",tail->data);	tail=tail->next;
	printf("%d ",tail->data);	tail=tail->next;
	printf("%d ",tail->data);	tail=tail->next;
	printf("%d ",tail->data);	tail=tail->next;
	printf("%d\n",tail->data);	tail=tail->next;*/
	print_node(tail);
	return 0;
}

Node *mac(){
	return (Node*)malloc(sizeof(Node));
}

Node *build_node(int n){
	int i=1;
	int num;
	Node *head,*p,*pre,*tail;
	head=mac();
	p=mac();
	pre=head;
	head->next=p;
	for(i=1;i<=n;i++){
		scanf("%d,",&num);
		p->data=num;
		//printf("num=%d ",num);
		//printf("data=%d ",p->data);
		pre->next=p;
		pre=p;
		p=mac();
	}
	tail=pre;
	tail->next=head->next;
	return tail;
}

Node *print_node(Node *pt){
	Node *p;
	for(p=pt->next;p!=pt;p=p->next)
		printf("%d,",p->data);
	printf("%d",pt->data);
	return pt;
}