/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void    Dfs(struct TreeNode* root, int *returnSize, int *S)
{
  
    if(!root)
    {
        return ;
    }
     Dfs(root->left, returnSize, S);
   S[(*returnSize)++] = root->val;
    Dfs(root->right, returnSize, S);
  
    

}


int calcsize(struct TreeNode* root)
{
    if(!root)
    {
        return 0;
    }
    
    return calcsize(root->left)+calcsize(root->right)+1;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* inorderTraversal(struct TreeNode* root, int* returnSize){
    

    int size = calcsize(root);
    int *S  =(int *) malloc(sizeof(int)*size); 
    memset(S,0,size);
    
    *returnSize = 0;
    Dfs(root, returnSize, S);

    return S;
}

