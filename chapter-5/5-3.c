/* Exercise 5.3
 * Write a pointer version of the function strcat 
 */

#include <stdio.h>
#include <string.h>

/* Copies string 't' to the end of 's', s must be big enough */
int my_strcat(char *s, char *t)
{
	for (; *s!= '\0'; s++)
	;
	for (; (*s = *t) != '\0'; s++, t++)
	;
}

main()
{
	char buf[1024];

	strcpy(buf, "Hello ");
	my_strcat(buf, "World.");
	printf ("Test 1 = %s\n", buf);

	buf[0] = '\0';
	my_strcat(buf, "This is good.");
	printf ("Test 2 = %s\n", buf);

	strcpy(buf, "I am still alive.");
	my_strcat(buf, "");
	printf ("Test 3 = %s\n", buf);

	buf[0] = '\0';
	my_strcat(buf, "");
	printf ("Test 4 (last) = %s\n", buf);
}
