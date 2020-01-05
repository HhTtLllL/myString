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
			my_str = new char[len];
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
		bool operator== (myString& s1);
		bool operator!= (myString& s1);
		bool operator< (myString& s1);
		bool operator> (myString& s1);
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
