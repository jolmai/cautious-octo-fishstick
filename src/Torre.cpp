#include "Torre.hpp"
#include "Cohete.hpp"
#include <stdio.h>

int tubosConectados;

void iniciaTorre();
void conectaTubosTorre();
void desconectaTubosTorre();
void transfiereCombustibleTorre(int e, float c);
void informaTorre();


void iniciaTorre()
{
	tubosConectados = 0;
}
void conectaTubosTorre()
{
	printf("Conectando tubos...\n");
	tubosConectados = 1;
	
}
void desconectaTubosTorre()
{
	printf("Desconectando tubos...\n");
	tubosConectados = 0;
	
}

void transfiereCombustibleTorre(int e, float c)
{
	if(tubosConectados != 1)
	{
		conectaTubosTorre();
		recibeCombustibleCohete(e, c);
	}
	else
	{
		recibeCombustibleCohete(e, c);
	}
}

void informaTorre()
{
	if(tubosConectados == 1)
	{
		printf("Los tubos estan conectados\n");
	}
	else
	{
		printf("Los tubos estan desconectados\n");
	}
	
	
}