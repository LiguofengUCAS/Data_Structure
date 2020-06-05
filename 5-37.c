//coder:Sagileo

#include <stdio.h>
#include <stdlib.h>
typedef char VARType;
typedef enum{CONST, VAR, LIST} ElemTag;
typedef struct GLNode {
    ElemTag tag;
    union{
        VARType VAR;
        struct{
            struct GLNode *hp, *tp;
        }ptr;
    } ;
} *GList;

int CreateGList(GList gl, char *str);     //根据串str创建gl指向的广义表， 成功返回1， 否则返回0
GList DeleteElem_Var(GList gl, char elem);      //删除gl广义表中的elem变量
GList DeleteElem_Const(GList gl, char elem);      //删除gl广义表中的elem常数
void PrintGList(GList gl);                //打印gl广义表
GList GLNAlloc();                         //为GList分配空间
int GetHead(char *p, char *str);            //从串str中分离出表头，用p指向
int GetTail(char *q, char *str);            //从串str中分离出表尾，用q指向
int GetHeadandTail(char *head, char *str);  //从串str中分离出表头head和表尾str
int StrCmp(char *p, char *q);               //字典序比较p和q大小，p大返回1，一样大返回0，否则返回-1
int StrLen(char *str);                      //返回串str长度
int StrCpy(char *sa, char *sb);             //将串sa复制到sb


int main(){
    char c, *str = NULL, *p = NULL, elem;
    int temp = 0, var;
    GList gl;
    gl = GLNAlloc();
    str = (char *)malloc(1000); p = str;
    if((c = getchar()) && c >= '0' && c <= '9'){
        temp = c - '0';
        while((c = getchar()) != ';')
            temp = temp * 10 + c - '0';
        elem = temp;
        var = 0;
    }else{
        elem = c;
        getchar();
        var = 1;
    }
    while((c = getchar()) != EOF){
        if(c != '\n') *(p++) = c;
    }
    *p = 0;
    CreateGList(gl, str);
    if(var)
        gl = DeleteElem_Var(gl, elem);
    else gl = DeleteElem_Const(gl, elem);
    printf("(");
    PrintGList(gl);
}

int CreateGList(GList gl, char *str){
    char emp[] = "()", *head = NULL;
    int temp = 0;
    head = (char *)malloc(1000);
    GList hp = NULL, tp = NULL;
    if(StrCmp(str, emp) == 0){
        gl = NULL;
        return -1;
    }
    if(StrLen(str) == 1 && (*str >= '9' || *str <= '0')){
        gl -> tag = VAR;
        if(*str >= '0' && *str <= '9')
            gl -> VAR = *str + '0';
        else gl -> VAR = *str;
        return 1;
    }else if(*str != '('){
        while(*str){
            temp = temp * 10 + *(str++) - '0';
        }
        gl -> tag = CONST;
        gl -> VAR = (char)temp;
        return 1;
    }
    if(!(hp = GLNAlloc())) return 0;
    if(!(tp = GLNAlloc())) return 0;
    gl -> tag = LIST;
    GetHeadandTail(head, str);
//    printf("get: head = %s, tail = %s\n", head, str);
    CreateGList(hp, head);
/*
    printf("created: head = ");
    PrintGList(hp);
    printf("\n");
*/
    gl -> ptr.hp = hp;
    if((temp = CreateGList(tp, str)) == -1)
        gl -> ptr.tp = NULL;
    else gl -> ptr.tp = tp;
}
GList DeleteElem_Var(GList gl, char elem){
    if(gl == NULL) return NULL;
    if(gl -> tag == VAR){
        if(gl -> VAR == elem)
            gl = NULL;
    }else if(gl -> tag == LIST){
        gl -> ptr.hp = DeleteElem_Var(gl -> ptr.hp, elem);
        gl -> ptr.tp = DeleteElem_Var(gl -> ptr.tp, elem);
    }
    return gl;
}
GList DeleteElem_Const(GList gl, char elem){
    if(gl == NULL) return NULL;
    if(gl -> tag == CONST){
        if(gl -> VAR == elem)
            gl = NULL;
    }else if(gl -> tag == LIST){
        gl -> ptr.hp = DeleteElem_Const(gl -> ptr.hp, elem);
        gl -> ptr.tp = DeleteElem_Const(gl -> ptr.tp, elem);
    }
    return gl;
}
void PrintGList(GList gl){
    if(gl == NULL) return;
    if(gl -> tag == VAR){
        printf("%c", gl -> VAR); 
        return;
    }else if(gl ->tag == CONST){
        printf("%d", gl -> VAR);
        return;
    }
    if(gl -> ptr.hp == NULL){
        PrintGList(gl -> ptr.tp);
        if(gl -> ptr.tp == NULL)
            printf(")");
    }else{    
        if(gl -> ptr.hp -> tag == LIST)
            printf("(");
        PrintGList(gl -> ptr.hp);
        if(gl -> ptr.hp && gl -> ptr.tp){
            if(gl -> ptr.tp -> ptr.hp == NULL && gl -> ptr.tp -> ptr.tp == NULL)
                ;
            else printf(",");
        }
        PrintGList(gl -> ptr.tp);
        if(gl -> ptr.tp == NULL)
            printf(")");
    }
}
GList GLNAlloc(){
    return (struct GLNode*)malloc(sizeof(struct GLNode));
}
int GetHeadandTail(char *head, char *str){
    int i; 
    char *p = NULL, *sp = NULL, stack[100];
    p = str; sp = stack;
    if(*(p++) != '(') return 0;  
    if(*p == '('){
        sp++; p++;
        while(stack != sp){
            if(*p == '(')
                sp++;
            else if(*p == ')')
                sp--;
            p++;
        }
        if(*p == ','){
            *p = 0;
            StrCpy(str + 1, head);
            *p = '(';
            StrCpy(p, str);
            return 1;
        }
        else if(*p == ')'){
            *p = 0;
            StrCpy(str + 1, head);
            *str = '('; str[1] = ')'; str[2] = 0;
            return 1;
        }
    }
    else{
//        *head = *p;
//        head[1] = 0;
        for(i = 0; str[i + 1] != ')' && str[i + 1] != ','; i++){
            head[i] = str[i + 1];
        }
        head[i] = 0;
        str[i + 1] = '(';
        StrCpy(str + i + 1, str);
        if(StrLen(str) == 1){
            str[1] = ')';
            str[2] = 0;
        }
        return 1;
    }
    return 0;
}

int StrLen(char *str){
    int len = 0;
    while(str[len] != 0)
        len++;
    return len;
}


int StrCmp(char *sa, char *sb){
    char *pa = sa, *pb = sb;
    while(*pa && *pb){
        if(*pa > *pb) return 1;
        else if(*pa < *pb) return -1;
        pa++, pb++;
    }
    if(*pb == *pa && *pa == 0) return 0;
    else return *pa == 0 ? -1 : 0;
}

int StrCpy(char *sa, char *sb){
    char *p = sa, *q = sb;
    while(*p){
        *(q++) = *(p++);
    }
    *q = 0;
}