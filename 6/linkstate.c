#include<stdio.h>
int i=0,j=0,k=0;
int
main ()
{
  // freopen("input.txt","r",stdin);
  int n, a[10][10], i, j, d[10], p[10], s[10];
  printf ("\n ENTER THE NO.OF NODES: ");
  scanf ("%d", &n);
  printf ("\n ENTER THE MATRIX ELEMENTS: ");
  for (i = 0; i < n; i++)
    {
      for (j = 0; j < n; j++)
	scanf ("%d", &a[i][j]);
    }
  printf ("\n");
  for (i = 0; i < n; i++)
    {
      printf ("The Link State Packets for Router %d\n", i + 1);
      printf ("NODES | DISTANCE\n");
      printf ("--------------\n");
      for (j = 0; j < n; j++)
	{
	  if (a[i][j] != 0 && a[i][j] != 9999)
	    {
	      printf ("%d     |     %d\n", j + 1, a[i][j]);
	    }
	}
      printf ("--------------\n");
    }
  for (i = 0; i < n; i++)
    {
      for (j = 0; j < n; j++)
	{
	  for (k = 0; k < n; k++)
	    {
	      if (a[i][j] > a[i][k] + a[k][j])
		a[i][j] = a[i][k] + a[k][j];
	    }
	}
    }
  printf ("\nShortest Distance for \n");
  for (i = 0; i < n; i++)
    {
      printf ("Router %d\n", i + 1);
      printf ("--------------\n");
      printf ("NODES | Shortest dist.\n");
      for (j = 0; j < n; j++)
	{
	  if (a[i][j]!=0) { printf ("%d     |     %d\n", j + 1, a[i][j]); }
	}
      printf ("--------------\n");
    }
  return 0;
}
