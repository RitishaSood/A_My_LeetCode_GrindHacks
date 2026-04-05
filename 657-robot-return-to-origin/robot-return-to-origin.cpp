class Solution {
public:
    bool judgeCircle(string moves) {
      vector<int> s(2,0);
      //s[1] sideways
      //s[0] vertical
      for(int i = 0 ;i<moves.length();i++){
        if(moves[i]=='U'){
            s[0]++;
        }else if(moves[i]=='D'){
            s[0]--;
        }else if(moves[i]=='L'){
            s[1]++;
        }else{
            s[1]--;
        }
      }
      for(auto it : s){
        if (it != 0){
            return false;
        }
      }
      return true;
    }
};