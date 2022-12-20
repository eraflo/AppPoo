#include "Mappage.h"

NS_Composant::Mappage::Mappage()
{
    this->m_email = "RIEN";
    this->m_pass = "RIEN";
}

NS_Composant::Mappage::~Mappage()
{

}

array<System::Data::SqlClient::SqlCommand^>^ NS_Composant::Mappage::SELECT()
{
    array<System::Data::SqlClient::SqlCommand^>^ cmds = gcnew array<System::Data::SqlClient::SqlCommand^>(1);
    System::Data::SqlClient::SqlCommand^ com = gcnew System::Data::SqlClient::SqlCommand();
    com->CommandType = System::Data::CommandType::StoredProcedure;
    com->CommandText = "dbo.SP_Connexion";
    com->Parameters->Add("@email", System::Data::SqlDbType::VarChar, 40)->Value = this->getEm();
    com->Parameters->Add("@password", System::Data::SqlDbType::VarChar, 30)->Value = this->getPass();
    cmds[0] = com;
    return cmds;
}

array<System::Data::SqlClient::SqlCommand^>^ NS_Composant::Mappage::DELETE()
{
    throw gcnew System::NotImplementedException();
}

array<System::Data::SqlClient::SqlCommand^>^ NS_Composant::Mappage::UPDATE()
{
    throw gcnew System::NotImplementedException();
}

array<System::Data::SqlClient::SqlCommand^>^ NS_Composant::Mappage::INSERT()
{
    throw gcnew System::NotImplementedException();
}

void NS_Composant::Mappage::setEm(String^ mail)
{
    this->m_email = mail;
}

void NS_Composant::Mappage::setPass(String^ pass)
{
    this->m_pass = pass;
}

String^ NS_Composant::Mappage::getEm(void)
{
    return this->m_email;
}

String^ NS_Composant::Mappage::getPass(void)
{
    return this->m_pass;
}
