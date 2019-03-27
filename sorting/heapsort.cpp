#include<bits/stdc++.h>
using namespace std;
void swap(vector<int> &a,int i,int j)
{
	int temp=a[i];
	a[i]=a[j];
	a[j]=temp;
}
void sink(vector<int> &a,int i,int n)
{
	while(2*i<=n)
	{
		int j=2*i;
		if(j<n && a[j+1]>a[j])
			j++;
		if(a[i]>a[j])
			break;
		swap(a,i,j);
		i=j;
	}
}
void heapsort(vector<int> &a)
{
	int n=a.size()-1;
	for(int i=n/2;i>=1;--i)
	{
		sink(a,i,n);
	}
	while(n>1)
	{
		swap(a,1,n);
		n--;
		sink(a,1,n);
	}
}
int main()
{
	int n;
	cin>>n;
	vector<int> a(n+1);
	for(int i=1;i<n+1;++i)
	{
		cin>>a[i];
	}
	heapsort(a);
	for(int i=1;i<n+1;++i)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
}