
int comp(void *a, void *b) {
    return *(int *)a - *(int *)b;
}

bool containsDuplicate(int* nums, int numsSize){
    if (!nums || !numsSize)
    {
        return false;
    } 

    qsort(nums, numsSize, sizeof(int), comp);
    for (int i = 0; i < numsSize - 1; i++) {
        if (nums[i] == nums[i+1])
            return true;
    }
    return false;


}
