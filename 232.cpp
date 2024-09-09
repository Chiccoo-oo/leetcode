class MyQueue
{
private:
    stack<int> s1, s2;

public:
    MyQueue()
    {
    }

    void push(int x)
    {
        while (s1.size())
        {
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(x);
        while (s2.size())
        {
            s1.push(s2.top());
            s2.pop();
        }
    }

    int pop()
    {
        int val = s1.top(); // Get the top element
        s1.pop();           // Remove the top element
        return val;
    }

    int peek()
    {
        return s1.top();
    }

    bool empty()
    {
        return s1.empty() && s2.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */