#include<iostream>

using namespace std;

//顺序存储
#define MAXLEN 255 //预定义最大串长为255
//静态数组
typedef struct {
	char ch[MAXLEN]; //每个分量存储一个字符
	int length; //串的实际长度
}SString;

//朴素模式匹配算法
int Index(SString S, SString T)
{
	int i = 1, j = 1;
	while (i <= S.length && j <= T.length)
	{
		if (S.ch[i] = T.ch[j]) {
			++i; ++j; //继续比较后继字符
		}
		else {
			i = i - j + 2;
			j = 1; //指针后退重新开始匹配
		}
	}
	if (j > T.length)
		return i - T.length;
	else return 0;
}

//KMP算法
int Index_KMP(SString S, SString T, int next[])
{
	int i = 1, j = 1;
	while (i <= S.length && j <= T.length)
	{
		if (j == 0 || S.ch[i] == T.ch[j])
		{
			++i;
			++j; //继续比较后继字符
		}
		else j = next[j];//模式串向右移动，主串不回溯
	}
	if (j > T.length)
		return i - T.length;//匹配成功
	else
		return 0;
}

//求next数组
void get_next(SString T, int next[])
{
	int i = 1, j = 0;
	next[1] = 0;//初始化
	while (i, T.length)
	{
		if (j == 0 || T.ch[i] == T.ch[j])
		{
			++i; ++j;
			next[i] = j;//若pi=pj,则next[j+1]=next[j]+1
		}
		else
			j = next[j];
	}
}

//改良后的nextval数组
void get_nextval(SString T, int nextval[])
{
	int i = 1, j = 0;
	nextval[1] = 0;
	while (i < T.length)
	{
		if (j == 0 || T.ch[i] == T.ch[j])
		{
			++i; ++j;
			if (T.ch[i] != T.ch[j]) nextval[i] = j;
			else nextval[i] = nextval[j];
		}
		else
			j = nextval[j];
	}
}