class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        // using counting sort 
        // we count the frequency of all the cost 
        // for that we need a hash array of size of max cost
        // find max cost'
        int mx = 0;
        for(int i = 0; i<costs.size();i++){
            mx = max(mx,costs[i]);

        }
        vector<int> hash(mx+1,0);
        for(auto it:costs){
            hash[it]++;
        }
        int ans = 0;
        int canBuy = 0;
        for(int i=1;i<=mx && coins > 0;i++){
            if(hash[i] == 0){
                continue;
            }
            if ((long long)hash[i] * i <= coins) {
            canBuy += hash[i];
            coins -= (long long)hash[i] * i;
}else{
                canBuy += (coins / i);
                break; 

            }

        
        }
        return canBuy;
    }
    
};