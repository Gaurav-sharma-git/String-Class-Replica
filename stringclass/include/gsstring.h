#ifndef __GSSTRING__H
#define __GSSTRING__H
#include<iostream>
using namespace std;
class gsString
{
private:
char *ptr;
int size;
public:
gsString();
gsString(const char *ptr);
gsString & operator=(const gsString &other);
gsString & operator=(const char *ptr);
virtual ~gsString();
int operator<(const gsString &other);
int operator<=(const gsString &other);
int operator>(const gsString &other);
int operator>=(const gsString &other);
int operator==(const gsString &other);
int operator!=(const gsString &other);
void operator+=(const gsString &other);
void append(const gsString &other);
int Size();
gsString operator+(const gsString &other);
friend istream & operator>>(istream &is,gsString &gsstring);
friend ostream & operator<<(ostream &out,gsString &gsstring);
};
#endif