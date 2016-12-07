/* 2016年10月26日20:51:12
 * 总结经验:
 *      1.返回值是Status的就要考虑何时返回的为ERROR, 何时返回OK
 *      2.每一个函数的函数体前说明该函数的功能
 *      3.注意代码和绘图的结合, 有助于思考
 *      4.在c++代码中, 函数形参用引用可以很方便的改变函数外面的值, 尽量避免使用指针
 *      5.在CLion中, 对经常用的for(int j = 0; j<?; j++) { }这个模型可以直接输入for后回车就可以直接自动补全, 只需要添加?相应的值
 * */
#include "linklist.h"

Status InitList(LinkList &L)
{
    L=(ElemType *)malloc(LIST_INIT_SIZE* sizeof(ElemType));
    if(!L)  exit(OVERFLOW);
    L->next = NULL;
    return OK;
}

Status DestroyList(LinkList &L)
{
    LinkList p = L->next;
    while (L){
        p=L->next;
        free(L);
        L=p;
    }
    return OK;
}

void ClearList(LinkList &L)
{
    LinkList p=L->next;
    while (p)
    {
        L->next=p->next;
        free(p);
        p=L->next;
    }
}

int ListLength(LinkList L)
{
    int n = 0;
    LinkList p=L->next;
    for(; p; p=p->next)
    {
        n++;
    }
    return n;
}

Status GetElem(LinkList L, int i, ElemType &e)
{
    LinkList p=L->next;
    for(int j=0; p&&j<i; j++)
    {
        p=p->next;
    }
    if(!p|| j>i)
        return ERROR;
    e=p->data;
    return OK;
}

LinkList LocateElem(LinkList L, ElemType e)
{
    LinkList p=L->next;
    while(p&&p->data!=e)
    {
        p=p->next;
    }
    return p;
}

ElemType PriorElem(LinkList L, ElemType Cur_e, ElemType &Pre_e)
{
    LinkList p=L->next;
    while(p->next&&p->next->data==Cur_e){
        p=p->next;
    }
    return p->data;
}

ElemType NextElem(LinkList L, ElemType Cur_e, ElemType &Next_e)
{
    LinkList p=L->next;
    while(p&&p->data==Cur_e)
    {
        p=p->next;
    }
    return p->next->data;
}

Status ListInsert(LinkList &L, int i, ElemType &e)
{
    LinkList p=L, s=(ElemType *)malloc(sizeof(LNode));
    for(int j=0; p&&j<i; j++)//既要确定p所指的结点是否为空, 又要确定计数器没有超过界限
    {
        p=p->next;
    }

    if (!p || j>i-1)
        return ERROR;

    s->data = e;//将插入的值赋给结点
    s->next = p->next;//将插入结点s的指针域指向p的下一个结点
    p->next = s;//p的指针域指向s

    return OK;//
}

Status ListDelete(LinkList &L, int i, ElemType &e)
{
    LinkList p=L->next, q;
    int j=0;
//    for (int j = 0; j < i-1; ++j) {
//    //这里不适合用for循环, 因为还要判断p->next是否到了链表结尾
//        p=p->next;
//    }
    while(p->next && j<i-1)
    {
        p=p->next;
        j++;
    }
    if(!p || j>i-1)
        return ERROR;
    q=p->next;
    p->next = q->next;
    e=q->data;
    free(p->next);
}