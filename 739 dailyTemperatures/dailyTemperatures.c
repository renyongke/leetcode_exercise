

typedef struct {
    int *data;
    int top;
   

} Stack;

/** initialize your data structure here. */

Stack* StackCreate(int num) {
    Stack *obj = malloc(sizeof(Stack));
    if(obj)
    {
        obj->top=-1;
        
        obj->data = (int*)malloc(num*sizeof(int));
        
        
        return obj;
    }
    
    return NULL;
}

void StackPush(Stack* obj, int x) {

    obj->data[++(obj->top)] =x;
    
}

int StackPop(Stack* obj) {

    if(obj->top <0)
    {
        
        return;
    }
    return  obj->data[(obj->top)--] ;
   
  
 
}

int StackTop(Stack* obj) {
    return obj->data[obj->top];
}



void StackFree(Stack* obj) {
   free(obj->data);
   obj->data =NULL;
   free(obj);
   obj=NULL;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* dailyTemperatures(int* T, int TSize, int* returnSize){

    int i=0;
    int k=0;
    Stack *stk = StackCreate(TSize);
    
    int *NT =  (int*)malloc(TSize*sizeof(int));
    memset(NT,0,sizeof(int)*TSize);
    for(i=0;i<TSize;i++)
    {
        
        //printf("---%d----stk->top =%d   \n",i,stk->top);
    
        while((stk->top>-1)&&(T[i]>T[stk->data[stk->top]]))
        {
            k = StackPop(stk);
            NT[k]= i-k;
            
        }
        
        StackPush(stk,i);
        
       
        
    }
    
    *returnSize= TSize;
    return NT;
}

