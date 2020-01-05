//##################################################################
// File Name: test.cpp
// File Effect: 
// Author: tttt
// mail: tttt@xiyoulinux.org
// Created Time: 2020年01月04日 星期六 22时31分20秒
//=============================================================
//!/usr/bin/python

#include <iostream>
#include <string>

using namespace std;

int main()
{
	string temp,temp1;
	cin >> temp >> temp1;
	cout << temp <<  endl;
	cout << temp1 <<  endl;
	temp.push_back('a');
	cout << temp << endl;

/*	cout << " temp size = " << temp.size() << endl;
	cout << " temp length = " << temp.length() << endl;
*/
	if(temp < temp1) cout << "小于" << endl;
	else cout << "不小于" << endl;

	return 0;
}
