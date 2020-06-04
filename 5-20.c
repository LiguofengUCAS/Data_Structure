#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node * next;
}Node;

void Print(Node *head, int dim, int n);
int WriteNumber();
int Dec(int *power, int dim, int n);

int main(){
    int dim, n;
    scanf("%d;%d;", &dim, &n);
    Node *p;
    Node *head;
    head = (Node*)malloc(sizeof(Node));
    head->data = 0;
    head->next = NULL;
    int input, count;
    while((input = WriteNumber()) != -1){
        count++;
        p = (Node*)malloc(sizeof(Node));
        p->data = input;
        p->next = head->next;
        head->next = p;
    }
    head->data = count;
    Print(head, dim, n);
    return 0;
}
void Print(Node *head, int dim, int n){
    int power[dim];
    Node *p;
    p = head->next;
    int i;
    for(i = 0; i < dim; i++){
        power[i] = n - 1;
    }
    while(p != NULL){
        if(p -> data == 0){
            ;
        }
        else
        { 
            if(p->data < 0){
                printf("-");
                p->data = (-1) * p->data;
            }
            else if(p != head->next){
                printf("+");
            }
            if((p -> next != NULL) && (p->data == 1)){
                if(power[0] > 1)
                    printf("x1E%d", power[0]);
                else if(power[0] == 1)
                    printf("x1");
            }
            else
            { 
                if(power[0] > 1){
                    printf("%dx1E%d", p->data, power[0]);
                }
                else if(power[0] == 1){
                    printf("%dx1", p->data);
                }
                else
                {
                    printf("%d", p->data);
                }
            }


            for(i = 1; i < dim; i++)
                if(power[i] > 1)
                    printf("x%dE%d", i + 1, power[i]);
                else if(power[i] == 1)
                    printf("x%d", i + 1);
        }
        if(!Dec(power, dim, n))
            printf("\n");
        p = p -> next;
    }
}

int Dec(int *power, int dim, int n){
    if(dim == 1 && power[0] == 0){
        return 0;
    }
    if(power[dim-1] > 0){
        power[dim-1]--; 
        return 1;
    }
    else if(Dec(power, dim - 1, n)){
        power[dim - 1] = n - 1;
        return 1;
    }
}

int WriteNumber(){
    char c;
    int temp = 0;
    while((c = getchar()) != EOF){
        if(c >= '0' && c <= '9'){
            temp = temp * 10 + c - '0';
        }else if(c == ',' || c == ';' || c == '\n')
            return temp;
    }
    if(temp != 0){
        return temp;
    }
    else 
    {
        return EOF;
    }
}