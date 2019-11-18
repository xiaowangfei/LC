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
int search(vector<int>& nums, int target) {
    int start = 0;
    int end = nums.size() - 1;

    while(start < end){
        int mid = (start + end)/2;
        if(target <= nums[mid]){
            end = mid;                      //Can leave return outside while loop, as long as end/start = mid, not +/- 1
        }
        else{
            start = mid + 1;
        }
    }
    if(nums[start] == target) return start;//Check here is OK.
    return -1;
        
    }

//First position of target
//Can't just return when target is found

int FirstPosition(vector<int> &nums, int target) {
    // write your code here
    int start = 0;
    int end = nums.size() - 1;
    while(start <= end){
        int mid = start + (end - start)/2;
        if(nums[mid] > target){
            end = mid -1;
        }
        else if(nums[mid] < target){
            start = mid + 1;
        }
        else if(mid > 0 && nums[mid - 1] == target){    //Check previous element. Need to make sure always progress, no dead loop 
            end = mid - 1;
        }
        else{
            return mid;                                 //return
        }
    }
    return -1;
}

// Leave two elements
int FirstPosition(vector<int> &nums, int target) {
    // write your code here
    int start = 0;
    int end = nums.size() - 1;
    while(start < end){
        int mid = start + (end - start)/2;
        if(nums[mid] >= target){
            end = mid;
        }
        else{
            start = mid + 1;
        }
    }
    if(nums[start] == target) return start;
    return -1;
}

//Find last
int LastPosition(vector<int> &nums, int target) {
    int start = 0;
    int end = nums.size() - 1;
    while(start <= end){ 
        int mid = start + (end - start)/2;
        if(nums[mid] > target){
            end = mid - 1;
        }
        else if(nums[mid] < target){
            start = mid + 1;
        }
        else if(mid < nums.size() -1 && nums[mid + 1] == target){
            start = mid + 1;
        }
        else{
            return mid;
        }
    }
    return -1;
}

//Summary: To make sure no dead loop(start and end can change when while condition are met):
//1) start <= end   : start = mid + 1 && end = mid -1   No tailing check
//2) start < end    : start = mid + 1 && end = mid      Check nums[start]
//3) start < end - 1: start = mid && end = mid          Check nums[start] && nums[end]
//4) When mid == target, don't move start/end to mid +/- 1. Check can be done outside while loop
