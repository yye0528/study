/*
 * main.cpp
 *
 *  Created on: Aug 29, 2013
 *      Author: ryan
 */

#include <iostream>
#include <string>

using namespace std;

class Pstring: public string{
private:
	unsigned int SZ;
public:
	Pstring(string s):SZ(6){
		if (s.size()>SZ){
			string(s.substr(0,SZ-1));
		}else{
			string(s);
		}
	}

};

int main(){

	Pstring str("123456789");
	cout<<str<<endl;

	return 0;
}


