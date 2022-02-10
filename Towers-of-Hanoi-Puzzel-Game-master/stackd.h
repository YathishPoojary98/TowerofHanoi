#include<stdio.h>
#define stacksize1 100
struct diskstack{
int x[stacksize1];
int top;
};
void init_stack(struct diskstack* stack){
stack->top=-1;
}
int tracestack(struct diskstack stack,int i){
if(i<=-1)
return -1;
return (stack.x[i]);
}
int stacksize(struct diskstack stack){
return stack.top;
}
void push(struct diskstack* stack,int item){
if(full(*stack)==0){
stack->top++;
stack->x[stack->top]=item;
}
}
int pop(struct diskstack* stack){
int n=stack->x[stack->top];
if(empty(*stack))
return -1;
stack->top--;
return n;
}

int empty(struct diskstack stack){
if(stack.top==-1)
return 1;
return 0;
}
int full(struct diskstack stack){
if(stack.top==stacksize1){
    return 1;
    }
    return 0;
}
int gettopelement(struct diskstack stack){
if(stack.top==-1)
 return -1;
return(stack.x[stack.top]);
}
