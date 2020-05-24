#include <iostream>
#include <vector>
using namespace std;


void subarray_with_given_sum(vector<int>v, int sum)
{
    int n = v.size();
    if(n <= 0)
    {
        cout<<-1<<endl;
        return;
    }
    
    int first=0, last=0;
    
    int curr_sum = v[0];
    while(first<n && last<n)
    {
        if(first > last)
        {
            last = first;
            curr_sum = v[first];
        }
        
        if(curr_sum == sum)
            break;    
        else if(curr_sum < sum)
        {
            last++;
            if(last<n)
                curr_sum += v[last];
            else
                break;
        }
        else
        {
            curr_sum -= v[first];
            first++;
        }
            
    }
    
    if(first == n || last == n)
    {
        cout<<-1<<endl;
        return;
    }
    else
    {
        cout<<first+1 <<" "<<last+1<<endl;
        return;
    }
    
}


int main() {
	
	int i, t;
	cin>>t;
	
	int j,x,n, sum;
	for(i=0;i<t;i++)
	{
	    vector<int>v;
	    int x;
	    cin>>n;
	    cin>>sum;
	    
	    for(j=0;j<n;j++)
	    {
	        cin>>x;
	        v.push_back(x);
	    }
	    subarray_with_given_sum(v, sum);
	}
	
	return 0;
}