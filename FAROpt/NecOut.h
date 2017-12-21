#pragma once
#include "Complex.h"
#include <vector>
#include "FileStructure.h"
class NecOut: public FileStructure {
public:
	NecOut();
	~NecOut();
	

	class Source {
	public:
		Source();
		Source(int tag, int seg, double vRe, double vIm, double iRe, double iIm, double zRe, double zIm, double aRe, double aIm, double power);
		Complex getI();
		Complex getV();
		~Source();
	private:
		int tag; 
		int seg;
		Complex v;
		Complex i;
		Complex z;
		Complex a;
		double power;
	};

	class RadiationPattern {
	public:
		RadiationPattern(double theta, double phi, double verticalGain, double horisontalGain, double totalGain, double axialPolarisation, double polarisationTilt, std::string polarisationSense, double eThetaMagnitude, double eThetaPhase, double ePhiMagnitude, double ePhiPhase);
		~RadiationPattern();
		RadiationPattern();
		double getTheta();
		double getPhi();
		double getGain();
		double getMagnitude();
		double getPhase();
		Complex getE();
	
	private:
		double theta;
		double phi;
		double verticalGain;
		double horisontalGain;
		double totalGain; 
		double axialPolarisation; 
		double polarisationTilt;
		std::string polarisationSense;
		double eThetaMagnitude;
		double eThetaPhase;
		double ePhiMagnitude;
		double ePhiPhase;
	};

	void addSource(int tag, int seg, double vRe, double vIm, double iRe, double iIm, double zRe, double zIm, double aRe, double aIm, double power);
	std::vector<NecOut::Source> getSources();

	void addRadiationPattern(double theta, double phi, double verticalGain, double horisontalGain, double totalGain, double axialPolarisation, double polarisationTilt, std::string polarisationSense, double eThetaMagnitude, double eThetaPhase, double ePhiMagnitude, double ePhiPhase);
	std::vector<NecOut::RadiationPattern> getRadiationPatterns();

private:
	std::vector<NecOut::Source> sources;
	std::vector<NecOut::RadiationPattern> radiationPatters;
};

