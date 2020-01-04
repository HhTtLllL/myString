#ifndef MYSTRING_H_
#define MYSTRING_H_
#include <iostream>

using namespace std;

class myString
{
	public :
		myString()	{ my_str = new char('\0'); }
		myString(const char *str);
		myString(myString &temp)
		{
			my_str = temp.str();
		}
		myString(size_t len,char ch)
		{
			my_str = new char[len];
			for(int i = 0;i < len;i++) my_str[i] = ch;
		}
		char * str() const
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
		char& operator[] (int index) const ;
		myString& operator= (const myString& str);
		int swap(myString& s1,myString& s2);



		
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
