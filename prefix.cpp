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


int performOperation(char op, int op1, int op2)
{
    int ans;
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
    char exp[1000], buffer[15], buffer2[15];
    int i,op1, op2, len, j, x;
    stack<int> s;
    printf("Enter a Prefix Expression:\n");
    gets(exp);
    len = strlen(exp);
    j = 0;
    for(i=len-1; i>=0; i--){

        if(exp[i]>='0' && exp[i]<='9'){
            buffer[j] = exp[i];
            //cout << buffer[j] << endl;
            j++;
        }
        else if(exp[i]==' '){
            if(j>0){
				cout << "Nilai j: " << j << endl;
				int n =j-1;
				int k;
                for(k = 0; k < j; k++){
					buffer2[k]=buffer[n];
					cout << buffer2[k]<<endl;
					n--;
                }
                buffer2[k+1] = '\0';
                x = atoi(buffer2);
                s.push(x);
                j = 0;
            }
        }

        else if(isOperator(exp[i])){
            op1 = s.top();
            s.pop();
            op2 = s.top();
            s.pop();
            s.push(performOperation(exp[i], op1, op2));
        }
    }

    printf("Answer is %d\n", s.top());

    return 0;
}
