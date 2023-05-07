//栈的应用——扩号匹配问题
#include<iostream>

using namespace std;

//定义顺序栈
# define  MaxSize 10
typedef struct {
    char data[MaxSize];
    int top;
} SqStack;

//初始化
void InitStack(SqStack& S) {
    S.top = -1;//栈顶指针始终指向栈顶元素
}

//入栈
bool Push(SqStack& S, char t) {
    if (S.top == MaxSize - 1)return false;//栈满
    S.data[++S.top] = t;
    return true;
}

//出栈
bool Pop(SqStack& S, char& x) {
    if (S.top == -1)return false;//栈空报错
    x = S.data[S.top--];
    return true;
}

//判空
bool StackEmpty(SqStack S) {
    return S.top == -1;
}

//括号匹配
bool bracketCheck(char* str, int length) {
    SqStack S;
    InitStack(S);//初始化一个栈
    for (int i = 0; i < length; i++) {
        if (str[i] == '(' || str[i] == '[' || str[i] == '{') {
            Push(S, str[i]);//扫描到左括号，入栈
        }
        else {
            if (StackEmpty(S))return false;//扫描到右括号且当前栈空，匹配失败
            char topElem;
            Pop(S, topElem);//栈顶元素出栈进行匹配
            if (str[i] == ')' && topElem != '(')
                return false;
            if (str[i] == ']' && topElem != '[')
                return false;
            if (str[i] == '}' && topElem != '{')
                return false;
        }
    }
    return StackEmpty(S);//最后检查栈，若空匹配成功，非空匹配失败
}

int main() {
    return 0;
}