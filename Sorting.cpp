#include <iostream>
using namespace std;
int swap(int* a,int* b)
{
	int k=0;
	int t=*a;
	*a=*b;
	*b=t;
	k++;
	cout<<k;
	
}

int index(int arr[],int left, int right)
{
	int last_e=arr[right];
	int j=left-1;
	for(int i=left;i<=right-1;i++)
	{
		if(arr[i]<last_e)
		{
			j++;
			swap(&arr[j],&arr[i]);
		}
	}
	swap(&arr[j+1],&arr[right]);
	return (j+1);
}
void fastsort(int arr[],int left,int right)
{
	
	if(left<right)
	{
	    int s= index(arr, left, right);
		
		fastsort(arr,left,s-1);
		fastsort(arr,s+1,right);
	}
	
}
int main()
{
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	fastsort(arr,0,n-1);
//	for(int i=0;i<n;i++)
//	{
//		cout<<arr[i]<<" ";
//	}
//cout<<k;	
	
	
}
