#include "ServiceStatistique.h"


NS_Service::ServiceStatistique::ServiceStatistique()
{
	this->mCalulator = gcnew NS_Composant::Simulation();
	this->mMap = gcnew MappageStat();
	this->mComDB = gcnew NS_Composant::CommunicationDatabase();
	this->mODs = gcnew System::Data::DataSet();
}

NS_Service::ServiceStatistique::~ServiceStatistique()
{
	delete this->mComDB;
	delete this->mMap;
	delete this->mODs;
}

System::Data::DataSet^ NS_Service::ServiceStatistique::Display(int)
{
	throw gcnew System::NotImplementedException();
	// TODO: ins�rer une instruction return ici
}

System::Data::DataSet^ NS_Service::ServiceStatistique::Calcul(int)
{
	throw gcnew System::NotImplementedException();
	// TODO: ins�rer une instruction return ici
}

System::Data::DataSet^ NS_Service::ServiceStatistique::Simulate(int)
{
	throw gcnew System::NotImplementedException();
	// TODO: ins�rer une instruction return ici
}
