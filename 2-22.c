#include <stdio.h>
#include <stdlib.h>

struct node{
	char letter;
	struct node *next;
};

struct node *build_node(char c);
struct node *nalloc();
void print_node(struct node *pi);

int main(){
	struct node *p,*pl;
	char c;
	int i=1;
	while((c=getchar())!=EOF){
		if(c!='\n'){
			if(i==1){
				p=build_node(c);
				i++;
			}else{
				pl=build_node(c);
				pl->next=p;
				p=pl;
			}
		}
		
	}
	print_node(pl);
	return 0;
}

struct node *build_node(char c){
	struct node *pnode;
	pnode=nalloc();
	pnode->letter=c;
	pnode->next=NULL;
	return pnode;
}


struct node *nalloc(){
	return (struct node*)malloc(sizeof(struct node));
}

void print_node(struct node *pi){
	while(pi!=NULL){
		printf("%c",pi->letter);
		pi=pi->next;	
	}
}