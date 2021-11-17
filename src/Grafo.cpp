#include "Grafo.h"
#include <fstream>
#include <iostream>
#include <map>
using namespace std;

Grafo::Grafo () {
    ocupados = 0;
    for (int i = 0; i < MAX; i++)
    {
        for (int j = 0; j < MAX; j++) {

            if (i != j)
                MatAdyacencia[i][j] = 9999;
            else
                MatAdyacencia[i][j] = -1;
        }
    }
    
    CargarDatos();
}

void Grafo::CargarDatos() {
    int n, d, p;
    string vertice, lineaVacia;
    string campo[3];

    map<string,int> mapa;

    ifstream archivo;
    archivo.open("Datos.in", ios::in);

    if (archivo.is_open()) 
    {
        archivo >> n; // Obtenemos el número de elementos con los que vamos a trabajar
        for (int i = 0; i < n; i++) { // Obtenemos el conjunto de elementos con los que vamos a trabajar
            
            archivo >> vertice; 
            Cjtovertices[i] = vertice;
            mapa[vertice] = i;
            ocupados++;
        }
        
        getline(archivo, lineaVacia);

        archivo >> d; // Obtenemos el número de adyacencias
        for (int i = 0; i < d; i++)
        {
            getline(archivo,campo[0],' ');
            getline(archivo,campo[1],' ');
            getline(archivo,campo[2],'\n');


            int origen  = mapa[campo[0]];
            int destino = mapa[campo[1]];
            MatAdyacencia[origen][destino] = stof(campo[2]);
        }

        getline(archivo, lineaVacia);

        archivo >> p;

        archivo.close();
    }
    
}

void Grafo::MostrarDatos(float Matriz[MAX][MAX]) {
    for (int i = 0; i < ocupados; i++)
    {
        for (int j = 0; j < ocupados; j++)
        {
            float dato = MatAdyacencia[i][j];
            
            if (dato == 9999)
                
            if (dato == -1)

            else

        }
        std::cout << endl;
    }
}

void Grafo::MostrarMatriz() {
    MostrarDatos(MatAdyacencia);
}