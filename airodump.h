#ifndef AIRODUMP_H
#define AIRODUMP_H

#include <iostream>
#include <string>
#include <map>
#include <tins/tins.h>
#include <unistd.h>

using namespace std;
using namespace Tins;

typedef Dot11::address_type bssid;
typedef map<bssid,pair<int,string>> aplist;

struct airodump{

    airodump(string interface);
    void run();

protected:
    char* dev;
    aplist ap_list;
    void show_ap_list();
    bool handle(PDU& pdu);

};

#endif // AIRODUMP_H
