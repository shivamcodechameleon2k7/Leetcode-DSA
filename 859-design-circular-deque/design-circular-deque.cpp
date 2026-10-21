
class MyCircularDeque {
    struct Node {
        int data;
        Node* prev;
        Node* next;

        Node(int x) {
            data = x;
            prev = nullptr;
            next = nullptr;
        }
    };

    Node* front;
    Node* rear;
    int size;
    int capacity;

public:
    MyCircularDeque(int k) {
        front = nullptr;
        rear = nullptr;
        size = 0;
        capacity = k;
    }

    bool insertFront(int value) {
        if (isFull()) {
            return false;
        }

        Node* temp = new Node(value);

        if (isEmpty()) {
            front = rear = temp;
        } else {
            temp->next = front;
            front->prev = temp;
            front = temp;
        }

        size++;
        return true;
    }

    bool insertLast(int value) {
        if (isFull()) {
            return false;
        }

        Node* temp = new Node(value);

        if (isEmpty()) {
            front = rear = temp;
        } else {
            rear->next = temp;
            temp->prev = rear;
            rear = temp;
        }

        size++;
        return true;
    }

    bool deleteFront() {
        if (isEmpty()) {
            return false;
        }

        Node* temp = front;

        if (front == rear) {
            front = rear = nullptr;
        } else {
            front = front->next;
            front->prev = nullptr;
        }

        delete temp;
        size--;
        return true;
    }

    bool deleteLast() {
        if (isEmpty()) {
            return false;
        }

        Node* temp = rear;

        if (front == rear) {
            front = rear = nullptr;
        } else {
            rear = rear->prev;
            rear->next = nullptr;
        }

        delete temp;
        size--;
        return true;
    }

    int getFront() {
        if (isEmpty()) {
            return -1;
        }

        return front->data;
    }

    int getRear() {
        if (isEmpty()) {
            return -1;
        }

        return rear->data;
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == capacity;
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