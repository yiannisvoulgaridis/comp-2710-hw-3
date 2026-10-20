#include "transaction.h"

std::string transaction::transaction_info()
{
  std::string info = "Transaction Number: " + std::to_string(transaction_number); // to_string to convert the transaction int to a string

  info +="\nCustomer:\n" + customer.person_info(); 

  info +="\nPurchased Item:\n" + purchased_item.product_info();
  info +="\nQuantity: " + std::to_string(quantity);

  return info;
}
