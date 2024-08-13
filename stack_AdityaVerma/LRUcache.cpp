// https://leetcode.com/problems/lru-cache/description/
// https://leetcode.com/problems/lru-cache/solutions/3780815/dll-map-c-java-python-beginner-friendly
// https://www.youtube.com/watch?v=81h8O-0U5oo

// approach 1

class LRUCache
{
public:
    int cap;
    vector<pair<int, int>> v;
    LRUCache(int capacity)
    {
        cap = capacity;
    }

    int get(int key)
    {
        for (int i = 0; i < v.size(); i++)
        {
            if (v[i].first == key)
            {
                int ans = v[i].second;
                pair<int, int> p = v[i];
                v.erase(v.begin() + i);
                v.push_back(p);
                return ans;
            }
        }
        return -1;
    }

    void put(int key, int value)
    {

        for (int i = 0; i < v.size(); i++)
        {
            if (v[i].first == key)
            {
                v.erase(v.begin() + i);
                v.push_back({key, value});
                return;
            }
        }
        if (v.size() == cap)
        {
            v.erase(v.begin());
            v.push_back({key, value});
        }
        else
        {
            v.push_back({key, value});
        }
    }
};


// approach 2

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
class LRUCache
{
public:
    class Node
    {
    public:
        int key;
        int val;
        Node *prev;
        Node *next;

        Node(int key, int val)
        {
            this->key = key;
            this->val = val;
        }
    };

    Node *head = new Node(-1, -1);
    Node *tail = new Node(-1, -1);

    int cap;
    unordered_map<int, Node *> m;

    LRUCache(int capacity)
    {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }

    void addNode(Node *newnode)
    {
        Node *temp = head->next;

        newnode->next = temp;
        newnode->prev = head;

        head->next = newnode;
        temp->prev = newnode;
    }

    void deleteNode(Node *delnode)
    {
        Node *prevv = delnode->prev;
        Node *nextt = delnode->next;

        prevv->next = nextt;
        nextt->prev = prevv;
    }

    int get(int key)
    {
        if (m.find(key) != m.end())
        {
            Node *resNode = m[key];
            int ans = resNode->val;

            m.erase(key);
            deleteNode(resNode);
            addNode(resNode);

            m[key] = head->next;
            return ans;
        }
        return -1;
    }

    void put(int key, int value)
    {
        if (m.find(key) != m.end())
        {
            Node *curr = m[key];
            m.erase(key);
            deleteNode(curr);
        }

        if (m.size() == cap)
        {
            m.erase(tail->prev->key);
            deleteNode(tail->prev);
        }

        addNode(new Node(key, value));
        m[key] = head->next;
    }
};