/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        while (root != nullptr)
        {
            if (p->val < root->val && q->val < root->val)
            {
                root = root->left;
            }
            else if (p->val > root->val && q->val > root->val)
            {
                root = root->right;
            }
            else
            {
                return root;
            }
        }
        return nullptr;
    }
};

class MyQueue
{
private:
    stack<int> ins;
    stack<int> outs;
    void transfer()
    {
        if (outs.empty())
        {
            while (!ins.empty())
            {
                outs.push(ins.top());
                ins.pop();
            }
        }
    }

public:
    MyQueue()
    {
    }

    void push(int x)
    {
        ins.push(x);
    }

    int pop()
    {
        transfer();
        int front = outs.top();
        outs.pop();
        return front;
    }

    int peek()
    {
        transfer();
        return outs.top();
    }

    bool empty()
    {
        return ins.empty() && outs.empty();
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