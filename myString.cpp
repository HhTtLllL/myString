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
//将字符串中的 ch1 替换 ch
myString& myString::replace(const char& ch,const char& ch1)
{
	int len1 = (*this).length();
	for(int i = 0;i < len1;i++)
	{
		if((*this)[i] == ch)
		{
			(*this)[i] = ch1;
		}
	}

	return (*this);
}

myString& myString::replace(char& ch,char& ch1)
{
	int len1 = (*this).length();
	for(int i = 0;i < len1;i++)
	{
		if((*this)[i] == ch)
		{
			(*this)[i] = ch1;
		}
	}

	return (*this);
}

myString& myString::replace(const int& i,const char& ch)
{
	int len1 = (*this).length();
	for(int j = i;j < len1;j++)
	{
		(*this)[j] = ch;
	}

	return (*this);
}

myString& myString::replace(int& i,char& ch)
{
	int len1 = (*this).length();
	for(int j = i;j < len1;j++)
	{
		(*this)[j] = ch;
	}

	return (*this);
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
//返回第一个差值
int myString::compare(myString& s2)
{
	int len1 = (*this).length();
	int len2 = s2.length();
	
	if(len1 != len2)
	{
		int min1 = min(len1,len2);
		for(int i = 0;i < min1;i++)
		{
			if((*this)[i] != s2[i])
			{
				return ((*this)[i] - s2[i]);
			}
		}

		if(len1 > len2)
		{
			return (*this)[min1];
		}
		else return s2[min1];
	}
	else
	{
		for(int i = 0;i < len1;i++)
		{
			if((*this)[i] != s2[i])
			{
				return ((*this)[i] - s2[i]);
			}
		}

		return 0;

	}
	
}
int myString::compare(const char* s)
{
	int len1 = (*this).length();
	int len2 = strlen(s);
	
	if(len1 != len2)
	{
		int min1 = min(len1,len2);
		for(int i = 0;i < min1;i++)
		{
			if((*this)[i] != s[i])
			{
				return ((*this)[i] - s[i]);
			}
		}

		if(len1 > len2)
		{
			return (*this)[min1];
		}
		else return s[min1];
	}
	else
	{
		for(int i = 0;i < len1;i++)
		{
			if((*this)[i] != s[i])
			{
				return ((*this)[i] - s[i]);
			}
		}

		return 0;

	}

}
int myString::compare(char* s)
{
	int len1 = (*this).length();
	int len2 = strlen(s);
	
	if(len1 != len2)
	{
		int min1 = min(len1,len2);
		for(int i = 0;i < min1;i++)
		{
			if((*this)[i] != s[i])
			{
				return ((*this)[i] - s[i]);
			}
		}

		if(len1 > len2)
		{
			return (*this)[min1];
		}
		else return s[min1];
	}
	else
	{
		for(int i = 0;i < len1;i++)
		{
			if((*this)[i] != s[i])
			{
				return ((*this)[i] - s[i]);
			}
		}

		return 0;

	}

}

void myString::insert(const int i,const char ch)
{
	int len1 = (*this).length();

	char* temp = new char[len1 + 1]; //
	for(int j = 0;j < i;j++)
	{
		temp[j] = (*this)[j];
	}
	temp[i] = ch;
	for(int j = i+1;j < len1+1;j++)
	{
		temp[j] = (*this)[j-1];
	}

	delete[] my_str;
	my_str = temp;

	return ;
}
//从第i个字符开始,加 n 个ch字符
void myString::insert(const int i,const char ch,const int n)
{
	int len1 = (*this).length();

	char* temp = new char[len1 + 1 + n]; //
	for(int j = 0;j < i;j++)
	{
		temp[j] = (*this)[j];
	}
	
	for(int j = i;j < i + n;j++)
	{
		temp[j] = ch;
	}

	for(int j = i+n;j < len1 + 1 + n;j++)
	{
		temp[j] = (*this)[j-n];
	}

	delete[] my_str;
	my_str = temp;

	return ;
}

void myString::insert(const int i,const char* s)
{
	int len1 = (*this).length();
	int len2 =strlen(s);
	char* temp = new char[len1 + len2 + 1];
	for(int j = 0;j < i;j++)	temp[j] = (*this)[j];
	int k  =0;
	for(int j = i;j < i + len2;j++)
	{
		temp[j] = s[k++];
	}
	k = i;
	for(int j = i + len2;j < len1 + len2;j++)
	{
		temp[j]	= (*this)[k++];
	}

	delete[] my_str;
	my_str = temp;

	return ;
}

myString myString::substr(int i,int j)
{
	myString temp;
	char* s = new char[j-i];
	int k = 0;
	for(i;i < j;i++)
	{
		//不可以执行 ???
		/*cout << (*this)[i] << endl;
		temp.push_back((*this)[i]);
		temp.push_back('s');
		cout << "temp = " << temp << endl;*/
		s[k++] = (*this)[i];
	}
	
	delete[] temp.my_str;
	temp.my_str = s;
	return temp;
}

void myString::copy(char* s,int n,const int pos)
{
	//s = new char[n+1];

	int i = pos;
	int k = 0;
	while(n--)
	{
		s[k++] = (*this)[i++];
		cout << k << endl;
	}
	s[k] = '\0';

	return ;
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

void myString::push_back(const char ch)
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
	//cout << " 111 \n";
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
