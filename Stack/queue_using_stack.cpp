void StackQueue :: push(int x)
 {
    s1.push(x);
 }

/*The method pop which return the element poped out of the queue*/
int StackQueue :: pop()
{
    int x;
    if(!s2.empty())
    {
        x = s2.top();
        s2.pop();
        return x;
    }

    if(s1.empty())
    {
        return -1;
    }

    while(s1.size() != 1)
    {
        x = s1.top();
        s1.pop();
        s2.push(x);
    }
    
    x = s1.top();
    s1.pop();
    return x;
}
