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
#include <string.h>
myString::myString(const char* str)
{
	const char *temp = str;
	int len = 0;
	while(str[len]) len++;
	my_str = new char[len + 1];
	len = 0;
	while(str[len]) 
	{
		my_str[len] = str[len];
		len++;
	}
	my_str[len] = '\0';
}
myString::myString(char* str)
{
	char *temp = str;
	int len = 0;
	while(str[len]) len++;
	my_str = new char[len + 1];
	len = 0;
	while(str[len]) 
	{
		my_str[len] = str[len];
		len++;
	}
	my_str[len] = '\0';
}

void myString::clear()
{
	if((*this).empty()) return;
	else
	{
		delete[] my_str;
		my_str = new char('\0');
	}

}
void myString::erase(const int& i)
{
        int len1 = (*this).length();
        char* temp = new char[len1];
        int num = 0;
        for(int j = 0;j < len1;j++)
        {
                if(i == j) continue;
                else 
                {
                        temp[num++] = (*this)[j];
                }
        }
        temp[num] = '\0';
        delete[] my_str;
        my_str = temp;
    
        return ;

}

void myString::erase(int& i)
{
	int len1 = (*this).length();
	char* temp = new char[len1];
	int num = 0;
	for(int j = 0;j < len1;j++)
	{
		if(i == j) continue;
		else 
		{
			temp[num++] = (*this)[j];
		}
	}
	temp[num] = '\0';
	delete[] my_str;
	my_str = temp;
	
	return ;
}

int myString::findbystr(char* s)
{
	//先计算s的next数组
	int n = strlen(s);
	int next[n];
	getnext(s,next,n);
	//用kmp
	
	return kmp(s,next);
}
int myString::findbystr(const char* s)
{
	//先计算s的next数组
	int n = strlen(s);
	int next[n];
	getnext(s,next,n);
	//用kmp
	
	return kmp(s,next);
}
void myString::getnext(const char* s,int* next,int n)
{
	int i,j;
	j = next[0] = -1;
	i = 0;
	while(i < n)
	{
		while(-1 != j && s[i] != s[j]) j = next[j];
		next[++i] = ++j;
	}
}
void myString::getnext(char* s,int* next,int n)
{
	int i,j;
	j = next[0] = -1;
	i = 0;
	while(i < n)
	{
		while(-1 != j && s[i] != s[j]) j = next[j];
		next[++i] = ++j;
	}
}
int myString::kmp(const char* s,int* next)
{
	int i = 0;
	int j = 0;
	int num = 0;
	int len1 = strlen(s);
	int len2 = (*this).length();

	while(i < len2)
	{
		if(j == -1 || (*this)[i] == s[j])
		{
			i++;
			j++;
		}
		else j = next[j];

		if(j == len1) //如果找到一个串
		{
			//num++;
			//j = next[j];
			//cout << "i = " << i << endl;
			//cout << "j = " << j << endl;
			return i-1;
		}
	}

	return -1;
}
int myString::kmp(char* s,int* next)
{
	int i = 0;
	int j = 0;
	int num = 0;
	int len1 = strlen(s);
	int len2 = (*this).length();

	while(i < len2)
	{
		if(j == -1 || (*this)[i] == s[j])
		{
			i++;
			j++;
		}
		else j = next[j];

		if(j == len1) //如果找到一个串
		{
			//num++;
			//j = next[j];
			//cout << "i = " << i << endl;
			//cout << "j = " << j << endl;
			return i-1;
		}
	}

	return -1;
}
                              //加 const 会报错
myString& myString::operator=(const myString& str)
{
	//如果原来有值就删除
	if((*this).length() == 1) 
	{
		delete[] my_str;
		my_str = new char('\0');
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
myString myString::operator+ (const char& ch)
{
	myString temp;
	int len1 = (*this).length();
	temp.my_str = new char[len1 + 2];
	for(int i = 0;i < len1;i++)
	{
		*(temp.my_str + i) = (*this)[i];
	}
	*(temp.my_str + len1) = ch;
	*(temp.my_str + len1 + 1) = '\0';

	return temp;
}
myString myString::operator+ (char& ch)
{
	myString temp;
	int len1 = (*this).length();
	temp.my_str = new char[len1 + 2];
	for(int i = 0;i < len1;i++)
	{
		*(temp.my_str + i) = (*this)[i];
	}
	*(temp.my_str + len1) = ch;
	*(temp.my_str + len1 + 1) = '\0';

	return temp;
}
myString myString::operator+ (myString& s1)
{
	myString temp;
	int len1 = s1.length();
	int len2 = (*this).length();

	temp.my_str = new char[len1 + len2 + 1];
	for(int i = 0;i < len2;i++)
	{
		*(temp.my_str + i) = *(my_str + i);
	}
	for(int i = 0;i < len1;i++)
	{
		*(temp.my_str + i + len2) = s1[i];
	}

	*(temp.my_str + len1+len2) = '\0';
	
	//myString(temp);
	return temp;
}

void myString::push_back(char ch)
{
	int len1 = (*this).length();
	char *temp = my_str;
	my_str = new char[len1 + 2];
	for(int i = 0;i < len1;i++)
	{
		*(my_str + i) = *(temp + i);
	}
	*(my_str + len1) = ch;
	*(my_str + len1 + 1) = '\0';
	
	return ;
}
void myString::operator+= (myString& s1)
{
	myString temp;
	temp = (*this) + s1;
	(*this) = temp;
}
void myString::operator+= (char& ch)
{
	myString temp;
	temp = (*this) + ch;
	(*this) = temp;
}
void myString::operator+= (const char& ch)
{
	myString temp;
	temp = (*this) + ch;
	(*this) = temp;
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
