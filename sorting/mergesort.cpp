#include<bits/stdc++.h>
using namespace std;
#define ull  unsigned long long int
void merge(vector<ull> &a,ull start,ull end)
{
	vector<ull> t1,t2;
	ull mid=start+(end-start)/2;
      for(ull i=start;i<=mid;++i)
	  {
		t1.push_back(a[i]);
	  }
	  for(ull i=mid+1;i<=end;++i)
	  {
	  	t2.push_back(a[i]);
	  }    
	  ull i,x,y;
	  for(i=start,x=0,y=0;x<t1.size() && y<t2.size();)
	  {
	  	if(t1[x]<=t2[y])
	  		a[i++]=t1[x++];
	  	else
	  		a[i++]=t2[y++];
	  		
	  }
	  if(x==t1.size() )
	  {
	  	while(y!=t2.size())
	    {
	      a[i++]=t2[y++];
	    }
	  }
	  else
	  {
	  	while(x!=t1.size())
	  	{
	  		a[i++]=t1[x++];
	  	}
	  }
}


void mergeSort(vector<ull> &a,ull start,ull end)
{
	
	if(start>=end)
	{
		return;
	}
	ull mid= start + (end-start)/2;
	
	
	mergeSort(a,start,mid);
	mergeSort(a,mid+1,end);
	
	merge(a,start,end);
}
int main()
{
	ull n;
	cin>>n;
	vector<ull> a(n);
	for(ull i=0;i<n;++i)
	{
		cin>>a[i];
	}
	mergeSort(a,0,n-1);
	for(ull i=0;i<n;++i)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
}

