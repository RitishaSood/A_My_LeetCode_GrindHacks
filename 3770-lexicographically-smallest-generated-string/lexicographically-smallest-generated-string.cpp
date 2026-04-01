class Solution {
public:
    string generateString(string str1, string str2) {
        int n = str1.length(), m = str2.length();
        string res (n+m-1, 'a');
        vector<bool> isFixed(n+m-1, false);

        for(int i=0; i<n; i++){
            if(str1[i] == 'T'){
                for(int j=0; j<m; j++){
                    int pos = i+j;
                    if(isFixed[pos] && res[pos] != str2[j]) return "";
                    res[pos] = str2[j];
                    isFixed[pos] = true;
                }
            }
        }

        for(int i=0; i<n; i++){
            if(str1[i] == 'F'){
                int count = 0;
                for(int j=m-1; j>=0; j--){
                    int pos = i+j;
                    if(res[pos] != str2[j]){
                        count ++;
                    }
                }

                if(count>0) continue;
                bool changed = false;
                for(int j=m-1; j>=0; j--){
                    int pos = i+j;
                    if(!isFixed[pos]){
                        res[pos] = 'b';
                        changed = true; break;
                    }
                }

                if(!changed) return "";
            }
        }

        return res;
    }
};