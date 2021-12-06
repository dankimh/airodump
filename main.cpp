#include <iostream>
#include <string>
#include <tins/tins.h>

#include "airodump.h"

using namespace std;
using namespace Tins;

void usage(){
    cout<<"syntax : airodump <interface>\n";
    cout<<"sample : airodump mon0\n";
    return;
}

int main(int argc, char* argv[]){

    if(argc!=2){
        usage();
        exit(1);
    }

    string dev=argv[1];

    airodump airodump(dev);
    airodump.run();

}
