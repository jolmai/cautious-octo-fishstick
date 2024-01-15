#include "Cohete.hpp"
#include "Torre.hpp"
#include <stdio.h>
#include <stdlib.h>

float depositos[3];
float capacidades[3] = {150000.00,50000.00,10000.00};
int separaciones[3];
float masa[3] = {5000, 2000, 500};
float velocidad;
float masaCohete;

void iniciaCohete();
void recibeCombustibleCohete(int e, float c);
int estaDepositoLlenoCohete(int e);
void consumeCombustibleCohete(int e, float c);
int estaDepositoVacioCohete(int e);
void separaEtapaCohete(int e);
void informaCohete();

void iniciaCohete()
{
	depositos[0] = 0.00; 
	depositos[1] = 0.00; 
	depositos[2] = 0.00; 
	separaciones[0] = 0;
	separaciones[1] = 0;
	separaciones[2] = 0;
	velocidad = 0.00;
	masaCohete = masa[0] + masa[1] + masa[2];
}

void recibeCombustibleCohete(int e, float c)
{
	int prob;
	int cal;
	prob = rand() % 10 + 1;
	cal = c * prob / 100;
	c = c - cal;
	
	if(estaDepositoLlenoCohete(e) != 1)
	{
		depositos[e] = depositos[e] + c;
		masaCohete = masaCohete + c;

	}
	else
	{
		depositos[e] = capacidades[e];
	}
}

int estaDepositoLlenoCohete(int e)
{
	if(e == 0)
	{
		if(depositos[e] >= capacidades[e])
		{
			//printf("La etapa 1 esta llena.\n");
			depositos[e] = capacidades[e];
			return 1;
		}
		
	}
	else if(e == 1)
	{
		if(depositos[e] >= capacidades[e])
		{
			//printf("La etapa 2 esta llena.\n");
			depositos[e] = capacidades[e];
			return 1;
		}
		
	}
	else if(e == 2)
	{
		if(depositos[e] >= capacidades[e])
		{
			//printf("La etapa 3 esta llena.\n");
			desconectaTubosTorre();
			depositos[e] = capacidades[e];
			return 1;
		}
		
	}
	return 0;
}

void consumeCombustibleCohete(int e, float c)
{
	float empuje;
	float incVel;
	int prob;
	int cal;
	
	
	if(e == 0)
	{
		prob = rand() % 10 + 1;
		cal = c * prob / 100;
		empuje = c * 10;
		masaCohete = masa[0] + masa[1] + masa[2] + depositos[0] + depositos[1] + depositos[2];
		
		incVel = empuje / masaCohete;
		velocidad = velocidad + incVel;
		c = c - cal;
		depositos[e] = depositos[e] - c;
		separaEtapaCohete(e);
	}
	if(e == 1)
	{
		prob = rand() % 10 + 1;
		cal = c * prob / 100;
		empuje = c * 10;
		masaCohete = masa[1] + masa[2] + depositos[1] + depositos[2];
		
		incVel = empuje / masaCohete;
		velocidad = velocidad + incVel;
		c = c - cal;
		depositos[e] = depositos[e] - c;
		separaEtapaCohete(e);
	}
	if(e == 2)
	{
		prob = rand() % 10 + 1;
		cal = c * prob / 100;
		empuje = c * 10;
		masaCohete =  masa[2] + depositos[2];
		
		incVel = empuje / masaCohete;
		velocidad = velocidad + incVel;
		c = c - cal;
		depositos[e] = depositos[e] - c;
		separaEtapaCohete(e);
	}
}

int estaDepositoVacioCohete(int e)
{
	if(depositos[e] <= 0)
	{
		depositos[e] = 0;
		return 1;
	}
	else
	{
		return 0;
	}
}

void separaEtapaCohete(int e)
{
	if(estaDepositoVacioCohete(e) != 0)
	{
		separaciones[e] = 1;
		printf("\nSe ha separado la etapa %d\n",e + 1);
	}
}

void informaCohete()
{
	printf("\nEl deposito de la etapa 1 es: %.2f\n", depositos[0]);
	printf("El deposito de la etapa 2 es: %.2f\n", depositos[1]);
	printf("El deposito de la etapa 3 es: %.2f\n", depositos[2]);
	printf("\nLa velocidad del cohete es de: %.2f m/s\n", velocidad);
	printf("\nEtapa 1 separada :%d \n", separaciones[0]);
	printf("Etapa 2 separada :%d \n", separaciones[1]);
	printf("Etapa 3 separada :%d \n", separaciones[2]);
	printf("\nLa masa del cohete es de: %.2f kg\n", masaCohete);
}