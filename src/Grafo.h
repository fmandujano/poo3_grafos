#pragma once
#include <vector>
#include <list>
#include <iostream>

class Nodo
{
public:
	int indice;
	std::string nombre;

	Nodo(int n, std::string nom)
	{
		indice = n;
		nombre = nom;
	}

};

class Arista
{
public:
	int desde;
	int hacia;
	float costo;

	Arista(int dsd, int hcia)
	{
		desde = dsd;
		hacia = hcia;
		costo = 1.0f;
	}
	Arista(int dsd, int hcia, float cost)
	{
		desde = dsd;
		hacia = hcia;
		costo = cost;
	}
	
};
class Grafo
{
public:
	Grafo() 
	{
		siguienteIndice = 0;
		
		//inicializar el vector de aristas
		
	}
	~Grafo() {}
	
	typedef std::list<Arista>			ListaAristas;
	typedef std::vector<ListaAristas>   VectorListaAristas;

	//vectoor de nodos
	std::vector<Nodo> nodos;
	VectorListaAristas aristas;

	void AgregarNodo(std::string nombre)
	{
		Nodo *n = new Nodo(siguienteIndice, nombre);
		nodos.push_back(*n);
		
		std::cout << "agregando nodo " << n->nombre << std::endl;

		siguienteIndice++;
		
		//agregar nodo a la lista de aristas
		aristas.push_back( ListaAristas() );
	}
	
	void AgregarArista(int _desde, int _hacia, float _costo )
	{
		Arista * ar = new Arista(_desde, _hacia, _costo  );
		//agregar arista a la lista
		aristas[_desde].push_back( *ar );
		//arista de vuelta en caso de no ser dirigido
		Arista * ar2 = new Arista(_hacia, _desde, _costo  );
		//agregar arista a la lista
		aristas[_hacia].push_back( *ar2 );
		
	}

	void ToString()
	{
		puts("Nodos en el grafo:");
		for (std::vector<Nodo>::iterator nodo = nodos.begin();
						nodo != nodos.end(); nodo++)
		{
			std::cout << nodo->indice << ":" << nodo->nombre << std::endl;
		}
	}

private:
	int siguienteIndice;

};




