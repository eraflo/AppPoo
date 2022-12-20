#include "Simulation.h"



NS_Composant::Simulation::Simulation()
{
	mCombiPossible[0] = gcnew tVariation(this, &Simulation::CalculTVA);
	mCombiPossible[1] = gcnew tVariation(this, &Simulation::CalculMarge);
	mCombiPossible[2] = gcnew tVariation(this, &Simulation::CalculDiscount);
	mCombiPossible[3] = gcnew tVariation(this, &Simulation::CalculBrand);
}

NS_Composant::Simulation::~Simulation()
{
	throw gcnew System::NotImplementedException();
}

void NS_Composant::Simulation::AddPossibilities(tVariation^)
{
	throw gcnew System::NotImplementedException();
}

double NS_Composant::Simulation::CalculTVA(double)
{
	return 0.0;
}

double NS_Composant::Simulation::CalculMarge(double)
{
	return 0.0;
}

double NS_Composant::Simulation::CalculDiscount(double)
{
	return 0.0;
}

double NS_Composant::Simulation::CalculBrand(double)
{
	return 0.0;
}
