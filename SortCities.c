#include"headers.h"

int cmp_city(const void *a, const void *b)
{
	struct city ca = *((struct city *)a);
	struct city cb = *((struct city *)b);
	return strcmp(ca.name, cb.name);
}

void sortCities(Cty cities)
{
	qsort(cities, ALL_CTY, sizeof(cities[0]), cmp_city);
}
