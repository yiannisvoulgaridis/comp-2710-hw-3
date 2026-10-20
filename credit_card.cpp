//implementation code for credit_card struct here
#include "credit_card.h"
#include <sstream>
#include <iomanip>


bool credit_card::make_purchase(double purchase_amount){
    if (purchase_amount+current_balance>limit){
        return false;
    }

    else{
        current_balance += purchase_amount;
        return true;
    }
}

bool credit_card::make_payment(double payment_amount)
{
    // this is to catch "fake" payments
    if (payment_amount <= 0){
        return false;
    }
    // guard against overpay
    else if (current_balance - payment_amount < 0){
        return false;
    }
    current_balance -= payment_amount;
    return true;
}
std::string credit_card::credit_card_info()
{
    // create string stream to get all output formatted properly
    std::ostringstream get_credit_card;
    get_credit_card<<std::fixed<<std::setprecision(2);
    get_credit_card<< cc_number << "\n" << limit << "\n" << current_balance;
    // use.str() to make stream back into string for return to accept
    return get_credit_card.str();
}