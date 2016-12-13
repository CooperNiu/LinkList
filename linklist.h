//linklist.h
// Created by Cooper on 11/10/2016.
#ifndef LINKLIST_LINKLIST_H
#define LINKLIST_LINKLIST_H

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include "constant.h"

#define LIST_INIT_SIZE 100  // 存储空间的创始分配量
#define LISTINCREMENT 10 //空间的分配增量

typedef struct LNode{
    ElemType data; //数据域
    struct LNode *next; //指针域
}LNode, *LinkList;//LNode是结点的名称, 而*LinkList是指向结点的指针

Status InitList(LinkList &L);    //构造一个空的链表
void DestroyList(LinkList &L);    //销毁链表
void ClearList(LinkList L); //清空链表
int ListLength(LinkList L);   //求链表长度
ElemType GetElem(LinkList L, int i, ElemType &e); //取元素
LinkList LocateElem(LinkList L, ElemType e);//定位元素
ElemType PriorElem(LinkList L, ElemType cur_e, ElemType &pre_e);//求前驱元素
ElemType NextElem(LinkList L, ElemType cur_e, ElemType &next_e);//求后继元素
Status ListInsert(LinkList &L, int i, ElemType &e);//插入元素
Status ListDelete(LinkList &L, int i, ElemType &e);//删除元素
Status ListOppose(LinkList &L);//倒置元素
Status ListEmpty(LinkList L);//清空链表
Status compare(ElemType a , ElemType b );
Status ListDelete_Homework(LinkList &L, ElemType mink, ElemType maxk);
Status ListTransver(LinkList L);
//Status ListTransver(LinkList L, Status (*visit)(ElemType));
#endif //LINKLIST_LINKLIST_H
