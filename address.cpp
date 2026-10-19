//implementation code for address struct here
#include "address.h"



string address::address_info(){
    if (!(address_line2.empty())){
        return address_line1 + "\n" + address_line2 + "\n" + city + ", " + state + " "+ zip;
    }
    else{
        return address_line1 + "\n" + city + ", " + state + " "+ zip;
    }
}
