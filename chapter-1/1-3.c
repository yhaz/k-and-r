/* K&R page 13  Exercise 1-3 */
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
	printf("%4.4s %6.6s\n", name(fahr), name(celsius));
	printf("%4.4s %6.6s\n", sep, sep);

	lower = 0;    /* Lower limit of temperature table */
	upper = 300;  /* Upper limit */
	step  = 20;   /* Step size */

	fahr = lower;
	while (fahr <= upper) {
		celsius = (5.0/9.0)  * (fahr-32.0);
		printf("%3.0f %6.1f\n", fahr, celsius);
		fahr = fahr + step;
	}
}
