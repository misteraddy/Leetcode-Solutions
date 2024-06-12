class Node {
public:
    int count;
    int num;

    Node(int count, int num) {
        this->count = count;
        this->num = num;
    }
};

class Compare {
public:
    bool operator()(Node* a, Node* b) {
        if (a->count == b->count) {
            return a->num < b->num;  
        }
        return a->count > b->count;  
    }
};

class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        vector<int> ans;

        unordered_map<int, int> ump;

        for (int num : nums) {
            ump[num]++;
        }

        priority_queue<Node*, vector<Node*>, Compare> pq;

        for (auto& pair : ump) {
            pq.push(new Node(pair.second, pair.first));
        }

        while (!pq.empty()) {
            Node* current = pq.top();
            pq.pop();
            for (int i = 0; i < current->count; i++) {
                ans.push_back(current->num);
            }
            delete current;  
        }

        return ans;
    }
};