/* Exercise 5.5
 * Write versionf of the library functions strncpy, strncat and strncmp, 
 * which operate on at most the first n chaacters of their argument
 * strings. For example strncpy(s, t, n) copies at most n characters of t to s.
 */

#include <stdio.h>
#include <string.h>

int my_strncmp(const char *s, const char *t,  size_t n)
{
	if (n == 0) return 0;

	while ( (n>1) && (*s == *t) && (*s != '\0') ) {
		n--, s++, t++;
	}

	return (*s - *t);
}

char* my_strncat(char *s, const char *t, size_t n)
{
	if (n > 0) {
		char *p;

		for (p = s; *p !='\0'; p++) 
		;

		for  (; n && ((*p++ = *t++) != '\0'); n--)
		;

		while(n--) {
			*p++ = '\0';
		}	

		*p = '\0';
	}

	return s;
}

char* my_strncpy(char *s, const char *t, size_t n)
{
	char *p = s;
	while (n-- && (*p++ = *t++) ){
		if (n == 0) /* do not do more copies */
			break;
	}

	/* Fill extra 0s if n is larger than strlen(t) */
	while(n--) {
		*p++ = '\0';
	}

 	*p = '\0';

	return s;
}


main()
{
	char s1[200], *s2;

	strcpy(s1,"123456789");
	s2 = "789";
	printf("s1 = %s, s2= %s\n", s1, s2); 
	printf("str4cpy %s\n", my_strncpy(s1,s2, 4));

	strcpy(s1,"123456789");
	s2 = "123456789";
	printf("s1 = %s, s2= %s\n", s1, s2); 
	printf("str3cat %s\n",  my_strncat(s1,s2, 3));

	strcpy(s1,"123456789");
	s2 = "123";
	printf("s1 = %s, s2= %s\n", s1, s2); 
	printf("str3cmp %d\n",  my_strncmp(s1,s2, 3));
}
