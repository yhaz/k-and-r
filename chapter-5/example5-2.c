/* As it appears on page 97. Section 5.2 */

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

/* getint:  get next integer from input into *pn */
int getint(int *pn)
{
	int c, sign;
	
	while (isspace ( c = getch())) /* skip white space */
		;
	
	if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
		ungetch(c);   /* it's not a number */
		return 0;
	}
	sign =  ( c == '-') ? -1 : 1;
	if ( c == '+' || c == '-' )
		c = getch();
	for (*pn = 0; isdigit(c); c = getch()) 
		*pn = 10 * *pn + (c - '0');
	*pn *= sign;
	if ( c != EOF)
		 ungetch(c);
	return c;
}
	

main()
{
	int x, next_char;

	next_char = getint(&x);
  
	printf("Input = %d stopped char = %x\n", x, next_char);
}
