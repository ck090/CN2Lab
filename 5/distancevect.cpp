#include<iostream>
#include<stdlib.h>
using namespace std;
int dm[20][20], no, i, j, k, source, dest;
void dvr(int , int);

struct node
{
  int dist[20];
  int from[20];
} route[10];


int main ()
{
  cout << "Enter the number of nodes:\t";
  cin >> no;
  cout << "Enter the Source and Destination nodes:\t";
  cin >> source >> dest;
  cout << "\nEnter the distance matrix:\n";
  for (i = 0; i < no; i++)
    {
      for (j = 0; j < no; j++)
	{
	  cin >> dm[i][j];
	  dm[i][i] = 0;
	  route[i].dist[j] = dm[i][j];
	  route[i].from[j] = j;
	}
    }
  int flag;
  do
    {
      flag = 0;
      for (i = 0; i < no; i++)
	{
	  for (j = 0; j < no; j++)
	    {
	      for (k = 0; k < no; k++)
		{
		  if ((route[i].dist[j]) >
		      (route[i].dist[k] + route[k].dist[j]))
		    {
		      route[i].dist[j] =
			(route[i].dist[k] + route[k].dist[j]);
		      route[i].from[j] = k;
		      flag = 1;
		    }
		}
	    }
	}
    }
  while (flag);
  for (i = 0; i < no; i++)
    {
      cout << "Router Info for Router: " << i + 1 << endl;
      cout << "Dest\t NextHop\t Dist" << endl;
      for (j = 0; j < no; j++)
	cout << "  " << j + 1 << " \t    " << route[i].from[j] +
	  1 << " \t \t   " << route[i].dist[j] << endl;
    }
cout << "The shortest path from Source to Destination is:\n";
cout  << source;
dvr(source, dest);
return 0;
}

void
dvr (int source, int dest)
{
  int cost = 0, ns = 0, ns1 = 0;
  for (i = 0; i < no; i++)
    {
      if (source - 1 == i)
	{
	  for (j = 0; j < no; j++)
	    {
	      if (j + 1 == dest)
		{
		  ns = route[i].from[j] + 1;
		  cout << "-->" << ns;
                  if (ns == dest)
		  { cout<<endl;exit(0);}
		  dvr (ns , dest);
		}
	    }
	} 
    }
}
