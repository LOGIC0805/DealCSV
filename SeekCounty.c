#include"headers.h"

void seekCounty(Cny counties)
{
	char countyInput[MAX_LINE/2];
	printf("�������ѯ����������");
	scanf("%s", countyInput);
	int bottom = 0, top = ALL_CNY - 1;
	int flag = 0;
	while(bottom <= top){
		int mid = bottom + (top - bottom) / 2;
		if(strcmp(countyInput, counties[mid].name) == 0){
			flag = 1;
			printf("���б��룺%s", counties[mid].num);
			printf("���ڳ��У�%s\n", counties[mid].prev->name);
			printf("����ʡ��%s\n", counties[mid].prev->prev->name);
		}
		if(strcmp(countyInput, counties[mid].name) > 0){
			bottom = mid + 1;
		}else{
			top = mid - 1;
		}
	}
	if(!flag){
		printf("����������������б��У���ѯʧ��\n");
	}
}

