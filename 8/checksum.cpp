#include<stdio.h>
#include<iostream>
using namespace std;

unsigned short check()
{
int sum = 0;
unsigned short int fields[10];

for(int i=0;i<9;i++)
{
cout << "Fields:\t" << i+1 << endl;
scanf("%x",&fields[i]);
sum += (unsigned short)fields[i];
while(sum>>16)
 sum = (sum & 0xFFFF) + (sum >> 16);
}
sum = ~sum;
cout << "\nThe Checksum is :\t" << sum << endl;
return (unsigned short) sum;
}

int main()
{
unsigned short res1, res2;
cout << "Sender:" << endl;
res1 = check();
cout << "Reciever:" << endl;
res2 = check();
if(res1 == res2)
 cout << "NO ERROR\n";
else
 cout << "ERROR\n";
}
