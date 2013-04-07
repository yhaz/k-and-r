/* K&R page 13  Exercise 1-4 */
#include <stdio.h>

#define name(n) #n

/* Print Fahrenheit-Celsius table
 *  for fahr = 0, 20, ..., 300
 */
main() {
	float fahr, celsius;
	int lower, upper, step;
	const char *sep = "============";

        /* Print the title line */
	printf("%7.7s %6.6s\n", name(celsius), name(fahr));
	printf("%7.7s %6.6s\n", sep, sep);

	lower = 0;    /* Lower limit of temperature table */
	upper = 100;  /* Upper limit */
	step = 10;    /* Step size */

	celsius = lower;
	while (celsius <= upper) {
		fahr = (9.0/5.0)  * celsius +32.0;
		printf("%7.0f %6.1f\n", celsius, fahr);
		celsius = celsius + step;
	}
}
