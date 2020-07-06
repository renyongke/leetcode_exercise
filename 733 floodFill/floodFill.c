int **visit;

void dfs(int **image, int imageSize, int *imageColSize, int x, int y, int color, int newColor)
{
   // printf("x = %d, y = %d\n", x, y);

    //array edge
    if (x < 0 || x >= imageSize || y < 0  || y >= imageColSize[x]) {
        return;
    }

    //unreachable
    if (image[x][y] != color) {
        return;
    }

    //visited
    if (visit[x][y] == 1) {
        return;
    }

    //up, down, left, right
    visit[x][y] = 1;
    dfs(image, imageSize, imageColSize, x - 1, y, color, newColor);
    dfs(image, imageSize, imageColSize, x + 1, y, color, newColor);
    dfs(image, imageSize, imageColSize, x, y - 1, color, newColor);
    dfs(image, imageSize, imageColSize, x, y + 1, color, newColor);
    image[x][y] = newColor;

    return;
}



/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** floodFill(int** image, int imageSize, int* imageColSize, int sr, int sc, int newColor, int* returnSize, int** returnColumnSizes){

    visit = calloc(imageSize,sizeof(int*));
    
    for(int i=0;i<imageSize;i++)
    {
        visit[i] = calloc(imageColSize[i],sizeof(int));
    }
    
    dfs(image,imageSize,imageColSize,sr,sc,image[sr][sc],newColor);
    
    * returnSize = imageSize;
  * returnColumnSizes  = calloc(imageSize,sizeof(int));
    
     for(int i=0;i<imageSize;i++)
    {
        (*returnColumnSizes)[i] = imageColSize[i];
    }
    
    return image;
    
    
}

