#include "ofApp.h"
#include "Grafo.h"
//--------------------------------------------------------------
Grafo *grafo;

int pasos=0;
ofVec2f *tempPos;
Nodo * tempNodoIniArista;

void ofApp::setup()
{
	//crear un grafo dirigido
	grafo = new Grafo( true );

	//UI
	gui.setup();
	gui.add(botonNodos.setup("Nodo"));
	gui.add(botonAristas.setup("Arista"));
	gui.setPosition((ofGetWidth() / 2) - (gui.getWidth() / 2), 
					ofGetHeight()- gui.getHeight()-100);
	botonNodos.addListener(this, &ofApp::AgregarNodo);
	botonAristas.addListener(this, &ofApp::AgregarArista);

	CambiarEstado(EstadoApp::esperando);
}

//lamada por el GUI
void ofApp::AgregarNodo()
{
	puts("agregar un nodo");
	CambiarEstado(EstadoApp::poniendoNodo);
}

//lamado por el GUI
void ofApp::AgregarArista()
{
	puts("ahora aristas");
	CambiarEstado( EstadoApp::poniendoAristaDesde);
}


//--------------------------------------------------------------
void ofApp::update()
{

}

//--------------------------------------------------------------
void ofApp::draw()
{
	if (estado == EstadoApp::esperando)
	{
		gui.draw();
	}
	else if (estado == EstadoApp::poniendoNodo)
	{
		ofDrawBitmapString("COLOCA EL NODO AHORA", 100, 60);
	}
	else if (estado == EstadoApp::poniendoAristaDesde)
	{
		ofDrawBitmapString("Toca el nodo origen", 100, 60);
	}
	else if (estado == EstadoApp::poniendoAristaHacia)
	{
		ofDrawBitmapString("Toca el nodo destino", 100, 60);
		if (tempNodoIniArista != NULL)
		{
			ofSetColor(ofColor::yellow);
			ofDrawLine(tempNodoIniArista->pos.x, 
				tempNodoIniArista->pos.y,
				ofGetMouseX(),
				ofGetMouseY());
		}
	}
	grafo->draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button)
{
	if(estado == EstadoApp::poniendoNodo )
	{
		PonerNodo(x,y);
	}
	else if (estado == EstadoApp::poniendoAristaDesde)
	{
		intentarNodoIni(x, y);
	}
	else if (estado ==  EstadoApp::poniendoAristaHacia)
	{
		//verificar si se hizo clic en nodo
		intentarTocarNodo(x, y);
	}
}

void ofApp::CambiarEstado(EstadoApp nueve)
{
	estado = nueve;
	printf("Cambiando a estado %i \n", estado);
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}

void ofApp::PonerNodo(float x, float y)
{
	ofVec2f pos(x, y);
	grafo->AgregarNodo(".", pos);
	CambiarEstado(EstadoApp::esperando);
}

void ofApp::intentarNodoIni(float x, float y)
{
	for (int i = 0; i < grafo->nodos.size(); i++)
	{
		float d = ofDistSquared(x, y, grafo->nodos[i].pos.x, grafo->nodos[i].pos.y);
		if (d < 625)
		{
			tempNodoIniArista = &grafo->nodos[i];
			CambiarEstado(EstadoApp::poniendoAristaHacia);
			return;
		}
	}
	CambiarEstado(EstadoApp::esperando);
	return;
}

void ofApp::intentarTocarNodo(float x, float y)
{
	for (int i = 0; i < grafo->nodos.size(); i++)
	{
		float d = ofDistSquared(x, y, grafo->nodos[i].pos.x, grafo->nodos[i].pos.y);
		if (d < 625)
		{
			Nodo * temp = &grafo->nodos[i];
			grafo->AgregarArista(tempNodoIniArista->indice, temp->indice, 1);
			CambiarEstado(EstadoApp::esperando);
			tempNodoIniArista = NULL;
		}
	}
}

void ofApp::Hanoi(int numDiscos, int origen, int destino, int libre)
{
	if (numDiscos > 0)
	{
		Hanoi(numDiscos - 1, origen, libre, destino);
		//std::cout << "Moviendo disco " << numDiscos << " de " <<
		//	origen << " a " << destino << std::endl;

		pasos++;
		Hanoi(numDiscos - 1, libre, destino, origen);
	}
}
