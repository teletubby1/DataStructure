#include<iostream>

using namespace std;

#define MAX_VERTEX_NUM 100//顶点数目的最大值

bool visited[MAX_VERTEX_NUM];//访问标记数组
void BFSTraverse(Graph G) //对图G进行广度优先遍历
{
	for (int i = 0; i < G.vexnum; ++i)
		visited[i] = false;//访问标记数组初始化
	InitQueue(Q);//初始化辅助队列Q
	for (int i = 0; i < G.vexnum; ++i)//从0号顶点开始遍历
	{
		if (!visited[i])//对每个连通分量调用一次BFS
			BFS(G, i);//vi未访问过，从vi开始BFS
	}
}

//广度优先遍历
void BFS(Graph G, int v) //从顶点v出发，广度优先遍历图G
{
	visit(v);//访问初始顶点v
	visited[v] = true;//对v做已访问标记
	Enqueue(Q, v);//顶点v入队列Q
	while (!isEmpty(Q))
	{
		DeQueue(Q, v);//顶点v处队列
		for (w = FirstNeighbor(G, v); w >= 0; w = NextNeighbor(G, v, w))
		{
			//检测v所有邻接点
			if (!visited[w])//w为v的尚未访问的邻接顶点
			{
				visit(w);//访问顶点w
				visited[w] = true;//对w做已访问标记
				EnQueue(Q, w);//顶点w入队列
			}
		}
	}
}

//解决非带权图的单源最短路径问题
void BFS_MIN_Distance(Graph G, int u)
{
	//d[i]表示从u到i结点的最短路径
	for (int i = 0; i < G.vexnum; ++i)
	{
		d[i] = 0x3f3f3f3f;//无穷大，初始化路径长度
	}
	visited[u] = true;
	d[u] = 0;
	EnQueue(Q, u);
	while (!isEmpty(Q))//BFS算法主过程
	{
		DeQueue(Q, u);//队头元素u出队
		for (w = FirstNeighbor(G, u); w >= 0; w = NextNeighbor(G, u, w))
		{
			if (!visited[w])//w为u的尚未访问的邻接顶点
			{
				visited[w] = true;//设已访问标记
				d[w] = d[u] + 1;//路径长度加1
				EnQueue(Q, w);//顶点w入队
			}
		}
	}
}


int main()
{
	return 0;
}