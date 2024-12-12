class Solution { 
public:// code written by sunny
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> pq(gifts.begin(), gifts.end()); 
        for (int i = 0; i < k; ++i) {
            int maxGifts = pq.top();
            pq.pop(); 
            int newGifts = static_cast<int>(floor(sqrt(maxGifts)));
            pq.push(newGifts);
        }
        long long totalGifts = 0;
        while (!pq.empty()) {
            totalGifts += pq.top();
            pq.pop();
        }
        
        return totalGifts;
    }
};
