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
//Iterative reverse two pointers
int helper(vector<int>& nums, int start, int end, int k){
    int result;
    while(true){    
        int left = start; 
        int right = end;
        while(left < right){
            while(nums[right] <= nums[end] && left < right){
                right--;
            }
            while(nums[left] > nums[end] && left < right){
                left++;
            }
            if(left < right){
                int temp = nums[left];
                nums[left] = nums[right];
                nums[right] = temp;
            }
        }
        if(nums[left] > nums[end]){//Dont' use >=. Be careful with only 1 element conditon for reverse two pointers!
            left++;
        }
        int temp = nums[end];
        nums[end] = nums[left];
        nums[left] = temp;

        if(left + 1 == k){
            result = nums[left]; 
            break;
        }
        else if(left + 1 > k){
            end = left - 1;
        }
        else{
            start = left + 1;
        }
    }
    return result;
}
