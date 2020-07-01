int Dfs(int* nums, int numsSize, int S, int sum)
{
    if (numsSize == 0) {
        if (S == sum) {
            return 1;
        } else {
            return 0;
        }
    }

    int left = Dfs(nums + 1, numsSize - 1, S, sum + nums[0]);
    int right = Dfs(nums + 1, numsSize - 1, S, sum - nums[0]);
    return left + right;
}

int findTargetSumWays(int* nums, int numsSize, int S){
    return Dfs(nums, numsSize, S, 0);
}

