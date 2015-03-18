#include <stdio.h>
#include <math.h>


int main()
{
    float aFloat   = -12.445f;
    int anInt      = (int) floor(aFloat + 0.5);
    int anotherInt = (int) (aFloat + 0.5);

    printf("Floor: %d and Cast: %d\n",anInt, anotherInt);  
    
    // You have to take care with negative numbers
    int yetAnotherInt = 0;

    if (aFloat >= 0)
        yetAnotherInt = (int) (aFloat + 0.5); 
    else 
        yetAnotherInt = (int) (aFloat - 0.5);
    //
    // Can also be done as
    // int yetAnotherInt = (aFloat >= 0) ? (int)(aFloat + 0.5) : (int)(aFloat - 0.5);

    printf("Floor: %d and Cast: %d\n",anInt, yetAnotherInt);
    
    return 0;
}