#include <stdio.h>

int main()
{
	int i = 0;
	int b = 0;
	int z;
	int n;

	/* Zähler einlesen */
	printf("Zähler eingeben:");
	scanf("%i", &z);
	/*Nenner einlesen*/
	printf("Nenner eingeben:");
	scanf("%i", &n);

	/*Sonderfälle*/
	if(n==0){
		printf("Invalide Zahleneingabe");
		return 0;
	}

	/*Kürzen*/
	while(b == 0){
		i++;
		
		if(z%(n/i)==0 && n%(n/i)==0){

			int k = n/i;
			printf("Zähler gekürzt: %i", z/k);
			printf("\nNenner gekürzt: %i", n/k);
			printf("\nEs wurde gekürzt mit: %i", k);
			b = 1;
		}
	};
	return 0;
}