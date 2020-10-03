/*
program to find Equilibirium point in array
*/

#include<bits/stdc++.h>
using namespace std;

int main() {
	
	int nt;
	cin>>nt;
	while(nt--)
	{
	    int n;
	    cin>>n;
	    int ar[n];
	    for(int i=0;i<n;i++)
	    {
	        cin>>ar[i];
	    }
	    int sum1=0,sum2=0,i=0,j=n-1,flag=0;		//maintain two sums only to track the left and right sum
	    while(i<=j)
	    {
	        if(sum1==sum2 && i==j)		
	        {
	            cout<<i+1<<endl;
	            flag=1;
	            break;
	        }
	        else if(sum1>sum2)
	        {
	            sum2+=ar[j--];
	        }
	        else
	        {
	            sum1+=ar[i++];
	        }
	    }
	    if(!flag)			// if no such point or element then print -1
	   cout<<"-1\n";
	}
	
	return 0;
}

