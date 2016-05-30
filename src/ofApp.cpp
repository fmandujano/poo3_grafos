#include "ofApp.h"
#include "Grafo.h"
//--------------------------------------------------------------
void ofApp::setup()
{
	Grafo *grafo = new Grafo();
	grafo->AgregarNodo("hugo");
	grafo->AgregarNodo("paco");
	grafo->AgregarNodo("luis");
	grafo->ToString();
	
	grafo->AgregarArista( 0, 1, 1 );
	grafo->AgregarArista( 1, 2, 1 );
	grafo->AgregarArista( 0, 2, 1 );
	
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

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
void ofApp::mousePressed(int x, int y, int button){

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
