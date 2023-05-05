//静态链表
#include <stdlib.h>
#include <stdlib.h>

#define MaxSize 10 //静态链表最大长度


//第一种定义方法
struct Node0 {
    int data;//存储数据元素
    int next;//下一个元素的数组下标
};
typedef struct Node SLinkList[MaxSize];

//第二种定义方法
typedef struct Node {
    int data;
    int next;
}SLinkList[MaxSize];

