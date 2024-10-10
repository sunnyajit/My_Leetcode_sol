 class MyCircularDeque {
    private:
    int* data;        
    int front;          
    int rear;          
    int maxSize;       
    int currentSize;    
 // code written by sunny
public:
    MyCircularDeque(int k) {
         maxSize = k;
        data = new int[maxSize];
        front = 0;
        rear = 0;
        currentSize = 0;
    }
    bool insertFront(int value) {
        if (isFull()) return false;
        front = (front - 1 + maxSize) % maxSize;  
        data[front] = value;
        currentSize++;
        return true;
    }
    bool insertLast(int value) {
        if (isFull()) return false;
        data[rear] = value;
        rear = (rear + 1) % maxSize;  
        currentSize++;
        return true;
    }
    bool deleteFront() {
        if (isEmpty()) return false;
        front = (front + 1) % maxSize;  
        currentSize--;
        return true;
        
    }
    
    bool deleteLast() {
        if (isEmpty()) return false;
        rear = (rear - 1 + maxSize) % maxSize;  
        currentSize--;
        return true;
    }
    
    int getFront() {
         if (isEmpty()) return -1;
        return data[front];
    }
    
    int getRear() {
         if (isEmpty()) return -1;
        return data[(rear - 1 + maxSize) % maxSize];  
    }
    
    bool isEmpty() {
         return currentSize == 0;
    }
    
    bool isFull() {
         return currentSize == maxSize;
    }
    ~MyCircularDeque() {
        delete[] data;
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