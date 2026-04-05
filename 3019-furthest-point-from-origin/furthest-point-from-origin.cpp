class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
    int count = 0;
    int dash = 0;
    int dis = 0;
    for(int i = 0 ; i<moves.length();i++){
     if(moves[i] == 'L'){
        count --;
     }else if(moves[i] == 'R'){
        count ++;
     }else{
       dash ++;
     }
    }
    if(count > 0){
        count = count + dash;
    }else {
        count = count - dash;
    }
    return abs(count) ;
    }
};