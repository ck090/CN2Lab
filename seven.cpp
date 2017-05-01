#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;

int crc(char* ip, char*op, char* poly, int mode) 
{
	int i=0,j=0;
	strcpy(op,ip);
	if(mode) 
	{
		for (i=0;i<strlen(poly);i++)
			strcat(op,"0");
	}
	for(i=0;i<strlen(ip);i++) 
	{
		if(op[i]=='1')
		{
			for(j=0;j<strlen(poly);j++)
			{
				if(op[i+j]==poly[j])
					op[i+j]='0';
				else
					op[i+j]='1';
			}
		}
	}
	for(i=0;i<strlen(op);i++)
	{
		if(op[i]=='1')
			return 0;
	}
	return 1;
}

int main()
{
	char recv[20],ip[20],op[20];
	char poly[20] = "10001000000100001";
	cout << "Enter the message:\t";
	cin >> ip;
	crc(ip,op,poly,1);
	cout << "Transmitted msg is\t" << ip << op+strlen(ip) << endl;
	cout << "enter recv mssg:\t";
	cin >> recv;
	if(crc(recv,op,poly,0))
		cout << "NO error\n";
	else
		cout << "Error\n";
}