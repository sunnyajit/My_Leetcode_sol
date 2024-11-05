class Solution {
public:
    int minChanges(string s) {
        int n = s.length();
        int countblockmakestring = 0;
          for(int i=0; i<n; i+=2){ // n tk maximum ja sksyyan
              if(s[i]!=s[i+1]){
                  countblockmakestring++; // x  = x+0=x=
              }
          }
        // usko return kr denge jo change hua hai...
        // O(n);
        // O(1); no extra space ko count kiya gya hai...
          return countblockmakestring;
    }
};