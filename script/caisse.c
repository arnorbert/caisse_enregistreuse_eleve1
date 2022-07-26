#include<stdio.h>
#include<stdlib.h>

int main()
{
	double valeur_a_payer = rand() % 10000 + 1;
	double montant_donner;
	printf("Vous devez payer: Rs %lf",valeur_a_payer);
	printf("\nInserez le montant que vous donnerez: Rs ");
	scanf("%lf",&montant_donner);
	if (montant_donner<valeur_a_payer)
	{
		printf("\nVous avez inserer une somme inferieur a la somme demandee.");
		printf("\nVeuillez inserer une somme valide(plus grande ou egal a la somme demandee): Rs ");
		scanf("%lf",&montant_donner);
	}
}
