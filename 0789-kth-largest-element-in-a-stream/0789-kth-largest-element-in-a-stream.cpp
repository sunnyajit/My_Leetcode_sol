class KthLargest {
 public: // code written by sunnny..
  KthLargest(int p, vector<int>& arrs) : p(p) {
    for (const int arr : arrs)
      heapify(arr);
  }
  int add(int man) {
    heapify(man);
    return minHeap.top();
  }
 private:
  const int p;
  priority_queue<int, vector<int>, greater<>> minHeap;
  void heapify(int man) {
    minHeap.push(man);
    if (minHeap.size() > p)
      minHeap.pop();
  }
};