#include <iostream>

using namespace std;

#define MaxSize 100

struct TreeNode {
    int value;//结点中的数据元素
    bool isEmpty;//判断结点是否为空
};

int main()
{
    TreeNode t[MaxSize];//定义一个长度为MaxSize的数组t，按照从上至下，从左至右的顺序依次存储二叉树中的各个结点

    for (int i = 0; i < MaxSize; i++)
    {
        t[i].isEmpty = true;//初始化时所有结点标记为空
    }
}