#include <stdio.h>

int main(){
	short numArray[10];
	int i;
	char c;

	printf("Please enter 10 numbers:");

	for(i=0;i<10;i++){
		scanf("%hd",&(numArray[i]));
	}

	scanf("%c",&c);
	printf("Press any key to continue:");
	scanf("%c",&c);

	long cube[2][5][2];
	printf("Please enter 20 numbers:");
	long *ptr;
	ptr = &(cube[0][0][0]);

	for(i=0;i<20;i++){
		scanf("%ld",ptr);
		ptr++;
	}

	scanf("%c",&c);
	printf("Press any key to continue:");
	scanf("%c",&c);
	return 0;
}