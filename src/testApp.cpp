/* Spencer Barton
 *
 * Got help from http://forum.openframeworks.cc/t/earth-iphone-app/2324/4 for image map to sphere
 */

#include "testApp.h"

//Struct to store hotel data
struct hotel_t {
    float latitude;
    float longitude;
    int capacity;
};

//--------------------------------------------------------------
void testApp::setup(){

    // begin easy cam
    cam.setDistance(500);
    cam.enableMouseInput();

    // setup earth image
    glEnable(GL_DEPTH_TEST); //enable depth comparisons and update the depth buffer
	ofDisableArbTex(); //needed for textures to work with gluSphere
	earth.loadImage("earth.jpg");
	earth.mirror(true, false); // mirror verticle

	//prepare quadric for sphere
	quadric = gluNewQuadric();
	gluQuadricTexture(quadric, GL_TRUE);
	gluQuadricNormals(quadric, GLU_SMOOTH);

    // csv load and parse
	csv.loadFile(ofToDataPath(DATA_FILENAME), CSV_SEPERATOR);

    globeMesh.setMode(OF_PRIMITIVE_POINTS);

	// populate mesh
	for(int i=0; i < csv.numRows; i++) {
		float lat = csv.getFloat(i, LAT_INDEX);
		float lng = csv.getFloat(i, LNG_INDEX);

		float x = getGlobeX(lat, lng);
		float y = getGlobeY(lat, lng);
		float z = getGlobeZ(lat, lng);

		globeMesh.addVertex(ofPoint(x,y,z));
		globeMesh.addColor(ofFloatColor(255,0,0));
	}

	cout << "Done loading" << endl;

}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
	ofBackground(0);

	cam.begin();

	//bind and draw texture
	glPushMatrix();
	ofRotateZ(90);
	earth.getTextureReference().bind();
	gluSphere(quadric, GLOBE_RADIUS, 100, 100);
	earth.getTextureReference().unbind();
	glPopMatrix();

	globeMesh.draw();


}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){

}

//--------------------------------------------------------------
// Globe Helper Functions
//--------------------------------------------------------------

float testApp::getGlobeX(float lat, float lng){
	return GLOBE_RADIUS * cos(ofDegToRad(lat)) * cos(ofDegToRad(lng));
}


float testApp::getGlobeY(float lat, float lng){
	return GLOBE_RADIUS * cos(ofDegToRad(lat)) * sin(ofDegToRad(lng));
}


float testApp::getGlobeZ(float lat, float lng){
	return GLOBE_RADIUS * sin(ofDegToRad(lat));
}


