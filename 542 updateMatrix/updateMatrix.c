#define MAX_NUM 10240
#define Min(a,b) (a<b ? a : b)

typedef struct{
    int x;
    int y;
}pos;

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** updateMatrix(int** matrix, int matrixSize, int* matrixColSize, int* returnSize, int** returnColumnSizes){
    
    int** result = (int**)malloc(matrixSize*sizeof(int*));
    
    int x=0,y=0;
    int front =0;
    int rear =0;
    int i=0,j=0;
    int dirs[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
    
    pos* queue = (pos*)malloc(MAX_NUM*sizeof(pos));
    
    for( i=0;i<matrixSize;i++)
    {
        result[i] =(int*) calloc(matrixColSize[i],sizeof(int));
        for(j=0;j<matrixColSize[i];j++)
        {
            if(matrix[i][j]!=0)
            {
                result[i][j] = INT_MAX;
            }
            else
            {
                queue[front].x =i;
                queue[front++].y =j;
                
            }
        }
    }
    
    
    while(front!=rear)
    {
        pos xp = queue[rear++];
        
        for(i=0;i<4;i++)
        {
            x = xp.x+dirs[i][0];
            y = xp.y+dirs[i][1];
            
            if((x>=0)&&(x<matrixSize)&&(y>=0)&&(y<matrixColSize[0]))
            {
                if(result[x][y]>result[xp.x][xp.y]+1)
                {
                    result[x][y] = result[xp.x][xp.y]+1;
                    queue[front].x =x;
                    queue[front++].y =y;
                    
                }
            }
        }
    
    }
    
 
    
    * returnSize = matrixSize;
  * returnColumnSizes  =(int*) malloc(matrixSize*sizeof(int));
    
    memcpy(*returnColumnSizes, matrixColSize, matrixSize * sizeof(int));
    
    return result;
    

}

