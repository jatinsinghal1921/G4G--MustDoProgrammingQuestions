#include <iostream>
#include <stack>
using namespace std;


bool are_paranthesis_balanced(string s)
{
    int i;
    stack<char>st;
    
    for(i=0;i<s.length();i++)
    {
        if(s[i] == '{' || s[i] == '(' || s[i] == '[')
        {
            st.push(s[i]);
        }
        else
        {
            if(st.empty())
            {
                return false;    
            }
            if((s[i] == ')' and st.top() == '(') || (s[i] == '}' and st.top() == '{') || (s[i] == ']' and st.top() == '[') )
            {
                st.pop();
            }
            else
            {
                return false;
            }
        }
    }
    if(!st.empty())
    {
        return false;
    }
    return true;
}


int main() {
    int t;
    cin>>t;
    
    string s;
    bool status;
    
    while(t){
        cin>>s;
        status = are_paranthesis_balanced(s);
        if(status == true)
        {
            cout<<"balanced"<<endl;
        }
        else
        {
            cout<<"not balanced"<<endl;    
        }
        t--;
    }
    
	return 0;
}