int threeSumClosest(vector<int>& nums, int target) {
    if(nums.size() < 3) return -1;
    int ans = nums[0] + nums[1] + nums[2];
    sort(nums.begin(), nums.end());
    for(int i = 2; i < nums.size(); i++){
        int left = 0;
        int right = i - 1;
        while(left < right){
            int sum = nums[left] + nums[right] + nums[i];
            if(sum == target){
                return target;
            }
            if(abs(target - sum) < abs(target - ans)){
                ans = sum;
            }
            if(sum < target){
                left++;
            }
            else{
                right--;
            }
        }
    }
    return ans;        
}
