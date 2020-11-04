#include"headers.h"
int ALL_CTY = 0, ALL_CNY = 0;

int main()
{
    Pvc provinces = (Pvc)malloc(MAX_PVC * sizeof(struct province));
	int i, j, k;
	for(i=0; i<MAX_PVC; i++){
		provinces[i].name = (char *)malloc(MAX_LINE/2 * sizeof(char));
        provinces[i].num = (char *)malloc(MAX_LINE/2 * sizeof(char));
        provinces[i].cnt = 0;
        provinces[i].next = NULL;
    }

	readProvincesCSV(provinces);
	readCitiesCSV(provinces);
	readCountiesCSV(provinces);

/*
    for(i=0; i<MAX_PVC; i++){
        printf("%s %s\n", provinces[i].name, provinces[i].num);
        for(j=0; j<provinces[i].cnt; j++){
        	printf("	%s %s\n", provinces[i].next[j].name, provinces[i].next[j].num);
        	for(k=0; k<provinces[i].next[j].cnt; k++){
        		printf("		%s %s\n", provinces[i].next[j].next[k].name, provinces[i].next[j].next[k].num);
			}
		}
		printf("-------------------------------------------------\n");
    }

    printf("%d %d\n",ALL_CTY,ALL_CNY);
*/

    Cty cities = (Cty)malloc(ALL_CTY * sizeof(struct city));
    Cny counties = (Cny)malloc(ALL_CNY * sizeof(struct county));
    int p = 0, q = 0;
    for(i=0; i<MAX_PVC; i++){
        for(j=0; j<provinces[i].cnt; j++){
        	cities[p].name = (char *)malloc(MAX_LINE/2 * sizeof(char));
        	cities[p].num = (char *)malloc(MAX_LINE/2 * sizeof(char));
        	strcpy(cities[p].name, provinces[i].next[j].name);
        	strcpy(cities[p].num, provinces[i].next[j].num);
        	cities[p].cnt = provinces[i].next[j].cnt;
        	cities[p].next = provinces[i].next[j].next;
        	cities[p++].prev = provinces[i].next[j].prev;
        	for(k=0; k<provinces[i].next[j].cnt; k++){
        		counties[q].name = (char *)malloc(MAX_LINE/2 * sizeof(char));
        		counties[q].num = (char *)malloc(MAX_LINE/2 * sizeof(char));
        		strcpy(counties[q].name, provinces[i].next[j].next[k].name);
        		strcpy(counties[q].num, provinces[i].next[j].next[k].num);
        		counties[q++].prev = provinces[i].next[j].next[k].prev;
			}
		}
    }

    sortCities(cities);
    sortCounties(counties);

    seekCity(cities);
    seekCounty(counties);

    system("pause");
    return 0;
}

