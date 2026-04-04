class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
    int len = encodedText.length();
    if(len == 0) return"";
    if(rows == 1) return encodedText;
    int col = len/rows;
    vector<string> mat(rows,string (col,' ')) ;
    for(int i = 0; i<len ; i++){
      int   r = i/col;
      int   c = i%col;
      mat[r][c] = encodedText[i];
    } 
    string res ="";
    for(int j = 0 ; j<col;j++){
        int x = j;
        int i = 0;
        while(i<rows && j<col){
            res.push_back(mat[i][j]);
            i++;
            j++;
        }
        j = x;
    }
    int z = res.length()-1;
    while(res[z] == ' '){
        res.pop_back();
        z--;
    }
    return res;
        
    }
};