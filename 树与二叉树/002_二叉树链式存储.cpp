#include<iostream>

using namespace std;

//定义储存数据类型
struct ElemType {
    int value;
};

typedef struct BiTNode {
    ElemType data;//数据域
    struct BiTNode* lchild, * rchild;//左右孩子指针
} BiTNode, * BiTree;

//初始化
void InitTree(BiTree root) {
    root = (BiTree)malloc(sizeof(BiTNode));
    root->data = { 1 };
    root->lchild = NULL;
    root->rchild = NULL;
}

//插入新结点
bool InsertNode(BiTree T, ElemType val) {
    BiTNode* p = (BiTNode*)malloc(sizeof(BiTNode));
    p->data = val;
    p->lchild = NULL;
    p->rchild = NULL;
    T->lchild = p;//作为左孩子
}

//访问函数
void visit(BiTree T) {
    printf("%d", T->data.value);
}

//先序遍历
void PreOder(BiTree T) {
    if (T != NULL) {
        visit(T);//访问根节点
        PreOder(T->lchild);//遍历左子树
        PreOder(T->rchild);//遍历右子树
    }
}

//中序遍历
void InOrder(BiTree T) {
    if (T != NULL) {
        InOrder(T->lchild);//遍历左子树
        visit(T);//访问根节点
        InOrder(T->rchild);//遍历右子树
    }
}

//后序遍历
void PostOder(BiTree T) {
    if (T != NULL) {
        PostOder(T->lchild);
        PostOder(T->rchild);
        visit(T);
    }
}

//用于层序遍历的辅助队列
typedef struct LinkNode {
    BiTNode* data;//存的是指针而非结点
    struct LinkNode* next;
} LinkNode;

typedef struct {
    LinkNode* front, * rear;//队头队尾
} LinkQueue;

void InitQueue(LinkQueue& Q) {
    Q.front = Q.rear = (LinkNode*)malloc(sizeof(LinkNode));
    //初始化时，front 、rear 都指向头节点
    Q.front->next = NULL;
}

bool EnQueue(LinkQueue& Q, BiTNode* x) {
    //判满？链式存储一般不需要判满，除非内存不足
    LinkNode* s = (LinkNode*)malloc(sizeof(LinkNode));
    if (s == NULL)return false;
    s->data = x;
    s->next = NULL;
    Q.rear->next = s;//新节点插入到rear之后
    Q.rear = s;//修改表尾指针
    return true;
}

bool DeQueue(LinkQueue& Q, BiTNode* x) {
    if (Q.front == Q.rear)return false;//队空
    LinkNode* p = Q.front->next;//用指针p记录队头元素
    x = p->data;//用x变量返回队头元素
    Q.front->next = p->next;//修改头节点的next指针
    if (Q.rear == p)//此次是最后一个节点出队
        Q.rear = Q.front;//修改rear指针，思考一下为什么？
    free(p); //释放节点空间
    return true;
}

bool isEmpty(LinkQueue Q) {
    return Q.front == Q.rear ? true : false;
}

//层序遍历
void levelOrder(BiTree T) {
    LinkQueue Q;//辅助队列
    InitQueue(Q);//
    BiTree p;
    EnQueue(Q, T);
    while (!isEmpty(Q)) {
        DeQueue(Q, p);//队头结点出队
        visit(p);
        if (p->lchild != NULL)
            EnQueue(Q, p->lchild);
        if (p->rchild != NULL)
            EnQueue(Q, p->rchild);
    }
}

//非递归实现
//顺序栈结构体
#define MaxSize 10 //定义栈中元素的最大个数
typedef struct
{
    BiTree data[MaxSize];//静态数组存放栈中元素
    int top;//栈顶指针
} SqStack;

//初始化
void InitStack(SqStack& S)
{
    S.top = -1;//初始化栈顶指针 若为0.则指向下一个插入的位置
}

//判空
bool IsEmpty(SqStack S)
{
    if (S.top == -1) return true;//判空
    else return false;
}

//进栈
bool Push(SqStack& S, BiTree x)
{
    if (S.top == MaxSize - 1)//栈满，报错
        return false;
    S.top = S.top + 1;//先加1
    S.data[S.top] = x;//新元素入栈 这两行等价于S.data[++S.top]=x;
    return true;
}

//出栈
bool Pop(SqStack& S, BiTree& x)
{
    if (S.top == -1) return false;//栈空，报错
    x = S.data[S.top];//栈顶元素先出栈
    S.top = S.top - 1;//指针再减一 这两行等价于 x=S.data[S.top--]
    return true;
}

//中序遍历
void InOrder2(BiTree T)
{
    SqStack S;
    InitStack(S);//初始化栈
    BiTree p = T;//p为遍历指针
    while (p || !IsEmpty(S))
    {
        if (p)
        {
            Push(S, p);//当前结点入栈
            p = p->lchild;//左孩子不空，一直向左走
        }
        else //出栈，并转向出栈结点的右子树
        {
            Pop(S, p); visit(p);//栈顶元素出栈，访问出栈结点
            p = p->rchild;//向右子树走，p赋值为当前结点的右孩子
        }//返回while循环继续进入if-else语句
    }
}

//先序遍历
void PreOrder2(BiTree T)
{
    SqStack S;
    InitStack(S); BiTree p = T;//初始化栈S；p是遍历指针
    while (p || !IsEmpty(S)) //栈不空或p不空时循环
    {
        if (p) //一路向左
        {
            visit(p); Push(S, p);//访问当前结点，并入栈
            p = p->lchild;//左孩子不空，一直向左走
        }
        else //出栈，并转向出栈结点的右子树
        {
            Pop(S, p);//栈顶元素出栈
            p = p->rchild;//向右子树走，p赋值为当前结点的右孩子
        } //返回while循环继续进入if-else语句
    }
}

//求树的深度
int treeDepth(BiTree T)
{
    if (T == NULL)
    {
        return 0;
    }
    else
    {
        int l = treeDepth(T->lchild);
        int r = treeDepth(T->rchild);
        //树的深度=Max（左子树深度，右子树深度）+1
        return l > r ? l + 1 : r + 1;
    }
}