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

	myString temp,temp1;
	/*if(temp.empty()) cout << "空" << endl;
	else cout << "非空" << endl;*/
	//cout << "size = " << temp.length();
	cin >> temp >> temp1;
	//temp.push_back('s');
	cout << temp << endl << temp1 << endl;
	//int i = 1;
	//char ch = 's';
	//char temp2[10] = "ssss";
	//temp.insert(1,temp2);
	
	//myString temp2;
	//temp2 = temp.substr(1,3);
	temp.insert(1,'2',3);
	cout << temp << endl;
	
	//char s[10] = "1111";
	//int i = temp.compare(s);
	//cout << i << endl;
	//char* s = "a";
	//int i = temp.findbystr("a");

	//temp.replace('1','2');
	//char ch = '1';
	//char ch1 = '2';
	//temp.replace(3,'2');
	//cout << temp << endl;
	//cout << "i = " << i << endl;


	//temp.clear();
	//temp2.clear();
	/*int i = 1;
	temp.erase(1);
	cout << "temp = " << temp << endl << temp1 << endl;*/
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
