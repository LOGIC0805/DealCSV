#include"headers.h"

void readProvincesCSV(Pvc provinces)
{
	FILE *provinceCSV = NULL;
	if((provinceCSV = fopen("datas/provinces/Ê¡¼¶±àÂë.csv", "r")) != NULL){
		char tmp[MAX_LINE];
		int i = -1;
       	while(fgets(tmp, MAX_LINE, provinceCSV)){
        	if(i == -1){
            	i++;
            	continue;
            }
            strcpy(provinces[i].name, strtok(tmp, DEL));
            strcpy(provinces[i++].num, strtok(NULL, DEL));
    	}
    	fclose(provinceCSV);
    	provinceCSV = NULL;
   }
}
