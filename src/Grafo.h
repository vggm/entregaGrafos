/*
 * Grafo.h
 *
 * Víctor González Morales
 * Eduardo Peña 
 *  
 */

#ifndef GRAFO_H_
#define GRAFO_H_

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>

using namespace std;

static const int MAX = 20;    //Constante de valor 20, es de utilidad ya que se indica que como máximo tedremos 14 + 6 nodos.

class Grafo {

	int    numVertices;				  //Numero de nodos que tendra nuestro Grafo
	int    numArcos;				  //Numero de arcos que tendra nuestro Grafo
	string Cjtovertices[MAX];    	  //Conjunto de nodos (vértices) que tendra nuestro Grafo
	float  MatAdyacencia[MAX][MAX];   //Conjunto de aristas valuadas  que tendra nuestro Grafo, (Matriz de Adyacencia)
	float  MFloyd[MAX][MAX];		  //Conjunto de aristas valuadas tras haber realizado Floyd o Kruskal
	int    MatP[MAX][MAX];			  //Matriz resultante de haber hecho Floyd

/********************************************************************************
/*	De esta forma tienes lo imprescindible para un grafo; los vértices y las aristas.
/*	Deberás añadir más matrices, si lo consideras necesario para resolver el ejercicio.
/*	Son las matrices que resultan de aplicar los diferentes algoritmos que vayas necesitando.
/**********************************************************************************************************/
	
	void camino (int origen, int destino, ofstream &salida);
	float arcoMinimo (int &org, int &dst, int visitados[MAX]);
	void copiarMatriz (float m[MAX][MAX]);
	void limpiarMatP ();
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

	/*
	 * PRE: {La estructuras del grafo han de estar correctamente definidas, inicializadas y cargadas}
	 * POST: {Muestra la matriz que se indica como parámetro de entrada.
	 * Complejidad: O(n^2)
	 */
	void MostrarMatriz();

	/*
	 * PRE: {La estructuras del grafo han de estar correctamente definidas, inicializadas y cargadas}
	 * POST: {Muestra la matriz que se indica como parámetro de entrada.
	 * Complejidad: O(n^2)
	 */
	void Floyd();

	/*
	 * PRE: {La estructuras del grafo han de estar correctamente definidas, inicializadas y cargadas}
	 * POST: {Muestra la matriz que se indica como parámetro de entrada.
	 * Complejidad: O(n^2)
	 */
	void MostrarMatP();

	/*
	 * PRE: {La estructuras del grafo han de estar correctamente definidas, inicializadas y cargadas}
	 * POST: {Almacena en MFloyd la matriz resultante de realizar Floyd}
	 * Complejidad: O(n^3)
	 */
	void makeFloyd ();

	/*
	 * PRE: {La estructuras del grafo han de estar correctamente definidas, inicializadas y cargadas}
	 * POST: {Almacena en MFloyd la matriz resultante de realizar Kruskal}
	 * Complejidad: O(n^3)
	 */
	void makeKruskal(float &kmsTotal);
	


};


#endif /* GRAFO_H_ */

