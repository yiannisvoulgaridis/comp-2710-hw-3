#include "store.h"

Store::Store()
{
  num_customers_ = 0;
  num_products_ = 0;
  num_transactions_ = 0;
}

// setter
void Store::num_customers(int customer_count)
{
  num_customers_ = customer_count;
}

// getter
int Store::num_customers()
{
    return num_customers_;
}

// setter
void Store::num_products(int product_count)
{
    num_products_ = product_count;
}

// getter
int Store::num_products()
{
    return num_products_;
}

// setter 
void Store::num_transactions(int transaction_count)
{
  num_transactions_ = transaction_count;
}

// getter
int Store::num_transactions()
{
    return num_transactions_;
}
// ========== adding customers =============
bool Store::add_customer(Person customer)
{
  if (num_customers_ >= 100) // checking if there's room at the inn
  {
    return false; // there's not -- we only have 100 spots in the array, if we're already at that number there's no more room
  }

  customers_[num_customers_] = customer;
  num_customers_ ++;

  return true;
} 

// ========== updating customers ============
bool Store::update_customer(int index, Person customer)
{
  if (index < 0 || index >= num_customers_)
  {
    return false;
  }

  customers_[index] = customer;
  return true;
}

// ========== get customer =================
Person Store::get_customer(int index)
{
  return customers_[index];
}

// ========== add product =================
bool Store::add_product(product item)
{
  if (num_products_>= 100)
  {
    return false;
  }

  products_[num_products_] = item;
  num_products_ ++;
  
  return true;
}

// ========== get product =================
product Store::get_product(int index)
{
  return products_[index];
}

// ========== add transaction ==============
bool Store::add_transaction(transaction ntransaction)
{
  if (num_transactions_>= 100)
  {
    return false;
  }

  transactions_[num_transactions_] = ntransaction;
  num_transactions_ ++;

  return true;
} 

// ========== get transaction ==============
transaction Store::get_transaction(int index)
{
    return transactions_[index];
}

// ========== find customer ================
int Store::find_customer(Person cust)
{
  for (int i = 0; i < num_customers_; i++)
  { // we're identifying the customer based on their credit card number, so we need to match
    // the unidentified cust's credit card number with an exisiting customer in the array.
    if (customers_[i].person_credit_card().cc_number == cust.person_credit_card().cc_number) 
    {
      // found appropiate index
      return i;
    }
 }
 return -1;
}

// ========== make purchase ================
bool Store::make_purchase(Person customer, product item, int amount)
{

  if (num_transactions_ >= 100 || amount <= 0) // 
  {
    return false;
  }

  int customer_index = find_customer(customer); // assign the customer
   
    if (customer_index == -1)
    {
      return false;
    }

  customer = customers_[customer_index]; // after validating the index, assign customer

  credit_card card = customer.person_credit_card();
  
  double purchase_amount = item.price * amount;
    
  if (card.make_purchase(purchase_amount) == false)
  {
    return false;
  }
    

    customer.person_credit_card(card);
    
    update_customer(customer_index, customer);
  
    transaction new_transaction;
    new_transaction.transaction_number = num_transactions_ + 1;
    new_transaction.customer = customer;
    new_transaction.purchased_item = item;
    new_transaction.quantity = amount;

    // if add transaction method doesn't work, then make purchase should return false
    if (add_transaction(new_transaction) == false)
    {
      return false;
    }

    // if not we want it to return true
    return true;
    
  }

// ======== prdouct info ==============
string Store::product_info()
{
  string info = "";
    for (int i = 0; i < num_products_; i++)
    {
      info += products_[i].product_info();
      info += "\n";
    }
  return info;
}

// ======= transaction info =============
string Store::transaction_info()
{
    string info = "";

    for (int i = 0; i < num_transactions_; i++)
      {
        info += transactions_[i].transaction_info();
        info += "\n";
      }
  return info;
}

// ========= customer info ===============
string Store::customer_info()
{
  string info = "";

  for (int i = 0; i < num_customers_; i++)
    {
      info += customers_[i].person_info(); // calling the person info method we've already defined
      info += "\n";
    }
  return info;
}

// ========== store info ==================
string Store::store_info()
{
  string info = "Store Information:\n";
  info += customer_info();
  info += transaction_info();
  info += product_info();

  return info;
}

// ========= purchase history ================
string Store::purchase_history(Person customer)
{
  string info = "";

  for (int i = 0; i < num_transactions_; i++)
    {
      if (transactions_[i].customer.person_credit_card().cc_number == 
        customer.person_credit_card().cc_number)
      {
        info += transactions_[i].transaction_info();
        info += "\n";
      }
    }

  return info;
}

