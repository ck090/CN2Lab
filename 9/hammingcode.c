#include<stdio.h>
#include<stdlib.h>
main ()
{
  int i, a[4], b[4], r[4], s[3];
  printf ("\nEnter 4 bit data word:");
  for (i = 3; i >= 0; i--)
    scanf ("%d", &a[i]);
  r[0] = (a[2] + a[1] + a[0]) % 2;
  r[1] = (a[2] + a[1] + a[3]) % 2;
  r[2] = (a[0] + a[1] + a[3]) % 2;
  printf ("\n7 bit hamming codeword is:\n");
  for (i = 3; i >= 0; i--)
    printf ("%d\t", a[i]);
  for (i = 2; i >= 0; i--)
    printf ("%d\t", r[i]);
  printf ("\n");
  printf ("\nEnter 4 bit recieved word:");
  for (i = 3; i >= 0; i--)
    scanf ("%d", &b[i]);
  s[0] = (b[2] + b[1] + b[0] + r[0]) % 2;
  s[1] = (b[3] + b[2] + b[1] + r[1]) % 2;
  s[2] = (b[0] + b[1] + b[3] + r[2]) % 2;
  printf ("\nSyndrome is:\n");
  for (i = 2; i >= 0; i--)
    printf ("%d\t", s[i]);
  if ((s[2] == 0) && (s[1] == 0) && (s[0] == 0))
    printf ("\nRecieved data is error free\n");
  else
    {
      if ((s[2] == 1) && (s[1] == 0) && (s[0] == 1))
	{
	  if (b[0] == 1)
	    b[0] = 0;
	  else
	    b[0] = 1;
	  printf
	    ("\nRecieved word has error in 1st bit(b0) position from right\n");
	}
      if ((s[2] == 1) && (s[1] == 1) && (s[0] == 1))
	{
	  if (b[1] == 1)
	    b[1] = 0;
	  else
	    b[1] = 1;
	  printf
	    ("\nRecieved word has error in 2nd bit(b1) position from right\n");
	}
      if ((s[2] == 0) && (s[1] == 1) && (s[0] == 1))
	{
	  if (b[2] == 1)
	    b[2] = 0;
	  else
	    b[2] = 1;
	  printf
	    ("\nRecieved word has error in 3rd bit(b2) position from right\n");
	}
      if ((s[2] == 1) && (s[1] == 1) && (s[0] == 0))
	{
	  if (b[3] == 1)
	    b[3] = 0;
	  else
	    b[3] = 1;
	  printf
	    ("\nRecieved word has error in 4th bit(b3) position from right\n");
	}
      printf ("Corrected recieved word is:\n");
      for (i = 3; i >= 0; i--)
	printf ("%d\t", b[i]);
    }
}
