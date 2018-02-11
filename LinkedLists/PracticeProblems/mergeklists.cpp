//merge k sorted lists

#include<bits/stdc++.h>
using namespace std;
void merge(list<int> l1,list<int> l2,list<int> &l3)
{
	cout<<l1.size()<<" "<<l2.size()<<endl;
	while(l1.size()>0 && l2.size()>0)
	{
		if(l1.front()<=l2.front())
		{
			l3.push_back(l1.front());
			l1.pop_front();
		}
		else
		{
			l3.push_back(l2.front());
			l2.pop_front();
		}
	}
	while(l1.size()>0)
	{
	    l3.push_back(l1.front());
		l1.pop_front();	
	}
	while(l2.size()>0)
	{
		l3.push_back(l2.front());
		l2.pop_front();
	}
}
int main()
{
	int k,n;
	cout<<"enter number of lists:";cin>>k;
	vector<list<int> > a(k);
	
	cout<<"enter size of lists:";cin>>n;
	cout<<"enter lists:\n";
	for(int i=0;i<k;++i)
	{
		list<int> b;
		for(int j=0;j<n;++j)
		{
			int temp;
			cin>>temp;
			b.push_back(temp);
		}
		a[i]=b;
	}
	while(a.size()>1)
	{
		list<int> c;
		merge(a[0],a[1],c);
		a.erase(a.begin(),a.begin()+2);
		a.push_back(c);
	}
	list<int>::iterator it;
	for(it=a[0].begin();it!=a[0].end();++it)
	{
		cout<<*it<<" ";
	}

}
