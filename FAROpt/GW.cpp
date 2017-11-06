#include "stdafx.h"
#include "GW.h"


GW::GW(int tag, int seg, double x1, double y1, double z1, double x2, double y2, double z2, double radius) {
	this->tag = tag;
	this->seg = seg;
	this->x1 = x1;
	this->x2 = x2;
	this->y1 = y1;
	this->y2 = y2;
	this->z1 = z1;
	this->z2 = z2;
	this->radius = radius;
}

GW::GW(GW &gw) {
	this->tag = gw.tag;
	this->seg = gw.seg;
	this->x1 = gw.x1;
	this->x2 = gw.x2;
	this->y1 = gw.y1;
	this->y2 = gw.y2;
	this->z1 = gw.z1;
	this->z2 = gw.z2;
	this->radius = gw.radius;
}


GW::~GW(){
}

std::string GW::toString() {
	std::stringstream stream;
	stream << "GW"
		<< ((NecCommand *)this)->toString(this->tag, 5)
		<< ((NecCommand *)this)->toString(this->seg, 3)
		<< ((NecCommand *)this)->toString(this->x1, 9, false)
		<< ((NecCommand *)this)->toString(this->y1, 9, false)
		<< ((NecCommand *)this)->toString(this->z1, 9, false)
		<< ((NecCommand *)this)->toString(this->x2, 9, false)
		<< ((NecCommand *)this)->toString(this->y2, 9, false)
		<< ((NecCommand *)this)->toString(this->z2, 9, false)
		<< ((NecCommand *)this)->toString(this->radius, 9, false);
	return stream.str();
}

