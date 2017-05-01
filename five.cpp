#include <stdio.h>
#include <iostream>
using namespace std;
int dm[10][10],n=0,source=0, dest=0,i=0,j=0,k=0;
void dvr(int, int);

struct node{
	int from[20],dist[20];
}route[10];

int main()
{
	cout << "Enter the number of nodes\t";
	cin >> n;
	cout << "enter s and dest\t";
	cin >> source >> dest;
	cout << "Enter the matrix\n";
	for (i = 0; i < n; i++)
    {
      for (j = 0; j < n; j++)
	{
	  cin >> dm[i][j];
	  dm[i][i] = 0;
	  route[i].dist[j] = dm[i][j];
	  route[i].from[j] = j;
	}
    }
	int flag;
	do {
		flag = 0;
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++)
			{
				for (k = 0; k < n; k++)
				{
					if ((route[i].dist[j])>(route[i].dist[k]+route[k].dist[j]))
					{
						route[i].dist[j]=route[i].dist[k]+route[k].dist[j];
						route[i].from[j]=k;
						flag=1;
					}
				}
			
			}
		}
	}while(flag);
	for (i = 0; i < n; i++)
	{
		cout << "Router info for router "<<i+1<<"\n";
		cout << "Dest\tNexthop\tDist\n";
		for (j = 0; j < n; j++)
		{
			cout << " " << j+1 << "\t "<< route[i].from[j]+1 << "\t\t "<< route[i].dist[j] << endl;
		}
	}
	cout << "The shortest path from source to dest\n";
	cout << source;
	dvr(source,dest);
	return 0;
}

void dvr(int source, int dest) 
{
	int ns = 0;
	for (int i = 0; i < n; i++)
	{
		if (source-1 == i)
		{
			for (int j = 0; j < n; j++)
			{
				if(j+1 == dest)
				{
					ns = route[i].from[j] + 1;
					cout << "-->" << ns;
					if(ns == dest)
						{ cout<<endl; exit(0);}
					dvr(ns,dest);
				}
			}
		}
	}
}
