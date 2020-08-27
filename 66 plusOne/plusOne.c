/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize){

        for (int i = digitsSize - 1; i >= 0; --i) 
        {
            if (digits[i] == 9)
            {
                digits[i] = 0;
            } 
            else 
            {
                digits[i]++;
                *returnSize = digitsSize;
                return digits;
            }
        }

    int *result = (int *) malloc(sizeof(int) * (digitsSize + 1));
    memset(result, 0, (digitsSize + 1) * sizeof(int));
    result[0] = 1;
    *returnSize = digitsSize + 1;
    return result;



}
