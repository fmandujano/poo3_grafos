#pragma once

#include "ofMain.h"
#include "ofxGui.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

		enum EstadoApp
		{
			esperando,
			poniendoNodo, 
			poniendoAristaDesde,
			poniendoAristaHacia,
			guardando,
		} estado;

		ofxPanel gui;
		ofxButton botonNodos;
		ofxButton botonAristas;
		ofxButton botonGuradar;

		void AgregarNodo();
		void AgregarArista();

		void PonerNodo(float x, float y);
		void intentarNodoIni(float x, float y);
		void intentarTocarNodo(float x, float y);
		void CambiarEstado(EstadoApp nuevo);
		
		void Hanoi(int numDiscos, int origen, int destino, int libre);
};
