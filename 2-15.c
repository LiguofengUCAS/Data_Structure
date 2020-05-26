#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *next;
};

struct node *build_node(signed int c);
struct node *nalloc(void);
void print_node(struct node *pi);

int main(){
	int m,n;
	int i=1,j=1;
	signed int c;
	struct node *pa,*pb,*p,*pe,*pl;
	scanf("%d %d",&m,&n);
	while(scanf("%d",&c)){
		if(i<=m){
			if(i==1){
				pa=build_node(c);
				p=pa;
				pl=pa;
			}else{
				p=build_node(c);
				pl->next=p;
				pl=p;
			}
			i++;
		}else{
			if(j==1){
				pb=build_node(c);
				pe=pb;
				pl=pb;
			}else{
				pe=build_node(c);
				pl->next=pe;
				pl=pe;
			}
			j++;
			if(j>n)
				break;
		}
	}

	if(m<=n){              
		p->next=pb;
		print_node(pa);
	}else{
		pe->next=pa;
		print_node(pb);
	}

	return 0;
}



struct node *build_node(signed int c){
	struct node *pnode;
	pnode=nalloc();
	pnode->data=c;
	pnode->next=NULL;
	return pnode;
}

struct node *nalloc(void){
	return (struct node*)malloc(sizeof(struct node));
}

void print_node(struct node *pi){
	while(pi!=NULL){
		printf("%d%s",pi->data,(pi->next==NULL)?"":" ");
		pi=pi->next;	
	}
}