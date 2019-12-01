vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> result;
    if(nums.size() < 3){
        return result;
    }
    sort(nums.begin(), nums.end());
    for(int i = 0; i < nums.size(); i++){
        if(i != 0 && nums[i] == nums[i - 1]){  //Remove duplicate
            continue;
        }
        int left = i + 1;                      // + 1
        int right = nums.size() - 1;
        while(left < right){
            int sum = nums[left] + nums[right] + nums[i];
            if(sum == 0){
                vector<int> temp;
                temp.push_back(nums[i]);
                temp.push_back(nums[left]);
                temp.push_back(nums[right]);
                result.push_back(temp);
            }
            if(sum <= 0){
                while(left < right && nums[left + 1] == nums[left]) left++; //remove duplicate
                left++;
            }
            if(sum >= 0){
                while(left < right && nums[right - 1] == nums[right]) right--;
                right--;
            }
        }            
    }
    return result;  
}
