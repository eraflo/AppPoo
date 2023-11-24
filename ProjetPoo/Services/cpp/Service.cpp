#include "../h/Service.h"

NS_Service::Service::Service()
{
	this->mMap = gcnew Mappage();
	this->mComDB = gcnew NS_Composant::CommunicationDatabase();
	this->mODs = gcnew System::Data::DataSet();
}

NS_Service::Service::~Service()
{
	delete this->mComDB;
	delete this->mMap;
	delete this->mODs;
}

System::Data::DataSet^ NS_Service::Service::connecter(array<String^>^ DataTableName, String^ mail, String^ pass)
{
	this->mMap->setEm(System::Convert::ToString(mail));
	this->mMap->setPass(System::Convert::ToString(pass));
	this->mODs->Clear();
	this->mODs = this->mComDB->GetRows(this->mMap->SELECT(), DataTableName);
	return this->mODs;
}

NS_Composant::CommunicationDatabase^ NS_Service::Service::GetCom()
{
	return this->mComDB;
}

System::Data::DataSet^ NS_Service::Service::GetDataSet()
{
	return this->mODs;
}

void NS_Service::Service::SetCom(CommunicationDatabase^ com)
{
	this->mComDB = com;
}

void NS_Service::Service::SetMap(Mappage^ map)
{
	this->mMap = map;
}

void NS_Service::Service::SetDataSet(System::Data::DataSet^ ds)
{
	this->mODs = ds;
}