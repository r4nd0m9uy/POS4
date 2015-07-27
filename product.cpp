/*
 * product.cpp
 *
 *  Created on: Jul 19, 2015
 *      Author: Kriz De Logi
 */


#include "product.h" //all other includes are in h file


product::product(): barcode_(0), stock_(0), title_(""), price_(0) {};
product::product(long barcode, long stock, string title, double price): barcode_(barcode),stock_(stock), title_(title), price_(price) {};
string product::getTitle()
{
	return title_;
}
void product::setTitle(string newTitle)
{
	title_ = newTitle;
}
long product::getBarcode()
{
	return barcode_;
}
double product::getPrice()
{
	return price_;
}
void product::setPrice(double newprice)
{
	price_=newprice;
}
long product::checkout(long amount)
{
	if(amount <= stock_) {
		stock_=stock_ - amount;
		return amount;
	}else{
		long co = stock_;
		stock_ = 0;
		return co;
	}
	return 0;
}
long product::getStock()
{
	return stock_;
}
void product::printItem(ostream& stream)
{
	stream << barcode_ << "\t" << stock_ << "\t" << fixed << setprecision(2) << price_ << "\t" << title_ << endl;
}
void product::writeItem(ostream& stream)
{
	stream << barcode_ << "\t" << stock_ << "\t" << title_ << "\t" << fixed << setprecision(2) << price_ << endl;
}

map<long, product> loadProductsfromFile(const char* file)
{
	map<long, product> products;
	string productline;
	ifstream productfile;
	static string pricelistfile;
	pricelistfile = file;
	productfile.open(file);
	if (productfile.is_open())
	{
		while (getline (productfile, productline))
		{
			//explode line in chunks
			long barcode, stock;
			string title;
			double price;
			stringstream ss(productline);
			ss >> barcode; //get barcode
			ss >> stock;
			getline (ss, title, '\t');//remove the tab
			getline (ss, title, '\t');
			ss >> price;


			//DEBUG
			//cout << barcode << ";" << stock << ";" << title << ";" << price*1.00 << ";" << endl;


			//associate product in productlist
			products[barcode] = product(barcode, stock, title, price);
		}
	}
	return products;
};
void writeProductstoFile(map<long, product>& products, const char* filename)
{
	ofstream writeout (filename);
	if (writeout.is_open())
	{
		for (std::map<long, product>::iterator it = products.begin(); it != products.end(); ++it)
			{
			  it->second.writeItem(writeout);
			}
		writeout.close();
	}
}
