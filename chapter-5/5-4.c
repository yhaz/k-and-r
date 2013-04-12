/* Exercise 5.4
 * Write a function that returns 1 if the string t occurs at 
 * the end of the string s, and zero otherwise.
 */

#include <stdio.h>
#include <string.h>

/* Returns 1 if string 't' occurs at the end of string 's',
   and zero otherwise  
*/
int strend(char *s, char *t)
{
	int sl = strlen(s), tl = strlen(t);

	if (sl < tl) 
		return 0;

	return (strcmp(s + sl - tl, t) == 0);
}

main()
{
	char *s1, *s2;

	s1 = "123456789";
	s2 = "789";
	printf("s1 = %s, s2= %s, strend %d\n", s1, s2, strend(s1,s2));

	s1 = "123456789";
	s2 = "123456789";
	printf("s1 = %s, s2= %s, strend %d\n", s1, s2, strend(s1,s2));

	s1 = "123456789";
	s2 = "123456789123456789";
	printf("s1 = %s, s2= %s, strend %d\n", s1, s2, strend(s1,s2));

	s1 = "123456789";
	s2 = "";
	printf("s1 = %s, s2= %s, strend %d\n", s1, s2, strend(s1,s2));

	s1 = "";
	s2 = "123456789";
	printf("s1 = %s, s2= %s, strend %d\n", s1, s2, strend(s1,s2));
}
