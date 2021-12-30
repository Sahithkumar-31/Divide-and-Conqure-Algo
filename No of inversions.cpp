#include <iostream>
using namespace std;
void merge(int a[],int l,int mid,int r,int n)
{
	int i = l;
	int j = mid+1;
	int k = l;
	int temp[n];
	while(i<=mid && j<=r)
	{
		if(a[i]<=a[j])
		{
			temp[k] = a[i];
			i++;
			k++;
		}
		else
		{
			temp[k] = a[j];
			j++;
			k++;
		}
	}
	while(i<=mid)
	{
			temp[k] = a[i];
			k++;
			i++;
		
	}
	while(j<=r)
	{
			temp[k] = a[j];
			k++;
			j++;
	}
	for(int t = 0;t<=r;t++)
	{
		a[t] = temp[t];
	}
}

void mergesort(int a[],int l,int r,int n)
{
	if(l<r)
	{
		int mid = (l+r)/2;
		mergesort(a,l,mid,n);
		mergesort(a,mid+1,r,n);
		merge(a,l,mid,r,n);
	}
}

int main()
{
	int n;
	cin>>n;
	int arr[n];
	
	for(int i = 0;i<n;i++)
	{
		cin>>arr[i];
	}
	cout<<"BEFORE SORTING"<<endl;
	for(int i = 0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	mergesort(arr,0,n-1,n);
	cout<<"AFTER SORTING"<<endl;
	for(int i = 0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
	
	
}
