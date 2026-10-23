#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

#include "address.h"
#include "credit_card.h"
#include "person.h"
#include "product.h"
#include "store.h"
#include "transaction.h"

using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::getline;
using std::ws; // skips the whitespace

int main()
{

	//import from text files

	ifstream in_stream_cc("credit_card.txt");
	ifstream in_stream_prod("products.txt");
	ifstream in_stream_ppl("people.txt");
	
		
	if (!in_stream_cc.is_open())
{
    cout << "Error opening credit_card.txt" << endl;
    return 1;
}
	
	if (!in_stream_prod.is_open())
{
    cout << "Error opening products.txt" << endl;
    return 1;
}
	if (!in_stream_ppl.is_open())
{
    cout << "Error opening people.txt" << endl;
    return 1;
}

	int num_cards;
	in_stream_cc >> num_cards; 
	string name;
	credit_card card;

	// loop to read each credit card
	for (int i = 0; i < num_cards; i++)
{
    getline(in_stream_cc >> std::ws, name); // reads cardholder name skipping whitespace from prev extraction

    in_stream_cc >> card.cc_number; // reads card number
    in_stream_cc >> card.limit; // reads limit
    in_stream_cc >> card.current_balance; // reads balance
}

	int num_people;
	in_stream_ppl >> num_people;
	
	string name;
	string phone;
	string street;
	string address_line2;
	string city;
	string state;
	string zip;
	
	for (int i = 0; i < num_people; i++)
	{
	    getline(in_stream_ppl >> std::ws, name);
	    getline(in_stream_ppl, phone);
	    getline(in_stream_ppl, street);
	    getline(in_stream_ppl, address_line2);
	    getline(in_stream_ppl, city);
	    getline(in_stream_ppl, state);
	    getline(in_stream_ppl, zip);

		auto it = cards.find(name);

			if (it == cards.end())
			{
			    cout << "No credit card found for " << name << endl;
			    return 1;
			}
			
			credit_card card = it->second;

		address person_addr;
		person_addr.address_line1 = street;
		person_addr.address_line2 = address_line2;
		person_addr.city = city;
		person_addr.state = state;
		person_addr.zip = zip;

		auto it = cards.find(name);

			if (it == cards.end())
			{
			    cout << "No credit card found for " << name << endl;
			    return 1;
			}
	
	    // Create address object
	    // Find matching credit card
	    // Create Person object
	    // Add Person to Store
	}

	
	//add to store and other variables
	

	//print store info after you finish importing info
	//from text files and add them to your store
	cout << "Store info: " << endl << endl;
	cout << store1.store_info() << endl << endl;

	//make random number of random transactions

	//print store info at the end
	cout << "Store info: " << endl << endl;
	cout << store1.store_info() << endl << endl;
}
