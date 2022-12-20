#include "MappageArticle.h"

NS_Composant::MappageArticle::MappageArticle()
{
    this->mIdArticle = 0;
    this->mReferenceArticle = "RIEN";
    this->mNameArticle = "RIEN";
    this->mDesignation = "RIEN";
    this->mPriceUHT = 0.0;
    this->mTVA = 0.0;
    this->mIdCategorie = 0;
    this->mStockColor = gcnew ColorStock();
}

NS_Composant::MappageArticle::~MappageArticle()
{
    delete this->mStockColor;
}

array<System::Data::SqlClient::SqlCommand^>^ NS_Composant::MappageArticle::SELECT()
{
    array<System::Data::SqlClient::SqlCommand^>^ cmds;
    System::Data::SqlClient::SqlCommand^ com1;
    System::Data::SqlClient::SqlCommand^ com2;

    switch (this->choice)
    {
    case 0:
        cmds = gcnew array<System::Data::SqlClient::SqlCommand^>(2);

        //commande pour récupérer les infos d'un article
        com1 = gcnew System::Data::SqlClient::SqlCommand();
        com1->CommandType = System::Data::CommandType::StoredProcedure;
        com1->CommandText = "dbo.SP_Select_Art";
        com1->Parameters->Add("@id_art", System::Data::SqlDbType::Int)->Value = this->GetIdArt();

        //commande pour récupérer les différents stocks de l'article
        com2 = gcnew System::Data::SqlClient::SqlCommand();
        com2->CommandType = System::Data::CommandType::StoredProcedure;
        com2->CommandText = "dbo.SP_Select_Stock_Art";
        com2->Parameters->Add("@id_art", System::Data::SqlDbType::Int)->Value = this->GetIdArt();
        cmds[0] = com1;
        cmds[1] = com2;
        break;
    case 1:
        cmds = gcnew array<System::Data::SqlClient::SqlCommand^>(1);

        //commande pour récupérer les infos de tous les articles
        com1 = gcnew System::Data::SqlClient::SqlCommand();
        com1->CommandType = System::Data::CommandType::StoredProcedure;
        com1->CommandText = "dbo.SP_Select_All_Art";
        cmds[0] = com1;
        break;
    case 2:
        cmds = gcnew array<System::Data::SqlClient::SqlCommand^>(1);

        //commande pour récupérer les infos d'une couleur
        com1 = gcnew System::Data::SqlClient::SqlCommand();
        com1->CommandType = System::Data::CommandType::StoredProcedure;
        com1->CommandText = "dbo.SP_Select_IdCol";
        com1->Parameters->Add("@name", System::Data::SqlDbType::VarChar, 15)->Value = this->GetStockColor()->colName;
        cmds[0] = com1;
        break;
    case 3:
        cmds = gcnew array<System::Data::SqlClient::SqlCommand^>(1);

        //commande pour récupérer les infos d'une catégorie
        com1 = gcnew System::Data::SqlClient::SqlCommand();
        com1->CommandType = System::Data::CommandType::StoredProcedure;
        com1->CommandText = "dbo.SP_Select_AllCat";
        cmds[0] = com1;
        break;
    default:
        break;
    }

    return cmds;
}

array<System::Data::SqlClient::SqlCommand^>^ NS_Composant::MappageArticle::DELETE()
{
    array<System::Data::SqlClient::SqlCommand^>^ cmds;
    cmds = gcnew array<System::Data::SqlClient::SqlCommand^>(1);

    //commande pour supprimer un article
    System::Data::SqlClient::SqlCommand^ com = gcnew System::Data::SqlClient::SqlCommand();
    com->CommandType = System::Data::CommandType::StoredProcedure;
    com->CommandText = "dbo.SP_Delete_Article";
    com->Parameters->Add("@id_art", System::Data::SqlDbType::Int)->Value = this->GetIdArt();
    cmds[0] = com;
    return cmds;
}

