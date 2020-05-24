/* The method push to push element into the stack */
void QueueStack :: push(int x)
{
    q1.push(x);
}

/*The method pop which return the element poped out of the stack*/
int QueueStack :: pop()
{
    int x;
    if(q1.empty())
        return -1;
    
    while(q1.size() > 1)
    {
        x = q1.front();
        q1.pop();
        q2.push(x);
    }
    x = q1.front();
    q1.pop();
    
    queue<int> temp;
    temp = q2;
    q2 = q1;
    q1 = temp;
    
    return x;
}