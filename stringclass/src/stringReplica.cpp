#include<gsstring.h>
#include<stringutils.h>
#include<iostream>
using namespace std;
using namespace stringutils;
gsString::gsString()
{
this->ptr=NULL;
this->size=0;
}
gsString::gsString(const char *ptr)
{
this->ptr=NULL;
if(ptr==NULL)return;
this->size=stringLength(ptr);
this->ptr=new char(this->size+1);
stringCopy(this->ptr,ptr);
}
gsString & gsString::operator=(const gsString &other)
{
if(this->ptr)delete [] this->ptr;
this->ptr=NULL;
this->size=0;
if(other.ptr==NULL)return *this;
this->size=stringLength(other.ptr);
this->ptr=new char(this->size+1);
stringCopy(this->ptr,other.ptr);
return *this;
}
gsString & gsString::operator=(const char *ptr)
{
if(this->ptr)delete [] this->ptr;
this->ptr=NULL;
this->size=0;
if(ptr==NULL)return *this;
this->size=stringLength(ptr);
this->ptr=new char(this->size+1);
stringCopy(this->ptr,ptr);
return *this;
}
gsString::~gsString()
{
if(this->ptr)delete [] this->ptr;
}

int gsString::operator<(const gsString &other)
{
if(this->ptr==NULL && other.ptr==NULL)return 0;
if(this->ptr==NULL)return 1;
if(other.ptr==NULL)return 0;
return stringCompare(this->ptr,other.ptr)<0;
}
int gsString::operator<=(const gsString &other)
{
if(this->ptr==NULL && other.ptr==NULL)return 1;
if(this->ptr==NULL)return 1;
if(other.ptr==NULL)return 0;
return stringCompare(this->ptr,other.ptr)<=0;
}
int gsString::operator>(const gsString &other)
{
if(this->ptr==NULL && other.ptr==NULL)return 0;
if(this->ptr==NULL)return 0;
if(other.ptr==NULL)return 1;
return stringCompare(this->ptr,other.ptr)>0;
}
int gsString::operator>=(const gsString &other)
{
if(this->ptr==NULL && other.ptr==NULL)return 1;
if(this->ptr==NULL)return 0;
if(other.ptr==NULL)return 1;
return stringCompare(this->ptr,other.ptr)>=0;
}

int gsString::operator==(const gsString &other)
{
if(this->ptr==NULL && other.ptr==NULL)return 1;
if(this->ptr==NULL)return 0;
if(other.ptr==NULL)return 0;
return stringCompare(this->ptr,other.ptr)==0;
}
int gsString::operator!=(const gsString &other)
{
if(this->ptr==NULL && other.ptr==NULL)return 0;
if(this->ptr==NULL)return 1;
if(other.ptr==NULL)return 1;
return stringCompare(this->ptr,other.ptr)!=0;
}
void gsString::operator+=(const gsString &other)
{
if(this->ptr==NULL && other.ptr==NULL)return;
if(other.ptr==NULL)return;
if(this->ptr==NULL)
{
(*this)=other;
return;
}
char *tmp=new char[this->size+other.size+1];
stringCopy(tmp,this->ptr);
stringConcatenate(tmp,other.ptr);
delete [] this->ptr;
this->ptr=tmp;
this->size=this->size+other.size;
}
void gsString::append(const gsString &other)
{
*this+=other;
}

gsString gsString::operator+(const gsString &other)
{
gsString k;
if(this->ptr==NULL && other.ptr==NULL)return k;
if(this->ptr==NULL)k=other;
else if(other.ptr==NULL)k=(*this);
else
{
k=(*this);
k+=other;
}
return k;
}
int gsString::Size()
{
return this->size;
}
istream & operator>>(istream &is,gsString &gsstring)
{
char *c=new char[1000];
is>>c;
gsstring=c;
delete[] c;
return is;
}

ostream & operator<<(ostream & out,gsString &gsstring)
{
if(gsstring.ptr==NULL)return out;
out<<gsstring.ptr;
return out;
}