#include "MappageAdresse.h"

NS_Composant::MappageAdresse::MappageAdresse()
{
    this->mNumber = 0;
    this->mComplement = "RIEN";
    this->mStreet = "RIEN";
    this->mPostalCode = 0;
    this->mIdCity = 0;
}

NS_Composant::MappageAdresse::~MappageAdresse()
{
    
}

array<System::Data::SqlClient::SqlCommand^>^ NS_Composant::MappageAdresse::SELECT()
{
    array<System::Data::SqlClient::SqlCommand^>^ cmds;
    cmds = gcnew array<System::Data::SqlClient::SqlCommand^>(1);

    //commande de récupération d'une adresse particulière
    System::Data::SqlClient::SqlCommand^ com = gcnew System::Data::SqlClient::SqlCommand();
    com->CommandType = System::Data::CommandType::StoredProcedure;
    com->CommandText = "dbo.SP_Select_Ad";
    com->Parameters->Add("@id_ad", System::Data::SqlDbType::Int)->Value = this->GetId();
    cmds[0] = com;
    return cmds;
}

array<System::Data::SqlClient::SqlCommand^>^ NS_Composant::MappageAdresse::DELETE()
{
    array<System::Data::SqlClient::SqlCommand^>^ cmds;
    cmds = gcnew array<System::Data::SqlClient::SqlCommand^>(1);

    //commande de suppresion d'une adresse et de ses références en tant qu'adresse de livraison ou facturation
    System::Data::SqlClient::SqlCommand^ com = gcnew System::Data::SqlClient::SqlCommand();
    com->CommandType = System::Data::CommandType::StoredProcedure;
    com->CommandText = "dbo.SP_Delete_Ad";
    com->Parameters->Add("@id_Ad", System::Data::SqlDbType::Int)->Value = this->GetId();
    cmds[0] = com;
    return cmds;
}

array<System::Data::SqlClient::SqlCommand^>^ NS_Composant::MappageAdresse::UPDATE()
{
    array<System::Data::SqlClient::SqlCommand^>^ cmds;
    cmds = gcnew array<System::Data::SqlClient::SqlCommand^>(1);

    //commande de modification des infos d'une adresse
    System::Data::SqlClient::SqlCommand^ com = gcnew System::Data::SqlClient::SqlCommand();
    com->CommandType = System::Data::CommandType::StoredProcedure;
    com->CommandText = "dbo.SP_Update_Ad";
    com->Parameters->Add("@id_ad", System::Data::SqlDbType::Int)->Value = this->GetId();
    com->Parameters->Add("@num", System::Data::SqlDbType::Int)->Value = this->GetNum();
    com->Parameters->Add("@comp", System::Data::SqlDbType::VarChar, 100)->Value = this->GetComp();
    com->Parameters->Add("@street", System::Data::SqlDbType::VarChar, 50)->Value = this->GetStreet();
    com->Parameters->Add("@postal_code", System::Data::SqlDbType::Int)->Value = this->GetPostalCode();
    com->Parameters->Add("@city", System::Data::SqlDbType::Int)->Value = this->GetIdCity();
    cmds[0] = com;
    return cmds;
}

array<System::Data::SqlClient::SqlCommand^>^ NS_Composant::MappageAdresse::INSERT()
{
    array<System::Data::SqlClient::SqlCommand^>^ cmds;
    cmds = gcnew array<System::Data::SqlClient::SqlCommand^>(1);

    //commande pour insérer une nouvelle adresse
    System::Data::SqlClient::SqlCommand^ com = gcnew System::Data::SqlClient::SqlCommand();
    com->CommandType = System::Data::CommandType::StoredProcedure;
    com->CommandText = "dbo.SP_Insert_Ad";
    com->Parameters->Add("@num", System::Data::SqlDbType::Int)->Value = this->GetNum();
    com->Parameters->Add("@comp", System::Data::SqlDbType::VarChar, 100)->Value = this->GetComp();
    com->Parameters->Add("@street", System::Data::SqlDbType::VarChar, 50)->Value = this->GetStreet();
    com->Parameters->Add("@p_code", System::Data::SqlDbType::Int)->Value = this->GetPostalCode();
    com->Parameters->Add("@city", System::Data::SqlDbType::Int)->Value = this->GetIdCity();
    cmds[0] = com;
    return cmds;
}

void NS_Composant::MappageAdresse::SetId(int _id)
{
    this->mId = _id;
}

void NS_Composant::MappageAdresse::SetNum(int num)
{
    this->mNumber = num;
}

void NS_Composant::MappageAdresse::SetComp(String^ compl)
{
    this->mComplement = compl;
}

void NS_Composant::MappageAdresse::SetStreet(String^ street)
{
    this->mStreet = street;
}

void NS_Composant::MappageAdresse::SetPostalCode(int code)
{
    this->mPostalCode = code;
}

void NS_Composant::MappageAdresse::SetIdCity(int id_city)
{
    this->mIdCity = id_city;
}

int NS_Composant::MappageAdresse::GetId()
{
    return this->mId;
}


int NS_Composant::MappageAdresse::GetNum()
{
    return this->mNumber;
}

String^ NS_Composant::MappageAdresse::GetComp()
{
    return this->mComplement;
}

String^ NS_Composant::MappageAdresse::GetStreet()
{
    return this->mStreet;
}

int NS_Composant::MappageAdresse::GetPostalCode()
{
    return this->mPostalCode;
}

int NS_Composant::MappageAdresse::GetIdCity()
{
    return this->mIdCity;
}
