#include<iostream>

using namespace std;

#define MAX_VERTEX_NUM 100//顶点数目的最大值

bool visited[MAX_VERTEX_NUM];//访问标记数组

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
}

int main()
{
	return 0;
}