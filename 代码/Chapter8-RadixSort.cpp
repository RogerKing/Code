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

int get_digit(int n)
{
	int digit=1;
	while( n )
	{
		n/=10;
		digit++;
	}
	return digit;
}

void Radix_Sort(int A[])
{
	int* B=new int[n];
	int C[10];
	int i,j,t,d,radix=1;

	d=get_digit(get_K(A));
	for( i=0; i<d ;i++,radix*=10  )
	{
		for( j=0; j<10 ; j++ )
			C[j]=0;
		for( j=0; j<n ; j++ )
		{
			t=A[j]/radix%10;
			C[t]++;
		}
		for( j=1; j<10 ; j++ )
			C[j]=C[j]+C[j-1];
		for( j=n-1; j>=0 ; j-- )
		{
			t=A[j]/radix%10;
			B[C[t]-1]=A[j];
			C[t]--;
		}
		for( j=0; j<n ; j++ )
			A[j]=B[j];
	}
	delete[] B;
}

void display(int A[])
{
	for( int i=0; i<n ; i++)
		cout<<A[i]<<" ";
	cout<<endl;
}

int main(int argc, char *argv[])
{
	int A[100];    
    while (cin >> n)  
    {
		for (int i = 0; i < n; i++)  
			cin >> A[i];  
		Radix_Sort(A);
        display(A);  
    }  
	return 0;
}
