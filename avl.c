#include <stdio.h>
#include <stdlib.h>
//
#define LH  1
#define EH  0
#define RH -1
typedef int ElemType;
typedef enum {false,true} bool;
//
typedef struct BSTNode{
    ElemType data;
    int bf;//balance flag
    struct BSTNode *lchild,*rchild;
}*BSTree,BSTNode;
//
void R_Rotate(BSTree* p)
{
    //
    BSTree lc = (*p)->lchild;
    (*p)->lchild = lc->rchild;
    lc->rchild = *p;
    *p = lc;
}
////
void L_Rotate(BSTree* p)
{
    //
    BSTree rc = (*p)->rchild;
    (*p)->rchild = rc->lchild;
    rc->lchild = *p;
    *p = rc;
}
//
void LeftBalance(BSTree* T)
{
    BSTree lc,rd;
    lc = (*T)->lchild;
    //
    switch (lc->bf)
    {
        case LH:
            (*T)->bf = lc->bf = EH;
            R_Rotate(T);
            break;
        case RH:
            rd = lc->rchild;
            switch(rd->bf)
        {
            case LH:
                (*T)->bf = RH;
                lc->bf = EH;
                break;
            case EH:
                (*T)->bf = lc->bf = EH;
                break;
            case RH:
                (*T)->bf = EH;
                lc->bf = LH;
                break;
        }
            rd->bf = EH;
            L_Rotate(&(*T)->lchild);
            R_Rotate(T);
            break;
    }
}
//
void RightBalance(BSTree* T)
{
    BSTree lc,rd;
    lc= (*T)->rchild;
    switch (lc->bf)
    {
        case RH:
            (*T)->bf = lc->bf = EH;
            L_Rotate(T);
            break;
        case LH:
            rd = lc->lchild;
            switch(rd->bf)
        {
            case LH:
                (*T)->bf = EH;
                lc->bf = RH;
                break;
            case EH:
                (*T)->bf = lc->bf = EH;
                break;
            case RH:
                (*T)->bf = EH;
                lc->bf = LH;
                break;
        }
            rd->bf = EH;
            R_Rotate(&(*T)->rchild);
            L_Rotate(T);
            break;
    }
}
int InsertAVL(BSTree* T,ElemType e,bool* taller)
{
    //
    if ((*T)==NULL)
    {
        (*T)=(BSTree)malloc(sizeof(BSTNode));
        (*T)->bf = EH;
        (*T)->data = e;
        (*T)->lchild = NULL;
        (*T)->rchild = NULL;
        *taller=true;
    }
    //
    else if (e == (*T)->data)
    {
        *taller = false;
        return 0;
    }
    //
    else if (e < (*T)->data)
    {
        //
        if(!InsertAVL(&(*T)->lchild,e,taller))
            return 0;
        //
        if(*taller)
        {
            //
            switch ((*T)->bf)
            {
                case LH:
                    LeftBalance(T);
                    *taller = false;
                    break;
                case  EH:
                    (*T)->bf = LH;
                    *taller = true;
                    break;
                case RH:
                    (*T)->bf = EH;
                    *taller = false;
                    break;
            }
        }
    }
    //
    else
    {
        if(!InsertAVL(&(*T)->rchild,e,taller))
            return 0;
        if (*taller)
        {
            switch ((*T)->bf)
            {
                case LH:
                    (*T)->bf = EH;
                    *taller = false;
                    break;
                case EH:
                    (*T)->bf = RH;
                    *taller = true;
                    break;
                case  RH:
                    RightBalance(T);
                    *taller = false;
                    break;
            }
        }
    }
    return 1;
}
//
bool FindNode(BSTree root,ElemType e,BSTree* pos)
{
    BSTree pt = root;
    (*pos) = NULL;
    while(pt)
    {
        if (pt->data == e)
        {
            //
            (*pos) = pt;
            return true;
        }
        else if (pt->data>e)
        {
            pt = pt->lchild;
        }
        else
            pt = pt->rchild;
    }
    return false;
}
//
void InorderTra(BSTree root)
{
    if(root->lchild)
        InorderTra(root->lchild);
   
    printf("%d ",root->data);
   
    if(root->rchild)
        InorderTra(root->rchild);
}

void DeleteAVL(BSTree* T,ElemType e,bool* taller)
{

}

int main()
{
    int i,nArr[] = {1,23,45,34,98,9,4,35,23};
    BSTree root=NULL,pos;
    bool taller;
    //
    for (i=0;i<9;i++)
        InsertAVL(&root,nArr[i],&taller);
    //
    InorderTra(root);
    //
    //DeleteAVL(root,e);
    //InorderTra(root);
    if(FindNode(root,35,&pos))
        printf("\nFind:%d\n",pos->data);
    else
        printf("\nNot find this Node\n");
    return 0;
}