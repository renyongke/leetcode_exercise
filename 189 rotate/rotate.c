
void reversal(int *nums,int start,int end)
{
    int temp=0;

    while(start<end)
    {
        temp = nums[start];
        nums[start] = nums[end];
        nums[end] = temp;
        start++;
        end--;
    }
}
void rotate(int* nums, int numsSize, int k){

    if(k>numsSize)
    {
        k= k%numsSize;
    }


    reversal(nums,0,numsSize-1);
    reversal(nums,0,k-1);
    reversal(nums,k,numsSize-1);

}
