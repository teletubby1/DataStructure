#include<iostream>

using namespace std;

//顺序存储
#define MAXLEN 255 //预定义最大串长为255
//静态数组
typedef struct {
	char ch[MAXLEN]; //每个分量存储一个字符
	int length; //串的实际长度
}SString;
//动态数组
typedef struct {
	char* ch; //按串长分配存储区，ch指向串的基地址
	int length; //串的长度
}HString;
//链式存储
typedef struct StringNode {
	char ch; //每个结点存1个字符
	struct StringNode* next;
}StringNode,*String;
//每个结点存多个字符
typedef struct StringNode2 {
	char ch[4]; //每个结点存四个字符
	struct StringNode2* next;
}StringNode2,*String2;

//求子串，用Sub返回串S的第pos个字符起长度为len的子串
bool SubString(SString& Sub, SString S, int pos, int len)
{
	//子串范围越界
	if (pos + len - 1 > S.length) return false;
	for (int i = pos; i < pos + len; i++)
		Sub.ch[i - pos + 1] = S.ch[i];
	Sub.length = len;
	return true;
}

//比较操作
int StrCompare(SString S, SString T)
{
	for (int i = 1; i <= S.length && i <= T.length; i++)
	{
		if (S.ch[i] != T.ch[i])
			return S.ch[i] - T.ch[i];
	}
	//扫描过的所有字符都相同，则长度长的串更大
	return S.length - T.length;
}


int main()
{
	HString S;
	S.ch = (char*)malloc(MAXLEN * sizeof(char));
	S.length = 0;
	return 0;
}
 