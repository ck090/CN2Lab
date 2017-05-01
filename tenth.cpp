#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
#define bktsize 512

void bktinput(int a, int b)
{
	if(a>bktsize)
		cout << "Bucket Overflow";
	else
	{
		sleep(1);
		while(a>b)
		{
			cout << b << " bytes Output\n";
			a -= b;
			sleep(1);
		}
		if (a>0)
			cout << "Last " << a << " bytes Output\n";
		cout << "Bucket output successful\n";
	}
}

int main()
{
	int pcktsize=0,op=0;
	cout << "Enter Output rate:\t";
	cin >> op;
	for(int i=0;i<4;i++)
	{
		sleep(1);
		pcktsize = rand()%100;
		cout << "\nPacket no: " << i+1 << " Packet size: " << pcktsize << endl;
		bktinput(pcktsize,op);
	}
	return 0;
}