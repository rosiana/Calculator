#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <stack>
#include <string.h>
#include <cmath>
#include <math.h>

using namespace std;

int main()
{
    char exp[1000], buffer[15];
    int i,op1, op2, len, j, x;
    stack<int> s;
    printf("Enter a Postfix Expression:\n");
    gets(exp);
    len = strlen(exp);
    j = 0;
    for(i=0; i<len;i++){

        if(exp[i]>='0' && exp[i]<='9'){
            buffer[j++] = exp[i];
        }
        else if(exp[i]==' '){
            if(j>0){
                buffer[j] = '\0';
                x = atoi(buffer);
                s.push (x);
                j = 0;
            }
        }

        else if(exp[i]=='+' || exp[i]=='-' || exp[i]=='*' || exp[i]==':' || exp[i]=='%' || exp[i]=='/'){
            op1 = s.top();
            s.pop();
            op2 = s.top();
            s.pop();
            switch(exp[i]){
                case '+':
                    s.push(op2 + op1);
                    break;
                case '-':
                    s.push(op2 - op1);
                    break;
                case '*':
                    s.push(op2 * op1);
                    break;
                case ':':
                    s.push(op2 / op1);
                    break;
                case '%':
                    s.push(op2 % op1);
                    break;
                case '/':
                    int div;
                    div = (int)floor(op2 / op1);
                    s.push(div);
                    break;
            }
        }
    }
    printf("Answer is %d\n", s.top());
    return 0;
}
