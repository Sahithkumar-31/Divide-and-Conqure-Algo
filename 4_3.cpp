#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int merge(int a[],int a1[],int left,int mid,int right)
{
	int count=0;
	int i=left;
	int j=mid;
	int k=left;
	while((i<=mid-1)&&(j<=right))
	{
	if (a[i]<=a[j])
	{
	a1[k++]=a[i++];}
	else
	{
		a1[k++]=a[j++];
		count=count+(mid-i);
	}
	}
	
	while(i<=mid-1){
		a1[k++]=a[i++];
	}
	while(j<=right)
	{
		a1[k++]=a[j++];
	}
	for(int i=left;i<=right;i++)
	{
		a[i]=a1[i];
	}

	return count;
}


int mergesort(int a[],int a1[],int left,int right)
{
	int count=0;
	int mid;
	if(right>left)
	{
	    mid=(right+left)/2;
		count+=mergesort(a,a1,left,mid);
		count+=mergesort(a,a1,mid+1,right);
		count+=merge(a,a1,left,mid+1,right);
	}

	return count;
}

int inverse_c(int a[],int n)
{
	int a1[n];
	return mergesort(a,a1,0,n-1);
}

int main()
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	int b=inverse_c(a,n);
	cout<<b;
	
	
}
