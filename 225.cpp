#include <queue>
using namespace std;

class MyStack
{
private:
    queue<int> q; // A queue to simulate stack operations

public:
    // Constructor
    MyStack()
    {
        // No initialization is needed
    }

    // Pushes an element onto the stack
    void push(int x)
    {
        q.push(x); // Push the new element to the queue
        // Rotate the queue so that the newly added element is at the front
        for (int i = 0; i < q.size() - 1; i++)
        {
            q.push(q.front()); // Move the front element to the back
            q.pop();           // Remove the front element
        }
    }

    // Removes the top element and returns it
    int pop()
    {
        int val = q.front(); // Get the front element (top of the stack)
        q.pop();             // Remove the front element
        return val;          // Return the popped element
    }

    // Returns the top element without removing it
    int top()
    {
        return q.front(); // The front of the queue is the top of the stack
    }

    // Returns true if the stack is empty, otherwise false
    bool empty()
    {
        return q.empty(); // Check if the queue is empty
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
