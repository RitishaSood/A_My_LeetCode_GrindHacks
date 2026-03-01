class Solution {
public:
    int minPartitions(string n) {
    // int num = stoi(s);
    char l = n[0];
    for (int i = 0 ; i< n.length() ; i++){
    if(n[i]>l){
        l = n[i];
    }
    }
    string s = "";
    s += l;
    int op = stoi(s);
    return op;
        
    }
};