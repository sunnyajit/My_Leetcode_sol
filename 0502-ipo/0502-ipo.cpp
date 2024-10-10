 class Solution {
public: // Code written by sunny
     int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
     
    vector<pair<int, int>> projects;
    for (int i = 0; i < profits.size(); ++i) {
        projects.push_back({capital[i], profits[i]});
    }
    
    sort(projects.begin(), projects.end());
    
    priority_queue<int> maxHeap;

    int index = 0;
    for (int i = 0; i < k; ++i) {

        while (index < projects.size() && projects[index].first <= w) {
            maxHeap.push(projects[index].second);
            ++index;
        }
        
        if (!maxHeap.empty()) {
            w += maxHeap.top();
            maxHeap.pop();
        } else {
            // If no more projects can be started, break early
            break;
        }
    }
    
    return w;
   }
};