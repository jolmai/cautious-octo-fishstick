#include "Director.hpp"
#include "Torre.hpp"
#include "Cohete.hpp"
#include <stdio.h>

int paso;

void iniciaDirector();
void simulaSecuencia();
int estaSecuenciaCompletada();
void informaDirector();



void iniciaDirector()
{
	paso = 1;
	conectaTubosTorre();
	paso++;
}

void  simulaSecuencia()
{
	if(estaDepositoLlenoCohete(0) != 1 && paso == 2)
	{
		transfiereCombustibleTorre(0, 200);
		if(estaDepositoLlenoCohete(0) == 1)
		{
			paso++;
		}
	}
	else if(estaDepositoLlenoCohete(1) != 1 && paso == 3)
	{
		transfiereCombustibleTorre(1, 100);
		if(estaDepositoLlenoCohete(1) == 1)
		{
			paso++;
		}
	}
	else if(estaDepositoLlenoCohete(2) != 1 && paso == 4)
	{
		transfiereCombustibleTorre(2, 50);
		if(estaDepositoLlenoCohete(2) == 1)
		{
			paso++;
		}
		
	}
	else if(estaDepositoVacioCohete(0) != 1 && paso == 5)
	{
		consumeCombustibleCohete(0, 500);
		if(estaDepositoVacioCohete(0) == 1)
		{
			paso++;
		}
	}
	else if(estaDepositoVacioCohete(1) != 1 && paso == 6)
	{
		consumeCombustibleCohete(1, 300);
		if(estaDepositoVacioCohete(1) == 1)
		{
			paso++;
		}
	}
	else if(estaDepositoVacioCohete(2) != 1 && paso == 7)
	{
		consumeCombustibleCohete(2, 100);
		if(estaDepositoVacioCohete(2) == 1)
		{
			paso++;
		}
	}
	else
	{
		paso = 8;
	}
}

int estaSecuenciaCompletada()
{
	if(paso == 8)
	{
		printf("Secuencia completada\n");
		return 1;
	}
	return 0;
}

void informaDirector()
{
	printf("Paso: %d\n", paso);
}