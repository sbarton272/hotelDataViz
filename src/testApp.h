#pragma once

#include "ofMain.h"
#include "ofxCsv.h"

using namespace wng;

class testApp : public ofBaseApp{

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
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
        float getGlobeX(float lat, float lng);
        float getGlobeY(float lat, float lng);
        float getGlobeZ(float lat, float lng);

        ofxCsv csv;
        ofMesh globeMesh;
        ofEasyCam cam;
        ofImage earth;
		GLUquadricObj *quadric;

		// id~hotelName~stars~price~cityName~stateName~countryCode~countryName~address~location~url~tripadvisorUrl~latitude~longitude~latlong~propertyType~chainId~rooms~facilities~checkIn~checkOut~rating
        const string DATA_FILENAME = "hotelsbase-latlong.txt";
        const string DEV_FILENAME = "developmentData.txt";
        const string CSV_SEPERATOR = "\t";
        const int LAT_INDEX = 0;
        const int LNG_INDEX = 1;
        const float GLOBE_RADIUS = 100;
        const float SPHERE_RADIUS = 1;
};
