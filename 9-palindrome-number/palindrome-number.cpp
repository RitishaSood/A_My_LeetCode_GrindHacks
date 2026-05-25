class Solution {
public:
    bool isPalindrome(int x) {
   long long a = llabs((long long) x);
   int sign = x>0?1:-1;
   long long rev = 0;
   if (x == 0) {
    return true;
   } 
   if(x<0){
    return false;
   }
   while(a!=0){
    rev = rev*10+(a%10);
    a/=10;
   }
   rev = rev*sign ;
   if (rev==x){
    return true;
   }else{
    return false;
   }
    }
};