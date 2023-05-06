//链栈的实现
#include <stdio.h>
#include <stdlib.h>

# define MaxSize 10
typedef struct LinkNode {
    int data;
    struct LinkNode* next;
} *LinkStack;

//函数声明
bool InitStack(LinkStack& LS);//初始化
bool Push(LinkStack& LS, int t);//入栈 参考头插法建立单链表
bool Pop(LinkStack& LS, int& x);//出栈,并打印出栈顶元素
bool GetTop(LinkStack LS, int& x);//读取栈顶元素，栈

//初始化
bool InitStack(LinkStack& LS) {
    LS = (LinkNode*)malloc(sizeof(LinkNode));//分配一个头节点
    if (LS == NULL) {
        return false;
    }
    LS->next = NULL;
    return true;
}

//入栈
bool Push(LinkStack& LS, int t) {
    LinkNode* s = (LinkNode*)malloc(sizeof(LinkNode));
    if (s == NULL)return false;
    s->data = t;
    s->next = LS->next;
    LS->next = s;
    return true;
}

//出栈
bool Pop(LinkStack& LS, int& x) {
    //判断
    if (LS->next == NULL)return false;//栈空,这里的条件
    LinkNode* q;
    q = LS->next;
    LS->next = q->next;
    x = q->data;
    free(q);
    return true;
}

//获取栈顶元素
bool GetTop(LinkStack LS, int& x) {
    if (LS == NULL)return false;
    x = LS->next->data;
    return true;
}
