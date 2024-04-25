#include <stdio.h>
#include <limits.h>
#include <float.h>

int main()
{
    printf("char类型的位数:%d\n", CHAR_BIT);
    printf("char类型的最大值:%d\n", CHAR_MAX);
    printf("char类型的最小值:%d\n", CHAR_MIN);
    printf("int类型的最大值:%d\n", INT_MAX);
    printf("int类型的最小值:%d\n", INT_MIN);
    printf("long类型的最大值:%ld\n", LONG_MAX);
    printf("long类型的最小值:%ld\n", LONG_MIN);
    printf("signed char类型的最大值:%d\n", SCHAR_MAX);
    printf("signed char类型的最小值:%d\n", SCHAR_MIN);
    printf("short类型的最大值:%d\n", SHRT_MAX);
    printf("short类型的最小值:%d\n", SHRT_MIN);
    printf("unsigned char类型的最大值:%d\n", UCHAR_MAX);
    printf("unsigned int类型的最大值:%u\n", UINT_MAX);
    printf("unsigned long类型的最大值:%lu\n", ULONG_MAX);
    printf("unsigned short类型的最大值:%d\n", USHRT_MAX);
    printf("long long类型的最大值:%lld\n", LLONG_MAX);
    printf("long long类型的最小值:%lld\n", LLONG_MIN);
    printf("unsigned long long类型的最大值:%llu\n", ULLONG_MAX);
    printf("float类型的最大值:%f\n", FLT_MAX);
    printf("float类型的最小值:%f\n", FLT_MIN);
    printf("double类型的最大值:%f\n", DBL_MAX);
    printf("double类型的最小值:%f\n", DBL_MIN);
    printf("long double类型的最大值:%Le\n", LDBL_MAX);
    printf("long double类型的最小值:%Lf\n", LDBL_MIN);
    printf("float类型的有效位数:%d\n", FLT_DIG);
    printf("double类型的有效位数:%d\n", DBL_DIG);
    printf("long double类型的有效位数:%d\n", LDBL_DIG);
    printf("float类型的精度值:%e\n", FLT_EPSILON);
    printf("double类型的精度值:%d\n", DBL_EPSILON);
    printf("long double类型的精度值:%d\n", LDBL_EPSILON);
    printf("float类型的尾数位数:%d\n", FLT_MANT_DIG);

    return 0;
}