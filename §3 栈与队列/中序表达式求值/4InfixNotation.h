#include<iostream>     
#include<cstring>
#include<cstdio>
#include<cctype>
#include<stack>
using namespace std;
//输入的表达式要以'#'结尾
 
stack<char> opter;    //运算符栈
stack<double> opval;  //操作数栈
 
int getIndex(char theta)   //获取theta所对应的索引
{
	int index = 0;
	switch (theta)
	{
	case '+':
		index = 0;
		break;
	case '-':
		index = 1;
		break;
	case '*':
		index = 2;
		break;
	case '/':
		index = 3;
		break;
	case '(':
		index = 4;
		break;
	case ')':
		index = 5;
		break;
	case '#':
		index = 6;
        break;
	default:
		break;
	}
	return index;
}


char getPriority(char theta1, char theta2)   //获取theta1与theta2之间的优先级
{
	const char priority[][7] =     //算符间的优先级关系
	{
		{ '>','>','<','<','<','>','>' },
		{ '>','>','<','<','<','>','>' },
		{ '>','>','>','>','<','>','>' },
		{ '>','>','>','>','<','>','>' },
		{ '<','<','<','<','<','=','0' },
		{ '>','>','>','>','0','>','>' },
		{ '<','<','<','<','<','0','=' },
	};
 
	int index1 = getIndex(theta1);
	int index2 = getIndex(theta2);
	return priority[index1][index2];
}


double calculate(double b, char theta, double a)   //计算b theta a
{
	switch (theta)
	{
	case '+':
		return b + a;
	case '-':
		return b - a;
	case '*':
		return b * a;
	case '/':
		return b / a;
	}
    return 0;
}

char GetChar(){
    char c = getchar();
    if(c == ' '){
        c = GetChar();
    }
    return c;
}



double Compute()   //表达式求值
{
	opter.push('#');      //'#'入栈
	int counter = 0;      //counter表示有多少个数字相继入栈，实现多位数的四则运算

	char c = GetChar();

	while (c != '#' || opter.top() != '#')
	{
		if (isdigit(c))   //c是数字位
		{
			if (counter == 1)   //counter=1：上一字符也是数字，故合并
			{
				double t = opval.top();
				opval.pop();
				opval.push(t * 10 + (c - '0'));
				counter = 1;
			}else{
				opval.push(c - '0');     //将c对应的数值入栈opval
				counter++;
			}

			c = GetChar();

		}else{
			counter = 0;   //counter置零
			switch (getPriority(opter.top(), c))   //获取运算符栈opter栈顶元素与c之间的优先级，用'>'，'<'，'='表示
			{
			case '<':               //<: c入栈opter
				opter.push(c);
				c = GetChar();
				break;

			case '=':               //=: opter栈顶元素弹出
				opter.pop();
				c = GetChar();
				break;

			case '>':               //>: 计算
				char theta = opter.top();
				opter.pop();
				double a = opval.top();
				opval.pop();
				double b = opval.top();
				opval.pop();
				opval.push(calculate(b, theta, a));
			}
		}
	}
	return opval.top();   //返回opval栈顶元素的值
}