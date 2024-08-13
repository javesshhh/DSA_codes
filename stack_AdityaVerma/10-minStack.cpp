// https://www.youtube.com/watch?v=asf9P2Rcopo&list=PL_z_8CaSLPWdeOezg68SKkeLN4-T_jNHd&index=10&ab_channel=AdityaVerma
// https://leetcode.com/problems/min-stack/description/

class MinStack
{
public:
    stack<int> s;
    stack<int> ss;
    MinStack()
    {
        while (s.size() != 0)
        {
            s.pop();
        }
        while (ss.size() != 0)
        {
            ss.pop();
        }
    }

    void push(int val)
    {
        s.push(val);
        if (ss.empty() || val <= ss.top())
        {
            ss.push(val);
        }
    }

    void pop()
    {
        int a = s.top();
        s.pop();
        if (a == ss.top())
        {
            ss.pop();
        }
    }

    int top()
    {
        return s.top();
    }

    int getMin()
    {
        if (ss.size() == 0)
            return -1;
        return ss.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

gfg
    // https://practice.geeksforgeeks.org/problems/get-minimum-element-from-stack/1?utm_source=geeksforgeeks&utm_medium=article_practice_tab&utm_campaign=article_practice_tab

    /*
    The structure of the class is as follows
    class _stack{
    stack<int> s;
    int minEle;
    public :
        int getMin();
        int pop();
        void push(int);
    };
    */

    class Solution
{
    int minEle;
    stack<int> s;
    stack<int> ss;

public:
    /*returns min element from stack*/
    int getMin()
    {

        // Write your code here
        if (ss.size() == 0)
            return -1;
        return ss.top();
    }

    /*returns poped element from stack*/
    int pop()
    {

        // Write your code here
        if (ss.size() == 0)
            return -1;
        int ans = s.top();
        s.pop();
        if (ans == ss.top())
        {
            ss.pop();
        }
        return ans;
    }

    /*push element x into the stack*/
    void push(int val)
    {

        // Write your code here
        if (s.empty() && ss.empty())
        {
            s.push(val);
            ss.push(val);
        }
        else
        {
            s.push(val);
            if (val <= ss.top())
            {
                ss.push(val);
            }
        }
        return;
    }
};

// only using one vector

class MinStack
{
public:
    vector<pair<int, int>> s;

    MinStack() {}

    void push(int val)
    {
        if (s.empty())
            s.push_back({val, val});
        else
            s.push_back({val, min(s.back().second, val)});
    }

    void pop() { s.pop_back(); }

    int top() { return s.back().first; }

    int getMin() { return s.back().second; }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */