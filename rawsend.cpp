/*
 Usage: ./rawsend <code> <length>
 */

#include "RCSwitch.h"
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    
    /*
     output PIN is hardcoded for testing purposes
     see https://projects.drogon.net/raspberry-pi/wiringpi/pins/
     for pin mapping of the raspberry pi GPIO connector
     */
    int PIN = 0;
    unsigned long code = atol(argv[1]);
    unsigned int length = atoi(argv[2]);
    
    if (wiringPiSetup () == -1) return 1;
    printf("sending code[%u] length[%u]\n", code, length);
    RCSwitch mySwitch = RCSwitch();
    mySwitch.enableTransmit(PIN);
    mySwitch.send(code, length);
    return 0;
}
