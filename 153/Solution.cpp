int findMin(vector<int>& nums) {
    if (nums.empty()) return -1;
    int start = 0;
    int end = nums.size() - 1;
    //Find the fisrt one that is smaller
    while(start < end){             //Be careful if there is only 1 item
        int mid = start + (end - start)/2;
        if(nums[mid] >= nums[0]){   //Since no duplicate, mid = 0 when start = 0 && end = 1
            start = mid + 1;
        }
        else{
            end = mid;
        }
    }
    if(nums[start] > nums[0]){
         return nums[0];
    }
    return nums[start];        
}
//Find first one that is <= nums[last]
int findMin(vector<int>& nums) {
    if (nums.empty()) return -1;
    int start = 0;
    int end = nums.size() - 1;
    while(start < end){             
        int mid = start + (end - start)/2;
        if(nums[mid] <= nums[nums.size() - 1]){   
            end = mid;
        }
        else{
            start = mid + 1;
        }
    }
    return nums[start];        
}
