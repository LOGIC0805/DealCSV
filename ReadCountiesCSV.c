#include"headers.h"

void readCountiesCSV(Pvc provinces)
{
	FILE *countyCSV = NULL;
	int i, j;
	for(i=0; i<MAX_PVC; i++){
	    for(j=0; j<provinces[i].cnt; j++){
	    	Cny counties =  (Cny)malloc(MAX_CNY * sizeof(struct county));
	    	int k;
	    	for(k=0; k<MAX_CNY; k++){
	    		counties[k].name = (char *)malloc(MAX_LINE/2 * sizeof(char));
	    		counties[k].num = (char *)malloc(MAX_LINE/2 * sizeof(char));
	    		counties[k].prev = NULL;
			}
			char filename[100] = "datas/counties/";
			strcat(filename, provinces[i].name);
			strcat(filename, "/");
			strcat(filename, provinces[i].next[j].name);
			strcat(filename, ".csv");
			if((countyCSV = fopen(filename, "r")) != NULL){
				char tmp[MAX_LINE];
				k = -1;
		       	while(fgets(tmp, MAX_LINE, countyCSV)){
		        	if(k == -1){
		            	k++;
		            	continue;
		            }
		        	strcpy(counties[k].name, strtok(tmp, DEL));
		        	strcpy(counties[k].num, strtok(NULL, DEL));
		        	counties[k++].prev = &provinces[i].next[j];
		    	}
		    	provinces[i].next[j].cnt = k;
		    	ALL_CNY += provinces[i].next[j].cnt;
		    	for(; k<MAX_CTY; k++){
		    		free(counties[k].name);
		    		free(counties[k].num);
					counties[k].name = NULL;
		        	counties[k].num = NULL;
		    	}
		    	provinces[i].next[j].next = counties;
		    	fclose(countyCSV);
		    	countyCSV = NULL;
			}
		}
	}
}
