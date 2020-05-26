//reference: ID sagileo

#include <stdlib.h>
#include <stdio.h>
#define MAXNUM 100
struct pnode{
//Polynomial. Head node coe is the number of nodes of the linked list.
    int coe;
    int power;
    struct pnode* next;
    struct pnode* pre;
};
struct pnode* BuildPolynomial(int n, int* (*datagen)());
struct pnode* Derivative(struct pnode *h);
struct pnode* palloc();
void PrintPolynomial_fifo(struct pnode *h);
void Sort_by_power(struct pnode *h,struct pnode *t);
void SwapNode(struct pnode *pa,struct pnode *pb);
struct pnode* DeleteLN(struct pnode *h);
struct pnode* FindTail(struct pnode *h);
struct pnode* SimplifyPoly(struct pnode *h);
char getch();
char getbuf();
int* input_Poly();
void ungetch(char c);
char buf[MAXNUM];
char *ph=buf,*pt=buf;

int main(){
    struct pnode *h,*t;
    h=BuildPolynomial(0,input_Poly);
    h=SimplifyPoly(h);
    h=Derivative(h);
    t=FindTail(h);
    Sort_by_power(h->next,t);
    if(h->next==NULL)
        printf("0\n");
    else PrintPolynomial_fifo(h->next);
}
struct pnode* SimplifyPoly(struct pnode *h){
    struct pnode *p=h->next,*q=h->next->next,*w;
    while(p->next!=NULL){
        while(q!=NULL){
            if(q->power==p->power){
                p->coe+=q->coe;
                q->coe=0;
                q=q->next;
            }
            else q=q->next;
        }
        p= p->next ;
        q= p->next ;
    }
    h=DeleteLN(h);
    return h;
}
struct pnode* Derivative(struct pnode *h){
    struct pnode *p=h->next,*q;
    while(p!=NULL){
        p->coe *= p->power;
        if(p->power)
            p->power--;
        p=p->next;
    }
    return DeleteLN(h);
}
struct pnode* DeleteLN(struct pnode *h){
//delete a node which satisfies the function qualified.
    struct pnode *pre=h,*p;
    p=pre->next;
    while(pre->next!=NULL){
        if(p->coe==0){
            pre->next=p->next;
            if(p->next!=NULL)
                p->next->pre=pre;
            free(p);   
            p=pre->next;  
            h->coe--;
        }else{
            pre=p;
            p=p->next;
        }
    }
    return h;
}
struct pnode* FindTail(struct pnode *h){
    struct pnode *t=h;
    while(t->next!=NULL)
        t=t->next;
    return t;
}
void Sort_by_power(struct pnode *h,struct pnode *t){
    if(h==t||h==t->next) 
        return;
    struct pnode *p=h->next,*q=t;
    while(p!=q->next){
        while(p->power>h->power){
            if(p==q->next) 
                break;
            if(p->power>q->power){
//                printf("\nswap:(%dx%d,%dx%d)\n",p->coe,p->power,q->coe,q->power);
                SwapNode(p,q);
            }
            q=q->pre;
        }
        if(p==q->next) 
            break;
        p=p->next;
    }
    if(h->power>q->power){
//    printf("\nswap:(%dx%d,%dx%d)\n",h->coe,h->power,q->coe,q->power);
        SwapNode(h,q);
    }
    Sort_by_power(h,q->pre);
    Sort_by_power(q->next,t);  
}
void SwapNode(struct pnode *pa,struct pnode *pb){
    if(pa==pb) return;
    int tempcoe,temppower;
    tempcoe = pa->coe;
    temppower = pa->power;
    pa->coe = pb->coe;
    pa->power = pb->power;
    pb->coe = tempcoe;
    pb->power = temppower;
}
char getch(){
    char c;
    return (c=getbuf())?c:getchar();
}
char getbuf(){
//    if(ph<pt) printf("getbuf:%d\n",*pt);
    return (ph==pt)?0:*(pt--);
}
void ungetch(char c){
    *(++pt)=c;
    return;
}

struct pnode* BuildPolynomial(int n, int* (*datagen)()){
//build a linked list with n nodes. Data are set as 0. if n==0, makelist until input==EOF;
    struct pnode *p,*plist;
    int coe,power;
    plist=palloc();
    plist->coe=n==0?0:n;
    plist->power=0;
    plist->pre =NULL;
    plist->next=NULL;
    if(!n){
        int *temp,i=0;
        while((temp=(*datagen)())!=NULL){
                coe=*temp;power=*(temp+1);
                p=palloc();
                p->coe=coe;
                p->power=power;
                p->next = plist->next;
                p->pre  = plist; 
                plist->next = p;
                if(p->next!=NULL)
                    p->next->pre = p;
                i++;
        }
        plist->coe=i;
    }
    return plist;
}

void PrintPolynomial_fifo(struct pnode *h){
//Print the linked list. If the first element is the number of nodes, please set the param h as h->next
    char coe[10],power[10];
    if(h!=NULL){
        PrintPolynomial_fifo(h->next);
//        printf("%s%dx^%d",(h->next!=NULL&&h->next->coe>0)?" + ":(h->next!=NULL&&h->next->coe<0)?" - ":"",h->coe,h->power);
        printf("%s%s%s%s%s",(h->next!=NULL&&h->coe>0)?" + ":(h->next!=NULL&&h->coe<0)?" - ":(h->next==NULL&&h->coe<0)?"- ":"",(!h->power||abs(h->coe)>1)?itoa(abs(h->coe),coe,10):"",(h->power)?"x":"",(h->power>1)?"^":"",(h->power>1)?itoa(h->power,power,10):"");
    }
    return;
}
struct pnode* palloc(){
    return (struct pnode*)malloc(sizeof(struct pnode));
}
int* input_Poly(){
    int data[2]={0,0},i=0,powercase=0,sign=1,signcase=0;
    int *p=data;
    char c,temp;
    switch (c=getch())
    {
    case ' ':c=getch();
    case '+':sign=1;break;
    case '-':sign=-1;break;
    case 'x':*p=1;ungetch(c);break;
    case EOF:return NULL;break;
    default:
        *p=c-'0';
    }
    while((c=getch())!='+'&&c!='-'&&c!=EOF){
        if(c==' '||c=='^'||c=='\n');
        else if(c>='0'&&c<='9'&&powercase==0){
            *data=*data*10+c-'0';
        }else if(c=='x'){
            *data=(*data)?*data:1;
            powercase=1;
            *data*=sign;
            if((temp=getch())!='^'){
                *(p+1)=1;
            }
            ungetch(temp);
        }
        else if(c>='0'&&c<='9'&&powercase==1){
            *(data+1)=*(data+1)*10+c-'0';
        }
    }
    if(c=='+'||c=='-')
        ungetch(c);
    return p;

}