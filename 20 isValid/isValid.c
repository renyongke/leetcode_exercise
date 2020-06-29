#define MAX_COUNT 10000
char stack[MAX_COUNT] = {0};
int stack_top = 0;

void stack_init()
{
	stack_top = 0;
	memset(stack, 0, sizeof(stack));
}

void stack_push(char ch)
{
	stack[stack_top++] = ch;
}

bool stack_empty()
{
	if (stack_top <= 0) {
		return true;
	}
	return false;
}

char stack_pop()
{
	char ch = stack[stack_top-1];
	stack[--stack_top] = 0;
	return ch;
}

bool isValid(char *s)
{
	if (s == NULL) {
		return false;
	}
	stack_init();
	for (int i = 0; s[i]; i++) 
    {
        switch(s[i]) {
    	case '(':
    	case '[':
    	case '{':
    		stack_push(s[i]);
    		break;
		case ')':
		case ']':
		case '}':
			if (stack_empty()) 
            {
				return false;
			}
            else 
            { // 不为空
				char ch = stack_pop();
				if ((ch == '(' && s[i] == ')') ||
					(ch == '[' && s[i] == ']') ||
					(ch == '{' && s[i] == '}'))
                {
				    break;
				} 
                else 
                {
					return false;
				}
			}
		default:
			return false;
		}
	}
	if (!stack_empty()) {
		return false;
	}
	return true;
}

