class MyCircularDeque {
public:
    int *arr;
    int size;
    int front;
    int rear;

    MyCircularDeque(int k) {
        size = k;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    bool insertFront(int value) {
        if ((front == 0 && rear == size - 1) || (rear + 1 == front)) {
            return false; // Deque is full
        } else if (front == -1 && rear == -1) {
            front++;
            rear++;
            arr[front] = value;
        } else if (front == 0 && rear != size - 1) {
            front = size - 1;
            arr[front] = value;
        } else {
            front--;
            arr[front] = value;
        }
        return true;
    }

    bool insertLast(int value) {
        if ((front == 0 && rear == size - 1) || (rear + 1 == front)) {
            return false; // Deque is full
        } else if (front == -1 && rear == -1) {
            front++;
            rear++;
            arr[rear] = value;
        } else if (rear == size - 1 && front != 0) {
            rear = 0;
            arr[rear] = value;
        } else {
            rear++;
            if (rear == size) {
                rear = 0;
            }
            arr[rear] = value;
        }
        return true;
    }

    bool deleteFront() {
        if (front == -1 && rear == -1) {
            return false; // Deque is empty
        } else if (front == rear) {
            front = -1;
            rear = -1;
        }
        else if(front == size - 1)
        {
            arr[front] = -1;
            front = 0 ;
        }
        else {
            arr[front] = -1;
            front++;
        }
        return true;
    }

    bool deleteLast() {
        if (front == -1 && rear == -1) {
            return false; // Deque is empty
        } else if (front == rear) {
            front = -1;
            rear = -1;
        }
        else if(rear == 0)
        {
            arr[rear] = 0 ;
            rear = size - 1 ;
        }
        else {
            arr[rear] = -1;
            rear--;
        }
        return true;
    }

    int getFront() {
        if (front == -1) {
            return -1; // Handle empty deque
        }
        return arr[front];
    }

    int getRear() {
        if (rear == -1) {
            return -1; // Handle empty deque
        }
        return arr[rear];
    }

    bool isEmpty() {
        return front == -1 && rear == -1;
    }

    bool isFull() {
        return (front == 0 && rear == size - 1) || (rear + 1 == front);
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */