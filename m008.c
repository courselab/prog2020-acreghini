/* m008.c - Lastname-Names.

   This program reads the name of a person from the standard input
   in the form 'First-name middle-names last-name' and outputs the 
   name in the form 'LAST-NAME, first-name middle-names'.
   The name should be entered using only ASCII characters (26 letter 
   of latim alphabet, no diacrictics).


   E.g.

      command line    : m008
      standard input  : John Little Bill Doe 
      expected output : DOE, John Little Bill

   Directions:

      Please, edit function lasname();
      do no not change function main().

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 256

/* Converts the string 's' from first-middle-last name 
   form into LAST-first-middle form. */

void lastname (char *s)
{
  char n[MAX];
  int x = 0;
  int y = 0;
  
 strcpy (n, s);

  for (int i = 0; i < strlen(n); i++)
  {
    if (n[i] == ' ')
    {
      x = i;
    }
  }

  for (int i = x + 1; i < strlen(n) - 1; i++)
  {
    if (n[i] >= 97) //começo das letras minúsculas
    {
      s[y++] = n[i] - 32;
    }
    else
    {
      s[y++] = n[i];
    }
  }

  
  s[y++] = ',';
  s[y++] = ' ';

  for (int i = 0; i <= x; i++)
  {
    s[y++] = n[i];
  }
  s[y] = '\0';
}



/* Do not edit this function. */

int main (int argc, char **argv)
{
  int n;
  char name[MAX];

  fgets (name, MAX-1, stdin);
  
  lastname (name);

  printf ("%s\n", name);
  
  return 0;
}
