#define MAX   5000
#define MAX1  1000

typedef struct {
    int totalNum;
    int data[MAX1];
    char str[MAX1][MAX1];
}STACK;

int isDigit(char s)
{
    if (s >= '0' && s <= '9') {
        return 1;
    }
    return 0;
}

int isAlpha(char s)
{
    if ((s >= 'a' && s <= 'z') || (s >= 'A' && s <= 'Z')) {
        return 1;
    }
    return 0;
}

char * decodeString(char * s)
{
    int i = 0;
    int j = 0;
    int len = strlen(s);
    int count = 0;
    //int pbufLen = 0;
    int cacheLen = 0;
    //int dequeCache = 0;
    char *pbuf = (char *)malloc(MAX * sizeof(char));
    memset(pbuf, 0, MAX * sizeof(char));

    char *cache = (char *)malloc(MAX * sizeof(char));
    memset(cache, 0, MAX * sizeof(char));

    char *dequeCache = (char *)malloc(MAX * sizeof(char));
    memset(dequeCache, 0, MAX * sizeof(char));

    //int alphaStack[MAX] = {0};

    STACK stack = {0};

    for (i = 0; i < len; i++) {
        if (isDigit(s[i])) {
            count = count * 10 + s[i] - '0';
        } else if (isAlpha(s[i])) {
            cache[cacheLen++] = s[i];
        } else if (s[i] == '[') {
            stack.data[stack.totalNum] = count;
            strcpy(&stack.str[stack.totalNum], cache);
            memset(cache, 0, MAX * sizeof(char));
            cacheLen = 0;
            count = 0;
            stack.totalNum++;
        } else if (s[i] == ']') {
            //printf("i is %d\n", i);
            strcpy(dequeCache, &stack.str[stack.totalNum - 1]);
            for (j = 0; j < stack.data[stack.totalNum - 1]; j++) {
                strcat(dequeCache, cache);
            }
            memset(cache, 0, MAX * sizeof(char));
            strcpy(cache, dequeCache);
            cacheLen = strlen(cache);
            stack.totalNum--;
        }

    }
    //cache[cacheLen] = '\0';
    return cache;
}
