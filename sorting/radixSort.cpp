//Radix sort

#include<bits/stdc++.h>
using namespace std;
#define R 10
vector<int> radixSort(vector<int> a)
{
	int m=*max_element(a.begin(), a.end());
	vector<int> aux(a.size());
	for(int k=1;m/k>0;k*=10)
	{
		vector<int> count(R+1,0);
		for(int i=0;i<a.size();++i)
			count[(a[i]/k)%10+1]++;
		for(int i=0;i<R;++i)
			count[i+1]+=count[i];
		for(int i=0;i<a.size();++i)
			aux[count[(a[i]/k)%10]++]=a[i];
		for(int i=0;i<a.size();++i)
			a[i]=aux[i];
	}
	return aux;
}
int main()
{
	cout<<"size:";
	int n;
	cin>>n;
	vector<int> a(n);
	
	for(int i=0;i<n;++i)
	{
		cin>>a[i];
	}
	a=radixSort(a);
	for(int i=0;i<n;++i)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
}