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
    std::stringstream ss;

    ss << std::fixed << std::setprecision(2);
    ss << "Credit card number: " << cc_number << "\n";
    ss << "Credit Card Limit: $" << limit << "\n";
    ss << "Current Balance: $" << current_balance;

    return ss.str();
}
