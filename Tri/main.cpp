/*
 * main.cpp
 *
 *  Created on: Sep 21, 2017
 *      Author: Santosh Kumar Mishra
 */

#include "Tri.h"
#include <iostream>

using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
	Tri t1;

	t1.insert("santosh");
	t1.insert("kumar");
	t1.insert("mishra");

	cout<<"\n Searching \"mishra\" in tri : "<<t1.search("mishra")<<endl;
	cout<<"\n Searching \"kumar\" in tri : "<<t1.search("kumar")<<endl;
	cout<<"\n Removing \"kumar\" from tri\n";
	t1.remove("kumar");
	
	cout<<"\n Seaching \"kumar\" in tri : "<<t1.search("kumar")<<endl;
	
	return 0;
}
