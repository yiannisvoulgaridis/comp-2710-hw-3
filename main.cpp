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
using std::string;
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

	int num_cards; //stores number at beginning of credit_card.txt
	in_stream_cc >> num_cards; //reads in that number from the file

	const int MAX_SIZE = 100; // max array capacity

	string card_names[MAX_SIZE]; //names on cc
	credit_card cards[MAX_SIZE]; //cc structs
	
	Person people[MAX_SIZE]; // person objects
	product products[MAX_SIZE]; //product structs
	
	Store store1; //creates the store object

	// loop to read each credit card
	for (int i = 0; i < num_cards; i++)
{
    getline(in_stream_cc >> ws, card_names[i]); // reads cardholder name skipping whitespace from prev extraction

    in_stream_cc >> cards[i].cc_number; // reads card number
    in_stream_cc >> cards[i].limit; // reads limit
    in_stream_cc >> cards[i].current_balance; // reads balance
}

	// read in people from people.txt
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

		address person_addr; // filling in the 5 members of address
		person_addr.address_line1 = street;
		person_addr.address_line2 = address_line2;
		person_addr.city = city;
		person_addr.state = state;
		person_addr.zip = zip;

		for (int j = 0; j < num_cards; j++)
		{
		    if (name == card_names[j]) // person found!
		    {
		        people[i] = Person(name, phone, person_addr, cards[j]); // info pulled

				store1.add_customer(people[i]); // person added to store
				
		        break;
		    }
		}
	}

		// read products from products.txt
		int num_products; // holds num of prods
		in_stream_prod >> num_products; 
		
		for (int i = 0; i < num_products; i++)
		{
		    getline(in_stream_prod >> ws, products[i].name);
		    getline(in_stream_prod, products[i].description);
		    in_stream_prod >> products[i].price;
		
		    store1.add_product(products[i]); //adds the completed product to the store's internal products array
		}

	//print store info after you finish importing info
	//from text files and add them to your store
	cout << "Store info: " << endl << endl;
	cout << store1.store_info() << endl << endl;

	//make random number of random transactions

	//print store info at the end
	cout << "Store info: " << endl << endl;
	cout << store1.store_info() << endl << endl;
}
