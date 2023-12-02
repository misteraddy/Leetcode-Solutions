

class MyStack {
public:
    MyStack() {

    }

    queue<int> q;

    void push(int x) {
        // Get previous size of queue
        int s = q.size();

        // Push the current element
        q.push(x);

        // Pop all the previous elements and put them after the current element
        for (int i = 0; i < s; i++) {
            // Add the front element again
            q.push(q.front());

            // Delete front element
            q.pop();
        }
    }

    int pop() {
        if (q.empty()) {
            cout << "No elements\n";
            return -1;
        } else {
            int ans = q.front();
            q.pop();
            return ans;
        }
    }

    int top() {
        return q.empty() ? -1 : q.front();
    }

    bool empty() {
        return q.empty();
    }
};