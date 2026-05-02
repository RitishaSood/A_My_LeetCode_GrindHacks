class Solution {
public:
    int rotatedDigits(int n) {
        
        int count = 0;
        while(n){
        int num = n;
        bool flag = true;
        int countdigit = 0;
        int countsame = 0;
        while(num > 0){
            
            int digit = num%10;
            if(digit != 2 && digit != 5 && digit != 6 && digit != 9 && digit != 0 && digit != 1 && digit != 8){
                flag = false;
                break;
            }
            if(flag == false){
                break;
            }
            if(digit == 1 || digit ==0||digit == 8){
                countsame++;
            }
            countdigit++;
            num = num/10;
        }
        if (flag && countdigit > countsame){
            count ++;
        }
        n--;
        }
        return count;
        
    }
};