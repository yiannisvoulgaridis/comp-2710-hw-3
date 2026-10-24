#include "person.h" 

Person::Person() // default constructor -- empty info
{
    name_ = "";
    phone_ = "";
    person_credit_card_.cc_number = 0; // go to this person's credit card and set its number, limit, and current balance
    person_credit_card_.limit = 0;
    person_credit_card_.current_balance = 0;
} 

Person::Person(string name, string phone, address person_address, credit_card person_credit_card)
{
    name_ = name;
    phone_ = phone;
    person_address_ = person_address;
    person_credit_card_ = person_credit_card;
    
} 
// receives a name, number, address object, credit card object as params and assigns each to the 
// corresponding private data member of the new person object

// setter
void Person::name(string name)
{
    name_ = name;
}

// getter
string Person::name()
{
    return name_;
}

// setter
void Person::phone(string phone)
{
    phone_ = phone;
}

// getter
string Person::phone()
{
    return phone_;
}

// setter  
void Person::person_address(address person_address)
{
    person_address_ = person_address;
}

// getter
address Person::person_address()
{
    return person_address_;
}

// setter 
void Person::person_credit_card(credit_card person_credit_card)
{
    person_credit_card_ = person_credit_card;
}

// getter 
credit_card Person::person_credit_card()
{
    return person_credit_card_;
}

string Person::person_info()
{
    string info = "Name: " + name_;
    info += "\nPhone: " + phone_;
    info += "\nAddress:\n" + person_address_.address_info();
    info += "\nCredit Card:\n" + person_credit_card_.credit_card_info();

    return info;
}
