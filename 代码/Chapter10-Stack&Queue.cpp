/*
 *Created by RogerKing
 *Email:jin_tengfei@163.com
 */

#include <iostream>
#include <string>
using namespace std;

/*****************ջ*******************************************************/
typedef struct Stack
{
	int top;//ջ��ָ��
	int stacksize;
	int *s;//����
}Stack;
//ջ�ĳ�ʼ��
void Init_Stack(Stack *S)
{
    S->stacksize = 100;
    S->s =(int*)malloc(sizeof(int)*S->stacksize);
    S->top = -1;
}
//��ӡջ
void Print(Stack S)
{
	int i;
	cout<<"��ջ�׵�ջ����˳�����:";
	for(i = 0; i <= S.top; i++)
		cout<<S.s[i]<<' ';
	cout<<endl;
}
//���һ��ջ�Ƿ�Ϊ��
bool Stack_Empty(Stack *S)
{
	if(S->top == 0)
		return true;
	else
		return false;
}
//��ջ
void Push(Stack *S, int x)
{
	S->top++;
	S->s[S->top] = x;
}
//��ջ
int Pop(Stack &S)
{
	if(Stack_Empty(&S))
	{
		cout<<"underflow"<<endl;
		exit(0);
	}
	else
	{
		S.top--;
		return S.s[S.top+1];
	}
}
/*****************����********************************************************/
typedef struct Queue
{
	int tail;//����ͷָ��
	int head;//����βָ��
	int length;//���г���
	int *q;//����
}Queue;
//�Ӷ���ͷ������β���
void Print(Queue Q)
{
	int i;
	cout<<"�Ӷ���ͷ������β:";
	if(Q.tail >= Q.head)
	{
		for(i = Q.head; i < Q.tail;i++)
			cout<<Q.q[i]<<' ';
		cout<<endl;
	}
	//��Ϊѭ����ԭ�򣬶���β�����ڶ���ͷ��ǰ��
	else
	{
		for(i = Q.head; i <= Q.length; i++)
			cout<<Q.q[i]<<' ';
		for(i = 1; i < Q.tail; i++)
			cout<<Q.q[i]<<' ';
		cout<<endl;
	}
}
////�ж϶����Ƿ�Ϊ��
//bool Queue_Empty(queue Q)
//{
//	if(Q.tail == Q.head)
//		return 1;
//	return 0;
//}
//�����
void Enqueue(Queue *Q, int x)
{
	Q->q[Q->tail] = x;
	if(Q->tail == Q->length)
		Q->tail = 1;
	else Q->tail++;
}
//������
int Dequeue(Queue &Q)
{
	int x = Q.q[Q.head];
	if(Q.head == Q.length)
		Q.head = 1;
	else Q.head++;
	return x;
}
int main()
{
//    Stack s;
//    Init_Stack(&s);
//    Push(&s,12);
//    Push(&s,23);
//    Push(&s,34);
//    Push(&s,96);
//    Push(&s,65);
//	  Print(s);
//    cout<<"top is:"<<Pop(s)<<endl;

    Queue q;
    q.length=10;
    q.q = (int*)malloc(sizeof(int)*q.length);
    q.head=0;
    q.tail=0;
    Enqueue(&q,10);
    Enqueue(&q,30);
	cout<<"head="<<q.head<<",tail="<<q.tail<<endl;
	Print(q);
	cout<<"ɾ������Ԫ�أ�"<<Dequeue(q)<<endl;
	cout<<"head="<<q.head<<",tail="<<q.tail<<endl;
}