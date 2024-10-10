 #include<string>
#include<cmath>

class Solution{
    public: 
      int scoreOfString(std::string str){
          int score = 0;
          for(int i=1; i<str.size(); i++){
              score+=abs(str[i]-str[i-1]);
              
          }
          
          return score;
      }
};