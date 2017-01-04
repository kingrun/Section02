#include "FKartuves.h"

using int32 = int;


void FKartuves::Reset()
{
	constexpr int32 MAX_BANDYMU = 8;
	const FString PasleptasZodis = "planet";

	ManoMaxBandymas = MAX_BANDYMU;
	ManoPasleptasZodis = PasleptasZodis;
	ManoEsamasBandymas = 1;
	return;
}

FKartuves::FKartuves() {Reset(); }//konstruktorius 

int32 FKartuves::GautMaxBandymu() const{ return ManoMaxBandymas; }
int32 FKartuves::TurimiBandymai() const { return ManoEsamasBandymas; }
int32 FKartuves::GautiZodzioIlgi() const { return ManoPasleptasZodis.length(); }


bool FKartuves::Pergale() const
{
	return false;
}

bool FKartuves::PatikrintiSpejima(FString) const
{
	return false;
}

// gauna teising spejima, padidina ejima ir parodo ekrane.
FKartuviuSkaicius FKartuves::PateiktSpejima(FString Spejimas)
{
	//didinti ejimo skaiciu
	ManoEsamasBandymas++;
	// sukurti gryzimo variable
	FKartuviuSkaicius KartuviuSkaicius;

	// loop per visus simbolius spejime
	int32 PasleptoZodzioIlgis = ManoPasleptasZodis.length();
	for (int32 MPZRaide = 0; MPZRaide < PasleptoZodzioIlgis; MPZRaide++)
	{
		//patikrint raides pagal paslepta zodi
		for (int32 SRaide = 0; SRaide < PasleptoZodzioIlgis; SRaide++)
		{
			//jei jie atitinka
			if (Spejimas[SRaide] == ManoPasleptasZodis[MPZRaide])
			{
				if (MPZRaide == SRaide) 
				{
					KartuviuSkaicius.Geras++; // didinti teisingu skaiciu jei ten atitinka
				}
				else
				{
					KartuviuSkaicius.Blogas++;// ir neteisingu jei neatitinka
				}
			}
		}	
	}
	
	return KartuviuSkaicius;
}
