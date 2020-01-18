#ifndef MYSTRING_H_
#define MYSTRING_H_
#include <iostream>

using namespace std;

class myString
{
	public :
		myString()	{ my_str = new char('\0'); }
		myString(const char *str);
		myString(char* str);
		myString(myString &temp)
		{
			int len1 = 0;
			if(temp.str() != NULL) len1 = temp.length();
			my_str = new char[len1 + 1];
			for(int i = 0;i < len1;i++)
			{
				my_str[i] = temp[i];
			}
			//my_str = temp.str();
		}
		myString(size_t len,char ch)
		{
			my_str = new char[len + 1];
			for(int i = 0;i < len;i++) my_str[i] = ch;
		}

		char* str() const
		{
			return my_str;
		}
		const size_t length() const 
		{
			int length = 0;
			while(my_str[++length]);
			
			//len = length;
			return length;
		}
		size_t size()const
		{
			int size = 0;
			while(my_str[++size]);
			
			//len = length;
			return size;
		}
		void swap(myString& s2)
		{
			
			myString temp = s2; //此处调用的不是赋值运算符,而是myString(&myString) 构造函数
			s2 = *this;
			*this = temp;
			/*myString temp(s2);
			s2 = *this;
			*this = temp;*/
			return ;
		}
		bool empty()
		{
			if(my_str == NULL) return true;
			else return false;
		}
		void push_back(char ch);
		void append(char ch)
		{
			push_back(ch);
		}
		//将字符串中的 ch1 替换 ch
		myString& replace(const char& ch,const char& ch1);
		myString& replace(char& ch,char& ch1);
		//从下标i 开始，将字符替换成ch
		myString& replace(const int& i,const char& ch);
		myString& replace(int& i,char& ch);
		void clear();
		//如果参数为 int,char ,首先匹配int,char,类型函数,如果没有此重载类型的函数，则匹配const int,const char 类型函数
		void insert(const int i,const char ch);
		//void insert(int& i,char ch);
		int findbystr(char* s);
		int findbystr(const char* s);
		void getnext(char* s,int* next,int n);
		void getnext(const char* s,int* next,int n);
		int kmp(char* s,int* next);
		int kmp(const char* s,int* next);
		void erase(const int& i);
		void erase(int& i);
		int compare(myString& s1);
		int compare(const char* s);
		int compare(char* s);
		bool operator== (myString& s1);
		bool operator!= (myString& s1);
		bool operator< (myString& s1);
		bool operator> (myString& s1);
		myString operator+ (char& ch);
		myString operator+ (const char& ch);
		myString operator+ (myString& s1);
		void operator+= (myString& s1);
		void operator+= (char &ch);
		void operator+= (const char& ch);
		char& operator[] (int index) const ;
		myString& operator= (const myString& str);



		
		~myString()
		{
			delete[] my_str;
		}
		friend ostream& operator<< (ostream& os,myString &str);
		friend istream& operator>> (istream& is,myString &str);
	
	private:
		char *my_str;
		int len;

};



#endif
