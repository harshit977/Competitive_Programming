/*
Program to find sum of pairs with Specific Difference

Runtime Complexity :: O(nLogn)
Space Complexity :: O(1)

*/


#include <iostream>
#include<algorithm>
using namespace std;

int main() {
	int nt;
	cin>>nt;
	while(nt--)
	{
	    int n,k;
	    cin>>n;
	    int ar[n];
	    for(int i=0;i<n;i++)
	    cin>>ar[i];
	    cin>>k;
	    sort(ar,ar+n,greater<int>()); // sorted in decreasing order
	    int ans=0;
	    for(int i=0;i<n-1;i++)
	    if(ar[i]-ar[i+1]<k)			// if difference less than k add them in output(ans)
	    {
	       ans+=ar[i]+ar[i+1];
	       i++;
	    }
	    }
	    cout<<ans<<endl;
	}
	return 0;
}
