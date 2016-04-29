#include <stdlib.h>
#include <stdio.h>
#include <time.h>


/********************* Structures **********************/

struct invoice{
	float invoice_amount;
};


struct taxes{
	float ir, pis, cofins, csll;
};


/*   Withhold Tax Rates   */
struct withhold_taxes{

	float ir_withhold_tax_rate,
	cofins_withhold_tax_rate,
	csll_withhold_tax_rate,
	pis_withhold_tax_rate,
	assumed_profit,
	govern_amount;
};


/* Method Prototypes */
struct taxes rates(void);
struct withhold_taxes calculate(struct invoice i,struct taxes t);

