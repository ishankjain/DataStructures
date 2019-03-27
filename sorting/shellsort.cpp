#include <bits/stdc++.h>
using namespace std;
void swap(vector<int> &a,int i,int j)
{
	int temp=a[i];
	a[i]=a[j];
	a[j]=temp;
}
void shellSort(vector<int> &a)
{
	for(int gap=a.size()/2;gap>=1;gap/=2)
	{
		for(int i=gap;i<a.size();++i)
		{
			for(int j=i-gap;j>=0;j-=gap)
			{
				if(a[j]>a[j+gap])
					swap(a,j,j+gap);
				else
					break;
			}
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
	shellSort(a);
	for(int i=0;i<n;++i)
	{
		cout<<a[i]<<" ";
	}
}
