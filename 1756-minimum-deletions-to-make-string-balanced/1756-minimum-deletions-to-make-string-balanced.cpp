 class Solution {
public: // code written by sunny..
    int minimumDeletions(string p) {
        int m = p.length();
        int cnt = 0;
        stack<char> tk;
        for(int j = 0; j < m; j++) {
            if(!tk.empty() && p[j] == 'a' && tk.top() == 'b') { //'ba'
                tk.pop();
                cnt++;
            } else {
                tk.push(p[j]);
            }
        }
        return cnt;
    }
};