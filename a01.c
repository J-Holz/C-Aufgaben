#include <stdio.h>

int main()
{
	int i;

	printf("   |");
	for(i=00; i<=15; i++){

		/*Headrow ausgeben*/
		printf("%02d ", i);

		/*Trennstrich zu Headrow*/
		if(i==15){
			printf("\n---+");
			for(i=0; i<=15; i++){
				printf("---");
			}
		}
	}

	/*Chars ausgeben*/
	for(i=0; i<=255; i++){
		printf("%2c ", i);

		/*Neue Zeile beginnen*/
		if(i%16==0 || i==0){
			printf("\n%3d|", i);
		}
	}

	return 0;
}