array<System::Data::SqlClient::SqlCommand^>^ NS_Composant::MappageArticle::UPDATE()
{
    array<System::Data::SqlClient::SqlCommand^>^ cmds;
    int size = 1;
    ColorStock^ tmp1 = gcnew ColorStock();
    tmp1 = this->mStockColor;
    while (tmp1 != nullptr)
    {
        tmp1 = tmp1->mNext;
        size++;
    }

    cmds = gcnew array<System::Data::SqlClient::SqlCommand^>(size);

    //commande pour modifier un article
    System::Data::SqlClient::SqlCommand^ com1 = gcnew System::Data::SqlClient::SqlCommand();
    com1->CommandType = System::Data::CommandType::StoredProcedure;
    com1->CommandText = "dbo.SP_Update_Art";
    com1->Parameters->Add("@id_art", System::Data::SqlDbType::Int)->Value = this->GetIdArt();
    com1->Parameters->Add("@ref", System::Data::SqlDbType::VarChar, 10)->Value = this->GetRefArticle();
    com1->Parameters->Add("@name", System::Data::SqlDbType::VarChar, 25)->Value = this->GetNameArticle();
    com1->Parameters->Add("@designation", System::Data::SqlDbType::VarChar, 250)->Value = this->GetDesignation();
    System::Data::SqlClient::SqlParameter^ param1 = gcnew System::Data::SqlClient::SqlParameter("@price", System::Data::SqlDbType::Decimal);
    param1->Precision = 5;
    param1->Scale = 2;
    com1->Parameters->Add(param1)->Value = this->GetPriceUHT();
    System::Data::SqlClient::SqlParameter^ param2 = gcnew System::Data::SqlClient::SqlParameter("@vat", System::Data::SqlDbType::Decimal);
    param2->Precision = 3;
    param2->Scale = 2;
    com1->Parameters->Add(param2)->Value = this->GetTVA();
    com1->Parameters->Add("@id_cat", System::Data::SqlDbType::Int)->Value = this->GetIdCategorie();
    cmds[0] = com1;

    //commande pour modifier les différents stocks d'un article
    ColorStock^ tmp2 = gcnew ColorStock();
    tmp2 = this->mStockColor;
    int pos = 1;
    while (tmp2 != nullptr)
    {
        System::Data::SqlClient::SqlCommand^ com = gcnew System::Data::SqlClient::SqlCommand();
        com->CommandType = System::Data::CommandType::StoredProcedure;
        com->CommandText = "dbo.SP_Update_Stock";
        com->Parameters->Add("@id_stock", System::Data::SqlDbType::Int)->Value = this->GetStockColor()->mIdStock;
        com->Parameters->Add("@threshold", System::Data::SqlDbType::Int)->Value = this->GetStockColor()->mReplenishmentThreshold;
        System::Data::SqlClient::SqlParameter^ param = gcnew System::Data::SqlClient::SqlParameter("@cost", System::Data::SqlDbType::Decimal);
        param->Precision = 15;
        param->Scale = 2;
        com->Parameters->Add(param)->Value = this->GetStockColor()->mProdCost;
        com->Parameters->Add("@ref", System::Data::SqlDbType::VarChar, 50)->Value = this->GetStockColor()->mReferenceProductColor;
        com->Parameters->Add("@qte", System::Data::SqlDbType::Int)->Value = this->GetStockColor()->mQuantityStock;
        com->Parameters->Add("@id_col", System::Data::SqlDbType::Int)->Value = this->GetStockColor()->mIdColor;
        com->Parameters->Add("@id_art", System::Data::SqlDbType::Int)->Value = this->GetStockColor()->mIdArt;
        cmds[pos] = com;
        tmp2 = tmp2->mNext;
        pos++;
    }


    return cmds;
}

