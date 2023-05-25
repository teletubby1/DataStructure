#include<iostream>

using namespace std;

//邻接矩阵
#define MaxVertexNum 100//顶点数目的最大值
typedef struct
{
	char Vex[MaxVertexNum];//顶点表 （可存更复杂的信息）
	int Edge[MaxVertexNum][MaxVertexNum];//邻接矩阵，边表（可以用bool型或枚举型变量表示边）
	int vexnum, arcnum;//图的当前顶点数和边数/弧数
}MGraph;

//邻接表
typedef char VertexType;//顶点的数据类型
//“边/弧”
typedef struct ArcNode
{
	int adjvex;//边/弧指向哪个节点
	struct ArcNode* next;//指向下一条弧的指针
	//InfoType info;//权值
}ArcNode;
//“顶点”
typedef struct VNode
{
	VertexType data;//顶点信息
	ArcNode* first;//第一条边/弧
}VNode,AdjList[MaxVertexNum];
//用邻接表存储的图
typedef struct
{
	AdjList vertices;
	int vexnum, arcnum;
}ALGraph;

int main()
{
	return 0;
}