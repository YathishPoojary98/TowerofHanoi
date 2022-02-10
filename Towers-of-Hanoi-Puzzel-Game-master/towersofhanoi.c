#include<stdio.h>
#include "stackd.h"
#include<SDL2/SDL.h>
#include <stdlib.h>
struct disk_color{
unsigned int red;
unsigned int blue;
unsigned int green;
};
struct disk_color dcolor[7];
const int SCREEN_WIDTH =1200;
const int SCREEN_HEIGHT = 720;
short int quit=0;
SDL_Event e;
SDL_Window *window=NULL;
SDL_Renderer *render=NULL;
SDL_Rect rect_a={80,200,150,300},rect_b={600,200,150,300},rect_c={1100,200,150,300};
SDL_Rect disk={10,10,70,15},pole;
struct diskstack stack_a,stack_b,stack_c;
short int no_of_disk=3,skip=0,location,drag_disk,from,to;
int init(){
register int i;
if(SDL_Init(SDL_INIT_VIDEO)<0){
    printf("Error while initializing SDL\n");
    return 0;
}
window=SDL_CreateWindow("Tower of Hanoi",SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,SCREEN_WIDTH,SCREEN_HEIGHT,SDL_WINDOW_SHOWN);
render=SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);
rect_b.x=rect_a.x+400;
rect_c.x=rect_b.x+400;
}
void game_init(){
    int i;
init_stack(&stack_a);
init_stack(&stack_b);
init_stack(&stack_c);
for(i=no_of_disk;i>0;i--){
push(&stack_a,i);
}
dcolor[0].red=136;
dcolor[0].green=3;
dcolor[0].blue=252;

dcolor[1].red=235;
dcolor[1].green=247;
dcolor[1].blue=5;

dcolor[2].red=5;
dcolor[2].green=247;
dcolor[2].blue=163;

dcolor[3].red=247;
dcolor[3].green=94;
dcolor[3].blue=5;

dcolor[4].red=255;
dcolor[4].green=157;
dcolor[4].blue=0;

dcolor[5].red=25;
dcolor[5].green=157;
dcolor[5].blue=240;

}


