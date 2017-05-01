#include <stdio.h>
#include <iostream>
using namespace std;

unsigned short check()
{
	int sum=0;
	unsigned short fields[10];

	for(int i=0;i<9;i++)
	{
		cout << "Field:\t" << i+1 << endl;
		scanf("%x",&fields[i]);
		sum += (unsigned short) fields[i];
		while(sum>>16)
			sum = (sum & 0xFFFF) + (sum>>16);
	}
	sum = ~sum;
	cout << "Check sum is:\t" << sum;
	return (unsigned short)sum;
}

int main()
{
	unsigned short res1,res2;
	cout << "\nSender:\n";
	res1 = check();
	cout << "\nReciever:\n";
	res2 = check();
	if(res1==res2)
		cout << "\nNoe error";
	else
		cout << "\nError";
	return 0;
}