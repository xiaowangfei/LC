//Insertion sort   
vector<int> sortArray(vector<int>& nums) {       
    for(int i = 1; i < nums.size(); i++){
        int key = nums[i];
        int j  = i - 1;
        while(j >= 0 && nums[j] > key){
            nums[j + 1] = nums[j];
            j--;
        }
        nums[j + 1] = key;
    }
    return nums;
}

//Quick sort
vector<int> sortArray(vector<int>& nums) {     
    quickSort(nums, 0, nums.size() - 1);
    return nums;
}

void quickSort(vector<int>& nums, int start, int end){
    if(start <= end){
        int q = partition(nums, start, end);               //Needs start & end
        quickSort(nums, start, q - 1);                     //q +- 1 needed to avoid dead loop/stack overflow
        quickSort(nums, q + 1, end);
    }
}

int partition(vector<int>& nums, int start, int end){
    int idx = start;
    int pivot = nums[end];
    for(int i = start; i < end; i++){
        if(nums[i] < pivot){
            int temp  = nums[idx];
            nums[idx] = nums[i];
            nums[i]   = temp;
            idx++;
        }
    }
    nums[end] = nums[idx];
    nums[idx] = pivot;
    return idx;
}

