//Use forward two pointers
int findKthLargest(vector<int>& nums, int k) {
    return helper(nums, 0, nums.size() - 1, k);
}
int helper(vector<int>& nums, int start, int end, int k){
    int idx = start;
    int key = nums[end];
    for(int i = start; i < end; i++){
        if(nums[i] >= key){
            int temp = nums[i];
            nums[i] = nums[idx];
            nums[idx] = temp;
            idx++;
        }
    }
    nums[end] = nums[idx];
    nums[idx] = key;
    //Or use len = idx - start + 1
    if(idx + 1 == k){
        return nums[idx];
    }
    else if(idx + 1 > k){
        return helper(nums, start, idx - 1, k);
    }
    else{
        return helper(nums, idx + 1, end, k);
    }
} 
//Can also be iterative
int helper(vector<int>& nums, int start, int end, int k){
    int result;
    while(true){
        int idx = start;
        int key = nums[end];
        for(int i = start; i < end; i++){
            if(nums[i] >= key){
                int temp = nums[i];
                nums[i] = nums[idx];
                nums[idx] = temp;
                idx++;
            }
        }
        nums[end] = nums[idx];
        nums[idx] = key;
        if(idx + 1 == k){
            result = nums[idx];
            break;
        }
        else if(idx + 1 > k){
            end = idx - 1;
        }
        else{
            start = idx + 1;
        }
    }
    return result;
} 
