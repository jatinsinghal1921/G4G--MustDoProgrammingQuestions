class _stack{
stack<int> s;
int minEle;
public :
    int getMin();
    int pop();
    void push(int);
};

/*returns min element from stack*/
int _stack :: getMin()
{
    if(s.empty())
       return -1;

    return minEle;
}

/*returns poped element from stack*/
int _stack ::pop()
{
    int x;
    if(s.empty())
        return -1;
    if(s.size() == 1 || s.top() >= minEle)
    {
        x = s.top();
        s.pop();
        return x;
    }
    
    x = minEle;
    minEle = 2*minEle - s.top();
    s.pop();
    return x;
    
}

/*push element x into the stack*/
void _stack::push(int x)
{
   if(s.empty())
   {
       minEle = x;
       s.push(x);
       return;
   }
   
   if(x >= minEle)
   {
       s.push(x);
       return;
   }
   
   s.push((2*x)-minEle);
   minEle = x;
   
}
