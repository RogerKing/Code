/*
 *Created by RogerKing
 *Email:jin_tengfei@163.com
 */


#include <iostream>


using namespace std;

//划分子数组  
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

int randomized_partition(int A[], int p, int r)
{
     int i = p + rand() % (r - p + 1);     
     int tmp=A[i];
	 A[i]=A[r];
	 A[r]=tmp;
     return PARTITION(A, p, r);
}

void randomized_quick_sort(int A[], int p, int r)
{
     if (p < r) {
          int q = randomized_partition(A, p, r);
          randomized_quick_sort(A, p, q - 1);
          randomized_quick_sort(A, q + 1, r);
     }
}

void display(int A[],int n)
{
	for( int i=0; i<n ; i++)
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
        randomized_quick_sort(A,0,n);  
        display (A, n);  
    }  
	return 0;
}
