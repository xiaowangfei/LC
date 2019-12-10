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

//Use last item as pivot and place it in the right place
int partition(vector<int>& nums, int start, int end){
    int idx = start;
    int pivot = nums[end];
    for(int i = start; i < end; i++){
        if(nums[i] <= pivot){
            int temp  = nums[idx];
            nums[idx] = nums[i];
            nums[i]   = temp;
            idx++;
        }
    }
    //The final three lines of PARTITION finish up by swapping the pivot element with
    //the leftmost element greater than x, thereby moving the pivot into its correct place
    //in the partitioned array, and then returning the pivot’s new index.  --Introduction to Algorithm
    nums[end] = nums[idx];
    nums[idx] = pivot;
    return idx;
}
//Use double pointer
int partition(vector<int>& nums, int start, int end){
    if(start >= end) return start;
    int left = start;
    int right =end;
    int pivot = nums[end];
    while(left < right){
        while(nums[right] >= pivot && left < right){
            right--;
        }
        while(nums[left] <= pivot && left < right){
            left++;
        }
        if(left < right){
            int temp = nums[left];
            nums[left] = nums[right];
            nums[right] = temp;
        }
    }
    if(nums[right] < pivot){
        right++;
    }
    nums[end] = nums[right];
    nums[right] = pivot;
    return right;
}
//Or use start as pivot
int partition(vector<int>& nums, int start, int end){
    if(start >= end) return start;
    int left = start;
    int right =end;
    int pivot = nums[start];
    while(left < right){
        while(nums[left] <= pivot && left < right){
            left++;
        }
        while(nums[right] >= pivot && left < right){
            right--;
        }
        if(left < right){
            int temp = nums[left];
            nums[left] = nums[right];
            nums[right] = temp;
        }
    }
    if(nums[right] > pivot){
        right--;
    }
    nums[start] = nums[right];
    nums[right] = pivot;
    return right;
}
//Double pointer note:


//Merge sort
vector<int> sortArray(vector<int>& nums) {
    vector<int> temp(nums);                         //Extra O(n) space for merge
    mergeSort(nums, temp, 0, nums.size() - 1);
    return nums;
}
void mergeSort(vector<int>& nums, vector<int>& temp, int start, int end){
    if(start < end){
        int mid = start + (end - start)/2;         //Divide by mid & mid + 1 to avoid deadloop
        mergeSort(nums, temp, start, mid);
        mergeSort(nums, temp, mid + 1, end);
        merge(nums, temp, start, mid, end);
    }
}
    
void merge(vector<int>& nums, vector<int>& temp, int start, int mid, int end){
    int idx1 = start;
    int idx2 = mid + 1;
    for(int i = start; i <= end; i++){
        if(idx1 <= mid && idx2 <= end){
            temp[i] = nums[idx1] < nums[idx2] ? nums[idx1++] : nums[idx2++];
        }
        else if(idx1 <= mid){
            temp[i] = nums[idx1++];
        }
        else if(idx2 <= end){
            temp[i] = nums[idx2++];
        }
    }
      
    for(int i = start; i <= end; i++){     //Copy back data
        nums[i] = temp[i];
    }
}

