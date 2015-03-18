#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <stack>
#include <string.h>

using namespace std;

bool isOperator(char ch)
{
    if (ch=='+' || ch=='-' || ch=='*' || ch=='/')
        return true;
    else
        return false;
}


float performOperation(float op1, float op2, char op)
{
    float ans;
    switch(op){
    case '+':
        ans = op2 + op1;
        break;
    case '-':
        ans = op2 - op1;
        break;
    case '*':
        ans = op2 * op1;
        break;
    case '/':
        ans = op2 / op1;
        break;
    }
    return ans;
}


int main()
{
    char exp[1000], buffer[15];
    int i, len, j;
    float op1, op2, x;
    stack<float> s;
    printf("Enter a Postfix Expression:\n");
    gets(exp);
    len = strlen(exp);
    j = 0;
    for(i=0; i<len;i++){

        if((exp[i]>='0' && exp[i]<='9') || exp[i]=='.'){
            buffer[j++] = exp[i];
        }
        else if(exp[i]==' '){
            if(j>0){
                buffer[j] = '\0';
                x = atof(buffer);
                s.push (x);
                j = 0;
            }
        }

        else if(isOperator(exp[i])){
            op1 = s.top();
            s.pop();
            op2 = s.top();
            s.pop();
            s.push(performOperation(op1, op2, exp[i]));
        }
    }

    printf("Answer is %f\n", s.top());

    return 0;
}
