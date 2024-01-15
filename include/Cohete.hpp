#ifndef __COHETE_HPP__
#define __COHETE_HPP__


void iniciaCohete();
void recibeCombustibleCohete(int e, float c);
int estaDepositoLlenoCohete(int e);
void consumeCombustibleCohete(int e, float c);
int estaDepositoVacioCohete(int e);
void separaEtapaCohete(int e);
void informaCohete();


#endif

// velocidad = velocidad + 100 * combustible / masa
/*empuje = comb * 10
incrementoVel = empuje / masa */






