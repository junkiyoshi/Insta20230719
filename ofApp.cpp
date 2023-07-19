#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(30);
	ofSetWindowTitle("openFrameworks");

	ofBackground(39);
	ofSetColor(239);
	ofNoFill();
	ofSetLineWidth(2);
}
//--------------------------------------------------------------
void ofApp::update() {

	ofSeedRandom(39);	
}

//--------------------------------------------------------------
void ofApp::draw() {

	ofTranslate(ofGetWindowSize() * 0.5);

	int param = ofMap(ofNoise(ofRandom(1000), ofGetFrameNum() * 0.05), 0, 1, 1, 100);
	int param_scale = ofMap(ofNoise(ofRandom(1000), ofGetFrameNum() * 0.05), 0, 1, 1, 5);

	ofBeginShape();
	for (float len = 0; len < 780; len += 0.05) {

		param = len * param_scale;
		ofVertex(this->make_point(len, param));
	}
	ofEndShape(false);
}

//--------------------------------------------------------------
glm::vec2 ofApp::make_point(float len, int param) {

	param = param % 100;
	if (param < 25) {

		return glm::vec2(ofMap(param, 0, 25, -len * 0.5, len * 0.5), -len * 0.5);
	}
	else if (param < 50) {

		return glm::vec2(len * 0.5, ofMap(param, 25, 50, -len * 0.5, len * 0.5));
	}
	else if (param < 75) {

		return glm::vec2(ofMap(param, 50, 75, len * 0.5, -len * 0.5), len * 0.5);
	}
	else {

		return glm::vec2(-len * 0.5, ofMap(param, 75, 100, len * 0.5, -len * 0.5));
	}
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}