#include "color.h"


/*
The function changes console color to purple.
input: none.
output: none.
runtime: o(1).
*/
void purple()
{
    printf("%s", PURPLE);
}


/*
The function changes console color to cyan.
input: none.
output: none.
runtime: o(1).
*/
void cyan()
{

    printf("%s", CYAN);
}


/*
The function changes console color to red.
input: none.
output: none.
runtime: o(1).
*/
void red()
{
    printf("%s", RED);
}


/*
The function changes console color to green.
input: none.
output: none.
runtime: o(1).
*/
void green()
{
    printf("\033[0;32m");
}
