class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        int n = nums.size();

        if(n == 0) return ans;

        int i = 1, j = 0;

        while(i < n)
        {
            long long diff = 1LL * nums[i] - nums[i - 1];

            if(diff != 1)
            {
                if(j == i - 1)
                {
                    ans.push_back(to_string(nums[j]));
                }
                else
                {
                    string range =
                        to_string(nums[j]) +
                        "->" +
                        to_string(nums[i - 1]);

                    ans.push_back(range);
                }

                j = i;
            }

            i++;
        }

        if(j == i - 1)
        {
            ans.push_back(to_string(nums[j]));
        }
        else
        {
            string range =
                to_string(nums[j]) +
                "->" +
                to_string(nums[i - 1]);

            ans.push_back(range);
        }

        return ans;
    }
};