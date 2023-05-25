#include<iostream>

using namespace std;

#define MaxVertexNum 100//图中顶点数目的最大值

//定义邻接表
typedef char VertexType;//顶点的数据类型
//“边/弧”
typedef struct ArcNode
{
	int adjvex;//边/弧指向哪个节点
	struct ArcNode* nextarc;//指向下一条弧的指针
	//InfoType info;//权值
}ArcNode;
//“顶点”
typedef struct VNode
{
	VertexType data;//顶点信息
	ArcNode* firstarc;//第一条边/弧
}VNode, AdjList[MaxVertexNum];
//用邻接表存储的图
typedef struct
{
	AdjList vertices;
	int vexnum, arcnum;
}ALGraph;


//拓扑排序
bool TopologicalSort(Graph G)
{
	InitStack(S);//初始化栈，存储入度为0的结点
	for (int i = 0; i < G.vexnum; i++)
	{
		if (indegree[i] == 0)
		{
			Push(S, i);//将所有入度为0的顶点进栈
		}
	}
	int count = 0;//计数，记录当前已经输出的顶点数
	while (!IsEmpty(S))//栈不空，则存在入度为0的顶点
	{
		Pop(S, i);//栈顶元素出栈
		print(count++) = i;//输出顶点i
		for (p = G.vertices[i].firstarc; p; p = p->nextarc)
		{
			//将所有i指向的顶点的入度减1，并且将入度为0的顶点压入栈S
			v = p->adjvex;
			if (!(--indegree[v]))//若为0
			{
				Push(S, v);//入栈
			}
		}
	}
	if (count < G.vexnum)
	{
		return false;//排序失败，有向图中有回路
	}
	else
		return true;//拓扑排序成功
}

//逆拓扑排序
void DFSTraverse(Graph G)//深度优先遍历图G
{
	for (v = 0; v < G.vexnum; ++v)
		visited[v] = false;//初始化已访问标记数据
	for (v = 0; v < G.vexnum; ++v)//从v=0开始遍历
		if (!visited[v])
			DFS(G, v);
}

void DFS(Graph G, int v)//从顶点v触发，深度优先遍历图G
{
	visit(v);//访问顶点v
	visited[v] = true;//设已访问标记
	for (w = FirstNeighbor(G, v); w >= 0; w = NextNeighbor(G, v, w))
	{
		if (!visited[w])
		{
			DFS(G, w); // w为v的尚未访问的邻接顶点
		}
	}
	print(v);//输出顶点
}

int main()
{
	return 0;
}