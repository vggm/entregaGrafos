/*
 * Grafo.h
 *
 *Indica el/los nombre/s del/los autor/es
 *  
 */

#ifndef GRAFO_H_
#define GRAFO_H_

#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

static const int MAX = 20;    //Constante de valor 20, es de utilidad ya que se indica que como máximo tedremos 14 + 6 nodos.

class Grafo {

	int    numVertices;				  //Número de nodos que tendrá nuestro Grafo
	string Cjtovertices[MAX];    	  //Conjunto de nodos (vértices) que tendrá nuestro Grafo
	float  MatAdyacencia[MAX][MAX];   //Conjunto de aristas valuadas  que tendrá nuestro Grafo, (Matriz de Adyacencia)
	float  MFloyd[MAX][MAX];
	int    MatP[MAX][MAX];

/********************************************************************************
/*	De esta forma tienes lo imprescindible para un grafo; los vértices y las aristas.
/*	Deberás añadir más matrices, si lo consideras necesario para resolver el ejercicio.
/*	Son las matrices que resultan de aplicar los diferentes algoritmos que vayas necesitando.
/**********************************************************************************************************/
	void makeFloyd ();

public:

	/*
	 * PRE: {Las estructuras del grafo han de estar correctamente definidas}
	 * POST: {-Inicializamos el numero de ocupados 0
     *  	  -Inicializamos el conjunto de vértices
     *        -Inicializamos el conjunto de caminos (Matriz de Adyacencia) con el valor 9999 en todas sus casillas y 0 en la diagonal,
	 *        }
	 * Complejidad: O(n^2)
	 */
	Grafo();

	/*
	 * PRE: {Las estructuras del grafo han de estar correctamente definidas e inicializadas}
	 * POST: {Abrimos un flujo de lectura del fichero "Datos.in" y cargamos las diferentes estructuras del Grafo a partir de los datos ...............}
	

	 * Complejidad: O(n)
	 */
	void CargarDatos();

	
/********************************************************************************/
/*	Deberás añadir más métodos necesarios para resolver el ejercicio.
/*	Documentarlos de forma correcta.
/**********************************************************************************************************/


	/*
	 * PRE: {La estructuras del grafo han de estar correctamente definidas, inicializadas y cargadas}
	 * POST: {Muestra la matriz que se indica como parámetro de entrada.
	 * Complejidad: O(n^2)
	 */
	void MostrarDatos(float matriz[MAX][MAX]);

	void MostrarMatriz();

	void Floyd();

	void MostrarMatP();

	void insertarNodo(string Nodo);

	void insertarArco(string origen, string destino);

	bool pertenece(string nombre);

	float arco(string origen, string destino);

	void adyacentes(string nodo, float lista[MAX]);

	



};


#endif /* GRAFO_H_ */

