/*
program to find Large No. division
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
	int nt;
	cin>>nt;
	while(nt--)
	{
	    string s,quo="";
	    int d;
	    cin>>s>>d;
	    int lenofd=floor(log10(d))+1;
	    int n=s.length();
	    long long rem=stoll(s.substr(0,lenofd));
	    for(int i=lenofd;i<n;i++)
	    {
	        long long tem=rem%d;
	        quo=quo+to_string(rem/d);
	        int t=stoi(s.substr(i,1));
	        rem=tem*10+t;
	    }
	    int ind=0;
	    quo=quo+to_string(rem/d);
	    while(quo[ind]=='0') ind++;
	    string ans=quo.substr(ind,quo.length()-ind+1);
	    if(ans=="")
	    cout<<'0'<<endl;
	    else
	    cout<<ans<<endl;
	}
	return 0;
}
