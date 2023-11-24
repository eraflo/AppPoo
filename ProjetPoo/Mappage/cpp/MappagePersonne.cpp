#include "../h/MappagePersonne.h"

NS_Composant::MappagePersonne::MappagePersonne()
{
    this->mId_personne = 0;
    this->mFirstName = "RIEN";
    this->mLastName = "RIEN";
    this->mMapAd = gcnew MappageAdresse();
}

NS_Composant::MappagePersonne::~MappagePersonne()
{
    delete this->mMapAd;
}

array<System::Data::SqlClient::SqlCommand^>^ NS_Composant::MappagePersonne::SELECT()
{
    throw gcnew System::NotImplementedException();
}

array<System::Data::SqlClient::SqlCommand^>^ NS_Composant::MappagePersonne::DELETE()
{
    throw gcnew System::NotImplementedException();
}

array<System::Data::SqlClient::SqlCommand^>^ NS_Composant::MappagePersonne::UPDATE()
{
    throw gcnew System::NotImplementedException();
}

array<System::Data::SqlClient::SqlCommand^>^ NS_Composant::MappagePersonne::INSERT()
{
    throw gcnew System::NotImplementedException();
}

void NS_Composant::MappagePersonne::SetId(int id)
{
    this->mId_personne = id;
}

void NS_Composant::MappagePersonne::SetLastName(String^ name)
{
    this->mLastName = name;
}

void NS_Composant::MappagePersonne::SetFirstName(String^ name)
{
    this->mFirstName = name;
}

void NS_Composant::MappagePersonne::SetEmail(String^ mail)
{
    this->email = mail;
}

void NS_Composant::MappagePersonne::SetChoice(int _choice)
{
    this->choice = _choice;
}

int NS_Composant::MappagePersonne::GetChoice()
{
    return this->choice;
}

int NS_Composant::MappagePersonne::GetId()
{
    return this->mId_personne;
}

String^ NS_Composant::MappagePersonne::GetLastName()
{
    return this->mLastName;
}

String^ NS_Composant::MappagePersonne::GetFirstName()
{
    return this->mFirstName;
}

String^ NS_Composant::MappagePersonne::GetEmail()
{
    return this->email;
}

NS_Composant::MappageAdresse^ NS_Composant::MappagePersonne::GetMapAd()
{
    return this->mMapAd;
}
