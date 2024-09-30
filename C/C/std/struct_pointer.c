#include <stdio.h>
#include <conio.h>

struct time_struct
{
    int hours;
    int minutes;
    int seconds;
};

void update(struct time_struct *t);
void display(struct time_struct *t);
void delay(void);


int main(){

    struct time_struct time;

    time.hours = 0;
    time.minutes = 0;
    time.seconds = 0;
    
    for(; !kbhit();){
        //* Passes only the address of the variable time, acting as a pointer
        update(&time);
        display(&time);
    }

    return 0;
}

void update(struct time_struct *t){
    
    t->seconds++;

    if (t->seconds == 60)
    {
        t->seconds = 0;
        t->minutes++;
    }

    
    if (t->minutes == 60)
    {
        t->minutes = 0;
        t->hours++;
    }

    
    if (t->hours == 24)
    {
        t->hours = 0;
    }

    delay();
    
}
void display(struct time_struct *t){
    printf("%d:",t->hours);
    printf("%d:",t->minutes);
    printf("%d\n",t->seconds);
}


void delay(void){
    for (long int i = 1; i < 30000000; i++);
}