#include "FKartuves.h"

void FKartuves::Reset()
{
	constexpr int MAX_BANDYMU = 8;
	ManoMaxBandymas = MAX_BANDYMU;

	ManoEsamasBandymas = 1;
	
	return;
}

FKartuves::FKartuves() {Reset(); }//konstruktorius 

int FKartuves::GautMaxBandymu() const{ return ManoMaxBandymas; }

int FKartuves::TurimiBandymai() const { return ManoEsamasBandymas; }

bool FKartuves::Pergale() const
{
	return false;
}

bool FKartuves::PatikrintiSpejima(std::string)
{
	return false;
}
