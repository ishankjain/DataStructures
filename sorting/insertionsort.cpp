#include <bits/stdc++.h>
using namespace std;
void swap(vector<int> &a,int i,int j)
{
	int temp=a[i];
	a[i]=a[j];
	a[j]=temp;
}
void insertionSort(vector<int> &a)
{
	for(int i=1;i<a.size();++i)
	{
		for(int j=i-1;j>=0;--j)
		{
			if(a[j]>a[j+1])
				swap(a,j,j+1);
			else
				break;
		}
	}
}
int main()
{
	int n;
	cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;++i){
		cin>>a[i];
	}
	insertionSort(a);
	for(int i=0;i<n;++i)
	{
		cout<<a[i]<<" ";
	}
}
