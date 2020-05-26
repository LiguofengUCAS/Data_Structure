#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100

typedef struct
{
    char *base;
    char *top;
    int size;
}sqstack;

void initstack(sqstack *s)
{
    s->base=(char*)malloc(MAXSIZE*sizeof(char));
    if(s->base==NULL)
    exit(0);
    s->top=s->base;
    s->size=MAXSIZE;
}

void push(sqstack *s,char e)
{
    if(s->top-s->base>=s->size)
    {
        s->base=(char*)realloc(s->base,100);
        if(s->base==NULL)
        exit(0);
        s->top=s->base+s->size;
        s->size=s->size+100;
    }
    *(s->top)=e;
    s->top++;
}

void pop(sqstack *s,char *e)
{
    *e = *--(s->top);
}

int len(sqstack s)
{
    return (s.top-s.base);
}

int main()
{
    sqstack s;
    char e;
    char c[100]={};
    int a;
    int i=0;
    initstack(&s);
    while((a=getchar())!=EOF)
    {
        c[i]=a;
        i++;
    }
    int j;
    for(j=0;j<i;j++)
    {
        if((c[j]>='a'&&c[j]<='z')||(c[j]>='A'&&c[j]<='Z'))
        {
            printf("%c",c[j]);
        }
        else if(c[j]==')')
        {
            pop(&s,&e);
            while(e!='(')
                  {
                      printf("%c",e);
                      pop(&s,&e);
                  }
        }
        else if( c[j] == '+' || c[j] == '-')
        {
            if( !len(s) )
            {
                push(&s, c[j]);
            }
            else
            {
                do
                    {
                      pop(&s, &e);
                       if( e == '(')
                       {
                           push(&s, e);
                       }
                       else
                        {
                           printf("%c", e);
                       }
                    }while( len(s) && e != '(');
                    push(&s, c[j]);
            }
        }
        else if(c[j]=='/'&&c[j-2]=='*')
        {
            pop(&s,&e);
            printf("%c",e);
            push(&s,c[j]);
        }
        else if( c[j] == '*' || c[j] == '/' || c[j] == '(')
        {
            push(&s, c[j]);
        }
    }
    while(len(s))
                {
                    pop(&s,&e);
                    printf("%c",e);
                }
    return 0;
}