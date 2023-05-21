#include<iostream>

using namespace std;

//树——双亲表示法（顺序存储法）
#define MAX_TREE_SIZE 100

typedef struct {
    int data; //数据元素
    int parent;//双亲位置域
}PTNode;
typedef struct {
    PTNode nodes[MAX_TREE_SIZE];//双亲表示
    int n;//结点数
}PTree;

//树——孩子表示法（顺序+链式存储）
struct CTNode {
    int child;//孩子节点在数组中的位置
    struct CTNode* next;//下一个孩子
};
typedef struct {
    int data; //数据元素，数据元素类型不定
    struct CTNode* firstChild;//第一个孩子
}CTBox;
typedef struct {
    CTBox nodes[MAX_TREE_SIZE];//双亲表示
    int n, r;//结点数和根的位置
}CTree;

//树——孩子兄弟表示法（链式存储）
typedef struct CSNode {
    int data; //数据域，数据类型不定
    struct CSNode* firstChild, * nextsibiling;//第一个孩子和右兄弟指针
}CSNode, * CSTree;

int main()
{
	return 0;
}