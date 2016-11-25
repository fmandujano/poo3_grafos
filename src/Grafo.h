#pragma once
#include <vector>
#include <list>
#include <iostream>

class Nodo
{

public:
	int indice;
	std::string nombre;
	ofVec2f pos;
	Nodo(int n, std::string nom, ofVec2f position)
	{
		indice = n;
		nombre = nom;
		pos = position;
	}

	void draw()
	{
		ofSetColor(250, 0, 0);
		ofDrawCircle(pos.x, pos.y, 25);
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
	Grafo( bool esDirigido  ) 
	{
		siguienteIndice = 0;
		dirigido = esDirigido;
		//inicializar el vector de aristas
		
	}
	~Grafo() {}
	
	typedef std::list<Arista>			ListaAristas;
	typedef std::vector<ListaAristas>   VectorListaAristas;

	//vector de nodos
	std::vector<Nodo> nodos;
	VectorListaAristas aristas;

	void AgregarNodo(std::string nombre, ofVec2f pos)
	{
		Nodo *n = new Nodo(siguienteIndice, nombre, pos);
		nodos.push_back(*n);
		
		std::cout << "agregando nodo " << n->nombre << std::endl;

		siguienteIndice++;
		
		//agregar nodo a la lista de aristas
		aristas.push_back( ListaAristas() );
	}
	
	void AgregarArista(int _desde, int _hacia, float _costo )
	{
		for (ListaAristas::iterator it = aristas[_desde].begin(); it != aristas[_desde].end(); it++)
		{
			if (it->hacia == _hacia)
			{
				puts("ya existia ese arista");
				return;
			}
		}

		Arista * ar = new Arista(_desde, _hacia, _costo  );
		//agregar arista a la lista
		aristas[_desde].push_back( *ar );
		//arista de vuelta en caso de no ser dirigido
		if (!dirigido)
		{
			Arista * ar2 = new Arista(_hacia, _desde, _costo);
			//agregar arista a la lista
			aristas[_hacia].push_back(*ar2);
		}
		
	}

	void draw()
	{
		for (int i = 0; i < nodos.size(); i++)
		{
			nodos[i].draw();
			//dibujar las aristas del nodo
			for (ListaAristas::iterator it = aristas[i].begin(); it != aristas[i].end(); it++)
			{
				ofSetColor(250, 150, 0);
				Nodo *origen = &(nodos[it->desde]);
				Nodo *destino = &(nodos[it->hacia]);
				ofDrawLine(origen->pos.x, origen->pos.y, destino->pos.x, destino->pos.y);

				//vector entre los nodos
				ofVec2f dir = (destino->pos - origen->pos).normalized();
				ofVec2f dir90 = ofVec2f(-dir.y, dir.x) * 25;
				ofVec2f dir270 = ofVec2f(dir.y, -dir.x) * 25;
				ofDrawLine(origen->pos.x + dir90.x , origen->pos.y + dir90.y, destino->pos.x, destino->pos.y);
				ofDrawLine(origen->pos.x + dir270.x, origen->pos.y + dir270.y, destino->pos.x, destino->pos.y);



			}
		}
	}

	void ToString()
	{
		puts("Matriz de adyacencia del grafo: \n\tXD");
		for (int i = 0; i < aristas.size(); i++)
		{
			std::cout << "\t" << i;
		}
		std::cout << std::endl;

		for (std::vector<Nodo>::iterator nodo = nodos.begin();
						nodo != nodos.end(); nodo++)
		{
			std::cout << nodo->indice << ":" << nodo->nombre << std::endl;
		}
	}

private:
	int siguienteIndice;
	bool dirigido =false;

};




