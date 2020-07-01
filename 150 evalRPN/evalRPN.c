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
        
        return -1;
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

int strToInt(char *str)
{
    
    int len = strlen(str);
    int temp = 0;
    int sum = 0;
    int sign =1;
    int i=0;
     if(str[0]=='-')
        {
            sign = -1;
            i=1;           
            
        }
    for (i; i < len; i++) 
    {
       
        temp = str[i] - '0';
        sum = sum * 10 + temp;
    }
    return sum * sign;
}
int evalRPN(char ** tokens, int tokensSize){

    Stack *stk = StackCreate(tokensSize); 
    int num;
    int firstNum=0;
    int secondNum =0;
   
    
    for(int i=0;i<tokensSize;i++)
    {
        
        if((strlen(tokens[i])==1)&&((tokens[i][0]=='+')||(tokens[i][0]=='-')||(tokens[i][0]=='*')||(tokens[i][0]=='/')))
        {
            //printf("i%d  %c \n",i,tokens[i][0]);
            
            secondNum = StackPop(stk);
            firstNum = StackPop(stk);
            
           // printf("firstNum = %d secondNum=%d\n",firstNum,secondNum);
            
            switch(tokens[i][0])
            {
                
                case '+':
                {                                  
                    num = firstNum + secondNum;                    
                    break;                   
                }
                case '-':
                {
                    num = firstNum - secondNum;
                    break;  
                }
                case '*':
                {                                  
                    num = firstNum * secondNum;                    
                    break;                   
                }
                case '/':
                {
                    num = firstNum / secondNum;
                    break;  
                }
                
            }
            StackPush(stk,num);
            
        }
        else
        {
            num = strToInt(tokens[i]);
            
            StackPush(stk,num);
           // printf("num =%d\n",num); 
        }
        
      
       
    }
    

    return StackPop(stk);
}

