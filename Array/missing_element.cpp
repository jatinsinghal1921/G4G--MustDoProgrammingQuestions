void get_missing_element(vector<int>v, int n)
{
    int i;
    int xor_val = 0;
    for(i=0;i<v.size();i++)
    {
        xor_val ^= v[i]; 
    }
    
    for(i=1;i<=n;i++)
    {
        xor_val ^= i;
    }
    
    cout<<xor_val<<endl;
}