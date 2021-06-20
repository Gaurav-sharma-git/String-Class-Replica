#include<gsstring.h>
#include<string.h>
#include<iostream>
using namespace std;
int main()
{
gsString g;
gsString k;
g="good";
cin>>k;
cout<<k.Size()<<endl;
k+=g;
cout<<k<<endl;

return 0;
}