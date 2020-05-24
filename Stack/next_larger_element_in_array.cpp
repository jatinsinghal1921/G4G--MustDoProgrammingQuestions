#include <iostream>
#include <vector>
#include <stack>
using namespace std;


void get_next_greater_element(vector<long long>v)
{
    vector<long long>output(v.size(),-1);
    
    stack<long long>st;
    st.push(0);
    
    long long i;
    for(i=1;i<v.size();i++)
    {
        if(v[i] > v[st.top()])
        {
            while(!st.empty() and v[i] > v[st.top()] )
            {
                output[st.top()] = v[i];
                st.pop();
            }
        }
        st.push(i);
    }
    
    for(i=0;i<output.size();i++)
    {
        cout<<output[i]<<" ";
    }
    cout<<endl;
}


int main() {
    
	long long t,n,x;
	cin>>t;
	
	while(t)
	{
	    cin>>n;
	    vector<long long>v;
        while(n)
        {
            cin>>x;
            v.push_back(x);
            n--;
        }
        get_next_greater_element(v);
        t--;
	}
	
	return 0;
}