#include <iostream>
#include <vector>

using namespace std;

void input (vector<int> &A)
{
	cout<<"�������ݣ�crtl+a�س�������\n";
    int data;
    while(cin>>data)    
		{
		A.push_back(data);
		}
}
void insertion_sort(vector<int> &A)
{
	for(int j=1;j<A.size();++j)
	{
		int key=A[j];
		int i=j-1;
		while(i>=0&&key<A[i])
		{
		    A[i+1]=A[i];
			--i;
		}
			A[i+1]=key;
	}
}
void output(vector<int> &A)
{
	cout<<"�����";
	for(vector<int>::iterator iter=A.begin();iter!=A.end();++iter)
		{
		cout<<*iter<<" ";
		}
		cout<<endl;
}

int main(int argc, char *argv[])
{
	vector<int> A;
    input(A);
	insertion_sort(A);
	output(A);
    return 0;
}
