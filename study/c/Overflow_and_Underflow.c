#include <stdio.h>
#include <math.h>
int main()
{
    float toobig = 3.4E38 * 100.0f;
    printf("%e\n", toobig);
    printf("%f\n", asin(4));
    return 0;
}