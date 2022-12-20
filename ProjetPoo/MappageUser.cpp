#include "MappageUser.h"

NS_Composant::MappageUser::MappageUser()
{
    this->mIdUser = 0;
    this->mPwd = "RIEN";
    this->mIdP = 0;
}

NS_Composant::MappageUser::~MappageUser()
{

}

array<System::Data::SqlClient::SqlCommand^>^ NS_Composant::MappageUser::SELECT()
{
    array<System::Data::SqlClient::SqlCommand^>^ cmds = gcnew array<System::Data::SqlClient::SqlCommand^>(1);
    System::Data::SqlClient::SqlCommand^ com = gcnew System::Data::SqlClient::SqlCommand();

    //commande pour récupérer un compte
    com->CommandType = System::Data::CommandType::StoredProcedure;
    com->CommandText = "dbo.SP_Select_User";
    com->Parameters->Add("@id_perso", System::Data::SqlDbType::Int)->Value = this->GetIdP();
    cmds[0] = com;
    return cmds;
}

array<System::Data::SqlClient::SqlCommand^>^ NS_Composant::MappageUser::DELETE()
{
    array<System::Data::SqlClient::SqlCommand^>^ cmds = gcnew array<System::Data::SqlClient::SqlCommand^>(1);
    System::Data::SqlClient::SqlCommand^ com = gcnew System::Data::SqlClient::SqlCommand();

    //commande pour supprimer un compte
    com->CommandType = System::Data::CommandType::StoredProcedure;
    com->CommandText = "dbo.SP_Delete_Users";
    com->Parameters->Add("@id_user", System::Data::SqlDbType::Int)->Value = this->GetIdUser();
    cmds[0] = com;
    return cmds;
}

array<System::Data::SqlClient::SqlCommand^>^ NS_Composant::MappageUser::UPDATE()
{
    array<System::Data::SqlClient::SqlCommand^>^ cmds = gcnew array<System::Data::SqlClient::SqlCommand^>(1);
    System::Data::SqlClient::SqlCommand^ com = gcnew System::Data::SqlClient::SqlCommand();

    //commande pour modifier un compte
    com->CommandType = System::Data::CommandType::StoredProcedure;
    com->CommandText = "dbo.SP_Update_Users";
    com->Parameters->Add("@id_user", System::Data::SqlDbType::Int)->Value = this->GetIdUser();
    com->Parameters->Add("@pwd", System::Data::SqlDbType::VarChar, 30)->Value = this->GetPwd();
    com->Parameters->Add("@id_people", System::Data::SqlDbType::Int)->Value = this->GetIdP();
    cmds[0] = com;
    return cmds;
}

array<System::Data::SqlClient::SqlCommand^>^ NS_Composant::MappageUser::INSERT()
{
    array<System::Data::SqlClient::SqlCommand^>^ cmds = gcnew array<System::Data::SqlClient::SqlCommand^>(1);
    System::Data::SqlClient::SqlCommand^ com = gcnew System::Data::SqlClient::SqlCommand();

    //commande pour créer un compte
    com->CommandType = System::Data::CommandType::StoredProcedure;
    com->CommandText = "dbo.SP_Insert_Users";
    com->Parameters->Add("@pwd", System::Data::SqlDbType::VarChar, 30)->Value = this->GetPwd();
    com->Parameters->Add("@id_people", System::Data::SqlDbType::Int)->Value = this->GetIdP();
    cmds[0] = com;
    return cmds;
}

void NS_Composant::MappageUser::SetIdUser(int id)
{
    this->mIdUser = id;
}

void NS_Composant::MappageUser::SetPwd(String^ pwd)
{
    this->mPwd = pwd;
}

void NS_Composant::MappageUser::SetIdP(int id)
{
    this->mIdP = id;
}

int NS_Composant::MappageUser::GetIdUser()
{
    return this->mIdUser;
}

String^ NS_Composant::MappageUser::GetPwd()
{
    return this->mPwd;
}

int NS_Composant::MappageUser::GetIdP()
{
    return this->mIdP;
}
