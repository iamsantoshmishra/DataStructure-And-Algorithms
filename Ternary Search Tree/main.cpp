/*
 * main.cpp
 *
 *  Created on: Sep 25, 2017
 *      Author: Santosh Kumar Mishra
 */


#include "TST.h"

#include <iostream>

using namespace std;


int main(){

	TST t1;

	t1.insert("cat");
	t1.insert("cats");
	t1.insert("up");
	t1.insert("bug");

	cout<<"Following is traversal of ternary search tree\n";
	t1.traverse();

	cout<<"\nFollowing are search results for cats, bu and cat respectively\n";
	t1.search("cats") ? cout<<"Found\n": cout<<"Not Found\n";
	t1.search("bu") ?    cout<<"Found\n": cout<<"Not Found\n";
	t1.search("cat") ?  cout<<"Found\n": cout<<"Not Found\n";

	cout<<"\nFollowing are search results for cats, bu and cat respectively after removing cats\n";
	t1.remove("cats");
	t1.search("cats") ? cout<<"Found\n": cout<<"Not Found\n";
	t1.search("bu") ?    cout<<"Found\n": cout<<"Not Found\n";
	t1.search("cat") ?  cout<<"Found\n": cout<<"Not Found\n";

	return 0;
}
