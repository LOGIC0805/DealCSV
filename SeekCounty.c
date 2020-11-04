#include"headers.h"

void seekCounty(Cny counties)
{
	char countyInput[MAX_LINE/2];
	printf("请输入查询的县市名：");
	scanf("%s", countyInput);
	int bottom = 0, top = ALL_CNY - 1;
	int flag = 0;
	while(bottom <= top){
		int mid = bottom + (top - bottom) / 2;
		if(strcmp(countyInput, counties[mid].name) == 0){
			flag = 1;
			printf("县市编码：%s", counties[mid].num);
			printf("所在城市：%s\n", counties[mid].prev->name);
			printf("所在省：%s\n", counties[mid].prev->prev->name);
		}
		if(strcmp(countyInput, counties[mid].name) > 0){
			bottom = mid + 1;
		}else{
			top = mid - 1;
		}
	}
	if(!flag){
		printf("输入的县市名不在列表中，查询失败\n");
	}
}

