class Solution {
public:
     // code written by sunny...
    int d;
    int C[1+1][100+1][100+1];  
    int solveForAlice(vector<int>& cp, int man, int j, int p) {
        if(j >= d)
            return 0;
        if(C[man][j][p] != -1)
            return C[man][j][p];
        int ret = (man == 1) ? -1 : INT_MAX;
        int sts = 0;
        for(int x = 1; x <= min(2*p, d-j); x++) {
            sts += cp[j+x-1];
            if(man == 1) { 
                ret = max(ret, sts + solveForAlice(cp, 0, j+x, max(p, x)));
            } else {  
                ret = min(ret, solveForAlice(cp, 1, j+x, max(p, x)));
            } 
        }
        return C[man][j][p] = ret;
    }
    int stoneGameII(vector<int>& cp) {
        d = cp.size();
        memset(C, -1, sizeof(C));
        return solveForAlice(cp, 1, 0, 1);
    }
};