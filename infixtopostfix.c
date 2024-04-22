#include <stdio.h>
#include <string.h>
#include <ctype.h>

int top = -1;
char s[50], item, exp[50];

void push(char item)
{
    top = top + 1;
    s[top] = item;
}

char pop()
{
    item = s[top];
    top = top - 1;
    return item;
}

int isOperator(char op)
{
    return (op == '^' || op == '*' || op == '/' || op == '+' || op == '-');
}

int getPrecedence(char op)
{
    if (op == '^')
        return 3;
    else if (op == '*' || op == '/')
        return 2;
    else if (op == '+' || op == '-')
        return 1;
    else
        return 0;
}

void toPostfix(char str[50])
{
    int j = 0;

    for (int i = 0; i < strlen(str); i++)
    {
        if (isalpha(str[i]))
        {
            exp[j] = str[i];
            j++;
        }
        else if (isOperator(str[i]))
        {
            while (top >= 0 && getPrecedence(s[top]) >= getPrecedence(str[i]))
            {
                exp[j] = pop();
                j++;
            }
            push(str[i]);
        }
        else if (str[i] == '(')
        {
            push(str[i]);
        }
        else if (str[i] == ')')
        {
            while (top >= 0 && s[top] != '(')
            {
                exp[j] = pop();
                j++;
            }
            if (top >= 0 && s[top] == '(')
            {
                pop(); // Discard the '('
            }
        }
    }

    while (top >= 0)
    {
        exp[j] = pop();
        j++;
    }

    for (int i = 0; i < j; i++)
    {
        printf("%c", exp[i]);
    }
}

int evaluatePostfix()
{
    int operandStack[50];
    int topOperand = -1;

    for (int i = 0; i < strlen(exp); i++)
    {
        if (isalpha(exp[i]))
        {
            printf("Enter value for operand %c: ", exp[i]);
            int value;
            scanf("%d", &value);
            operandStack[++topOperand] = value;
        }
        else if (isOperator(exp[i]))
        {
            int operand2 = operandStack[topOperand--];
            int operand1 = operandStack[topOperand--];

            switch (exp[i])
            {
            case '^':
                operandStack[++topOperand] = operand1 ^ operand2;
                break;
            case '*':
                operandStack[++topOperand] = operand1 * operand2;
                break;
            case '/':
                operandStack[++topOperand] = operand1 / operand2;
                break;
            case '+':
                operandStack[++topOperand] = operand1 + operand2;
                break;
            case '-':
                operandStack[++topOperand] = operand1 - operand2;
                break;
            }
        }
    }

    return operandStack[topOperand];
}

int main()
{
    char str[50];
    printf("Enter the expression: ");
    gets(str);

    for (int i = 0; i < strlen(str); i++)
    {
        str[i] = toupper(str[i]);
    }

    toPostfix(str);

    int result = evaluatePostfix();
    printf("\nResult of the postfix expression: %d\n", result);

    return 0;
}
