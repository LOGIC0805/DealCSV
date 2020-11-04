#include"headers.h"

int cmp_county(const void *a, const void *b)
{
	struct county ca = *((struct county *)a);
	struct county cb = *((struct county *)b);
	return strcmp(ca.name, cb.name);
}

void sortCounties(Cny counties)
{
	qsort(counties, ALL_CNY, sizeof(counties[0]), cmp_county);
}
