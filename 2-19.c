#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *next;
};

struct node *build_node(int n);
struct node *nalloc(void);
struct node *delete(struct node *pd,int min,int max);
void print_node(struct node *pi);

int main(){
	struct node *p,*pn,*ps,*pl;
/*
	p is the next node of pn
	ps is the pointer of the head node
	pl is the last pointer of pn
*/
	int mink,maxk;
	int dt;                         //record the value of input number
	int i=1;
	while(scanf("%d",&dt)!=EOF){    //build a linked list
		if(i==1){
			p=build_node(dt);
			ps=p;
			pn=p;
		}else{
			p=build_node(dt);
			pn->next=p;
			pl=pn;
			pn=p;
		}
		i++;
	}
	pn->next=NULL;
	maxk=pn->data;
	mink=pl->data;

	ps=delete(ps,mink,maxk);

	print_node(ps);
	return 0;
}

struct node *build_node(int n){
	struct node *pnode;
	pnode=nalloc();
	pnode->data=n;
	return pnode;
}

struct node *nalloc(void){
	return (struct node*)malloc(sizeof(struct node));
}

struct node *delete(struct node *pd,int min,int max){
	struct node *pre,*pm,*p;
	int i=1;
	pm=pd;
	pre=pd;
	p=pre->next;
	while(p->next!=NULL){
		if(i==1){
/*
	whether the head node is between min and max
*/
			if(pre->data>min && pre->data<max){
				pd=p;
				free(pre);
				pm=pd;
				pre=pd;
				p=pre->next;
			}else{
				pm=pre;
				pre=p;
				p=p->next;
				i++;
			}
		}

		if(p->data>min && p->data<max){
			pre->next=p->next;
			free(p);
			p=pre->next;
		}else{
			pm=pre;
			pre=p;
			p=p->next;
		}
	}

	pm->next=NULL;
	free(pre);
	free(p);

	return pd;
}
/*
	the order of the pointers is pm->pre->p
*/

void print_node(struct node *pi){
	while(pi!=NULL){
		printf("%d%s",pi->data,(pi->next)!=NULL?" ":"");
		pi=pi->next;	
	}
}

