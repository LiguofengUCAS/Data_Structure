#include <stdio.h>
#include <stdlib.h>

#define MAXBIT 5

typedef int Status;

typedef int ElemType;

typedef struct Node
{
    int i,j;
    ElemType e;
    struct Node *right,*down;
}Node,*OList;

typedef struct
{
    OList *rhead,*chead;
    int mu,nu;
}CrossList;

OList CreatNode(int x,int y,ElemType data)
{
    OList p;
    p=(OList)malloc(sizeof(struct Node));
    p->i=x;
    p->j=y;
    p->e=data;
    p->right=NULL;
    p->down=NULL;

    return p;
}

CrossList CreatList(int row,int col)
{
    char c;
    char temp[MAXBIT];
    int p,q,bit;
    OList cen;
    CrossList M;
    OList r_left,c_up;
    M.mu=row;
    M.nu=col;

    M.rhead=(OList*)malloc((row+1)*sizeof(OList));
    M.chead=(OList*)malloc((col+1)*sizeof(OList));

    p=1,q=1,bit=0;
    while(p<=row)
    {
        c=getchar();
        if((c>='0' && c<='9') || c=='-')
            temp[bit++]=c;
        else if(c==',' || c==';' || c=='+' || c=='\n')
        {
            temp[bit]='\0';
            if(atoi(temp)!=0)
            {
                cen=CreatNode(p,q,atoi(temp));

                bit=0;
                if(M.rhead[p]==NULL)
                {
                    M.rhead[p]=cen;
                    r_left=cen;
                }
                else
                {
                    r_left->right=cen;
                    r_left=cen;
                }

                if(M.chead[q]==NULL)
                {
                    M.chead[q]=cen;
                    c_up=cen;
                }
                else
                {
                    c_up->down=cen;
                    c_up=cen;
                }
            }
            if(q<col)
                q++;
            else if(q==col)
            {
                p++;
                q=1;
            }
        }    
    }
    return M;
}

CrossList AddMatrix(CrossList M,CrossList N)
{
    int p,q,sum;
    OList cen,r_left,c_up;
    CrossList S;
    S.mu=M.mu;
    S.nu=M.nu;

    S.rhead=(OList*)malloc((S.mu+1)*sizeof(OList));
    S.chead=(OList*)malloc((S.nu+1)*sizeof(OList));

    for(p=1;p<=S.mu;p++)
    {
        for(q=1;q<=S.nu;q++)
        {
            sum=GetMatrixData(M,p,q)+GetMatrixData(N,p,q);

            if(sum!=0)
            {
                cen=CreatNode(p,q,sum);
                
                if(S.rhead[p]==NULL)
                {
                    S.rhead[p]=cen;
                    r_left=cen;
                }
                else
                {
                    r_left->right=cen;
                    r_left=cen;
                }

                if(S.chead[q]==NULL)
                {
                    S.chead[q]=cen;
                    c_up=cen;
                }
                else
                {
                    c_up->down=cen;
                    c_up=cen;
                }
            }
        }
    }
    return S;
}

void PrintMatrix(CrossList M)
{
    int p,q;
    OList scan,pre;
    pre=M.rhead[1];
    printf("[");
    for(p=1;p<=M.mu;p++)
    {
        for(q=1;q<=M.nu;q++)
        {
            if(GetMatrixData(M,p,q)!=0)
            {
                if(q==1)
                    printf("[");
                printf("%d%s",GetMatrixData(M,p,q),(q==M.nu)?"]":",");
                if(p!=M.mu && q==M.nu)
                    printf(";");
            }
            else
            {
                if(q==1)
                    printf("[");
                printf("0%s",(q==M.nu)?"]":",");
                if(p!=M.mu && q==M.nu)
                    printf(";");
            }
        }
    }
    printf("]\n");
    return;
}

Status GetMatrixData(CrossList M,int p,int q)
{
    OList pre,scan;
    pre=M.rhead[p];
    scan=pre;
    while(scan!=NULL)
    {
        if(scan->j==q)
            return scan->e;
        else
        {
            pre=scan;
            scan=pre->right;
        }
    }
    return 0;
}

int main()
{
    int row,col;
    CrossList M,N,S;
    scanf("%d;%d;",&row,&col);
    M=CreatList(row,col);
    N=CreatList(row,col);
    S=AddMatrix(M,N);
    PrintMatrix(S);
    return 0;
}