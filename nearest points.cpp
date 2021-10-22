#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <utility>
using namespace std;
bool comp(int a, int b)
{
    return (a < b);
}
int compare(const pair<int, int> &a,const pair<int, int> &b)
{
	return (a.first<b.first);
}
double distance(vector<pair<int, int> > &a,int s,int e)
{
	int t=-1;
	for(int i=s;i<e;i++)
	{
		for(int j=s+1;j<e;j++)
		{
			int k= sqrt(pow((a[i].first-a[j].first),2)+pow(a[i].second-a[j].second,2));
			if(t=-1||t<k)
			{
				t=k;
			}
		}
	}
	return t;
}
vector<pair<int, int> >dis(vector<pair<int, int> > &a,int s,int e)
{
	
	vector<pair<int, int> > t(1);
	int j=-1;
	for(int i=s;i<e;i++)
	{
		int k= sqrt(pow((a[i].first-a[s].first),2)+pow(a[i].second-a[s].second,2));
		if(j=-1||j<k)
		{
			t[0].first=a[i].first;
			t[0].second=a[i].second;
		}
	
	}
	return t;
}

int main()
{
	int n;
	cin>>n;
	vector<pair<int,int> >a(n);
	vector<pair<int,int> >c(1);
	vector<pair<int,int> >b(1);
	
	for(int i=0;i<n;i++)
	{
		cin>>a[i].first>>a[i].second;
	}
	sort(a.begin(),a.end(),compare);
	int a1=distance(a,0,n/2);
	int b1=distance(a,n/2,n);
	b=dis(a,n/2,0);
	c=dis(a,n/2,n);
	int c1= sqrt(pow((b[0].first-c[0].first),2)+pow(b[0].second-c[0].second,2));
    cout<<std::min({a1,b1,c1},comp);
}
