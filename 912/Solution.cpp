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
        while(nums[right] >= pivot && left < right){ //right move first
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
        while(nums[left] <= pivot && left < right){ //left move first
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
//0.The point is to let left/right pointer cross condition
//1.left++ pointer and right-- pointer, whoever moves first will cross boundary(left condition & right condition(usually NOT left))
//2.Even if left != right and they swap value, eventually left/right who moves first will cross bounday
//3.When left == right(ending condition), two special cases to check: 
//a).pointer never move(consider as CROSS)
//b).pointer moved all the way to the end(DID NOT CROSS)
//eg. left move first & ending with left conditon: left moves all the way to the end. left first & right condition: left cross boundary
//4.OOOXXX case: To find first XXX, let left move first to cross from OOO to XXX. Because when left cross(out of while loop for left),
//the condition becomes XXX, and it's looking for first XXX. This is consistent, otherwise consider special case listed as 3.a eg.
//Find first XXX  left first(!while(O))                         right first(!while(X))
//all OOOOOO      3.b, all way to end.expected special case     3.a never moved, confused with normal OOOXXX conditon, and return ++right
//all XXXXXX      3.a, never moved. already find answer         3.b all the way to end, which is actually normal condition
//Similarly, to find last OOO, move right first from XXX to cross OOO. 
//5.Be careful is there is only ONE element!


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

