class Solution {
public:
    int reverse(int x) {
    int sign = x>0?1:-1;
    long long a = llabs((long long)x);
      long long rev = 0;
      
      while(a!=0){
        rev = rev*10 +(a%10);
        a/=10;
      }
      if ((rev*sign)>INT_MAX || (rev*sign)<INT_MIN){
        return 0;
      }else{
        return (int)(rev*sign);
      }
       
    }
};