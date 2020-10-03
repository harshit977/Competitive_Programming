#include <iostream>
using namespace std;

int main() {
	int nt;
	cin>>nt;
	while(nt--)
	{
	    int n;
	    cin>>n;
	    int ar[n],en=0,flag=0,mi=100000;
	    for(int i=0;i<n;i++)
	    {
	        cin>>ar[i];
	        if(en<0)
	        {flag=1;mi=min(mi,en);}
	        en+=ar[i];
	    }
	    if(!flag)
	    cout<<1;
	    else
	    cout<<abs(mi)+1;
	    cout<<endl;
	}
	return 0;
}
