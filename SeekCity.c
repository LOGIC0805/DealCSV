#include"headers.h"

void seekCity(Cty cities)
{
	char cityInput[MAX_LINE/2];
	printf("�������ѯ�ĳ�������");
	scanf("%s", cityInput);
	int bottom = 0, top = ALL_CTY - 1;
	int flag = 0;
	while(bottom <= top){
		int mid = bottom + (top - bottom) / 2;
		if(strcmp(cityInput, cities[mid].name) == 0){
			flag = 1;
			printf("���б��룺%s", cities[mid].num);
			printf("����ʡ��%s\n", cities[mid].prev->name);
		}
		if(strcmp(cityInput, cities[mid].name) > 0){
			bottom = mid + 1;
		}else{
			top = mid - 1;
		}
	}
	if(!flag){
		printf("����ĳ����������б��У���ѯʧ��\n");
	}
}
