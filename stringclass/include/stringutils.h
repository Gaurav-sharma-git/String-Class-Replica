#ifndef __STRINGUTILS__H
#define __STRINGUTILS__H
namespace stringutils
{
int stringLength(const char *ptr);
void stringCopy(char *t,const char *s);
int stringCompare(const char *t,const char *s);
void stringConcatenate(char *t,char *s);
}
#endif