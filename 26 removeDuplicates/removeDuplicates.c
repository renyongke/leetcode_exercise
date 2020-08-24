int removeDuplicates(int* nums, int numsSize){

int i=0;
int tmp = 0;
int index=0;
for(i=0;i<numsSize;i++)
{
    if(i==0)
    {
        tmp = nums[0];
        index+=1;
    }
    else
    {
        if(nums[i]==tmp)
        {
            
        }
        else
        {
            tmp = nums[i];
            nums[index] =tmp; 
            index+=1;
        }
    }
}
    return index;
}
