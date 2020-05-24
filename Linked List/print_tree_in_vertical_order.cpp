void verticalOrder(Node *root)
{
    if(root == 0)
        return;
    
    map<int,vector<int>>hash;
    int v_distance = 0;
    
    queue<pair<Node*, int>>q;
    q.push(make_pair(root, 0));
    
    while(!q.empty())
    {
        pair<Node*, int>p = q.front();
        Node* temp = p.first;
        int v_level = p.second;
        
        if(hash.find(v_level) == hash.end())
        {
            vector<int>v;
            v.push_back(temp->data);
            hash[v_level] = v;
        }
        else
            hash[v_level].push_back(temp->data);
        
        q.pop();
        
        if(temp->left)
            q.push(make_pair(temp->left,v_level-1));
        if(temp->right)
            q.push(make_pair(temp->right,v_level+1));
    }
    
    map<int,vector<int>>:: iterator it;
    
    for(it = hash.begin(); it != hash.end(); it++)
    {
        vector<int>v = it->second;
        for(int i=0;i<v.size();i++)
            cout<<v[i]<<" ";
    }
    
}

