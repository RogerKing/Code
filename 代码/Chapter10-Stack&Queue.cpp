/*
 *Created by RogerKing
 *Email:jin_tengfei@163.com
 */

#include <iostream>
#include <string>
using namespace std;

/*****************栈*******************************************************/
typedef struct Stack
{
	int top;//栈顶指针
	int stacksize;
	int *s;//数组
}Stack;
//栈的初始化
void Init_Stack(Stack *S)
{
    S->stacksize = 100;
    S->s =(int*)malloc(sizeof(int)*S->stacksize);
    S->top = -1;
}
//打印栈
void Print(Stack S)
{
	int i;
	cout<<"从栈底到栈顶的顺序输出:";
	for(i = 0; i <= S.top; i++)
		cout<<S.s[i]<<' ';
	cout<<endl;
}
//检查一个栈是否为空
bool Stack_Empty(Stack *S)
{
	if(S->top == 0)
		return true;
	else
		return false;
}
//入栈
void Push(Stack *S, int x)
{
	S->top++;
	S->s[S->top] = x;
}
//出栈
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
/*****************队列********************************************************/
typedef struct Queue
{
	int tail;//队列头指针
	int head;//队列尾指针
	int length;//队列长度
	int *q;//数组
}Queue;
//从队列头到队列尾输出
void Print(Queue Q)
{
	int i;
	cout<<"从队列头到队列尾:";
	if(Q.tail >= Q.head)
	{
		for(i = Q.head; i < Q.tail;i++)
			cout<<Q.q[i]<<' ';
		cout<<endl;
	}
	//因为循环的原因，队列尾可能在队列头的前面
	else
	{
		for(i = Q.head; i <= Q.length; i++)
			cout<<Q.q[i]<<' ';
		for(i = 1; i < Q.tail; i++)
			cout<<Q.q[i]<<' ';
		cout<<endl;
	}
}
////判断队列是否为空
//bool Queue_Empty(queue Q)
//{
//	if(Q.tail == Q.head)
//		return 1;
//	return 0;
//}
//入队列
void Enqueue(Queue *Q, int x)
{
	Q->q[Q->tail] = x;
	if(Q->tail == Q->length)
		Q->tail = 1;
	else Q->tail++;
}
//出队列
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
	cout<<"删除队列元素："<<Dequeue(q)<<endl;
	cout<<"head="<<q.head<<",tail="<<q.tail<<endl;
}