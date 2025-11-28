// File: AppMain.cpp
// Applies List Class: Ordered linked list

#include <iostream>
#include <string>
#include "ProductList.h"
#include"stdio.h"
using namespace std;
using std::string;

int main()
{
	ProductList Product;
	
	Product.insertFirst(1,"Product_");
	Product.insertAfter(2,"Product_");
	Product.insertAfter(3,"Product_");
	Product.insertAfter(4,"Product_");
	Product.insertAfter(5,"Product_");
	
	Product.traverse();
	
	cout<<" List Size: "<<Product.listSize()<<endl;
	
	cout<< "-----------------------------"<<endl;
	
	Product.deleteEnd(); cout<< endl;
	
	Product.traverse();
	
	cout<<" List Size: "<<Product.listSize() <<endl;
	
	cout<< "-----------------------------"<<endl;
	
	cout<< " Make All List Empty " << endl;
	
	Product.makeListEmpty(); 
	
	cout<<" List Size: "<<Product.listSize();
	
	
	return 0;
}

