 class TaskManager { //code written by sunny
    unordered_map<int, pair<int,int>> mp; 
    priority_queue<pair<int,int>> pq;     

public:
    TaskManager(vector<vector<int>>& tasks) {
        for (auto &t : tasks) {
            int userId = t[0], taskId = t[1], priority = t[2];
            mp[taskId] = {userId, priority};
            pq.push({priority, taskId});
        }
    }
    
    void add(int userId, int taskId, int priority) {
        mp[taskId] = {userId, priority};
        pq.push({priority, taskId});
    }
    
    void edit(int taskId, int newPriority) {
        int userId = mp[taskId].first;
        mp[taskId] = {userId, newPriority};
        pq.push({newPriority, taskId});  
    }
    
    void rmv(int taskId) {
        mp.erase(taskId);  
    }
    
    int execTop() {
        while (!pq.empty()) {
            auto [priority, taskId] = pq.top();
            pq.pop();
            if (mp.find(taskId) != mp.end() && mp[taskId].second == priority) {
                int userId = mp[taskId].first;
                mp.erase(taskId);  
                return userId;
            }
        }
        return -1;  
    }
};
