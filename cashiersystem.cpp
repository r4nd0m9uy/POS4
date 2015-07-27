/*
 * cashiersystem.cpp
 *
 *  Created on: Jul 25, 2015
 *      Author: kristina
 */


#include "cashiersystem.h"

void listproducts(map<long, product>& products)
{
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
void add(map<long, product>& products)
{
	map<long, product>::iterator it;
	long barcode;
	cin >> barcode;
	it = products.find(barcode);
	if (it == products.end())
	{
		string naam;
		long stock;
		string price;
		cout << "Naam? ";
		getline(cin, naam, '\n');
		getline(cin, naam, '\n');
		if(naam=="") {cout << "Artikel niet toegevoegd. (naam)";}else{
			cout << "Prijs? ";
			cin >> price;
			if(price=="") {cout << "Artikel niet toegevoed. (prijs)";}else{
				cout << "Voorraad? ";
				cin >> stock;
				if(stock==0) {cout << "Artikel niet toegevoed. (stock)";}else{
					stringstream ss;
					double newprice;
					ss << price; ss >> newprice;
					product newproduct(barcode, stock, naam, newprice);
					products[barcode]=newproduct;
					cout << "Artikel " << barcode << " (" << naam << ") toegevoegd. " << endl;
		}}}
	}else{
		string title = products[barcode].getTitle();
		cout << "Artikel " << barcode << " (" << title << ") reeds bestaand!";

	}
}
void remove(map<long, product>& products)
{
	//long barcode;
	//cin >> barcode;
//HIER!
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
		switchmap["add"] = 4;
		switchmap["remove"] = 5;
		switchmap["stock"] = 6;
		switch(switchmap[command]) {
		case 1:
			listproducts(products);
			break;
		case 2:
			if(1) { //needed cause of string answer line...
				string answer;
				while (answer != "y" and answer != "n" and !saved) {
				cout << "Recent changes aren't saved yet. Do you still want to quit? [y/n].";
				cin >> answer;}
				if(answer=="y" or saved) {
					cout << "Cashiersystem Terminated." << endl << "Goodbye.";
					exit(0);
				}

			}
			break;
		case 3:
			writeProductstoFile(products, "prijslijst.txt");
			saved = true;
			break;
		case 4:
			add(products);
			break;
		case 5:
			remove(products);
			break;
		default:
			throw("Command not found <listen>");
		}
	}
}



