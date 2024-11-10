//infix to postfix
#include<stdio.h>
#include<string.h>
#include <ctype.h>
#include<stdlib.h>
#define MAX 100
char stack[MAX];
int top=-1;

void push(char x){
if(top==MAX-1){
printf("OVERFLOW");
return;
}

stack[++top]=x;

}

char pop(){
if(top==-1){
printf("Stack underflow");

}

return stack[top--];

}
int precedence (char x){
if(x=='(')
return 0;
if(x=='+' || x=='-')
return 1;
if(x=='*' || x=='/')
return 2;
if(x=='^')
return 3;

return 0;

}

void infixtopostfix(char *infix,char *postfix){
int i=0,k=0;
char x;
while(infix[i]){
if(isalnum(infix[i])){
postfix[k++]=infix[i];
}
else if(infix[i]=='('){
push(infix[i]);

}
else if(infix[i]==')'){
while((x=pop())!='('){
postfix[k++]=x;
}

}
else{ //operator

while(top!=-1 && precedence(stack[top])>=precedence(infix[i])){
postfix[k++]=pop();
}
push(infix[i]);//pushing the operator after popping

}
i++;

}
while(top!=-1){
postfix[k++]=pop();
}
postfix[k]='\0';

}

int main(){
char infix[MAX],postfix[MAX];
printf("\nEnter the infix expression\n");
scanf("%s",infix);
infixtopostfix(infix,postfix);
printf("Postfix expression is %s\n",postfix);
return 0;

}
