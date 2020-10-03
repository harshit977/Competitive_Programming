/*
program to find Nth no. made with prime no.
It is same as converting any no. to base 4
where
1=2, 2=3, 3=5, 4=7

Runtime Complexity :: O(log4(n))
Space complexity :: O(1), excluding string which holds the final answer
*/

#include <iostream>
using namespace std;

int main() {
	int nt;
	cin>>nt;
	string s="7235";
	while(nt--)
	{
	    int n;
	    cin>>n;
	    string ans="";
	    while(n)		//converting no. to base 4 and storing ans in string
	    {
	        int r=n%4;
	        ans=s[r]+ans;
	        n=n/4;
	        if(r==0)
	        n--;
	    }
	    cout<<ans<<endl;
	}
	return 0;
}
