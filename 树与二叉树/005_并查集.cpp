#include<iostream>

using namespace std;

#define SIZE 10
int UFSets[SIZE];//集合元素数组

//初始化
void Initial(int S[])
{
	for (int i = 0; i < SIZE; i++)
		S[i] = -1;
}

//查，找到x所属集合（返回x所属根节点）
int Find(int S[], int x)
{
	while (S[x] >= 0)
		x = S[x];
	return x;//根节点S[]小于0
}

//查优化，压缩路径
int Find2(int S[], int x)
{
	int root = x;
	while (S[root] >= 0) root = S[root];//循环找到根
	while (x != root) //压缩路径
	{
		int t = S[x];//t指向x的父节点
		S[x] = root;//x直接挂到根节点下
		x = t;
	}
	return root;
}

//并，将两个集合根节点传入，合并为一个
void Union(int S[], int Root1, int Root2)
{
	//判断为不同集合
	if (Root1 == Root2) return;
	//将根Root2连接到另一根Root1下面
	S[Root2] = Root1;
}

//并优化，让小树合并到大树，用根节点的绝对值表示树的结点总数
void Union2(int S[], int Root1, int Root2)
{
	if (Root1 == Root2) return;
	if (S[Root2] > S[Root2]) //Root2更大，绝对值更小，结点数更小
	{
		S[Root1] += S[Root2];//累加结点总数
		S[Root2] = Root1;//小树合并到大树
	}
	else
	{
		S[Root2] += S[Root1];
		S[Root1] = Root2;
	}
}
