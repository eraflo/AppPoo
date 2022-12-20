#include "ServiceCommande.h"


NS_Service::ServiceCommande::ServiceCommande()
{
	this->mMap = gcnew MappageCommande();
	this->mComDB = gcnew NS_Composant::CommunicationDatabase();
	this->mODs = gcnew System::Data::DataSet();
}

NS_Service::ServiceCommande::~ServiceCommande()
{
	delete this->mComDB;
	delete this->mMap;
	delete this->mODs;
}

System::Data::DataSet^ NS_Service::ServiceCommande::Display(int cmd, array<String^>^ dataTableName)
{
	this->GetDataSet()->Clear();
	this->mMap->SetChoice(0);
	this->mMap->SetIdCmd(cmd);
	this->SetDataSet(this->GetCom()->GetRows(this->mMap->SELECT(), dataTableName));
	return this->GetDataSet();
}

System::Data::DataSet^ NS_Service::ServiceCommande::DisplayAll(array<String^>^ dataTableName)
{
	this->GetDataSet()->Clear();
	this->mMap->SetChoice(1);
	this->SetDataSet(this->GetCom()->GetRows(this->mMap->SELECT(), dataTableName));
	return this->GetDataSet();
}

void NS_Service::ServiceCommande::Add(String^ del_date, String^ issue_date, double discount, String^ ref, array<NS_Composant::Basket^>^ panier, array<NS_Composant::Payment^>^ paiements)
{
	int* id_adresse;

	this->mMap->SetChoice(0);
	this->mMap->SetDeliveryDate(del_date);
	this->mMap->SetEmissionDate(issue_date);
	this->mMap->SetCmdReference(ref);
	this->mMap->SetCmdDiscount(discount);
	id_adresse = this->GetCom()->ActionRowsId(this->mMap->INSERT());

	this->mMap->SetChoice(1);
	Basket^ panier_rempli = this->remplirPanier(panier);
	Payment^ paiement_renseigné = this->remplirPaiement(paiements);

	this->mMap->SetBasket(panier_rempli);
	this->mMap->SetPayment(paiement_renseigné);

	this->GetCom()->ActionRows(this->mMap->INSERT());

	this->mMap->SetChoice(2);
	this->GetCom()->ActionRows(this->mMap->INSERT());
}

void NS_Service::ServiceCommande::Edit(int id_cmd, String^ del_date, String^ issue_date, double discount, String^ ref, array<NS_Composant::Basket^>^ panier, array<NS_Composant::Payment^>^ paiements)
{
	this->mMap->SetIdCmd(id_cmd);
	this->mMap->SetDeliveryDate(del_date);
	this->mMap->SetEmissionDate(issue_date);
	this->mMap->SetCmdReference(ref);
	this->mMap->SetCmdDiscount(discount);

	Basket^ panier_rempli = this->remplirPanier(panier);
	Payment^ paiement_renseigné = this->remplirPaiement(paiements);

	this->mMap->SetBasket(panier_rempli);
	this->mMap->SetPayment(paiement_renseigné);

	this->GetCom()->ActionRows(this->mMap->UPDATE());
}

void NS_Service::ServiceCommande::Invoice(int)
{
	throw gcnew System::NotImplementedException();
}

void NS_Service::ServiceCommande::Delete(int _id)
{
	this->mMap->SetIdCmd(_id);
	this->GetCom()->ActionRows(this->mMap->DELETE());
}

NS_Composant::Basket^ NS_Service::ServiceCommande::remplirPanier(array<Basket^>^ panier)
{
	int i = 1;
	NS_Composant::Basket^ new_panier = gcnew Basket();
	new_panier = panier[0];
	NS_Composant::Basket^ tmp = gcnew Basket();
	tmp = new_panier;
	while (i < panier->Length)
	{
		tmp->mNext = panier[i];
		tmp = tmp->mNext;
		i++;
	}
	return new_panier;
}

NS_Composant::Payment^ NS_Service::ServiceCommande::remplirPaiement(array<Payment^>^ paiements)
{
	int i = 1;
	NS_Composant::Payment^ new_paiement = gcnew Payment();
	new_paiement = paiements[0];
	NS_Composant::Payment^ tmp = gcnew Payment();
	tmp = new_paiement;
	while (i < paiements->Length)
	{
		tmp->mNext = paiements[i];
		tmp = tmp->mNext;
		i++;
	}
	return new_paiement;
}
