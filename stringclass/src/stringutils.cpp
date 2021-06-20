#include<stringutils.h>
using namespace stringutils;
#include<iostream>
using namespace std;
int stringutils::stringLength(const  char *ptr)
{
//if(ptr==NULL)return 0;
int i=0;
while(*ptr!='\0')
{
i++;
ptr++;
}
return i;
}
void stringutils::stringCopy(char *t,const char *s)
{
for(;*s!='\0';s++)
{
*t=*s;
t++;
}
*t='\0';
}
int stringutils::stringCompare(const char *t,const char *s)
{
char e,f;
while(*t!='\0' && *s!='\0')
{
e=*t;
f=*s;
if(e>=97 && e<=122)e=e-32;
if(f>=97 && f<=122)f=f-32;
if(e!=f)break;
t++;
s++;
}
if(*t=='\0' || *s=='\0')return *t-*s;
return e-f;
}

void stringutils::stringConcatenate(char *t,char *s)
{
while(*t!='\0')
{
t++;
}
while(*s!='\0')
{
*t=*s;
t++;
s++;
}
*t='\0';
}
