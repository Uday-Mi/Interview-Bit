/*
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x) – Push element x onto stack.
pop() – Removes the element on top of the stack.
top() – Get the top element.
getMin() – Retrieve the minimum element in the stack.
Note that all the operations have to be constant time operations.

Questions to ask the interviewer :

Q: What should getMin() do on empty stack? 
A: In this case, return -1.

Q: What should pop do on empty stack? 
A: In this case, nothing. 

Q: What should top() do on empty stack?
A: In this case, return -1
NOTE : If you are using your own declared global variables, make sure to clear them out in the constructor.
**/

stack <int> s;
int minEle;

MinStack::MinStack() {
    
    while (!s.empty())
    s.pop();
    
    minEle = -1;
    
}

void MinStack::push(int x) {
    
    if (s.size() == 0)
    {
        s.push(x);
        minEle = x;
    }
    
    else
    {
        if (x >= minEle)
        {
            s.push(x);
        }
        else
        {
            s.push(2 * x - minEle);
            minEle = x;
        }
    }
    
}

void MinStack::pop() {
    
    if (s.size() > 0)
    {
        if (s.top() == minEle)
        {
            s.pop();
            minEle = -1;
        }
        else if (s.top() > minEle)
        {
            s.pop();
        }
        else
        {
            minEle = 2 * minEle - s.top();
            s.pop();
        }
    }
    
}

int MinStack::top() {
    
    if (s.size() == 0)
    return -1;
    
    else
    {
        if (s.top() >= minEle)
        return s.top();
        else
        {
            return minEle;
        }
    }
    
}

int MinStack::getMin() {
    
    if (s.size() == 0)
    return -1;
    
    return minEle;
    
}

