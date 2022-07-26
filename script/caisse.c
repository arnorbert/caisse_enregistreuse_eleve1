#include<stdio.h>
#include<stdlib.h>

double calcule_monnaie(double vap, double md)
{
	return md - vap;
}

int main()
{
	double valeur_a_payer = rand() % 10000 + 1;
	double montant_donner;
	double change;
	int count = 0;
	printf("Vous devez payer: Rs %lf",valeur_a_payer);
	printf("\nInserez le montant que vous donnerez: Rs ");
	scanf("%lf",&montant_donner);
	if (montant_donner<valeur_a_payer)
	{
		printf("\nVous avez inserer une somme inferieur a la somme demandee.");
		printf("\nVeuillez inserer une somme valide(plus grande ou egal a la somme demandee): Rs ");
		scanf("%lf",&montant_donner);
	}
	change = calcule_monnaie(valeur_a_payer,montant_donner);


	double tb[7]={2000, 1000, 500, 200, 100, 50, 25};
	double tp[7]={20, 10, 5, 1, 0.50, 0.20, 0.05};
	while((change != 0))
        {
		for(int i = 0; i<7; i++)
		{
                	while((change-tb[i])>=0)
                	{
                	        change = change - tb[i];
                	        count = count + 1;
                	}
                	if (count != 0)
                	{
                	        printf("\nRetournez %d billet(s) de Rs %lf\n",count, tb[i]);
                	        count = 0;
                	}
		}
		for(int i = 0; i<7; i++)
		{
                	while((change-tp[i])>=0)
                	{
                	        change = change - tp[i];
                	        count = count + 1;
                	}
                	if (count != 0)
                	{
                	        printf("\nRetournez %d piece(s) de Rs %lf\n",count, tp[i]);
                	        count = 0;
                	}
		}
        }
}
