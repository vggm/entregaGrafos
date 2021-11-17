#include <iostream>
#include "Grafo.h"

int main()
{
	Grafo *g = new Grafo();
	g->MostrarMatriz();
	delete g;
}