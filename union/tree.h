﻿#ifndef TREE_H
#define TREE_H
#include<iostream>
/*树的双亲表示法结点结构定义*/
#define MAX_TREE_SIZE 100
typedef int TElemType; /*树结点的数据类型，目前暂定为整形*/
typedef struct PTNode  /*结点结构*/
{
    TElemType data; /*结点数据*/
    int parent;     /*双亲位置*/
}PTNode;
typedef struct     /*树结构*/
{
    PTNode nodes[MAX_TREE_SIZE];/*结点数组*/
    int r, n;                   /*根的位置和结点数*/
}PTree;


/*树的孩子表示法结构定义*/
#define MAX_TREE_SIZE 100
typedef struct CTNode /*孩子结点*/
{
    int child;
    struct CTNode *next;
}*ChildPtr;
typedef struct  /*表头结构*/
{
    TElemType data;
    ChildPtr firstchild;
}CTBox;
typedef struct      /*树结构*/
{
    CTBox nodes[MAX_TREE_SIZE]; /*结点数组*/
    int r,n;                    /*根的位置和结点数*/
}CTree;
/*树的孩子兄弟表示法结构定义*/
typedef struct CSNode
{
    TElemType data;
    struct CSNode *firstchild,*rightsib;
}CSNode,*CSTree;

/*二叉树的二叉链表结点结构定义*/
typedef struct BiTNode /*结点结构*/
{
    TElemType data; /*结点数据*/
    struct BiTNode *lchild, *rchild; /*左右孩子指针*/
}BiTNode,*BiTree;

/*二叉树的前序遍历递归算法*/
void PreOrderTraverse(BiTree T)
{
    if(T==nullptr)
        return;
    printf("%c", T->data); /*显示结点数据，可以更改为其他对结点操作*/
    PreOrderTraverse(T->lchild);/*再先序遍历左子树*/
    PreOrderTraverse(T->rchild);/*最后先序遍历右子树*/
}
/*二叉树的中序遍历递归算法*/
void InOrderTraverse(BiTree T)
{
    if(T==nullptr)
        return;
    InOrderTraverse(T->lchild);/*中序遍历左子树*/
    printf("%c", T->data); /*显示结点数据，可以更改为其他对结点操作*/
    InOrderTraverse(T->rchild);/*最后中序遍历右子树*/
}
/*二叉树的后序遍历递归算法*/
void PostOrderTraverse(BiTree T)
{
    if(T==nullptr)
        return;
    PostOrderTraverse(T->lchild);/*先后序遍历左子树*/
    PostOrderTraverse(T->rchild);/*再后序遍历右子树*/
    printf("%c", T->data); /*显示结点数据，可以更改为其他对结点操作*/

}

//实现前序遍历序列为AB#D##c##
/*按前序输入二叉树中结点的值（一个字符）*/
/*#表示空树，构造二叉链表表示二叉树T。*/
void CreateBiTree(BiTree *T)
{
    TElemType ch;
    scanf("%c", &ch);
    if(ch=='#')
        *T=NULL;
    else
    {
        *T=(BiTree)malloc(sizeof(BiTNode));
        if(!*T)
            //exit(OVERFLOW);
            ;
        (*T)->data=ch;//生成根结点
        CreateBiTree(&(*T)->lchild);//构造左子树
        CreateBiTree(&(*T)->rchild);//构造右子树
    }
}
/*二叉树的二叉线索存储结构定义*/
typedef enum{Link, Thread} PointerTag; /*Link==0表示指向左右孩子指针*/
                                       /*Thread==1表示指向前驱或者后续的线索*/
typedef struct BiThrNode        /*二叉线索存储结点结构*/
{
    TElemType data; /*结点数据*/
    struct BiThrNode *lchild, *rchild;/*左右孩子指针*/
    PointerTag LTag;
    PointerTag RTag;   /*左右标志*/
}BiThrNode,*BiThrTree;

//中序遍历线索化的递归函数代码如下：
/*中序遍历进行中序线索化*/
void InThreading(BiThrTree p)
{
    if(p)
    {
        InThreading(p->lchild);/*递归左子树线索化*/
        if(!p->lchild)   /*没有左孩子*/
        {
            p->LTag=Thread;/*前驱线索*/
           偏
        }
    }
}
#endif // TREE_H
