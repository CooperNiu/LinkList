/*
 * 链表实现,初始化成功
 * */
#include "linklist.h"
using namespace std;
int main()
{   LinkList L;
    ElemType e=0; int j=0, N;
    cout<<"please input the number of elements:";
    cin>>N;
    for(int i=0; i<N; i++)
    {
        printf("请输入%d个整数:", N);
        InitList(L);
        for(j=1; j <=N; ++j)
        {   scanf("%d", &e);
            ListInsert(L, j, e);
        }
        ListEmpty(L);//判断是否插入成功
        ListTransver(L);//输出链表中的各项元素

        GetElem(L, 3, e);//从链表中读取元素
        printf("\n链表中的第3个元素是%d\n", e);//读取其中一个元素

        printf("\n链表长度是: %d", ListLength(L));
        printf("\n4的前驱元素是:%d", PriorElem(L, 4, e));
        printf("\n4的后继元素是:%d\n", NextElem(L, 4, e));

        ListDelete(L, 2, e);//删除第2个元素
        printf("删除第2个元素后");
        ListTransver(L);//输出各项

        ListOppose(L);//逆置链表
        printf("\n逆置后:");
        ListTransver(L);//输出各项

//    ListDelete_Homework(L, 3, 5);//删除介于3和5之间的元素
//    printf("删除介于3和5之间的元素后:");
//    ListTransver(L);//输出各项

        printf("\n定位第一个结点,输出结点中存储的data:%d\n", LocateElem(L, 1)->data);

        ClearList(L);//清空链表
        ListEmpty(L);//判空
    DestroyList(L);
        ListEmpty(L);
    }
    return 0;
}