#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int maj(vector<long long>&a,int l,int r)
{
	if(l==r) return -1;
	if(l+1==r) return a[l];
	
	int l_e = maj(a,l,(l+r-1)/2 + 1);
	int r_e = maj(a,(l+r-1)/2 + 1,r);
	
	int k=0;
	
	for(int i=l;i<r;i++)
	{
		if(a[i]==l_e)
		k=k+1;
	}
	
    if(k>(r-l)/2)
	 {return l_e;}
	 
    int m=0;
    for(int i=l;i<r;i++)
	{
		if(a[i]==r_e)
		m=m+1;
	}
	if(m>(r-l)/2)
	return r_e;
	
	return -1;
}



int main()
{
	int n,j;
	cin>>n;
	vector<long long>a(n);
	
	for(size_t i=0;i<n;i++)
	{
		cin>>a[i];
	}
	

	j=maj(a,0,n);
	cout<<(j!=-1);	
}
