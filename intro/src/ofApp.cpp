#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofEnableSmoothing();
    
    cam.setDistance(8);
    
//    for (float u = 0.0; u < 2*PI; u += 2*PI/100) {
//        for (float v = 0.0; v < 2*PI; v += 2*PI/100) {
//            float x = sin(u) * 10.0 * cos(v);
//            float y = sin(v) + cos(u) * 10.0 * cos(v);
//            float z = cos(v) + 10.0 * sin(v) * sin(u);
//            shape1.addVertex(ofVec3f(x,y,z));
//        }
//    }
//
//    
//    shape1.setMode(OF_PRIMITIVE_LINE_STRIP);
//    
//    for (float u = 0.0; u < 2*PI; u += 2*PI/100) {
//        for (float v = 0.0; v < PI; v += PI/100) {
//            float x = cos(v);
//            float y = u + u * sin(v) * sin(u);
//            float z = sin(v) * cos(u);
//            shape2.addVertex(ofVec3f(x,y,z));
//        }
//    }
//    
//    
//    shape2.setMode(OF_PRIMITIVE_LINE_STRIP);
    
    ofSetColor(0);
}

//--------------------------------------------------------------
void ofApp::update(){
    shape1.clear();
    float morph = ofMap(mouseX, 0, ofGetWidth(), 0.0, 1.0);
    
    int n = 100;
    
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            //shape1
            float u1 = i * 2*PI/n;
            float v1 = j * 2*PI/n;
            float x1 = sin(u1) * 1.0 * cos(v1);
            float y1 = sin(v1) + cos(u1) * 1.0 * cos(v1);
            float z1 = cos(v1) + 1.0 * sin(v1) * sin(u1);
            
            //shape2
            float u2 = i * 2*PI/n;
            float v2 = j * PI/n;
            float x2 = cos(v2);
            float y2 = u2 + u2 * sin(v2) * sin(u2);
            float z2 = sin(v2) * cos(u2);
            
            //morph
            float x = x1 * morph + x2 * (1.0 - morph);
            float y = y1 * morph + y2 * (1.0 - morph);
            float z = z1 * morph + z2 * (1.0 - morph);
            
            shape1.addVertex(ofVec3f(x,y,z));
            shape1.addColor(ofFloatColor((float)i / n, (float)j / n, 0.5));
        }
    }
    
    shape1.setMode(OF_PRIMITIVE_LINE_STRIP);
}

//--------------------------------------------------------------
void ofApp::draw(){
    cam.begin();
    shape1.draw();
    cam.end();
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
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
