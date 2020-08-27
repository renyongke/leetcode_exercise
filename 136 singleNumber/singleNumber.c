
int singleNumber(int* nums, int numsSize){
    //fun1
    //return numsSize==1?nums[0]:(singleNumber(nums+1,numsSize-1)^nums[0]);

    //fun2
    int ans =0;

    for(int i=0;i<numsSize;i++)
    {
        ans ^= nums[i];
    }

    return ans;
}
