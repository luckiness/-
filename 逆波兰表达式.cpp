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
//����һ���ṹ�����������������ͺ������ֵ
struct Cell
{
Type _type;
int _value;
};
//�沨�����ʽ���㺯��
int CountRNP(Cell a[],size_t size)
{
	stack <int> s;
	//����������һ������Ϊ�յ������±����ö���
	assert(a);
		for(size_t i=0;i<size;i++)
		{//������ߵ�Ԫ����Ϊ��ֵ����ֱ��ѹ��ջ��
			if(a[i]._type==OP_NUM)
			{
			s.push(a[i]._value);
			}
			//��������ߵ�Ԫ�ز���ֵ�������������������������������Ԫ�س�ջ����������
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