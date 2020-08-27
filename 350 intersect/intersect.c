/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int cmp( const void * a , const void * b )
{
    return *(int *)a > *(int *)b;
}

int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize){

    int *buffer = (int *)malloc(sizeof(int)* nums1Size);
    int i=0,j=0;

    qsort(nums1,nums1Size,sizeof(int),cmp);
    qsort(nums2,nums2Size,sizeof(int),cmp);
     *returnSize = 0;
    while( (i < nums1Size) && (j < nums2Size) )
    {
        if(nums1[i] == nums2[j] )
        {
            buffer[*returnSize]= nums1[i];
            *returnSize += 1;
            i++;
            j++;
        }
        else if(nums1[i]<nums2[j]  )
        {
            i++;
        }
        else 
        {
            j++;
        }

    }

    return buffer;

}
