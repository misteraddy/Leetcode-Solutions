class Node {
public:
    int count;
    char ch;

    Node(int count, char ch) {
        this->count = count;
        this->ch = ch;
    }
};

class Compare {
public:
    bool operator()(Node* a, Node* b) {
        return a->count < b->count;    // decreasing order mei < 
    }  
};

class Solution {
public:
    string frequencySort(string s) {
        string ans = "";

        vector<int> temp(256, 0); // Adjusted to accommodate full ASCII range

        for (char ch : s) {
            temp[ch]++;     //ch - a se out of bound chala jaa rha tha 
        }

        priority_queue<Node*, vector<Node*>, Compare> pq;

        for (int i = 0; i < 256; i++) {
            if (temp[i] > 0) {
                Node* pushThis = new Node(temp[i], static_cast<char>(i));
                pq.push(pushThis);
            }
        }

        while (!pq.empty()) {
            Node* element = pq.top(); pq.pop();

            char character = element->ch;
            int counter = element->count;

            while (counter > 0) {
                ans += character;
                counter--;
            }
        }

        return ans;
    }
};

//Error 
/*

Line 33: Char 38: error: excess elements in scalar initializer
   33 |                 Node* pushThis = new Node*(temp[i],i + 'a');
      |                                    yaha pe

Line 3: Char 25: error: unknown type name 'Node'
    3 |         bool operator()(Node* a,Node* b)
      |

    custom comparator ka use karna pada mereko
*/