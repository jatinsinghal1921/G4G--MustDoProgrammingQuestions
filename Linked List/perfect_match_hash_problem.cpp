int PerfectMatch(vector<int> v, int n) 
{
    unordered_map<int, vector<int>>umap;
    int i, element, sum;
    for(i=0;i<n;i++)
    {   
        sum = 0;
        element = v[i];
        while(element !=0)
        {
            sum += element %10;
            element /= 10;
        }
        umap[sum].push_back(v[i]);
    }
    
    long long  largest_sum = 0;
    for (auto x : umap)
    {
        if(x.second.size() > 1)
        {
            sort(x.second.begin(), x.second.end(), greater<int>()); 
            sum = (x.second)[0] + (x.second)[1];
            if(sum > largest_sum)
            {
                largest_sum = sum;
            }
        }
    }
    if(largest_sum == 0)
    {
        return -1;
    }
    return largest_sum;
}