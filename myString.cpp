//##################################################################
// File Name: myString.cpp
// File Effect: 
// Author: tttt
// mail: tttt@xiyoulinux.org
// Created Time: 2020年01月04日 星期六 20时00分40秒
//=============================================================
//!/usr/bin/python

#include "myString.h"
#include <iostream>

myString::myString(const char *str)
{
	const char *temp = str;
	int len = 0;
	while(str[len]) len++;
	my_str = new char[len];
	len = 0;
	while(str[len]) 
	{
		my_str[len] = str[len];
		len++;
	}
}
			      //加 const 会报错
myString& myString::operator=(myString& str)
{
	if(my_str != NULL) 
	{
		delete[] my_str;
		my_str = NULL;
	}

	int len = str.length();
	my_str = new char[len];
	for(int i = 0;i < len;i++)
	{
		my_str[i] = str[i];
	}
	return *this;
}
char& myString::operator[](int index)
{
	return my_str[index];
}
ostream& operator<< (ostream& os,myString &str)
{
	os << str.str();
	return os;
}
istream& operator>> (istream& is,myString &str)
{
	is >> str.my_str;
	return is;
}
