/*
 * main.cpp
 *
 *  Created on: Jul 19, 2015
 *      Author: Kriz De Logi
 */

#include <iostream>

//personal includes
#include "main.h"

//namespaces
using namespace std;


int main () {
	map<long, product> products = loadProductsfromFile("prijslijst.txt");
	while (1) {
	try{
		listen(products);
	}
	catch(const char* msg) {
		cout << "Error given: '";
		cout << msg;
		cout << "'" << endl;
	}
	}


	return 0;
}
