#include <iostream>
#include "Grafo.h"

int main()
{
	Grafo *g = new Grafo();
	g->CargarDatos();
	g->MostrarMatriz();
	g->Floyd();
	g->MostrarMatP();
	delete g;
}