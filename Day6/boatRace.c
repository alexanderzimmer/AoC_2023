#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {

    long time = 54817088;
    long distance = 446129210351007;
    long count = 0;
    
    for (int i=0; i<=time; i++) {
        long timeLeft = time;
        timeLeft = timeLeft - i;
        if ((timeLeft * i) > distance) {
            count++;
        }
    }
     
    printf("%ld\n", count);

    return 0;
}