//Check both side
int findPeakElement(vector<int>& nums) {
    int start = 0;
    int end = nums.size() - 1;
    while(start <= end){
        int mid = start + (end - start)/2;
        if((mid == 0 || nums[mid] > nums[mid - 1]) && (mid == nums.size() - 1 || nums[mid] > nums[mid + 1])){
            return mid;
        }
        if(mid == 0 || nums[mid] > nums[mid - 1]){
            start = mid + 1;
        }
        else{
            end = mid - 1;
        }
    }
    return -1;
}
//Find first where nums[mid] > nums[mid + 1]
int findPeakElement(vector<int>& nums) {
    int start = 0;
    int end = nums.size() - 1;
    while(start < end){
        int mid = start + (end - start)/2;
        if(nums[mid] > nums[mid + 1]){
            end = mid;
        }
        else{
            start = mid + 1;
        }
    }
    return start;
}
