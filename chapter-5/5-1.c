/* Exercise 5.1 
 * As written, getint treats a + or - not followed by a digit 
   as a vaild representation of zero. Fix it to push such a 
   character back on the input.
 */

#include <ctype.h>
#include <stdio.h>

int getch()
{
	return getc(stdin);
}

int  ungetch(int c)
{
	return ungetc(c, stdin);
}

/* getint:  get next integer from input into *pn
   Return values:
     EOF  end of file
     0:    not a number
     >0:   valid numbr
*/
int getint(int *pn)
{
	int c, sign;
	int signc = -1;
	
	while (isspace ( c = getch())) /* skip white space */
		;
	
	if (!isdigit(c) && c != EOF && c != '+' && c != '-') { 
		goto not_a_number;   /* it's not a number */
	}
	sign =  ( c == '-') ? -1 : 1;
	if ( c == '+' || c == '-' ) {
		signc = c;
		c = getch();
		if (!isdigit(c)) {
			goto not_a_number;   /* it's not a number */
		}
	}
	for (*pn = 0; isdigit(c); c = getch())
		*pn = 10 * *pn + (c - '0');
	*pn *= sign;
	if ( c != EOF)
		 ungetch(c);
	return c;

not_a_number:
	if (signc)
		ungetch(signc);
	ungetch(c);
	return 0;
}

main()
{
	int x, rv;

	rv = getint(&x);
  
	if ( rv == EOF || rv == 0)
		printf("Invalid input \n");
	else
		printf("Input = %d, rv = %x\n", x, rv);
}
