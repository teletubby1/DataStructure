//带头节点的单链表

#include <stdio.h>
#include <stdlib.h>

//结构体
typedef struct LNode {
    int data;
    LNode* next;
} LNode, * LinkList;

//函数定义
bool InitList(LinkList& L);     //初始化
bool Empty(LinkList L);         //判空
bool ListInsert(LinkList& L, int i, int e);//按位插入
bool InsertNextNode(LNode* p, int e);//指定节点的后插操作
bool InsertPriorNode(LNode* p, int e);//指定节点的前插操作————先完成后插，再交换数据以实现前插
bool ListDelete(LinkList& L, int i, int& e);//按指定位序删除节点并返回其值
bool DeleteNode(LNode* p);//删除指定节点

//初试化(带有头节点)
bool InitList(LinkList& L) {
    L = (LNode*)malloc(sizeof(LNode));//分配一个头节点
    if (L == NULL)
        return false;//头节点分配失败，可能是内存不足
    L->next = NULL;//头节点之后暂时没有节点，头节点也不存放数据
    return true;
}

//判空
bool Empty(LinkList L) {
    //    if(L->next==NULL)
    //        return true;
    //    else
    //        return false;
    return (L->next == NULL);
}

//按位插入
bool ListInsert(LinkList& L, int i, int e) {
    if (i < 1)return false;//判断位序i是否合法
    LNode* p;//指针指向当前扫面到的节点
    int j = 0;//记录p指向的节点的位序
    p = L;//L指向头节点，从头开始
    while (p != NULL && j < i - 1) {
        //循环扫描
        p = p->next;
        j++;
    }
    if (p == NULL) //i值超过来表长，不合法
        return false;
    LNode* s = (LNode*)malloc(sizeof(LNode));
    s->data = e;
    //下面的顺序不可交换
    s->next = p->next;
    p->next = s; //将结点s连到p之后
    return true;
}

//指定节点的后插操作
bool InsertNextNode(LNode* p, int e) {
    if (p == NULL)
        return false;//判断指定节点是否存在
    LNode* s = (LNode*)malloc(sizeof(LNode));
    if (s == NULL)return false;//分配内存失败
    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}

//指定节点的前插操作
//先完成后插，再交换数据以实现前插
bool InsertPriorNode(LNode* p, int e) {
    if (p == NULL)return false;
    LNode* s = (LNode*)malloc(sizeof(LNode));
    if (s == NULL)return false;
    s->next = p->next;
    p->next = s;
    s->data = p->data;
    p->data = e;
    return true;
}

//按指定位序删除节点并返回其值
bool ListDelete(LinkList& L, int i, int& e) {
    if (i < 1)return false;
    LNode* p;
    int j = 0;
    p = L;
    while (p != NULL && j < i - 1) {
        p = p->next;
        j++;
    }
    LNode* q = p->next;
    e = q->data;
    p->next = q->next;
    free(q);
    return true;
}

//删除指定节点
bool DeleteNode(LNode* p) {
    if (p == NULL)
    {
        return false;
    }
    LNode* q = p->next;//令q指向*p的后续结点
    p->data = p->next->data;//和后续结点交换数据域
    p->next = q->next;//将*q结点从链中“断开”
    free(q);//释放后续结点的存储空间
    return true;
}

//按值查找
LNode* LocateElem(LinkList L, int e)
{
    LNode* p = L->next;//从第1个结点开始查找数据域为e的结点
    while (p != NULL && p->data != e)
    {
        p = p->next;
    }
    return p;//找到后返回该结点指针，否则返回NULL；
}

//按位查找
LNode* GetElem(LinkList L, int i)
{
    if (i < 0)
    {
        return NULL;
    }
    LNode* p;//指针p指向当前扫描到的结点
    int j = 0;//当前p指向的是第几个结点
    p = L;//L指向头结点，头结点是第0个结点（不存数据）
    while (p != NULL && j < i)
    {
        p = p->next;
        j++;
    }
    return p;
}

//求表长
int Lnegth(LinkList L)
{
    int len = 0;//统计表长
    LNode* p = L;
    while (p->next != NULL)
    {
        p = p->next;
        len++;
    }
    return len;
}

//尾插法建立单链表（正向建立单链表）
LinkList List_TailInsert(LinkList& L)
{
    int x;
    L = (LinkList)malloc(sizeof(LNode));//建立头结点
    LNode* s, * r = L;//r为表尾指针，方便尾插
    scanf("%d", &x);//输入结点的值
    while (x != 9999)//输入9999表示结束
    {
        s = (LNode*)malloc(sizeof(LNode));
        s->data = x;
        r->next = s;
        r = s;//r指向新的表尾结点，永远保持r指向最后一个结点，避免重复操作
        scanf("%d", &x);
    }
    r->next = NULL;
    return L;
}

//头插法建立单链表(不断对头结点进行尾插操作）
LinkList List_HeadInsert(LinkList& L)//逆向建立单链表
{
    LNode* s;
    int x;
    L = (LinkList)malloc(sizeof(LNode));//创建头结点
    L->next = NULL;//初始为空链表
    scanf("%d", &x);//输入结点的值
    while (x != 9999)//输入9999表示结束
    {
        s = (LNode*)malloc(sizeof(LNode));//创建新结点
        s->data = x;
        s->next = L->next;
        L->next = s;//将新结点插入表中，L为头指针
        scanf("%d", &x);
    }
    return L;
}

void PrintList(LinkList L) {
    //循环打印整个链表
    LNode* p = L->next;//扫描指针
    int j = 0;
    if (p == NULL)printf("这是一个空表\n");
    while (p != NULL) {
        printf("LinkList[%d]=%d\n", j, p->data);
        p = p->next;
        j++;
    }
}
