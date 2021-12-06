#include "airodump.h"

using namespace std;
using namespace Tins;

void airodump::show_ap_list(){

    system("clear");

    cout<<"AP list\n";
    cout<<"BSSID\t\t\tbeacons\tSSID\n";

    int count=0;
    for(auto &data:ap_list){
        count++;
        cout<<data.first<<"\t"<<data.second.first<<"\t"<<data.second.second<<"(ssid length: "<<data.second.second.size()<<")\n";
    }
    return;
}

bool airodump::handle(PDU &pdu){
    const Dot11Beacon& beacon=pdu.rfind_pdu<Dot11Beacon>();

    if(!beacon.from_ds()&&!beacon.to_ds()){
        bssid addr=beacon.addr2();
        if(ap_list.count(addr)){
            ap_list[addr].first++;
        }
        else{
            string ssid=beacon.ssid();
            ap_list.insert({addr,{1,ssid}});
        }
        show_ap_list();
    }
    return true;
}

airodump::airodump(string interface){
    dev=(char*)interface.c_str();
}

void airodump::run()
{
    SnifferConfiguration config;
    config.set_filter("type mgt subtype beacon");
    config.set_rfmon(true);
    Sniffer sniffer(dev, config);
    sniffer.sniff_loop(make_sniffer_handler(this, &airodump::handle));
}
