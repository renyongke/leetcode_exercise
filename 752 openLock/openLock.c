#define LOCKSIZE 5
#define MAX_ELEM_NUM 10000

typedef struct Node {
    char str[LOCKSIZE];
    int step;
} Node;
typedef Node ElemType;

typedef struct MyQueue {
    ElemType elem[MAX_ELEM_NUM];
    int front;
    int rear;
} MyQueue;

bool IsQueueFull(MyQueue* Q)
{
    if ((Q->rear + 1) % MAX_ELEM_NUM == Q->front) {
        return true;
    }
    return false;
}

bool IsQueueEmpty(MyQueue* Q)
{
    if (Q->front == Q->rear) {
        return true;
    }
    return false;
}

MyQueue* QueueInit()
{
    MyQueue* Q = (MyQueue *)malloc(sizeof(MyQueue));
    memset(Q, 0, sizeof(MyQueue));

    return Q;
}

void QueuePush(MyQueue* Q, ElemType elem)
{
    if (IsQueueFull(Q)) {
        return;
    }
    Q->elem[Q->rear] = elem;
    Q->rear = (Q->rear + 1) % MAX_ELEM_NUM;
}

void QueuePop(MyQueue* Q, ElemType* elem)
{
    if (IsQueueEmpty(Q)) {
        return;
    }
    *elem = Q->elem[Q->front];
    Q->front = (Q->front + 1) % MAX_ELEM_NUM;
}

void ConvertLock(int* arr, int origiNum)
{
    if (origiNum == 0) {
        arr[0] = 1;
        arr[1] = 9;
    }
    else if (origiNum == 9) {
        arr[0] = 8;
        arr[1] = 0;
    }
    else {
        arr[0] = origiNum - 1;
        arr[1] = origiNum + 1;
    }
}

int StrToInt(char* str)
{
    int len = strlen(str);
    int temp = 0;
    int sum = 0;
    for (int i = 0; i < len; i++) {
        temp = str[i] - '0';
        sum = sum * 10 + temp;
    }
    return sum;
}

bool CheckCanReach(bool *deadFlag, char* target)
{
    int count = 0;
    for (int i = 0; i < LOCKSIZE - 1; i++) {
        int temp[2] = { 0, 0 };
        ConvertLock(temp, target[i] - '0');
        for (int j = 0; j < 2; j++) {
            Node node;
            memcpy(node.str, target, sizeof(char) * LOCKSIZE);
            node.str[i] = temp[j] + '0';

            if (deadFlag[StrToInt(node.str)] == true) {
                count++;
            }
        }
    }

    if (count == (LOCKSIZE - 1) * 2) {
        return false;
    }
    return true;
}

int BFS(bool* deadFlag, char* target, bool* visitedArr)
{
    MyQueue *Q = QueueInit();

    Node initNode;
    memset(&initNode, 0, sizeof(Node));
    memcpy(initNode.str, "0000", sizeof(char) * LOCKSIZE);

    if (deadFlag[StrToInt(initNode.str)] == false) {
        QueuePush(Q, initNode);
        visitedArr[StrToInt(initNode.str)] = true;        
    }

    while (!IsQueueEmpty(Q)) {
        QueuePop(Q, &initNode);

        if (strcmp(initNode.str, target) == 0) {
            free(Q);
            return initNode.step;
        }

        for (int i = 0; i < LOCKSIZE - 1; i++) {
            int temp[2] = { 0, 0 };
            ConvertLock(temp, initNode.str[i] - '0');
            for (int j = 0; j < 2; j++) {
                Node newNode;
                memcpy(newNode.str, initNode.str, sizeof(char) * LOCKSIZE);
                newNode.str[i] = temp[j] + '0';
                newNode.step = initNode.step + 1;

                if (deadFlag[StrToInt(newNode.str)] == false && visitedArr[StrToInt(newNode.str)] == false) {
                    QueuePush(Q, newNode);
                    visitedArr[StrToInt(newNode.str)] = true;
                }
            }
        }
    }

    free(Q);
    return -1;
}

int openLock(char** deadends, int deadendsSize, char* target)
{
    bool *deadFlag = (bool *)malloc(sizeof(bool) * MAX_ELEM_NUM);
    memset(deadFlag, false, sizeof(bool) * MAX_ELEM_NUM);
    for (int i = 0; i < deadendsSize; i++) {
        deadFlag[StrToInt(deadends[i])] = true;
    }

    if (!CheckCanReach(deadFlag, target)) {
        free(deadFlag);
        return -1;
    }

    bool* visited = (bool *)malloc(sizeof(bool) * MAX_ELEM_NUM);
    memset(visited, false, sizeof(bool) * MAX_ELEM_NUM);

    int result = BFS(deadFlag, target, visited);

    free(deadFlag);
    free(visited);

    return result;
}

