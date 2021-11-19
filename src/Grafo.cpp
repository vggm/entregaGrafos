#include "Grafo.h"
#include <fstream>
#include <iostream>
#include <map>
using namespace std;

Grafo::Grafo () {
    numVertices = 0;

    for (int i = 0; i < MAX; i++)
        Cjtovertices[i] = '\0';

    for (int i = 0; i < MAX; i++)
        for (int j = 0; j < MAX; j++) 

            if (i != j)
                MatAdyacencia[i][j] = 9999;
            else
                MatAdyacencia[i][j] = -1;

    for (int i = 0; i < MAX; i++)
        for (int j = 0; j < MAX; j++) 
            if (i != j)
                MFloyd[i][j] = 9999;
            else
                MFloyd[i][j] = -1;

    for (int i = 0; i < MAX; i++)
        for (int j = 0; j < MAX; j++)
            MatP[i][j] = -1;
        
    CargarDatos();
}

void Grafo::CargarDatos() {
    int n, d, p;
    string vertice, lineaVacia;
    string campo[3];
    string org, dst;

	map<string,int> mapaVertices;


    ifstream archivo;
    archivo.open("Datos.in", ios::in);

    ofstream salida;
    salida.open("Datos.out", ios::trunc);

    if (archivo.is_open() && salida.is_open()) 
    {
        archivo >> n; // Obtenemos el número de elementos con los que vamos a trabajar
        for (int i = 0; i < n; i++) { // Obtenemos el conjunto de elementos con los que vamos a trabajar
            
            archivo >> vertice; 
            Cjtovertices[i] = vertice;
            mapaVertices[vertice] = i;
            numVertices++;
        }
        

        archivo >> d; // Obtenemos el número de adyacencias
        for (int i = 0; i < d; i++)
        {   
            for (int j = 0; j < 3; j++)
                archivo >> campo[j];


            int origen  = mapaVertices[campo[0]];
            int destino = mapaVertices[campo[1]];
            float kms   = stof(campo[2]);
            MatAdyacencia[origen][destino] = kms; // Asignamos la distancia entre dos ciudades
            MatAdyacencia[destino][origen] = kms; // Es la misma distancia desde el origen al destino como del destino al origen

            // La matriz de Floyd, al principio tendrá lo mismos valores que la Matriz de Adyacencia
            MFloyd[origen][destino] = kms; 
            MFloyd[destino][origen] = kms; 
        }

        // Una vez recogidas todas las distancias, creamos la matriz de floyd
        this->makeFloyd();

        archivo >> p; // Número de consultas que haremos
        for (int i = 0; i < p; i++)
        {
            archivo >> org;
            archivo >> dst;

            int origen = mapaVertices[org];
            int destino= mapaVertices[dst];

            salida << org << " ";
            this->camino(origen,destino,salida);
            salida << dst << " " << MFloyd[origen][destino] << endl;
        }
        
        salida.close();
        archivo.close();
    }
    
}

void Grafo::MostrarDatos(float Matriz[MAX][MAX]) {
    for (int i = 0; i < numVertices; i++)
    {
        for (int j = 0; j < numVertices; j++)
        {
            float dato = Matriz[i][j];
            string mostrar;

            if (dato == 9999)
                mostrar = "  n  ";
            else if (dato == -1)
                mostrar = "  -1 ";
            else
                mostrar = to_string(dato).substr(0,5);

            cout << " " << mostrar << " ";
        }
        cout << endl;
    }
}

void Grafo::makeFloyd() {
    int n = numVertices;
    float newResult;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (i != j)
				for (int k = 0; k < n; k++)
					if (MFloyd[i][k] != 9999 && k != i) {
						newResult = MFloyd[j][i] + MFloyd[i][k];
						if (newResult < MFloyd[j][k]) {
							MFloyd[j][k] = newResult;
							MatP[j][k]= i;
						}
					}	
}

void Grafo::camino(int origen, int destino, ofstream &s) {
    int k;
    k = MatP[origen][destino];

    if (k != -1)
    {
        camino(origen,k,s);
        s << Cjtovertices[k] << " ";
        camino(k,destino,s);
    }
}

void Grafo::MostrarMatriz() {
    cout << "--- Mostrando Matriz de Adyacencia ---" << endl;
    MostrarDatos(MatAdyacencia);
}

void Grafo::Floyd() {
    cout << "--- Mostrando Matriz de Floyd ---" << endl;
    MostrarDatos(MFloyd);
}

void Grafo::MostrarMatP() {
    cout << "--- Mostrando Matriz P ---" << endl;
    for (int i = 0; i < numVertices; i++) 
    {
        for (int j = 0; j < numVertices; j++)
            if (MatP[i][j] == -1)
                cout << "-1 ";
            else
                cout << " " << MatP[i][j] << " ";
        cout << endl;
    }
}