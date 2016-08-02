#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<stack>
#include<assert.h>
using namespace std;

enum Type
{
OP_NUM,
OP_SYMBOL,
};

enum SYMBOL
{
ADD,
SUB,
MUL,
DIV,
};
//定义一个结构体数组包括数组的类型和数组的值
struct Cell
{
Type _type;
int _value;
};
//逆波兰表达式计算函数
int CountRNP(Cell a[],size_t size)
{
	stack <int> s;
	//若函数参数一定不能为空的条件下必须用断言
	assert(a);
		for(size_t i=0;i<size;i++)
		{//数组里边的元素若为数值，则直接压入栈中
			if(a[i]._type==OP_NUM)
			{
			s.push(a[i]._value);
			}
			//若数组里边的元素不是值，而是运算符，则将离运算符最近的两个元素出栈，进行运算
			else
			{
				int right=s.top();
				s.pop();
				int left=s.top();
				s.pop();
				switch(a[i]._value)
				{
				case ADD:
					s.push(left+right);
					break;
				case SUB:
					s.push(left-right);
					break;
				case MUL:
					s.push(left*right);
					break;
				case DIV:
					s.push(left/right);
					break;
				default:

				break;
				}
			}
		}
		return s.top();
}

int main()
{
	Cell a[]={{OP_NUM, 12},{OP_NUM, 3},{OP_NUM, 4},
	          {OP_SYMBOL,ADD},{OP_SYMBOL,MUL},
			  {OP_NUM, 6},{OP_SYMBOL,SUB},{OP_NUM, 8},{OP_NUM, 2},
	          {OP_SYMBOL,DIV},{OP_SYMBOL,ADD}};
	size_t size =sizeof(a)/sizeof(Cell);
	cout<<CountRNP(a, size)<<endl;
	system("pause");
	return 0;
}