//function.cpp 函数的定义
// Created by Cooper on 11/10/2016.
//
#include "linklist.h"

Status InitList(LinkList &L)
{
    L = (LinkList) malloc(sizeof(LNode)); //为链表分配空间
    if(!L) exit(OVERFLOW); // 如果是空, 则返回溢出
    L->next=NULL; //这一条也可用于判断链表是否为空
    return OK;
}    //构造一个空的链表
void DestroyList(LinkList &L)
{
    LinkList  p=L; //临时变量
    while (p)
    {
        p=L->next; //存储指针位置
        free(L); //释放内存
        L=p; //指向下一个结点
    }
}    //销毁链表, 结果是L=NULL, 链表不存在, 头结点的空间也被释放
void ClearList(LinkList L)
{
    LinkList p=L->next;  //指向头结点
    while(p)
    {
        L->next=p->next; //把指针指向首结点, 存储其位置
        free(p); //释放
        p=L->next; //指向下一结点
    }
} //清空链表, 结果是L->next=NULL, 即头结点为空
int ListLength(LinkList L)
{
    int n=0;//计数器
    LinkList p=L->next;//指针从第一个结点开始,跳过头结点
    while (p){//当指针不为空时
        n++;//计数器+1
        p=p->next;//指针后移
    }
    return n;
}   //求链表长度
Status GetElem(LinkList L, int i, ElemType &e)
{
    //由函数参数e传递读取的元素值
    int j=1;//计数器
    LinkList p = L->next;
    for(; p&&j<i; ++j)//把指针指向第i个元素
        p=p->next;
    if(!p||j>i)
        return ERROR;
    e=p->data;
    return OK;
} //取元素
//LinkList LocateElem(LinkList L, ElemType e, Status (*compare)(ElemType, ElemType))
LinkList LocateElem(LinkList L, ElemType e)
{
    LinkList p=L->next;
    while(p&&!compare(p->data, e))
        p=p->next;
    return p;
}//定位元素
Status compare(ElemType a, ElemType b)
{
    if(a==b)
        return OK;
    else
        return ERROR;
}
ElemType PriorElem(LinkList L, ElemType cur_e, ElemType &pre_e)
{
    LinkList p=L->next;//p指向头结点
    while(p->next&&!compare(p->next->data, cur_e))//下一个结点不为空且下一个元素就是cur_e
        p=p->next;
    return p->data;//p就是p->next的前驱
}//求前驱元素
ElemType NextElem(LinkList L, ElemType cur_e, ElemType &next_e)
{
    LinkList p=L->next;
    while(p&&!compare(p->data, cur_e))
        p=p->next;
    return p->next->data;
}//求后继元素
Status ListInsert(LinkList &L, int i, ElemType &e)
{
    LinkList p=L, s=(LinkList)malloc(sizeof(LNode));
    int j=0;
    while(p&&j<i-1)//将p定位到第i-1个元素所在的结点
    {
        p=p->next;
        ++j;
    }
    if(!p||j>i-1)
        return ERROR;
    s->data=e;//生成一个数据域为e的结点,用指针s指向它

    //将s所指向的结点插入到链表中
    s->next=p->next;
    p->next=s;
}//插入元素
Status ListDelete(LinkList &L, int i, ElemType &e)
{//删除的是第i个元素
    LinkList p=L, q;
    int j=0;//计数器
    while(p->next&&j<i-1)//将指针p定位到第i-1个元素所在的结点
    {
        p=p->next;
        ++j;
    }
    if(p->next&&j>i-1)
        return ERROR;
    q=p->next;//将q指向被删除结点
    p->next=q->next;
    e=q->data; //将删除元素的数据域的值传回
    free(q);
}//删除元素

/*
 *Status ListTransver(LinkList L, Status (*visit)(ElemType))
{
    LinkList p;
    for(p=L->next; p; p=p->next)
    {
        if(!visit(p->data))
            return ERROR;
    }
    return OK;
}/*遍历输出顺序表中所有元素, 原始的遍历仅仅是访问,并不输出*/
Status ListTransver(LinkList L)
{
    LinkList p;
    for(p=L->next; p; p=p->next)
    {
        printf("%d  ", p->data);
    }
    return OK;
}/*遍历输出顺序表中所有元素*/
Status ListOppose(LinkList &L)
{
    LinkList p, q;//临时变量
    p=L;//用p记录下链表的首地址,以便后续覆盖L中存储的链表首地址
    p=p->next;//首地址来访问头结点
    L->next=NULL;//将链表的首地址清空,以便重新插入结点
    while(p)
    {
        q=p;//q现在所指向的就是旧的链表的头结点
        p=p->next;//p指针后移,指向首元结点
        q->next=L->next;//第一次循环是将NULL赋给了q->next
        L->next=q;//然后将旧链表首地址给了L->next,
    }
    return OK;
}//就地倒置元素
Status ListEmpty(LinkList L)
{
    if(L->next==NULL)
    {
        printf("Empty!\n");
        return TRUE;
    }
    else
    {
        printf("Not empty!\n");
        return FALSE;
    }
}//判断链表是否为空

//Status ListDelete_Homework(LinkList &L, ElemType mink, ElemType maxk)
//{
//    //删除表中所有值大于maxk和小于mink的元素,同时释放被删结点的空间, mink和maxk是给定的参数
//    LinkList p, q, prev=NULL;
//    if(mink>maxk)//确定参数合法
//        return ERROR;
//    p=L;
//    prev=p;
//    p=p->next;
//    while(p&&p->data<maxk)
//    {//在链表中,元素的值小于给定的最大值
//        if(p->data<=mink)
//        {//元素值大于等于最小值
//            prev=p;//记录元素位置
//            p=p->next;//指针指向下一个元素
//        }
//        else//若元素值小于最小值,就删除
//        {   prev->next=p->next;//记录的指针向后移动
//            q=p;
//            p=p->next;
//            free(q);
//        }
//    }
//    return OK;
//}