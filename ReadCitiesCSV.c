#include"headers.h"

void readCitiesCSV(Pvc provinces)
{
	FILE *cityCSV = NULL;
	int i;
	for(i=0; i<MAX_PVC; i++){
		Cty cities = (Cty)malloc(MAX_CTY * sizeof(struct city));
		int j;
		for(j=0; j<MAX_CTY; j++){
			cities[j].name = (char *)malloc(MAX_LINE/2 * sizeof(char));
	        cities[j].num = (char *)malloc(MAX_LINE/2 * sizeof(char));
	        cities[j].cnt = 0;
	        cities[j].next = NULL;
	        cities[j].prev = NULL;
	    }
	    char filename[100] = "datas/cities/";
		strcat(filename, provinces[i].name);
		strcat(filename, ".csv");
		if((cityCSV = fopen(filename, "r")) != NULL){
			char tmp[MAX_LINE];
			j = -1;
	       	while(fgets(tmp, MAX_LINE, cityCSV)){
	        	if(j == -1){
	            	j++;
	            	continue;
	            }
	        	strcpy(cities[j].name, strtok(tmp, DEL));
	        	strcpy(cities[j].num, strtok(NULL, DEL));
	        	cities[j++].prev = &provinces[i];
	    	}
	    	provinces[i].cnt = j;
	    	ALL_CTY += provinces[i].cnt;
	    	for(; j<MAX_CTY; j++){
	    		free(cities[j].name);
	    		free(cities[j].num);
				cities[j].name = NULL;
	        	cities[j].num = NULL;
	    	}
	    	provinces[i].next = cities;
	    	fclose(cityCSV);
	    	cityCSV = NULL;
		}
	}
}

