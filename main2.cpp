#include<iostream>
#include<cstring>
using namespace std;

#include "stack.h"

int main(int argc, char **argv){
    Stack s;
   
/*
  Exercise 2
 printf("Checking the parentheses in argv arguments\n");
*/

    printf("Checking the parentheses in argv arguments\n");

    int i,j;

    for(i=1;i<argc;i++){

        int correct = 1;

        for(j=0;j<strlen(argv[i]);j++){
            // Use stack to help with the parentheses

            if(argv[i][j] == '(' || argv[i][j] == '{' || argv[i][j] == '['){
                s.push(argv[i][j]);
            }

            else if(argv[i][j] == ')'){
                int t = s.pop();
                if(t != '('){
                    cout << "argv " << i << " incorrect: mismatch\n";
                    correct = 0;
                    break;
                }
            }

            else if(argv[i][j] == '}'){
                int t = s.pop();
                if(t != '{'){
                    cout << "argv " << i << " incorrect: mismatch\n";
                    correct = 0;
                    break;
                }
            }

            else if(argv[i][j] == ']'){
                int t = s.pop();
                if(t != '['){
                    cout << "argv " << i << " incorrect: mismatch\n";
                    correct = 0;
                    break;
                }
            }
        }

        if(correct){
            if(s.pop() == -1)
                cout << "argv " << i << " correct\n";
            else
                cout << "argv " << i << " incorrect: too many open parenthesis\n";
        }

        while(s.pop() != -1);  // clear stack for next argv
    }

   return 0;
}