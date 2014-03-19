/*
 *Created by RogerKing
 *Email:jin_tengfei@163.com
 */


#include <iostream>

using namespace std;
int n;
int get_K(int A[])
{
	int k=A[0];
	for( int i=1; i<n ; i++ )
	{
		if( k<A[i] )
			k=A[i];
	}
	return k;
}

void Counting_Sort(int A[],int B[], int k)
{
	int* C=new int[k+1];
	int i;
	for( i=0; i<=k ; i++ )
		C[i]=0;
	for( i=0; i<n ; i++ )
		C[A[i]]++;
	for( i=1; i<=k ; i++ )
		C[i]=C[i]+C[i-1];
	for( i=n-1; i>=0 ; i-- )
	{
		B[C[A[i]]-1]=A[i];
		C[A[i]]--;
	}
	delete[] C;
}

void display(int A[])
{
	for( int i=0; i<n ; i++)
		cout<<A[i]<<" ";
	cout<<endl;
}

int main(int argc, char *argv[])
{
	int A[100],B[100];   
    while (cin >> n)  
    {
		for (int i = 0; i < n; i++)  
			cin >> A[i];  
        int k=get_K(A);
		Counting_Sort(A,B,k);
        display(B);  
    }  
	return 0;
}
