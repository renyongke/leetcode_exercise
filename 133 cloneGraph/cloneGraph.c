/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     int numNeighbors;
 *     struct Node** neighbors;
 * };
 */

#define MAX_NODE_NUM 101


void dfs(struct Node* s, struct Node** result, struct Node** dump){
      int i = 0;
    if(*result==NULL)
    {
       *result = (struct Node*)malloc(sizeof(struct Node));
        memset(*result,0,sizeof(struct Node));
        (*result)->val = s->val;
        (*result)->numNeighbors = s->numNeighbors;
        (*result)->neighbors = (struct Node**)malloc(sizeof(struct Node*) * (s->numNeighbors));
        memset((*result)->neighbors,0,sizeof(struct Node*)*(s->numNeighbors));
    }
    
    dump[s->val] = *result;
    
    for(i=0;i<s->numNeighbors;i++)
    {
        if(s->neighbors[i]!=NULL)
        {
            if(dump[s->neighbors[i]->val]==NULL)
            {
                dfs(s->neighbors[i],&((*result)->neighbors[i]),dump );
            }
            else
            {
                (*result)->neighbors[i] = dump[s->neighbors[i]->val];
            }
        
        }
    }
    
    return ;
    
}

struct Node *cloneGraph(struct Node *s) {
    
   struct Node *dump[MAX_NODE_NUM] ={NULL};
   struct Node * result =NULL;
    
    if(s == NULL)
    {
        return NULL;
    }
    
    dfs(s,&result,dump);
   
    
    return result;
}
