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
myString& myString::operator=(const myString& str)
{
	//如果原来有值就删除
	if(my_str != NULL) 
	{
		delete[] my_str;
		my_str = NULL;
	}

	int len = str.length();
	my_str = new char[len + 1];
	for(int i = 0;i < len;i++)
	{
		my_str[i] = str[i];
	}
	return *this;
}
char& myString::operator[](int index) const 
{
	return my_str[index];
}
bool myString::operator==(myString& s1)
{
	if((*this).length() != s1.length()) return false;
	else
	{
		for(int i = 0;i < s1.length();i++)	if(*(my_str + i) != s1[i]) return false;
	}
	
	return true;
}
bool myString::operator!= (myString& s1)
{
	if((*this).length() != s1.length()) return true;
	else
	{
		for(int i = 0;i < s1.length();i++) if(*(my_str + i) != s1[i]) return true;
	}

	return false;
}
bool myString::operator< (myString& s1)
{
	int len1 = 0;
	( ((*this).length()) < s1.length() ) ? len1 = ((*this).length()) : len1 = s1.length();

	for(int i = 0;i < len1;i++)
	{
		if(*(my_str + i) != s1[i])
		{
			if(*(my_str + i) > s1[i]) return false;
			else return true;
		}
	}
	//已有的字符串完全相等
	if((*this).length() == s1.length()) return false;
	else if((*this).length() < s1.length()) return true;
	else return false;

	return false;
}
bool myString::operator> (myString& s1)
{
	return (s1 < (*this));
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
