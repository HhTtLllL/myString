//##################################################################
// File Name: test_myString.cpp
// File Effect: 
// Author: tttt
// mail: tttt@xiyoulinux.org
// Created Time: 2020年01月04日 星期六 20时01分06秒
//=============================================================
//!/usr/bin/python

#include <iostream>
#include "myString.h"
#include <cstring>
#include <string>

using namespace std;
void test(myString &str)
{
	
}
int main()
{
	myString temp;
	cin >> temp;
	char ch = temp[2];
	ch = 'r';
	cout << temp;


	/*cout << temp << " "  << temp.length()<< endl;
	cout << temp.size() << endl;
	int len = temp.length();
	cout << len << endl;
	len = 5;*/
	//string b;
	//cout << strlen(b) << endl;
/*	myString a(5,'a');
	myString b(a);
	cout << a << endl;
	printf("%s\n",a.str());
	//myString s("asdasds");
	printf("%s\n",b.str());
*/
	return 0;
}