void draw_drag_disk(){
int x,y;
SDL_GetMouseState(&x,&y);
disk.x=x;
disk.y=y;
disk.w=getwidthofdisk(drag_disk);
SDL_SetRenderDrawColor(render,255,0,0,255);
SDL_RenderFillRect(render,&disk);
}
int valid_move(int f,int t){
int d;
if(f==1){
    d=gettopelement(stack_a);
}
else if(f==2){
    d=gettopelement(stack_b);
}
else if(f==3){
    d=gettopelement(stack_c);
}
if(d==-1)
    return 0;
if(t==1){
    if(gettopelement(stack_a)>d  || gettopelement(stack_a)==-1)
    return 1;
}
else if(t==2) {
    if(gettopelement(stack_b)>d || gettopelement(stack_b)==-1)
    return 1;
}
else if(t==3){
    if(gettopelement(stack_c)>d || gettopelement(stack_c)==-1)
    return 1;
}
return 0;
}
void move_disk(int f,int t){
    int d;
if(!valid_move(f,t)){
return;
}
if(f==1){
    d=pop(&stack_a);

}
else if(f==2){
    d=pop(&stack_b);
}
else if(f==3){
    d=pop(&stack_c);
}
if(d==-1)
    return;
if(t==1){
    push(&stack_a,d);
}
else if(t==2) {
    push(&stack_b,d);
}
else if(t==3){
    push(&stack_c,d);
}

}
void clear_screen(){
SDL_SetRenderDrawColor(render,128,159,255,255);
SDL_RenderClear(render);
}
int getmouselocation(){
int x,y;
SDL_GetMouseState(&x,&y);
if(rect_a.x<x && (rect_a.x+rect_a.w)>x && rect_a.y<y && (rect_a.y+rect_a.h)>y)
return 1;
if(rect_b.x<x && (rect_b.x+rect_b.w)>x && rect_b.y<y && (rect_b.y+rect_b.h)>y)
return 2;
if(rect_c.x<x && (rect_c.x+rect_c.w)>x && rect_c.y<y && (rect_c.y+rect_c.h)>y)
return 3;
return 0;
}
void draw_background1(){
//SDL_SetRenderDrawColor(render,128,159,255,255);
SDL_RenderFillRect(render,&rect_a);
}
void draw_background2(){
//SDL_SetRenderDrawColor(render,128,159,255,255);
SDL_RenderFillRect(render,&rect_b);
}
void draw_background3(){
//SDL_SetRenderDrawColor(render,128,159,255,255);
SDL_RenderFillRect(render,&rect_c);
}
void draw_pole(SDL_Rect b){
int mid_x,mid_y;
pole.w=15;
pole.h=no_of_disk*25;
mid_x=b.x+b.w/2-pole.w/2;
pole.x=mid_x;
pole.y=b.y+b.h-pole.h-15;
SDL_SetRenderDrawColor(render,0,0,255,255);
SDL_RenderFillRect(render,&pole);
pole.w=getwidthofdisk(no_of_disk)+30;
pole.h=15;
pole.x=b.x+b.w/2-pole.w/2;
pole.y=b.y+b.h-pole.h;
SDL_RenderFillRect(render,&pole);
}
int getwidthofdisk(int n){
return (3*n+1)*10;
}
void draw_tower(){
int t,size,mid,i=0;
int mid_x,mid_y,r,b,g;
int offset=15;
int m=2.5;
int c;
c=stacksize(stack_a)+1;
draw_pole(rect_a);
if(skip==1 && (location==1)){
from=1;
drag_disk=gettopelement(stack_a);
c--;
draw_drag_disk();
}
while(i!=c){
t=tracestack(stack_a,i);
size=getwidthofdisk(t);
mid=size/2;
disk.w=size;
mid_x=rect_a.x+rect_a.w/2;
mid_y=rect_a.y+rect_a.h;
disk.x=mid_x-mid;
disk.y=mid_y-(offset*m);
m=m+1;
SDL_SetRenderDrawColor(render,dcolor[t-1].red,dcolor[t-1].green,dcolor[t-1].blue,255);
SDL_RenderFillRect(render,&disk);
i++;
}
i=0;
m=2.5;
c=stacksize(stack_b)+1;
draw_pole(rect_b);
if(skip==1 && (location==2)){
from=2;
drag_disk=gettopelement(stack_b);
if(drag_disk==-1)
goto x1;
c--;
draw_drag_disk();
}
while(i!=c){
t=tracestack(stack_b,i);
size=getwidthofdisk(t);
mid=size/2;
disk.w=size;
mid_x=rect_b.x+rect_b.w/2;
mid_y=rect_b.y+rect_b.h;
disk.x=mid_x-mid;
disk.y=mid_y-(offset*m);
m=m+1;
SDL_SetRenderDrawColor(render,dcolor[t-1].red,dcolor[t-1].green,dcolor[t-1].blue,255);
SDL_RenderFillRect(render,&disk);
i++;
}
x1:
i=0;
m=2.5;
c=stacksize(stack_c)+1;
draw_pole(rect_c);
if(skip==1 && (location==3)){
from=3;
drag_disk=gettopelement(stack_c);
if(drag_disk==-1)
return;
c--;
draw_drag_disk();
}
while(i!=c){
t=tracestack(stack_c,i);
size=getwidthofdisk(t);
mid=size/2;
disk.w=size;
mid_x=rect_c.x+rect_c.w/2;
mid_y=rect_c.y+rect_c.h;
disk.x=mid_x-mid;
disk.y=mid_y-(offset*m);
m=m+1;
SDL_SetRenderDrawColor(render,dcolor[t-1].red,dcolor[t-1].green,dcolor[t-1].blue,255);
SDL_RenderFillRect(render,&disk);
i++;
}
}

int game_over(){
int i;
for(i=0;i<no_of_disk;i++){
if(tracestack(stack_c,i)!=no_of_disk-i)
return 0;
}
return 1;
}
int main( int argc, char* args[]){
    int x,y,data;
init();
game_init();
while(quit!=1){
clear_screen();
draw_background1();
draw_background2();
draw_background3();
draw_tower();
while(SDL_PollEvent(&e)){
    switch(e.type){
case SDL_QUIT:
    quit=1;
case SDL_MOUSEMOTION:

break;
case SDL_MOUSEBUTTONDOWN:
    if(e.button.button==SDL_BUTTON_LEFT){
      location=getmouselocation();
        skip=1;
    }
break;
case SDL_MOUSEBUTTONUP:
     if(e.button.button==SDL_BUTTON_LEFT){
        skip=0;
if(from!=0 && getmouselocation()!=0)
move_disk(from,getmouselocation());
    }
    }
}
SDL_RenderPresent(render);
SDL_Delay(20);
if(game_over()){
no_of_disk++;
game_init();
if(no_of_disk==7)
return 0;
}
}
SDL_DestroyRenderer(render);
SDL_DestroyWindow( window );
SDL_Quit();
  return 0;
}
