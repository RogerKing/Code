/*
 *Created by RogerKing
 *Email:jin_tengfei@163.com
 */


#include <iostream>
#include <stdlib.h>

using namespace std;
int heap_size,i;

int PARENT(int i)
{
	return i/2;
}//查找堆中节点父母

int LEFT(int i)
{
	return 2*i+1;
}//查找堆中节点左孩子(因为程序下标是从0开始的)

int RIGHT(int i)
{
	return 2*i+2;
}//查找堆中节点右孩子

void Max_Heapify(int A[],int i,int n)
{
	int l=LEFT(i);
	int r=RIGHT(i);
	int largest;
	heap_size=n;

	if( l<heap_size&&A[l]>A[i] )
		largest=l;
	else
		largest=i;
	if( r<heap_size&&A[r]>A[largest] )
		largest=r;
	if( largest!=i )
	{
		int tmp=A[largest];
		A[largest]=A[i];
		A[i]=tmp;
		Max_Heapify(A,largest,heap_size);
	}
}

void Bulid_Max_Heap(int A[],int n)
{
	heap_size=n;
	for( i=heap_size/2+1; i>=0; --i)
		Max_Heapify(A,i,heap_size);	
}

void HeapSort(int A[],int n)
{
	heap_size=n;
	Bulid_Max_Heap(A,heap_size);
	int tmp;
	for( i=heap_size-1 ; i>=1 ; --i  )
	{
		tmp=A[0];
		A[0]=A[i];
		A[i]=tmp;
		Max_Heapify(A,0,--heap_size);
	}
	
}

void display(int A[],int n)
{
	for( i=0; i<n ; i++)
		cout<<A[i]<<" ";
	cout<<endl;
}
int main(int argc, char *argv[])
{
	int A[100];  
    int n;  
    while (cin >> n)  
    {
		for (int i = 0; i < n; i++)  
			cin >> A[i];  
        HeapSort (A, n);  
        display (A, n);  
    }  
	return 0;
}
