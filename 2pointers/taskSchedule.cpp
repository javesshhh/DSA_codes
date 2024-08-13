// https://leetcode.com/problems/task-scheduler/description/
// https://www.youtube.com/watch?v=rYh-Kkbzsnw&ab_channel=codestorywithMIK

class Solution
{
public:
    int leastInterval(vector<char> &tasks, int n)
    {
        map<char, int> m;
        for (auto it : tasks)
        {
            m[it]++;
        }
        priority_queue<int> pq;
        for (auto it : m)
        {
            pq.push(it.second);
        }
        int ans = 0;
        while (!pq.empty())
        {
            vector<int> temp;
            for (int i = 0; i < n + 1; i++)
            {
                if (!pq.empty())
                {
                    int tp = pq.top();
                    pq.pop();
                    temp.push_back(tp - 1);
                }
            }
            for (auto it : temp)
            {
                if (it != 0)
                {
                    pq.push(it);
                }
            }
            if (pq.empty())
            {
                ans += temp.size();
            }
            else
            {
                ans += (n + 1);
            }
        }
        return ans;
    }
};

// for greedy formula  https://leetcode.com/problems/task-scheduler/solutions/3280549/full-explanation-using-priority-queue-and-formula-based-approach

class Solution
{
public:
    int leastInterval(vector<char> &tasks, int n)
    {
        vector<int> mp(26, 0);
        int max_freq = 0, count_maxfreq = 0, sz = tasks.size();
        for (char i : tasks)
        {
            mp[i - 'A']++; // count the number of times a task needs to be done
            if (mp[i - 'A'] > max_freq)
            {
                max_freq = mp[i - 'A']; // find maximum frequency
            }
        }
        for (int i = 0; i < 26; i++)
        {
            if (mp[i] == max_freq)
                count_maxfreq++; // number of tasks having maximum frequency
        }
        int time = (max_freq - 1) * (n + 1) + count_maxfreq; // total time taken to complete all tasks
        return max(time, sz);
    }
};