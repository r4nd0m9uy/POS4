/*
 * product.h
 *
 *  Created on: Jul 19, 2015
 *      Author: Kriz De Logi
 */

#ifndef PRODUCT_H_
#define PRODUCT_H_
#include <iostream>
#include <map>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <iomanip>
//#include <string>
using namespace std;

//product class
class product
{public:
	product();
	product(long barcode, long stock, string title, double price);

	//accessors:
	string getTitle();
	double getPrice();
	long getBarcode();
	long getStock();

	//setters:
	void setTitle(string newtitle);
	long checkout(long amount);
	void setPrice(double newprice);

	//printers:
	void printItem(ostream& stream = cout);
	void writeItem(ostream& stream = cout);



private:
	long barcode_;
	long stock_;
	string title_;
	double price_;

};

//load product list
map<long, product> loadProductsfromFile(const char* file);

//write to product list
void writeProductstoFile(map<long, product>& products, const char* filename);

#endif /* PRODUCT_H_ */
