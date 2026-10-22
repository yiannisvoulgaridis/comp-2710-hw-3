//code for product struct here
#include "product.h"
#include <sstream>
#include <iomanip>

std::string product::product_info()
{
    //create formatted string for price
    std::ostringstream product_nbr;
    product_nbr<<std::fixed<<std::setprecision(2);
    product_nbr<< price;

    //retrun statement with combination of strings and format
    return name + "\n" + description + "\n" + product_nbr.str();
}