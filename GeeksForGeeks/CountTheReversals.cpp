/*
Program to Count the reversal in given string to correct the bracket Sequence

Runtime Complexity :: O(n)
Space complexity :: O(n)

*/
#include <bits/stdc++.h>
using namespace std;

int main() {
	int nt;
	cin>>nt;
	while(nt--)
	{
	    string brack;
	    cin>>brack;
	    stack<char> st;
	    int n=brack.length();
	    for(int i=0;i<n;i++)
	    {
	        if(!st.empty() && brack[i]=='}' && st.top()=='{')  //store unbalanced brackets in stack
	        st.pop();
	        else st.push(brack[i]);
	    }
	    int si=st.size();
	    double cob=0,ccb=0;  // cob= count of opening brackets , ccb= count of closing brackets
	    if(si%2)
	    {
	        cout<<-1<<endl;  	// if size of unbalanced brackets is odd then it is impossible to correct the sequence, so ouptut -1
	        continue;
	    }
	    while(!st.empty())
	    {
	        if(st.top()=='{') cob=cob+1;
	        else ccb=ccb+1;
	        st.pop();
	    }
	    cout<<ceil(cob/2)+ceil(ccb/2)<<endl;  //ceil is important here
	}
	return 0;
}
