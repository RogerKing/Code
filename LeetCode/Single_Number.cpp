/*
 *Created by RogerKing
 *Email:jin_tengfei@163.com
 */


#include <iostream>

using namespace std;

int singleNumber(int A[], int n) 
{
	int s = A[0];
	for( int i=1; i<n; ++i)
		s^=A[i];
	return s;
 }

void display(int A[],int n)
{
	cout<<"The array:";
	for( int i=0; i<n ; i++)
		cout<<A[i]<<" ";
	cout<<endl;
}

int main()
{
	int A[9]={1,2,3,4,5,4,3,2,1};
	display(A,9);
	cout<<"The single one:"<<singleNumber(A,9)<<endl;
	return 0;
}