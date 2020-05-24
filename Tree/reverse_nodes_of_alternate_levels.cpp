void reverse_alternate(node* root)
{
    if(root == 0)
        return;
    
    queue<node*>q1, q2;
    stack<char>st;
    
    q1.push(root);
    while(!q1.empty())
    {
        while(!q1.empty())
        {
            node* temp = q1.front();
            q1.pop();
            
            if(temp->left)
            {
                q2.push(temp->left);
                st.push(temp->left->data);
            }
            if(temp->right)
            {
                q2.push(temp->right);
                st.push(temp->right->data);
            }
        }
        
        while(!q2.empty())
        {
            node* temp = q2.front();
            q2.pop();
            
            temp->data = st.top();
            st.pop();
            
            if(temp->left)
                q1.push(temp->left);
            if(temp->right)
                q1.push(temp->right);
        }
    }
}