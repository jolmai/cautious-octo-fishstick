#include "Cohete.hpp"
#include "Torre.hpp"
#include "Director.hpp"


void main()
{
	iniciaCohete();
	iniciaTorre();
	iniciaDirector();
	while(estaSecuenciaCompletada() != 1)
	{
		simulaSecuencia();
		informaCohete();
		informaDirector();
	}
	
	
}