//循环单链表
#include <stdio.h>
#include <stdlib.h>

typedef struct LNode {
    int data;
    struct LNode* next;
}LNode, * LinkList;

//函数声明
bool InitRLinkList(LinkList& L);//初始化
bool IsTail(LinkList L, LNode* p);//判断P是不是表尾指针

//初始化一个循环单链表
bool InitRLinkList(LinkList& L) {
    L = (LNode*)malloc(sizeof(LNode));//分配一个头节点
    if (L == NULL)
        return false;//内存不足，分配失败；
    L->next = L;//头节点nex指向头节点，以此形成循环链表
    return true;
}

//判空
bool Empty(LinkList L)
{
    if (L->next == L)
        return true;
    else
        return false;
}

//判断P是不是表尾指针
bool IsTail(LinkList L, LNode* p) {
    return (p->next == L);
}

//循环双链表

typedef struct DNode {
    int data;
    struct DNode* prior, * next;
}DNode, * DLinkList;

//函数声明
bool InitRDLinkList(DLinkList& L);//初始化
bool iTail(DLinkList L, DNode* p);//判断节点p是不是循环双链表的表尾节点
bool InsertNextDNode(DNode* p, DNode* s);//在p节点之后插入s节点
bool DeleteNextDNode(DLinkList& L, DNode* p);//删除操作

//初始化
bool InitRDLinkList(DLinkList& L) {
    L = (DNode*)malloc(sizeof(DNode));//分配头节点
    if (L == NULL)return false;
    L->prior = L;
    L->next = L;//循环抱住自己
    return true;
}

//判断节点p是不是循环双链表的表尾节点
bool iTail(DLinkList L, DNode* p) {
    return (p->next == L);
}

//在p节点之后插入s节点
bool InsertNextDNode(DNode* p, DNode* s) {
    s->next = p->next;
    p->next->prior = s;
    s->prior = p;
    p->next = s;
    return true;
}

//删除操作
bool DeleteNextDNode(DLinkList& L, DNode* p) {
    DNode* q = p->next;
    p->next = q->next;
    q->next->prior = p;
    free(q);
    return true;
}