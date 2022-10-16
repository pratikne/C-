//Approach 1: Two pointer approach
int maxOperations(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(),nums.end()); //IMP*

        int i=0,j=n-1,count=0;
        while(i<j)
        {
            if (nums[i]+nums[j]==k)
            {
                count++,i++,j--;
            }
            else if (nums[i]+nums[j]>k)
                j--;
            else i++;
        }
        return count;
        
    }
// Time complexity O(n log n)
// Space complexity O(1)


//Appproach 2 : Using unordered map
int maxOperations(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        int res = 0;
        for (int n : nums) {
            if (map[k - n] > 0) { //for n, check if (k - n) is present in map.if yes, then increment count of res and decrement freq of (k - n)
                res++;
                map[k - n]--;
            } else {
                map[n]++; //if not present, insert n in map
            }
        }
        return res;
    }
// Time complexity O(n)
// Space complexity O(n)
