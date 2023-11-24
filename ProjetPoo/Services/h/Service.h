#pragma once
#include "../../Mappage/h/Mappage.h"
#include "../../CommunicationDatabase.h"

using namespace NS_Composant;


namespace NS_Service
{
	ref class Service
	{
	protected:
		Mappage^ mMap;
		NS_Composant::CommunicationDatabase^ mComDB;
		System::Data::DataSet^ mODs;
	public:
		Service();
		~Service();
		System::Data::DataSet^ connecter(array<String^>^, String^, String^);
		CommunicationDatabase^ GetCom();
		System::Data::DataSet^ GetDataSet();
		void SetCom(CommunicationDatabase^);
		void SetMap(Mappage^);
		void SetDataSet(System::Data::DataSet^);
	};
}

