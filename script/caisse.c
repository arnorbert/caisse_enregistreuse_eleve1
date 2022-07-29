#include<stdio.h>
#include<stdlib.h>
#include<string.h>

double calcule_monnaie(double vap, double md)
{
	return md - vap;
}

void RCaisse(int* nb, int* np, double* tb, double* tp)
{
	int n=0;
	printf("===================================================================\n");
	for(int i = 0; i<7; i++)
        {
		printf("Combien de billets de Rs %lf voulez-vous inserer? ",tb[i]);
		scanf("%d",&n);
		nb[i]=nb[i]+n;
		n=0;
	}

	for(int i = 0; i<7; i++)
        {
                printf("Combien de pieces de Rs %lf voulez-vous inserer? ",tp[i]);
                scanf("%d",&n);
                nb[i]=np[i]+n;
		n=0;
        }
}

int main()
{
	double valeur_a_payer = rand() % 10000 + 1;
	double montant_donner;
	double change;
	int count = 0;
	char d[3];
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


	int nombre_billets[7]={9,8,10,9,14,8,11};
        int nombre_pieces[7]={20,25,13,17,7,9,8};

	printf("===================================================================");

	double tb[7]={2000, 1000, 500, 200, 100, 50, 25};
	double tp[7]={20, 10, 5, 1, 0.50, 0.20, 0.05};
	if(change != 0)
        {
		for(int i = 0; i<7; i++)
		{
                	while((change-tb[i])>=0)
                	{
                	        count = count + 1;
				if((nombre_billets[i] - count)<0)
				{
					count= count - 1;
					break;
				}
				change = change - tb[i];
                	}
                	if (count != 0)
                	{
                	        printf("\nRetournez %d billet(s) de Rs %lf\n",count, tb[i]);
				nombre_billets[i] = nombre_billets[i] - count;
                	        count = 0;
                	}
		}
		for(int i = 0; i<7; i++)
		{
                	while((change-tp[i])>=0)
                	{
                	        count = count + 1;
				if((nombre_pieces[i] - count)<0)
                                {
                                        count= count - 1;
                                        break;
                                }
				change = change - tp[i];
                	}
                	if (count != 0)
                	{
                	        printf("\nRetournez %d piece(s) de Rs %lf\n",count, tp[i]);
				nombre_pieces[i] = nombre_pieces[i] - count;
                	        count = 0;
                	}
		}
		printf("===================================================================");
		if(change>0)
		{
			printf("\nAlert: Il n'y a pas assez de billets/pieces pour cette transaction.\n");
			printf("Voulez-vous remplir la caisse et continuer(oui/non): ");
			scanf("%s",d);
			char z[] = {'o', 'u', 'i'};
			int compare = strcmp(d, z);
			if(compare)
			{
				RCaisse(nombre_billets,nombre_pieces,tb,tp);
			}
			printf("\n===================================================================\n");
		}
        }




	printf("\n");
	for(int i = 0; i<7; i++)
	{
		printf("Il reste %d billet(s) de Rs %lf.\n",nombre_billets[i],tb[i]);
	}
	for(int i = 0; i<7; i++)
        {
                printf("Il reste %d piece(s) de Rs %lf.\n",nombre_pieces[i],tp[i]);
        }
	printf("===================================================================\n");
}

