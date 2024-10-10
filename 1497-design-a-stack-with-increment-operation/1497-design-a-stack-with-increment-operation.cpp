class CustomStack {
private: // code wriiten by sunny
     vector<int> stack; 
    vector<int> increments;  
    int maxSize;

public:
    CustomStack(int maxSize) : maxSize(maxSize) {
        stack.reserve(maxSize);
        increments.resize(maxSize, 0);
    }
    
    void push(int x) {
        if (stack.size() < maxSize) {
            stack.push_back(x);
        }
    }
    
    int pop() {
        if (stack.empty()) {
            return -1;
        }
        int index = stack.size() - 1;
        int value = stack.back() + increments[index]; 
        stack.pop_back();
        if (index > 0) {
            increments[index - 1] += increments[index];  
        }
        increments[index] = 0; 
        return value;
    }
    void increment(int k, int val) {
        int limit = min(k, (int)stack.size()); 
        if (limit > 0) {
            increments[limit - 1] += val;  
        }
    }
};