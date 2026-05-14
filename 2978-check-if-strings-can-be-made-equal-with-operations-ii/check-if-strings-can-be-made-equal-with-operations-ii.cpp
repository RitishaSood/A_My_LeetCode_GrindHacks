class Solution {
public:
    bool checkStrings(string s1, string s2) {
    int i = 0;
    // int j = 0;
    int n = s1.length();
    int m = s2.length();
    if(n != m)return false;

    while(i<n){
        if(s1[i]==s2[i]){
        i++;
        continue;
        }
        else{
        int j = i+2;
        while(j<m){
            if(s1[i]==s2[j]){
                swap(s2[i],s2[j]);
                break;
            }else{
               j+=2;
            }
        }
        if(s1[i]!=s2[i]){
        return false;
        }
      }
      i++;
    }
    return true;
    }
};