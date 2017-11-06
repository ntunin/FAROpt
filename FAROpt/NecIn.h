#pragma once
#include "NecCommand.h"
#include "FileStructure.h"
#include <vector>
#include "CM.h"
#include "CE.h"
#include "GW.h"
#include "GE.h"
#include "GN.h"
#include "FR.h"
#include "EX.h"
#include "PT.h"
#include "RP.h"
#include "EN.h"

class NecIn: public FileStructure
{
public:
	NecIn();
	~NecIn();

	void setCM(CM &cm);
	void setCE(CE &ce);
	void pushGW(GW &gw);
	void setGE(GE &ge);
	void setGN(GN &gn);
	void setFR(FR &fr);
	void pushEX(EX &ex);
	void setPT(PT &pt);
	void setRP(RP &rp);
	void setEN(EN &en);

	CM *getCM();
	CE *getCE();
	std::vector<GW *> *getGW();
	GE *getGE();
	GN *getGN();
	FR *getFR();
	std::vector<EX *> *getEX();
	PT *getPT();
	RP *getRP();
	EN *getEN();

	


private:
	CM *cm;
	CE *ce;
	std::vector<GW *> *gw;
	GE *ge;
	GN *gn;
	FR *fr;
	std::vector<EX *> *ex;
	PT *pt;
	RP *rp;
	EN *en;

};

