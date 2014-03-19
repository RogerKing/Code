/*
 *Created by RogerKing
 *Email:jin_tengfei@163.com
 */


#include <iostream>

using namespace std;

int n;

/***********线性时间求最小值******************************************************/  
int Minimum(int A[])
{
	int Min=A[0];
	for( int i=1; i<n ; i++ )
	{
		if( Min>A[i] )
			Min=A[i];
	}
	return Min;
}
/***********通过3n/2次比较求最小值和最大值******************************************************/ 
void Min_Max(int A[],int *Min,int *Max)
{
	int i;
	if( n%2 == 0 )
	{
		if( A[0]<A[1] )
		{
			*Min=A[0];
			*Max=A[1];
		}
		else
		{
			*Min=A[1];
			*Max=A[0];
		}
		i=2;
	}
	else
	{
		*Min=*Max=A[0];
		i=1;
	}

	for( ; i<n-1 ; i+=2 )
	{
		if( A[i]<A[i+1] )
		{
			if( A[i]<*Min )
				*Min=A[i];
			if( A[i+1]>*Max )
				*Max=A[i+1];
		}
		else
		{
			if( A[i+1]<*Min )
				*Min=A[i+1];
			if( A[i]>*Max )
				*Max=A[i];
		}
		
	}
	
}

/**************以期望线性时间作选择**************************************/  
int PARTITION(int A[], int p,int r)  
{  
    int x=A[r];//A[r]作为主元，围绕它来划分子数组  
    int i=p-1,j,tmp;  
    for( j=p; j<=r-1 ; j++ )  
    {  
        if( A[j]<=x )  
        {  
            i++;  
            tmp=A[j]; //小于A[r]的数往左移，交换A[i]和A[j]的值    
            A[j]=A[i];  
            A[i]=tmp;  
        }     
    }  
    tmp=A[j]; //交换A[r]和A[i+1]的值    
    A[j]=A[i+1];  
    A[i+1]=tmp;  
    return i+1;  
}  

int Randomized_Partition(int A[], int p, int r)
{
     int i = p + rand() % (r - p + 1);     
     int tmp=A[i];
	 A[i]=A[r];
	 A[r]=tmp;
     return PARTITION(A, p, r);
}

int Randomized_Select(int A[], int p, int r, int i )
{
     if( p==r )
		 return A[p];
	 int q=Randomized_Partition(A,p,r);
	 int k=q-p+1;
	 if( i == k )
		 return A[q];
	 else if( i<k )
		 return Randomized_Select(A,p,q-1,i);
	 else
		 return Randomized_Select(A,q+1,r,i-k);
}
void display(int A[])
{
	for( int i=0; i<n ; i++)
		cout<<A[i]<<" ";
	cout<<endl;
}

int main(int argc, char *argv[])
{
	int A[10]={23,12,34,26,78,45,87,15,60,19};
//	n=10;
//	int Min,Max;
//	Min=Minimum(A);
//	cout<<"Min="<<Min<<endl;
//	Min_Max(A,&Min,&Max);
//	cout<<"Min="<<Min<<endl;
//	cout<<"Max="<<Max<<endl;

//    for(int i=1;i<=10;++i)
//	{
//		cout<<"The "<<i<<"th number is:"<<Randomized_Select(A,0,9,i)<<endl;
//	}
     

	return 0;
}
