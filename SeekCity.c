#include"headers.h"

void seekCity(Cty cities)
{
	char cityInput[MAX_LINE/2];
	printf("请输入查询的城市名：");
	scanf("%s", cityInput);
	int bottom = 0, top = ALL_CTY - 1;
	int flag = 0;
	while(bottom <= top){
		int mid = bottom + (top - bottom) / 2;
		if(strcmp(cityInput, cities[mid].name) == 0){
			flag = 1;
			printf("城市编码：%s", cities[mid].num);
			printf("所在省：%s\n", cities[mid].prev->name);
		}
		if(strcmp(cityInput, cities[mid].name) > 0){
			bottom = mid + 1;
		}else{
			top = mid - 1;
		}
	}
	if(!flag){
		printf("输入的城市名不在列表中，查询失败\n");
	}
}
