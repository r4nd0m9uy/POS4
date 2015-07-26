/*
 * cashiersystem.cpp
 *
 *  Created on: Jul 25, 2015
 *      Author: kristina
 */


#include "cashiersystem.h"

void listproducts(map<long, product>& products) {
	//cout << "products listed." << endl;
	for (std::map<long, product>::iterator it = products.begin(); it != products.end(); ++it)
	{
	  it->second.printItem();
	}
}

void registerp(string command, map<long, product>& products)
{
	shoppingcart sc;
	while(command != ".") {
	long barcode;
	int amount;
	stringstream ss(command);
	ss >> barcode;
	cin >> amount;
	sc.addtocart(barcode, amount);
	cin >> command;
	}
	sc.printcart(products, cout);
}



void listen(map<long, product>& products)
{
	static bool saved = true;
	string command;
	cin >> command;
	string::const_iterator it = command.begin();
	while (it != command.end() && isdigit(*it)) ++it;
	if (!command.empty() && it == command.end()) {
		saved = false;
		registerp(command, products);
	}else{
		map<string, int> switchmap;
		switchmap["list"] = 1;
		switchmap["quit"] = 2;
		switchmap["save"] = 3;
		switch(switchmap[command]) {
		case 1:
			listproducts(products);
			break;
		case 2:
			if(saved) {
			cout << "Cashiersystem Terminated." << endl << "Goodbye.";
			exit(0);}
			else{
				string answer;
				while (answer != "y" and answer != "n") {
				cout << "Recent changes aren't saved yet. Do you still want to quit? [y/n].";
				cin >> answer;}
				if(answer=="y") {
					cout << "Cashiersystem Terminated." << endl << "Goodbye.";
					exit(0);
				}

			}
			break;
		default:
			throw("Command not found <listen>");
		}
	}
}



