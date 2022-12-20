#pragma once
#include "Service.h"
#include "Simulation.h"
#include "MappageStat.h"
namespace NS_Service
{
	ref class ServiceStatistique : public Service
	{
	private:
		NS_Composant::Simulation^ mCalulator;
		MappageStat^ mMap;

	public:
		ServiceStatistique();
		~ServiceStatistique();
		System::Data::DataSet^ Display(int);
		System::Data::DataSet^ Calcul(int);
		System::Data::DataSet^ Simulate(int);
	};
}


