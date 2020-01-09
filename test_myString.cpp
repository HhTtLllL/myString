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

int main()
{

	myString temp,temp1,temp2;
	/*if(temp.empty()) cout << "空" << endl;
	else cout << "非空" << endl;*/
	//cout << "size = " << temp.length();
	cin >> temp >> temp1;
	cout << temp << endl << temp1 << endl;
	
	//temp.clear();
	//temp2.clear();
	int i = 1;
	temp.erase(1);
	cout << "temp = " << temp << endl << temp1 << endl;
	//cout << temp + temp1 << endl;;
	//temp.append('c');
	//char ch = 'w';
	//char ch = 'w';
	//temp1 += 'a';
	//temp2 = temp + 'w';
	//cout << temp1 << endl;
	/*	if(temp > temp1) cout << "大于\n";
	else cout << "不大于\n";*/
	//temp.swap(temp1);
	//cout << "temp = " << temp << endl << "temp1 = "<< temp1 << endl;
	

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
