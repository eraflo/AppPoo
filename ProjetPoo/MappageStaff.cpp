#include "MappageStaff.h"

NS_Composant::MappageStaff::MappageStaff() : MappagePersonne()
{
    this->mIdManager = 0;
    this->mHiringDate = "RIEN";
    this->mIdAd = 0;
    this->compte = gcnew MappageUser();
}

NS_Composant::MappageStaff::~MappageStaff()
{
    delete this->compte;
}

array<System::Data::SqlClient::SqlCommand^>^ NS_Composant::MappageStaff::SELECT()
{
    array<System::Data::SqlClient::SqlCommand^>^ cmds = gcnew array<System::Data::SqlClient::SqlCommand^>(1);
    System::Data::SqlClient::SqlCommand^ com = gcnew System::Data::SqlClient::SqlCommand();

    switch (this->choice)
    {
    case 0:
        //commande pour récupérer un staff
        com->CommandType = System::Data::CommandType::StoredProcedure;
        com->CommandText = "dbo.SP_Select_One_Staff";
        com->Parameters->Add("@id_perso", System::Data::SqlDbType::Int)->Value = this->GetId();
        cmds[0] = com;
        break;
    case 1:
        //commande pour récupérer tous les staffs
        com->CommandType = System::Data::CommandType::StoredProcedure;
        com->CommandText = "dbo.SP_Select_All_Staff";
        cmds[0] = com;
        break;
    default:
        break;
    }

    return cmds;
}

array<System::Data::SqlClient::SqlCommand^>^ NS_Composant::MappageStaff::DELETE()
{
    array<System::Data::SqlClient::SqlCommand^>^ cmds;

    System::Data::SqlClient::SqlCommand^ com1;
    System::Data::SqlClient::SqlCommand^ com2;
    System::Data::SqlClient::SqlCommand^ com3;


    switch (this->GetChoice())
    {
    case 0:
        cmds = gcnew array<System::Data::SqlClient::SqlCommand^>(1);

        //commande pour récup l'adresse d'un staff
        com1 = gcnew System::Data::SqlClient::SqlCommand();
        com1->CommandType = System::Data::CommandType::StoredProcedure;
        com1->CommandText = "dbo.SP_Select_Ad_People";
        com1->Parameters->Add("@id_p", System::Data::SqlDbType::Int)->Value = this->GetId();
        break;
    case 1:
        cmds = gcnew array<System::Data::SqlClient::SqlCommand^>(1);

        //commande pour récup le compte d'un staff
        com2 = gcnew System::Data::SqlClient::SqlCommand();
        com2->CommandType = System::Data::CommandType::StoredProcedure;
        com2->CommandText = "dbo.SP_Select_User";
        com2->Parameters->Add("@id_p", System::Data::SqlDbType::Int)->Value = this->GetId();
        break;
    case 2:
        cmds = gcnew array<System::Data::SqlClient::SqlCommand^>(1);

        //commande pour supprimer un staff
        com3 = gcnew System::Data::SqlClient::SqlCommand();
        com3->CommandType = System::Data::CommandType::StoredProcedure;
        com3->CommandText = "dbo.SP_Delete_Staffs";
        com3->Parameters->Add("@id_staff", System::Data::SqlDbType::Int)->Value = this->GetId();
        cmds[0] = com3;
        break;
    case 3:
        cmds = gcnew array<System::Data::SqlClient::SqlCommand^>(1);


        //commande pour supprimer l'adresse du staff
        cmds[0] = this->GetMapAd()->DELETE()[0];
        break;
    case 4:
        cmds = gcnew array<System::Data::SqlClient::SqlCommand^>(1);

        //commande pour supprimer le compte du staff
        cmds[1] = this->GetMapUser()->DELETE()[0];
        break;
    default:
        break;
    }

    return cmds;
}

array<System::Data::SqlClient::SqlCommand^>^ NS_Composant::MappageStaff::UPDATE()
{
    array<System::Data::SqlClient::SqlCommand^>^ cmds = gcnew array<System::Data::SqlClient::SqlCommand^>(1);
    System::Data::SqlClient::SqlCommand^ com = gcnew System::Data::SqlClient::SqlCommand();

    //commande pour modifier un staff
    com->CommandType = System::Data::CommandType::StoredProcedure;
    com->CommandText = "dbo.SP_Update_Staff";
    com->Parameters->Add("@id_people", System::Data::SqlDbType::Int)->Value = this->GetId();
    com->Parameters->Add("@id_sup", System::Data::SqlDbType::Int)->Value = this->GetIdManager();
    com->Parameters->Add("@date", System::Data::SqlDbType::Date)->Value = this->GetHiringDate();
    com->Parameters->Add("@id_ad", System::Data::SqlDbType::Int)->Value = this->GetIdAd();
    cmds[0] = com;
    return cmds;
}

array<System::Data::SqlClient::SqlCommand^>^ NS_Composant::MappageStaff::INSERT()
{
    array<System::Data::SqlClient::SqlCommand^>^ cmds;
    cmds = gcnew array<System::Data::SqlClient::SqlCommand^>(1);

    System::Data::SqlClient::SqlCommand^ com1;
    System::Data::SqlClient::SqlCommand^ com2;

    switch (this->GetChoice())
    {
    case 0:
        //commande pour insérer une personne
        com1 = gcnew System::Data::SqlClient::SqlCommand();
        com1->CommandType = System::Data::CommandType::StoredProcedure;
        com1->CommandText = "dbo.SP_Insert_People";
        com1->Parameters->Add("@fname", System::Data::SqlDbType::VarChar, 20)->Value = this->GetFirstName();
        com1->Parameters->Add("@lname", System::Data::SqlDbType::VarChar, 30)->Value = this->GetLastName();
        com1->Parameters->Add("@mail", System::Data::SqlDbType::VarChar, 40)->Value = this->GetEmail();
        cmds[0] = com1;
        break;
    case 1:
        //commande pour insérer le staff
        com2 = gcnew System::Data::SqlClient::SqlCommand();
        com2->CommandType = System::Data::CommandType::StoredProcedure;
        com2->CommandText = "dbo.SP_Insert_Staff";
        com2->Parameters->Add("@id_people", System::Data::SqlDbType::Int)->Value = this->GetId();
        com2->Parameters->Add("@id_sup", System::Data::SqlDbType::Int)->Value = this->GetIdManager();
        com2->Parameters->Add("@date", System::Data::SqlDbType::Date)->Value = this->GetHiringDate();
        com2->Parameters->Add("@id_address", System::Data::SqlDbType::Int)->Value = this->GetIdAd();
        cmds[0] = com2;
        break;
    default:
        break;
    }

    return cmds;
}

void NS_Composant::MappageStaff::SetIdManager(int id)
{
    this->mIdManager = id;
}

void NS_Composant::MappageStaff::SetHiringDate(String^ date)
{
    this->mHiringDate = date;
}

void NS_Composant::MappageStaff::SetIdAd(int id)
{
    this->mIdAd = id;
}

void NS_Composant::MappageStaff::SetChoice(int choice)
{
    this->choice = choice;
}

int NS_Composant::MappageStaff::GetIdManager()
{
    return this->mIdManager;
}

String^ NS_Composant::MappageStaff::GetHiringDate()
{
    return this->mHiringDate;
}

int NS_Composant::MappageStaff::GetIdAd()
{
    return this->mIdAd;
}

NS_Composant::MappageUser^ NS_Composant::MappageStaff::GetMapUser()
{
    return this->compte;
}

int NS_Composant::MappageStaff::GetChoice()
{
    return this->choice;
}
