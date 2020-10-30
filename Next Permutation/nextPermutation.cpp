class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int pivot = -1;
        
        for(int i = nums.size() - 1; i > 0; i--){
            if(nums[i] > nums[i-1]){
                pivot = i-1;
                break;
            }    
        }
        if(pivot == -1){ 
            reverse(nums.begin(), nums.end());
            return;
        }
        int num = nums[pivot];
        int nextLar = nums.size() - 1;
        for(int i = nextLar; i > pivot; i--){
            if(nums[i] > num){
                nextLar = i;
                break;
            }
        }
        swap(nums[pivot], nums[nextLar]);
        reverse((nums.begin() + pivot+1), nums.end());
        
    }
};
