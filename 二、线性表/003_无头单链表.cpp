//不带头节点的单链表

#include <stdio.h>
#include <stdlib.h>

//结构体
typedef struct LNode {
    int data;
    struct LNode* next;
} LNode, * LinkList;
//等价于
//struct LNode{
//    int data;
//    struct LNode *next;
//};
//
//typedef struct LNode LNode;
//typedef struct LNode *LinkList;

//函数声明
bool InitList(LinkList& L);//初始化
bool Empty(LinkList L);//判空
bool ListInsert(LinkList& L, int i, int e);//插入

//初始化
bool InitList(LinkList& L) {
    L = NULL;//空表暂时没有任何数据
    return true;
}

//判断是否为空
bool Empty(LinkList L) {
    return (L == NULL);
}
//等价于
//bool Empty1(LinkList L){
//    if (L==NULL)
//        return true;
//    else
//        return false;
//}

//在指定位置插入元素
bool ListInsert(LinkList& L, int i, int e) {
    if (i < 1)return false;//判断位序i是否合法
    //不带头节点时，插入位置正好为表头时，得单独处理
    if (i = 1) {
        LNode* s = (LNode*)malloc(sizeof(LNode));
        s->data = e;
        s->next = L;
        L = s;
        return true;
    }
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
    p->next = s;
    return true;
}

void PrintList(LinkList L) {
    //循环打印整个链表
    LNode* p = L;//扫描指针
    int j = 0;
    if (p == NULL)printf("这是一个空表\n");
    while (p != NULL) {
        printf("LinkList[%d]=%d", j, p->data);
        p = p->next;
        j++;
    }
}