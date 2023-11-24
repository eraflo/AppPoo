#include "../h/MappageCustomer.h"

NS_Composant::MappageCustomer::MappageCustomer() : MappagePersonne()
{
    this->mBirthDate = "RIEN";
}

NS_Composant::MappageCustomer::~MappageCustomer()
{

}

array<System::Data::SqlClient::SqlCommand^>^ NS_Composant::MappageCustomer::SELECT()
{
    array<System::Data::SqlClient::SqlCommand^>^ cmds = gcnew array<System::Data::SqlClient::SqlCommand^>(1);
    System::Data::SqlClient::SqlCommand^ com = gcnew System::Data::SqlClient::SqlCommand();

    switch (this->GetChoice())
    {
    case 0:
        //commande pour récupérer un client
        com->CommandType = System::Data::CommandType::StoredProcedure;
        com->CommandText = "dbo.SP_Select_One_Cust";
        com->Parameters->Add("@id_cust", System::Data::SqlDbType::Int)->Value = this->GetId();
        cmds[0] = com;
        break;
    case 1:
        //commande pour récupérer tous les clients
        com->CommandType = System::Data::CommandType::StoredProcedure;
        com->CommandText = "dbo.SP_Select_All_Cust";
        cmds[0] = com;
        break;
    case 2:
        //commande pour récup toutes les adresses d'un client
        com->CommandType = System::Data::CommandType::StoredProcedure;
        com->CommandText = "dbo.SP_Select_Ad_People";
        com->Parameters->Add("@id_p", System::Data::SqlDbType::Int)->Value = this->GetId();
        cmds[0] = com;
        break;
    default:
        break;
    }
    return cmds;
}

array<System::Data::SqlClient::SqlCommand^>^ NS_Composant::MappageCustomer::DELETE()
{
    array<System::Data::SqlClient::SqlCommand^>^ cmds;

    System::Data::SqlClient::SqlCommand^ com1;
    System::Data::SqlClient::SqlCommand^ com2;
    System::Data::SqlClient::SqlCommand^ com3;


    switch (this->GetChoice())
    {
    case 0:
        cmds = gcnew array<System::Data::SqlClient::SqlCommand^>(1);

        //commande pour récup l'adresse d'un client
        com1 = gcnew System::Data::SqlClient::SqlCommand();
        com1->CommandType = System::Data::CommandType::StoredProcedure;
        com1->CommandText = "dbo.SP_Select_Ad_People";
        com1->Parameters->Add("@id_p", System::Data::SqlDbType::Int)->Value = this->GetId();
        cmds[0] = com1;
        break;
    case 1:
        cmds = gcnew array<System::Data::SqlClient::SqlCommand^>(1);

        //commande pour supprimer un client
        com2 = gcnew System::Data::SqlClient::SqlCommand();
        com2->CommandType = System::Data::CommandType::StoredProcedure;
        com2->CommandText = "dbo.SP_Delete_Cust";
        com2->Parameters->Add("@id_cust", System::Data::SqlDbType::Int)->Value = this->GetId();
        cmds[0] = com2;
        break;
    case 2:
        cmds = gcnew array<System::Data::SqlClient::SqlCommand^>(1);

        //commande pour supprimer l'adresse du client
        cmds[0] = this->GetMapAd()->DELETE()[0];
        break;
    default:
        break;
    }

    return cmds;
}

array<System::Data::SqlClient::SqlCommand^>^ NS_Composant::MappageCustomer::UPDATE()
{
    array<System::Data::SqlClient::SqlCommand^>^ cmds = gcnew array<System::Data::SqlClient::SqlCommand^>(3);
    System::Data::SqlClient::SqlCommand^ com = gcnew System::Data::SqlClient::SqlCommand();
    System::Data::SqlClient::SqlCommand^ com1 = gcnew System::Data::SqlClient::SqlCommand();

    //commande pour modifier une personne
    com->CommandType = System::Data::CommandType::StoredProcedure;
    com->CommandText = "dbo.SP_Update_People";
    com->Parameters->Add("@id_people", System::Data::SqlDbType::Int)->Value = this->GetId();
    com->Parameters->Add("@fname", System::Data::SqlDbType::Int)->Value = this->GetFirstName();
    com->Parameters->Add("@lname", System::Data::SqlDbType::Int)->Value = this->GetLastName();
    com->Parameters->Add("@mail", System::Data::SqlDbType::Date)->Value = this->GetEmail();
    cmds[0] = com;

    //commande pour modifier un client
    com1->CommandType = System::Data::CommandType::StoredProcedure;
    com1->CommandText = "dbo.SP_Update_Cust";
    com1->Parameters->Add("@id_cust", System::Data::SqlDbType::Int)->Value = this->GetId();
    com1->Parameters->Add("@date", System::Data::SqlDbType::Date)->Value = this->GetBirthdate();
    cmds[1] = com1;
    return cmds;
}

array<System::Data::SqlClient::SqlCommand^>^ NS_Composant::MappageCustomer::INSERT()
{
    array<System::Data::SqlClient::SqlCommand^>^ cmds;
    cmds = gcnew array<System::Data::SqlClient::SqlCommand^>(1);

    System::Data::SqlClient::SqlCommand^ com1;
    System::Data::SqlClient::SqlCommand^ com2;
    System::Data::SqlClient::SqlCommand^ com3;
    System::Data::SqlClient::SqlCommand^ com4;

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
        //commande pour insérer le client
        com2 = gcnew System::Data::SqlClient::SqlCommand();
        com2->CommandType = System::Data::CommandType::StoredProcedure;
        com2->CommandText = "dbo.SP_Insert_Cust";
        com2->Parameters->Add("@id_p", System::Data::SqlDbType::Int)->Value = this->GetId();
        com2->Parameters->Add("@birth_date", System::Data::SqlDbType::Date)->Value = this->GetBirthdate();
        cmds[0] = com2;
        break;
    case 2:
        //commande pour insérer une adresse de facturation
        com3 = gcnew System::Data::SqlClient::SqlCommand();
        com3->CommandType = System::Data::CommandType::StoredProcedure;
        com3->CommandText = "dbo.SP_Insert_Bill_Ad";
        com3->Parameters->Add("@id_address", System::Data::SqlDbType::Int)->Value = this->GetMapAd()->GetId();
        com3->Parameters->Add("@id_people", System::Data::SqlDbType::Int)->Value = this->GetId();
        cmds[0] = com3;
        break;
    case 3:
        //commande pour insérer une adresse de livraison
        com4 = gcnew System::Data::SqlClient::SqlCommand();
        com4->CommandType = System::Data::CommandType::StoredProcedure;
        com4->CommandText = "dbo.SP_Insert_Deliver";
        com4->Parameters->Add("@id_address", System::Data::SqlDbType::Int)->Value = this->GetMapAd()->GetId();
        com4->Parameters->Add("@id_people", System::Data::SqlDbType::Int)->Value = this->GetId();
        cmds[0] = com4;
        break;
    default:
        break;
    }

    return cmds;
}

void NS_Composant::MappageCustomer::SetBirthDate(String^ date)
{
    this->mBirthDate = date;
}

String^ NS_Composant::MappageCustomer::GetBirthdate()
{
    return this->mBirthDate;
}


