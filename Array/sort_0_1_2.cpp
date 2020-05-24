#include <iostream>
#include <vector>
using namespace std;

void sort_three_integers(vector<int>&v)
{
    int zeroCount = 0, oneCount = 0, twoCount = 0;
    int i;
    for(i=0;i<v.size();i++)
    {
        if(v[i] == 0)
            zeroCount++;
        else if(v[i] == 1)
            oneCount++;
        else
            twoCount++;
    }
    
    i=0;
    
    while(zeroCount)
    {
        v[i] = 0;
        i++;
        zeroCount--;
    }

    while(oneCount)
    {
        v[i] = 1;
        i++;
        oneCount--;
    }    
    
    while(twoCount)
    {
        v[i] = 2;
        i++;
        twoCount--;
    }    
    
}

void display_vector(vector<int> v)
{
    int i=0;
    while(i < v.size())
    {
        cout<<v[i]<<" ";
        i++;
    }
    cout<<endl;
}

int main() {
	
	int i, t;
	cin>>t;
	
	int j,x,n;
	for(i=0;i<t;i++)
	{
	    vector<int>v;
	    int x;
	    cin>>n;
	    
	    for(j=0;j<n;j++)
	    {
	        cin>>x;
	        v.push_back(x);
	    }
	    sort_three_integers(v);
	    display_vector(v);
	}
	
	return 0;
}