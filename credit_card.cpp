//implementation code for credit_card struct here
#include "credit_card.h"

// assuming that current_balance is what will be charged and not "money owed"
bool credit_card::make_purchase(double purchase_amount){
    if (purchase_amount+current_balance>limit){
        return false;
    }

    else{
        current_balance += purchase_amount;
        return true;
    }
}