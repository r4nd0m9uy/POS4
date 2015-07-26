/*
 * cashiersystem.h
 *
 *  Created on: Jul 25, 2015
 *      Author: kristina
 */

#ifndef CASHIERSYSTEM_H_
#define CASHIERSYSTEM_H_

#include <iostream>
#include <map>
#include <cstdlib>
#include <string>
#include "product.h"
#include "shoppingcart.h"
using namespace std;

void listen(map<long, product>& products);
void execute(string command);






#endif /* CASHIERSYSTEM_H_ */
