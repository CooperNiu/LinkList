/*
 * ����ʵ��,��ʼ���ɹ�
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
        printf("������%d������:", N);
        InitList(L);
        for(j=1; j <=N; ++j)
        {   scanf("%d", &e);
            ListInsert(L, j, e);
        }
        ListEmpty(L);//�ж��Ƿ����ɹ�
        ListTransver(L);//��������еĸ���Ԫ��

        GetElem(L, 3, e);//�������ж�ȡԪ��
        printf("\n�����еĵ�3��Ԫ����%d\n", e);//��ȡ����һ��Ԫ��

        printf("\n��������: %d", ListLength(L));
        printf("\n4��ǰ��Ԫ����:%d", PriorElem(L, 4, e));
        printf("\n4�ĺ��Ԫ����:%d\n", NextElem(L, 4, e));

        ListDelete(L, 2, e);//ɾ����2��Ԫ��
        printf("ɾ����2��Ԫ�غ�");
        ListTransver(L);//�������

        ListOppose(L);//��������
        printf("\n���ú�:");
        ListTransver(L);//�������

//    ListDelete_Homework(L, 3, 5);//ɾ������3��5֮���Ԫ��
//    printf("ɾ������3��5֮���Ԫ�غ�:");
//    ListTransver(L);//�������

        printf("\n��λ��һ�����,�������д洢��data:%d\n", LocateElem(L, 1)->data);

        ClearList(L);//�������
        ListEmpty(L);//�п�
    DestroyList(L);
        ListEmpty(L);
    }
    return 0;
}