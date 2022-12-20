#include "CommunicationDatabase.h"

NS_Composant::CommunicationDatabase::CommunicationDatabase()
{
	this->sCnx = "Data Source=MSI\\MSSQL_MFLORIAN;Initial Catalog=ProjetPOO;User ID=User_Project;Password=1234";
	this->rSql = "RIEN";

	this->mOCnx = gcnew System::Data::SqlClient::SqlConnection(this->sCnx);
	this->mOCmd = gcnew System::Data::SqlClient::SqlCommand(this->rSql, this->mOCnx);

	this->mOCmd->CommandType = System::Data::CommandType::StoredProcedure;
}

NS_Composant::CommunicationDatabase::~CommunicationDatabase()
{
	
}

void NS_Composant::CommunicationDatabase::SetSQL(String^ rq_sql)
{
	if (rq_sql == "" || rq_sql == "RIEN")
	{
		this->rSql = "RIEN";
	}
	else
	{
		this->rSql = rq_sql;
	}
}

System::Data::DataSet^ NS_Composant::CommunicationDatabase::GetRows(array<System::Data::SqlClient::SqlCommand^>^ com, array<String^>^ DataTableName)
{
	int i = 0;
	int lenght = com->Length;
	this->mODs = gcnew System::Data::DataSet();
	while (i < lenght)
	{
		this->mOCmd = com[i];
		this->mOCmd->Connection = this->mOCnx;
		this->mODa = gcnew System::Data::SqlClient::SqlDataAdapter(this->mOCmd);
		this->mODa->Fill(this->mODs, DataTableName[i]);
		i++;
	}
	return this->mODs;
}

int* NS_Composant::CommunicationDatabase::ActionRowsId(array<System::Data::SqlClient::SqlCommand^>^ com)
{
	int* id = new int();

	int i = 0;
	int lenght = com->Length;
	while (i < lenght)
	{
		this->mOCmd = com[i];
		this->mOCmd->Connection = this->mOCnx;
		this->mOCnx->Open();
		id[i] = System::Convert::ToInt32(this->mOCmd->ExecuteScalar());
		this->mOCnx->Close();
		i++;
	}

	return id;
}

void NS_Composant::CommunicationDatabase::ActionRows(array<System::Data::SqlClient::SqlCommand^>^ com)
{
	int i = 0;
	int lenght = com->Length;
	while (i < lenght)
	{
		this->mOCmd = com[i];
		this->mOCmd->Connection = this->mOCnx;
		this->mOCnx->Open();
		this->mOCmd->ExecuteNonQuery();
		this->mOCnx->Close();
		i++;
	}
}