array<System::Data::SqlClient::SqlCommand^>^ NS_Composant::MappageArticle::INSERT()
{
    array<System::Data::SqlClient::SqlCommand^>^ cmds;
    int size = 1;
    ColorStock^ tmp1 = gcnew ColorStock();
    tmp1 = this->mStockColor;
    while (tmp1 != nullptr)
    {
        tmp1 = tmp1->mNext;
        size++;
    }

    cmds = gcnew array<System::Data::SqlClient::SqlCommand^>(size);

    //commande pour insérer un article
    System::Data::SqlClient::SqlCommand^ com1 = gcnew System::Data::SqlClient::SqlCommand();
    com1->CommandType = System::Data::CommandType::StoredProcedure;
    com1->CommandText = "dbo.SP_Insert_Art";
    com1->Parameters->Add("@ref", System::Data::SqlDbType::VarChar, 10)->Value = this->GetRefArticle();
    com1->Parameters->Add("@name", System::Data::SqlDbType::VarChar, 25)->Value = this->GetNameArticle();
    com1->Parameters->Add("@designation", System::Data::SqlDbType::VarChar, 250)->Value = this->GetDesignation();
    System::Data::SqlClient::SqlParameter^ param1 = gcnew System::Data::SqlClient::SqlParameter("@price", System::Data::SqlDbType::Decimal);
    param1->Precision = 5;
    param1->Scale = 2;
    com1->Parameters->Add(param1)->Value = this->GetPriceUHT();
    System::Data::SqlClient::SqlParameter^ param2 = gcnew System::Data::SqlClient::SqlParameter("@vat", System::Data::SqlDbType::Decimal);
    param2->Precision = 3;
    param2->Scale = 2;
    com1->Parameters->Add(param2)->Value = this->GetTVA();
    com1->Parameters->Add("@cat", System::Data::SqlDbType::Int)->Value = this->GetIdCategorie();
    cmds[0] = com1;


    //commande pour insérer les stocks de l'article
    ColorStock^ tmp2 = gcnew ColorStock();
    tmp2 = this->mStockColor;
    int pos = 1;
    while (tmp2 != nullptr)
    {
        System::Data::SqlClient::SqlCommand^ com = gcnew System::Data::SqlClient::SqlCommand();
        com->CommandType = System::Data::CommandType::StoredProcedure;
        com->CommandText = "dbo.SP_Update_Stock";
        com->Parameters->Add("@threshold", System::Data::SqlDbType::Int)->Value = this->GetStockColor()->mReplenishmentThreshold;
        System::Data::SqlClient::SqlParameter^ param = gcnew System::Data::SqlClient::SqlParameter("@cost", System::Data::SqlDbType::Decimal);
        param->Precision = 15;
        param->Scale = 2;
        com->Parameters->Add(param)->Value = this->GetStockColor()->mProdCost;
        com->Parameters->Add("@ref", System::Data::SqlDbType::VarChar, 50)->Value = this->GetStockColor()->mReferenceProductColor;
        com->Parameters->Add("@qte", System::Data::SqlDbType::Int)->Value = this->GetStockColor()->mQuantityStock;
        com->Parameters->Add("@color", System::Data::SqlDbType::Int)->Value = this->GetStockColor()->mIdColor;
        com->Parameters->Add("@id_art", System::Data::SqlDbType::Int)->Value = this->GetStockColor()->mIdArt;
        cmds[pos] = com;
        tmp2 = tmp2->mNext;
        pos++;
    }


    return cmds;
}

void NS_Composant::MappageArticle::SetIdArt(int id)
{
    this->mIdArticle = id;
}

void NS_Composant::MappageArticle::SetRefArticle(String^ ref)
{
    this->mReferenceArticle = ref;
}

void NS_Composant::MappageArticle::SetNameArticle(String^ name)
{
    this->mNameArticle = name;
}

void NS_Composant::MappageArticle::SetDesignation(String^ designation)
{
    this->mDesignation = designation;
}

void NS_Composant::MappageArticle::SetPriceUHT(double price)
{
    this->mPriceUHT = price;
}

void NS_Composant::MappageArticle::SetTVA(double tva)
{
    this->mTVA = tva;
}

void NS_Composant::MappageArticle::SetIdCategorie(int id)
{
    this->mIdCategorie = id;
}

void NS_Composant::MappageArticle::SetStockColor(ColorStock^ stocks)
{
    ColorStock^ tmp = gcnew ColorStock();
    tmp = this->mStockColor;
    while (tmp != nullptr)
    {
        tmp = tmp->mNext;
    }
    tmp = stocks;
}

void NS_Composant::MappageArticle::SetChoice(int choice)
{
    this->choice = choice;
}

int NS_Composant::MappageArticle::GetIdArt()
{
    return this->mIdArticle;
}

String^ NS_Composant::MappageArticle::GetRefArticle()
{
    return this->mReferenceArticle;
}

String^ NS_Composant::MappageArticle::GetNameArticle()
{
    return this->mNameArticle;
}

String^ NS_Composant::MappageArticle::GetDesignation()
{
    return this->mDesignation;
}

double NS_Composant::MappageArticle::GetPriceUHT()
{
    return this->mPriceUHT;
}

double NS_Composant::MappageArticle::GetTVA()
{
    return this->mTVA;
}

int NS_Composant::MappageArticle::GetIdCategorie()
{
    return this->mIdCategorie;
}

NS_Composant::ColorStock^ NS_Composant::MappageArticle::GetStockColor()
{
    return this->mStockColor;
}

int NS_Composant::MappageArticle::GetChoice()
{
    return this->choice;
}

