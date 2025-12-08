class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue <pair<string,int>> q;
        q.push({beginWord,1});
        unordered_set <string> st(wordList.begin(),wordList.end());
        while(!q.empty()){
            auto out = q.front();
            q.pop();
            string word = out.first;
            int step = out.second;
            if(word==endWord){
                return step;
            }
            for(int i = 0 ; i<word.size();i++){
               char original = word[i];
               for(char j = 'a';j<='z';j++){
                word[i]=j;
                //word found
                if(st.find(word)!=st.end()){
                    st.erase(word);
                    q.push({word,step+1});
                }
                word[i]=original;
               }
               
               }
              
        }
         return 0;
    }
};