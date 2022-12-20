#pragma once


using namespace System;
namespace NS_Composant
{
	ref class CommunicationDatabase
	{
	private:
		System::Data::SqlClient::SqlConnection^ mOCnx;
		System::Data::SqlClient::SqlCommand^ mOCmd;
		System::Data::SqlClient::SqlDataAdapter^ mODa;
		System::Data::DataSet^ mODs;
		String^ rSql;
		String^ sCnx;
		void SetSQL(String^);
	public:
		CommunicationDatabase();
		~CommunicationDatabase();
		System::Data::DataSet^ GetRows(array<System::Data::SqlClient::SqlCommand^>^, array<String^>^);
		int* ActionRowsId(array<System::Data::SqlClient::SqlCommand^>^);
		void ActionRows(array<System::Data::SqlClient::SqlCommand^>^);
	};
}


