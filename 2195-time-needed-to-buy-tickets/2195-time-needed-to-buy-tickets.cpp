 class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int  n =tickets.size();
        queue<int>q;
        for(int i=0; i<n; i++){
            q.push(i);
        }
        int times=0;
        while(true){
            if(tickets[k]==0)break;
            int curr = q.front();
            tickets[curr]--;
            times++;
            q.pop();
            if(tickets[curr]!=0){
                q.push(curr);
            }
        }
        return times;
    }


};
