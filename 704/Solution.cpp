int search(vector<int>& nums, int target) {
    int start = 0;
    int end = nums.size() - 1;
    while(start < end){
        int mid = (start + end)/2;
        if(target == nums[mid]){
            return mid;
        }
        if(target < nums[mid]){
            end = mid;
        }
        else{
            start = mid + 1;
        }
    }
    return -1;
    
}
int search(vector<int>& nums, int target) {
    int start = 0;
    int end = nums.size() - 1;

    while(start < end){  //This doesn't check the last item
        int mid = (start + end)/2;
        if(target == nums[mid]){
            return mid;
        }
        if(target < nums[mid]){
            end = mid;
        }
        else{
            start = mid + 1;
        }
    }
        
    if(nums[start] == target) return start;  //Check it here
        
    return -1;
        
}
