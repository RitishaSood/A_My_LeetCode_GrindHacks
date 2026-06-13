class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
    int numofwords = words.size();
    string ctd = "";  
    // char hash[26];
    //     for(int i = 25;i>=0;i--){
    //         hash[i]='a'+i;    
    //     }
    for(int i=0;i<numofwords;i++){
    int n = words[i].length();
        int sum = 0;
        for(int j = 0;j<n;j++){
           sum+= weights[words[i][j]-'a'];
        }
        sum= sum%26;
        ctd += char('z' - sum);
    }   
         return ctd;
    }
   
    
};