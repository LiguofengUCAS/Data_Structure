#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef char Element;
typedef struct node{
	Element ch;
	struct node *next;
}Node;

Node *build_node(char c);
Node *mac();
Node *Replace(Node *ps,Node *pt,Node *pv);

int main(){
	int c;
	int i=1;
	int judge=0;
	Node *p,*ps,*pt,*pv,*pre;
	while((c=getchar())!=EOF){
		if(c==' '){
			judge++;
			i=0;
			p->next=NULL;
		}
		if(c=='\n'){
			break;
		}
		if(i==1 && c!=' '){
			if(judge==0){
				p=build_node(c);
				ps=p;
				pre=p;
			}else if(judge==1){
				p=build_node(c);
				pt=p;
				pre=p;
			}else if(judge==2){
				p=build_node(c);
				pv=p;
			}
		}
		if(i>1 && c!=' '){
			p=build_node(c);
			pre->next=p;
			pre=p;
		}
		i++;
	}

	Replace(ps,pt,pv);
	return 0;
}

Node *build_node(char c){
	Node *p;
	p=mac();
	p->ch=c;
	return p;
}

Node *mac(){
	return (Node*)malloc(sizeof(Node));
}

Node *Replace(Node *ps,Node *pt,Node *pv){
	Node *p1,*p2,*phead,*ptail,*p;
	phead=mac();
	p1=ps,p2=pt,phead->next=ps;
	while(p1!=NULL && p2!=NULL){
		if(p1->ch==p2->ch){
			p1=p1->next;
			ptail=p1;
			p2=p2->next;
		}else{
			p2=pt;
			phead=phead->next;
			p1=phead->next;
		}
	}

	if(p1==NULL && p2!=NULL){
		printf("");
		return ps;
	}
	else if(p2==NULL){
		if(phead->next!=ps){
			/*for(p=phead->next;p!=ptail;p=p->next)
				free(p);*/
			phead->next=pv;
			pv->next=ptail;
			for(p=ps;p!=NULL;p=p->next)
				printf("%c",p->ch);
			return ps;
		}else{
			ps=pv;
			/*for(p=phead->next;p!=ptail;p=p->next)
				free(p);*/
			pv->next=ptail;
			for(p=ps;p!=NULL;p=p->next)
				printf("%c",p->ch);
			return ps;
		}
	}
}
//if i keep the steps of "free", the program will run out of time

