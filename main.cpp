#include <iostream>
#include <string>

#include <csignal>
#include <cstring>

#include <termios.h>

#include "serial.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::getline;

char *serialPortName;
unsigned serialBaudRate;

void output(){
    string input;
    while(cin){
        getline(cin, input); 
        serialWrite(input.c_str(), input.size());
        //cout << input << endl;
    }
}

void setup(){
    cout << "using port " << serialPortName << " at " << serialBaudRate << " baud" << endl;

    //options are: B115200, B230400, B9600, B19200, B38400, B57600, B1200, B2400, B4800
    switch(serialBaudRate){
        case 115200:
            serialBaudRate = B115200;
            break;
        case 9600:
            serialBaudRate = B9600;
            break;
    }

    openSerial(serialPortName, serialBaudRate);
}

int main(int argc, char **argv){
    if(argc < 3){
        cout << "missing arguments" << endl;
        cout << "suggested usage: ./serial /dev/ttyUSB0 115200" << endl;
        exit(1);
    }

    serialPortName = argv[1];
    serialBaudRate = strtol(argv[2], NULL, 10);

    setup();
    output();

    closeSerial();
}
