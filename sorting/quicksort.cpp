#include<bits/stdc++.h>
using namespace std;
void swap(vector<int> &a,int i,int j)
{
	int temp=a[i];
	a[i]=a[j];
	a[j]=temp;
}
void qsort(vector<int> &a,int lo,int hi)
{
	if(lo>=hi)
		return;
	int target=lo,i=lo+1,j=hi;
	while(i<=j)
	{
		if(a[target]==a[i])
			i++;
		else if(a[target]>a[i])
		{
			swap(a,i,target);
			i++;target++;
		}
		else if(a[target]<a[i])
		{
			swap(a,i,j);
			j--;
		}
	}
	qsort(a,lo,target-1);
	qsort(a,i,hi);
}
int main()
{
	int n;
	cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;++i)
	{
		cin>>a[i];
	}
	qsort(a,0,n-1);
	for(int i=0;i<n;++i)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
}