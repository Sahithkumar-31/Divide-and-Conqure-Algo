#include <iostream>
#include <string>
using namespace std;
void comparision(long long c[][2],long long p[],int points)
{   
    int out[points];
    for(int j=0;j<points;j++)
	{
		out[j]=0;
	}
	
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<points;j++)
		{
			if(c[i][0]<=p[j] && c[i][1]>=p[j])
			{out[j]=out[j]+1;}
		}
	}
	for(int j=0;j<points;j++)
	{   
		cout<<out[j]<<"\n";
	}
	
}
int main()
{
    int seg,points;
	cin>>seg>>points;
	long long c[seg][2],p[points];
	
	for(int i=0;i<seg;i++)
	{
		for(int j=0;j<2;j++)
		{
			cin>>c[i][j];
			
		}
		
	}
	for(int i=0;i<points;i++)
	{
		cin>>p[i];
	}
	comparision(c,p,points);
}
