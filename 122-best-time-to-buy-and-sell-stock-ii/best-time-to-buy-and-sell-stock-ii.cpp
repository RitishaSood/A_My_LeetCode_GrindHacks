class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int ans = 0;
        int buy = prices[0];

        int n = prices.size();

        for(int i = 1; i < n; i++)
        {
            int sell = prices[i] - buy;

            if(sell > 0)
            {
                ans += sell;
            }

            buy = prices[i];
        }

        return ans;
    }
};