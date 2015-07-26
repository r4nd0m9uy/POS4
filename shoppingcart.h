/*
 * shoppingcart.h
 *
 *  Created on: Jul 25, 2015
 *      Author: kristina
 */

#ifndef SHOPPINGCART_H_
#define SHOPPINGCART_H_
#include <iostream>
#include <map>
#include "product.h"
#include <iomanip>
using namespace std;

class shoppingcart {
public:
	void addtocart(long& barcode, int& amount);
	void removefromcart(long& barcode);
	void printcart(map<long, product>& products, ostream& stream = cout);
	map<long, int> bitems;
};




#endif /* SHOPPINGCART_H_ */
