/*
 * shoppingcart.cpp
 *
 *  Created on: Jul 25, 2015
 *      Author: kristina
 */


#include "shoppingcart.h"

void shoppingcart::addtocart(long& barcode, int& amount) {
	bitems[barcode]=amount+bitems[barcode];
}
void shoppingcart::removefromcart(long& barcode) {
	bitems[barcode]=0;
}
void shoppingcart::printcart(map<long, product>& products, ostream& stream) {
	double total = 0;
	for (map<long, product>::iterator it = products.begin(); it != products.end(); ++it)
	{
		long barcode = it->second.getBarcode();

		if(bitems[barcode]>0) {
			long amount = products[barcode].checkout(bitems[barcode]);
			cout << amount << "\t" << products[barcode].getTitle() << "\t" << fixed << setprecision(2) << products[barcode].getPrice()*amount << endl;
			total+=products[barcode].getPrice()*bitems[barcode];

		}
	}
	cout << "Totaal:\t" << fixed << setprecision(2) << total << endl;
}

