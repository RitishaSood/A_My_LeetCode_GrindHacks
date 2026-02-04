class Solution {
private:

    // Function to find the prefix maximum array
    vector<int> findPrefixMax(vector<int> &arr, int &n) {
        // To store the prefix maximum
        vector<int> prefixMax(n);
        // Initial configuration
        prefixMax[0] = arr[0];
        // Traverse the array
        for(int i=1; i < n; i++) {
            // Store the maximum till ith index
            prefixMax[i] = 
                max(prefixMax[i-1], arr[i]);
        }
        
        // Return the prefix maximum array
        return prefixMax;
    }
    
    // Function to find the suffix maximum array
    vector<int> findSuffixMax(vector<int> &arr, int &n) {
        // To store the suffix maximum
        vector<int> suffixMax(n);
        
        // Initial configuration
        suffixMax[n-1] = arr[n-1];
        
        // Traverse the array
        for(int i=n-2; i >= 0; i--) {
            
            // Store the maximum till ith index
            suffixMax[i] = 
                max(suffixMax[i+1], arr[i]);
        }
        // Return the suffix maximum array
        return suffixMax;
    }
    
public:
    
    int trap(vector<int> &height){
        int n = height.size(); // Size of array
        // To store the total trapped rainwater
        int total = 0;
        
        // Calculate prefix maximum array
        vector<int> leftMax = 
            findPrefixMax(height, n);
        
        // Calculate suffix maximum array
        vector<int> rightMax = 
            findSuffixMax(height, n);
        
        // Traverse the array
        for(int i=0; i < n; i++) {
            
            // If there are higher groundson both side to hold water 
            if(height[i] < leftMax[i] &&
               height[i] < rightMax[i]) {
                
                // Add up the water on top of current height
                total += ( min(leftMax[i], rightMax[i]) - 
                           height[i] );
            }
        }
        
        // Return the result
        return total;
    }
};