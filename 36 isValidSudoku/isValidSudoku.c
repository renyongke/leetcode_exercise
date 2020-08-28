bool isValidSudoku(char** board, int boardSize, int* boardColSize){

    int i=0,j=0;

    int m=0,n=0;

    int nums[11];
    memset(nums,0,sizeof(nums));


    for(i=0;i<boardSize;i++)
    {
         memset(nums,0,sizeof(nums));

         for(j=0;j<* boardColSize;j++)
         {
             if(board[i][j]!='.')
             {
               
                 if(nums[board[i][j]-'0']!=0)
                 {
                    return false;
                 }
                 else
                 {
                     nums[board[i][j]-'0'] = 1;
                 }
             }
         }
    }


    for(j=0;j<boardSize;j++)
    {
         memset(nums,0,sizeof(nums));

         for(i=0;i<* boardColSize;i++)
         {
             if(board[i][j]!='.')
             {
               
                 if(nums[board[i][j]-'0']!=0)
                 {
                    return false;
                 }
                 else
                 {
                     nums[board[i][j]-'0'] = 1;
                 }
             }
         }
    }


    for(i=0;i<boardSize;i+=3)
    {
         

         for(j=0;j<* boardColSize;j+=3)
         {
            memset(nums,0,sizeof(nums));

                 for(m=i;m<i+3;m++)
                 {
                     
                     for(n=j;n<j+3;n++)
                     {

                        if(board[m][n]!='.')
                        {              
                                if(nums[board[m][n]-'0']!=0)
                                {
                                    return false;
                                }
                                else
                                {
                                    nums[board[m][n]-'0'] = 1;
                                }
                        }
                     }
                 }
               
                
             
         }
    }



    return true;
}
