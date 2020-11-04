#ifndef _HEADERS_
#define _HEADERS_
#endif

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define DEL ","
#define MAX_LINE 100
#define MAX_PVC 5
#define MAX_CTY 20
#define MAX_CNY 30
extern int ALL_CTY, ALL_CNY;

typedef struct province *Pvc;
typedef struct city *Cty;
typedef struct county *Cny;
struct province{
	int cnt;
    char *name;
    char *num;
    Cty next;
};
struct city{
	int cnt;
	char *name;
    char *num;
    Pvc prev;
    Cny next;
};
struct county{
	char *name;
    char *num;
    Cty prev;
};

void readProvincesCSV(Pvc provinces);
void readCitiesCSV(Pvc provinces);
void readCountiesCSV(Pvc provinces);
int cmp_city(const void *a, const void *b);
void sortCities(Cty cities);
int cmp_county(const void *a, const void *b);
void sortCounties(Cny counties);
void seekCity(Cty cities);
void seekCounty(Cny counties);
