/*
 * ����ʵ��,��ʼ���ɹ�
 * */
#include "linklist.h"
//using namespace std;
//int main()
//{   LinkList L;
//    ElemType e=0; int j=0, N;
//    cout<<"please input the number of elements:";
//    cin>>N;
//    for(int i=0; i<N; i++)
//    {
//        printf("������%d������:", N);
//        InitList(L);
//        for(j=1; j <=N; ++j)
//        {   scanf("%d", &e);
//            ListInsert(L, j, e);
//        }
//        ListEmpty(L);//�ж��Ƿ����ɹ�
//        ListTransver(L);//��������еĸ���Ԫ��
//
//        GetElem(L, 3, e);//�������ж�ȡԪ��
//        printf("\n�����еĵ�3��Ԫ����%d\n", e);//��ȡ����һ��Ԫ��
//
//        printf("\n��������: %d", ListLength(L));
//        printf("\n4��ǰ��Ԫ����:%d", PriorElem(L, 4, e));
//        printf("\n4�ĺ��Ԫ����:%d\n", NextElem(L, 4, e));
//
//        ListDelete(L, 2, e);//ɾ����2��Ԫ��
//        printf("ɾ����2��Ԫ�غ�");
//        ListTransver(L);//�������
//
//        ListOppose(L);//��������
//        printf("\n���ú�:");
//        ListTransver(L);//�������
//
////    ListDelete_Homework(L, 3, 5);//ɾ������3��5֮���Ԫ��
////    printf("ɾ������3��5֮���Ԫ�غ�:");
////    ListTransver(L);//�������
//
//        printf("\n��λ��һ�����,�������д洢��data:%d\n", LocateElem(L, 1)->data);
//
//        ClearList(L);//�������
//        ListEmpty(L);//�п�
//        DestroyList(L);
//        ListEmpty(L);
//    }
//    return 0;
//}

/* main2-1.c ����bo2-1.c�������� */
#include"c1.h"
typedef int ElemType;
#include"c2-1.h"
#include"bo2-1.c"

Status comp(ElemType c1,ElemType c2) /* ����Ԫ���ж�����(ƽ����ϵ) */
{
    if(c1==c2*c2)
        return TRUE;
    else
        return FALSE;
}

void visit(ElemType *c) /* ListTraverse()���õĺ���(����Ҫһ��) */
{
    printf("%d ",*c);
}

void dbl(ElemType *c) /* ListTraverse()���õ���һ����(Ԫ��ֵ�ӱ�) */
{
    *c*=2;
}

int main()
{
    SqList L;
    ElemType e,e0;
    Status i;
    int j,k;
    i=InitList(&L);
    printf("��ʼ��L��L.elem=%u L.length=%d L.listsize=%d\n",L.elem,L.length,L.listsize);
    for(j=1;j<=5;j++)
        i=ListInsert(&L,1,j);
    printf("��L�ı�ͷ���β���1��5��*L.elem=");
    for(j=1;j<=5;j++)
        printf("%d ",*(L.elem+j-1));
    printf("\n");
    printf("L.elem=%u L.length=%d L.listsize=%d\n",L.elem,L.length,L.listsize);
    i=ListEmpty(L);
    printf("L�Ƿ�գ�i=%d(1:�� 0:��)\n",i);
    i=ClearList(&L);
    printf("���L��L.elem=%u L.length=%d L.listsize=%d\n",L.elem,L.length,L.listsize);
    i=ListEmpty(L);
    printf("L�Ƿ�գ�i=%d(1:�� 0:��)\n",i);
    for(j=1;j<=10;j++)
        ListInsert(&L,j,j);
    printf("��L�ı�β���β���1��10��*L.elem=");
    for(j=1;j<=10;j++)
        printf("%d ",*(L.elem+j-1));
    printf("\n");
    printf("L.elem=%u L.length=%d L.listsize=%d\n",L.elem,L.length,L.listsize);
    ListInsert(&L,1,0);
    printf("��L�ı�ͷ����0��*L.elem=");
    for(j=1;j<=ListLength(L);j++) /* ListLength(L)ΪԪ�ظ��� */
        printf("%d ",*(L.elem+j-1));
    printf("\n");
    printf("L.elem=%u(�п��ܸı�) L.length=%d(�ı�) L.listsize=%d(�ı�)\n",L.elem,L.length,L.listsize);
    GetElem(L,5,&e);
    printf("��5��Ԫ�ص�ֵΪ��%d\n",e);
    for(j=3;j<=4;j++)
    {
        k=LocateElem(L,j,comp);
        if(k)
            printf("��%d��Ԫ�ص�ֵΪ%d��ƽ��\n",k,j);
        else
            printf("û��ֵΪ%d��ƽ����Ԫ��\n",j);
    }
    for(j=1;j<=2;j++) /* ����ͷ�������� */
    {
        GetElem(L,j,&e0); /* �ѵ�j�����ݸ���e0 */
        i=PriorElem(L,e0,&e); /* ��e0��ǰ�� */
        if(i==INFEASIBLE)
            printf("Ԫ��%d��ǰ��\n",e0);
        else
            printf("Ԫ��%d��ǰ��Ϊ��%d\n",e0,e);
    }
    for(j=ListLength(L)-1;j<=ListLength(L);j++) /* ����������� */
    {
        GetElem(L,j,&e0); /* �ѵ�j�����ݸ���e0 */
        i=NextElem(L,e0,&e); /* ��e0�ĺ�� */
        if(i==INFEASIBLE)
            printf("Ԫ��%d�޺��\n",e0);
        else
            printf("Ԫ��%d�ĺ��Ϊ��%d\n",e0,e);
    }
    k=ListLength(L); /* kΪ�� */
    for(j=k+1;j>=k;j--)
    {
        i=ListDelete(&L,j,&e); /* ɾ����j������ */
        if(i==ERROR)
            printf("ɾ����%d������ʧ��\n",j);
        else
            printf("ɾ����Ԫ��ֵΪ��%d\n",e);
    }
    printf("�������L��Ԫ�أ�");
    ListTraverse(L,visit); /* ���ζ�Ԫ�ص���visit()�����Ԫ�ص�ֵ */
    printf("L��Ԫ��ֵ�ӱ���");
    ListTraverse(L,dbl); /* ���ζ�Ԫ�ص���dbl()��Ԫ��ֵ��2 */
    ListTraverse(L,visit);
    DestroyList(&L);
    printf("����L��L.elem=%u L.length=%d L.listsize=%d\n",L.elem,L.length,L.listsize);

    return 0;
}