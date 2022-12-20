#include "MappageCommande.h"

NS_Composant::MappageCommande::MappageCommande()
{
    this->mIdCmd = 0;
    this->mEmissionDate = "RIEN";
    this->mReferenceCmd = "RIEN";
    this->mDiscount = 0.0;
    this->mDeliveryDate = "RIEN";
    this->mIdCustomer = 0;
    this->mListPayment = gcnew Payment();
    this->mListArticle = gcnew Basket();
}

NS_Composant::MappageCommande::~MappageCommande()
{
    delete this->mListArticle;
    delete this->mListPayment;
}

array<System::Data::SqlClient::SqlCommand^>^ NS_Composant::MappageCommande::SELECT()
{
    array<System::Data::SqlClient::SqlCommand^>^ cmds;

    System::Data::SqlClient::SqlCommand^ com1;
    System::Data::SqlClient::SqlCommand^ com2;
    System::Data::SqlClient::SqlCommand^ com3;


    switch (this->choice)
    {
    case 0:
        cmds = gcnew array<System::Data::SqlClient::SqlCommand^>(3);


        //commande pour récuperer la commande
        com1 = gcnew System::Data::SqlClient::SqlCommand();
        com1->CommandType = System::Data::CommandType::StoredProcedure;
        com1->CommandText = "dbo.SP_Select_Cmd";
        com1->Parameters->Add("@id_cmd", System::Data::SqlDbType::Int)->Value = this->GetIdCmd();


        //commande pour récupérer le panier
        com2 = gcnew System::Data::SqlClient::SqlCommand();
        com2->CommandType = System::Data::CommandType::StoredProcedure;
        com2->CommandText = "dbo.SP_Select_Stock_Basket";
        com2->Parameters->Add("@id_cmd", System::Data::SqlDbType::Int)->Value = this->GetIdCmd();

        //commande pour récupérer les paiements
        com3 = gcnew System::Data::SqlClient::SqlCommand();
        com3->CommandType = System::Data::CommandType::StoredProcedure;
        com3->CommandText = "dbo.SP_Select_Pay";
        com3->Parameters->Add("@id_cmd", System::Data::SqlDbType::Int)->Value = this->GetIdCmd();

        //ajout des commandes dans la liste de commande à effectuer
        cmds[0] = com1;
        cmds[1] = com2;
        cmds[2] = com3;
        break;
    case 1:
        cmds = gcnew array<System::Data::SqlClient::SqlCommand^>(1);

        //commande pour récupérer les infos de tous les articles
        com1 = gcnew System::Data::SqlClient::SqlCommand();
        com1->CommandType = System::Data::CommandType::StoredProcedure;
        com1->CommandText = "dbo.SP_Select_All_Cmd";
        cmds[0] = com1;
        break;
    default:
        break;
    }

    return cmds;
}

array<System::Data::SqlClient::SqlCommand^>^ NS_Composant::MappageCommande::DELETE()
{
    array<System::Data::SqlClient::SqlCommand^>^ cmds;
    cmds = gcnew array<System::Data::SqlClient::SqlCommand^>(1);

    //commande de suppression d'une commande et de tout les éléments qui s'y réfère
    System::Data::SqlClient::SqlCommand^ com1 = gcnew System::Data::SqlClient::SqlCommand();
    com1->CommandType = System::Data::CommandType::StoredProcedure;
    com1->CommandText = "dbo.SP_Delete_Orders";
    com1->Parameters->Add("@id_cmd", System::Data::SqlDbType::Int)->Value = this->GetIdCmd();
    cmds[0] = com1;
    return cmds;
}

array<System::Data::SqlClient::SqlCommand^>^ NS_Composant::MappageCommande::UPDATE()
{
    array<System::Data::SqlClient::SqlCommand^>^ cmds;
    int size = 1;
    Basket^ tmp1 = gcnew Basket();
    tmp1 = this->mListArticle;
    while (tmp1 != nullptr)
    {
        tmp1 = tmp1->mNext;
        size++;
    }

    Payment^ tmp2 = gcnew Payment();
    tmp2 = this->mListPayment;
    while (tmp1 != nullptr)
    {
        tmp1 = tmp1->mNext;
        size++;
    }

    cmds = gcnew array<System::Data::SqlClient::SqlCommand^>(size);
    System::Data::SqlClient::SqlCommand^ com1 = gcnew System::Data::SqlClient::SqlCommand();
    com1->CommandType = System::Data::CommandType::StoredProcedure;

    //commande pour update la table Order
    com1->CommandText = "dbo.SP_Update_Order";
    com1->Parameters->Add("@id_cmd", System::Data::SqlDbType::Int)->Value = this->GetIdCmd();
    com1->Parameters->Add("@del_date", System::Data::SqlDbType::Date)->Value = this->GetDeliveryDate();
    com1->Parameters->Add("@issue_date", System::Data::SqlDbType::Date)->Value = this->GetEmissionDate();
    com1->Parameters->Add("@ref", System::Data::SqlDbType::VarChar, 43)->Value = this->GetCmdReference();
    System::Data::SqlClient::SqlParameter^ param1 = gcnew System::Data::SqlClient::SqlParameter("@discount", System::Data::SqlDbType::Decimal);
    param1->Precision = 15;
    param1->Scale = 2;
    com1->Parameters->Add(param1)->Value = this->GetCmdDiscount();

    cmds[0] = com1;

    //commande pour update la table include (panier d'article)
    Basket^ tmp3 = gcnew Basket();
    tmp3 = this->mListArticle;
    int pos = 1;
    while (tmp2 != nullptr)
    {
        System::Data::SqlClient::SqlCommand^ com2 = gcnew System::Data::SqlClient::SqlCommand();
        com2->CommandType = System::Data::CommandType::StoredProcedure;
        com2->CommandText = "dbo.SP_Update_Basket";
        com2->Parameters->Add("@id_cmd", System::Data::SqlDbType::Int)->Value = this->GetIdCmd();
        com2->Parameters->Add("@id_stock", System::Data::SqlDbType::Int)->Value = this->GetBasket()->mIdStock;
        com2->Parameters->Add("@quantity_bought", System::Data::SqlDbType::Int)->Value = this->GetBasket()->mPurchaseQuantity;
        com2->Parameters->Add("@qte_r", System::Data::SqlDbType::Int)->Value = this->GetBasket()->mReductionQuantity;
        cmds[pos] = com2;
        tmp2 = tmp2->mNext;
        pos++;
    }

    //commande pour update la table Payments
    Payment^ tmp4 = gcnew Payment();
    tmp4 = this->mListPayment;
    pos = 1;
    while (tmp2 != nullptr)
    {
        System::Data::SqlClient::SqlCommand^ com3 = gcnew System::Data::SqlClient::SqlCommand();
        com3->CommandType = System::Data::CommandType::StoredProcedure;
        com3->CommandText = "dbo.SP_Update_Payment";
        com3->Parameters->Add("@id_pay", System::Data::SqlDbType::Int)->Value = this->GetPayment()->mIdPay;
        com3->Parameters->Add("@pay_date", System::Data::SqlDbType::Date)->Value = this->GetPayment()->mDatePayment;
        com3->Parameters->Add("@balance_date", System::Data::SqlDbType::Date)->Value = this->GetPayment()->mDatePaymentBalance;
        com3->Parameters->Add("@means", System::Data::SqlDbType::VarChar, 15)->Value = this->GetPayment()->mMeansPayment;
        com3->Parameters->Add("@amount", System::Data::SqlDbType::Int)->Value = this->GetPayment()->mSommePay;
        System::Data::SqlClient::SqlParameter^ param = gcnew System::Data::SqlClient::SqlParameter("@amount", System::Data::SqlDbType::Decimal);
        param->Precision = 15;
        param->Scale = 2;
        com3->Parameters->Add(param)->Value = this->GetPayment()->mSommePay;
        com3->Parameters->Add("@id_cmd", System::Data::SqlDbType::Int)->Value = this->GetIdCmd();
        cmds[pos] = com3;
        tmp2 = tmp2->mNext;
        pos++;
    }

    return cmds;
}

array<System::Data::SqlClient::SqlCommand^>^ NS_Composant::MappageCommande::INSERT()
{
    array<System::Data::SqlClient::SqlCommand^>^ cmds;

    System::Data::SqlClient::SqlCommand^ com1;
    System::Data::SqlClient::SqlCommand^ com2;
    System::Data::SqlClient::SqlCommand^ com4;
    System::Data::SqlClient::SqlCommand^ com5;

    System::Data::SqlClient::SqlParameter^ param1;

    Basket^ tmp1 = gcnew Basket();
    tmp1 = this->mListArticle;

    Payment^ tmp2 = gcnew Payment();
    tmp2 = this->mListPayment;

    Basket^ tmp3 = gcnew Basket();
    tmp3 = this->mListArticle;

    Payment^ tmp4 = gcnew Payment();
    tmp4 = this->mListPayment;


    int size = 0;
    int pos;
    switch (this->GetChoice())
    {
    case 0:
        size++;
        cmds = gcnew array<System::Data::SqlClient::SqlCommand^>(size);
        com1 = gcnew System::Data::SqlClient::SqlCommand();
        com1->CommandType = System::Data::CommandType::StoredProcedure;

        //commande pour insert dans la table Order
        com1->CommandText = "dbo.SP_Insert_Order";
        com1->Parameters->Add("@del_date", System::Data::SqlDbType::Date)->Value = this->GetDeliveryDate();
        com1->Parameters->Add("@issue_date", System::Data::SqlDbType::Date)->Value = this->GetEmissionDate();
        com1->Parameters->Add("@ref", System::Data::SqlDbType::VarChar, 43)->Value = this->GetCmdReference();
        param1 = gcnew System::Data::SqlClient::SqlParameter("@discount", System::Data::SqlDbType::Decimal);
        param1->Precision = 15;
        param1->Scale = 2;
        com1->Parameters->Add(param1)->Value = this->GetCmdDiscount();

        cmds[0] = com1;
        break;
    case 1:

        while (tmp1 != nullptr)
        {
            tmp1 = tmp1->mNext;
            size++;
        }


        while (tmp1 != nullptr)
        {
            tmp1 = tmp1->mNext;
            size++;
        }

        cmds = gcnew array<System::Data::SqlClient::SqlCommand^>(size);

        //commande pour update la table include (panier d'article)
        pos = 1;
        while (tmp2 != nullptr)
        {
            com2 = gcnew System::Data::SqlClient::SqlCommand();
            com2->CommandType = System::Data::CommandType::StoredProcedure;
            com2->CommandText = "dbo.SP_Update_Basket";
            com2->Parameters->Add("@id_cmd", System::Data::SqlDbType::Int)->Value = this->GetIdCmd();
            com2->Parameters->Add("@id_stock", System::Data::SqlDbType::Int)->Value = this->GetBasket()->mIdStock;
            com2->Parameters->Add("@quantity_bought", System::Data::SqlDbType::Int)->Value = this->GetBasket()->mPurchaseQuantity;
            com2->Parameters->Add("@qte_r", System::Data::SqlDbType::Int)->Value = this->GetBasket()->mReductionQuantity;
            cmds[pos] = com2;
            tmp2 = tmp2->mNext;
            pos++;
        }

        //commande pour update la table Payments
        pos = 1;
        while (tmp2 != nullptr)
        {
            System::Data::SqlClient::SqlCommand^ com3 = gcnew System::Data::SqlClient::SqlCommand();
            com3->CommandType = System::Data::CommandType::StoredProcedure;
            com3->CommandText = "dbo.SP_Update_Payment";
            com3->Parameters->Add("@id_pay", System::Data::SqlDbType::Int)->Value = this->GetPayment()->mIdPay;
            com3->Parameters->Add("@pay_date", System::Data::SqlDbType::Date)->Value = this->GetPayment()->mDatePayment;
            com3->Parameters->Add("@balance_date", System::Data::SqlDbType::Date)->Value = this->GetPayment()->mDatePaymentBalance;
            com3->Parameters->Add("@means", System::Data::SqlDbType::VarChar, 15)->Value = this->GetPayment()->mMeansPayment;
            com3->Parameters->Add("@amount", System::Data::SqlDbType::Int)->Value = this->GetPayment()->mSommePay;
            System::Data::SqlClient::SqlParameter^ param = gcnew System::Data::SqlClient::SqlParameter("@amount", System::Data::SqlDbType::Decimal);
            param->Precision = 15;
            param->Scale = 2;
            com3->Parameters->Add(param)->Value = this->GetPayment()->mSommePay;
            com3->Parameters->Add("@id_cmd", System::Data::SqlDbType::Int)->Value = this->GetIdCmd();
            cmds[pos] = com3;
            tmp2 = tmp2->mNext;
            pos++;
        }
        break;
    case 2:
        cmds = gcnew array<System::Data::SqlClient::SqlCommand^>(2);

        com4 = gcnew System::Data::SqlClient::SqlCommand();
        com5 = gcnew System::Data::SqlClient::SqlCommand();
        com4->CommandType = System::Data::CommandType::StoredProcedure;
        com5->CommandType = System::Data::CommandType::StoredProcedure;

        //commande pour insert dans la table Historique
        com4->CommandText = "dbo.SP_Insert_History";
        com4->Parameters->Add("@id_cmd", System::Data::SqlDbType::Int)->Value = this->GetIdCmd();
        com4->Parameters->Add("@id_people", System::Data::SqlDbType::Int)->Value = this->GetIdCustomer();
        com4->Parameters->Add("@cust_service_num", System::Data::SqlDbType::VarChar, 10)->Value = "0787901242";
        com4->Parameters->Add("@comp_name", System::Data::SqlDbType::VarChar, 30)->Value = "Amogus";
        com4->Parameters->Add("@logo", System::Data::SqlDbType::VarChar, 50)->Value = "E:\Document\CESI\Cours\\2eme_année\POO\Projet\POO_Project\ProjetPOO\Logo.png";
        com4->Parameters->Add("@comp_ad", System::Data::SqlDbType::VarChar, 50)->Value = "85 avenue Chandele, 76000, Rouen";
        com4->Parameters->Add("@ref_cmd", System::Data::SqlDbType::VarChar, 43)->Value = this->GetCmdReference();

        cmds[0] = com4;

        //commande pour insérer la facture
        com5->CommandText = "dbo.SP_Insert_Bill";
        com5->Parameters->Add("@id_people", System::Data::SqlDbType::Int)->Value = this->GetIdCustomer();
        com5->Parameters->Add("@id_cmd", System::Data::SqlDbType::Int)->Value = this->GetIdCmd();

        cmds[1] = com5;

        break;
    default:
        break;
    }

    return cmds;
}

void NS_Composant::MappageCommande::SetChoice(int choice)
{
    this->choice = choice;
}

void NS_Composant::MappageCommande::SetIdCmd(int id)
{
    this->mIdCmd = id;
}

void NS_Composant::MappageCommande::SetEmissionDate(String^ date)
{
    this->mEmissionDate = date;
}

void NS_Composant::MappageCommande::SetCmdReference(String^ ref)
{
    this->mReferenceCmd = ref;
}

void NS_Composant::MappageCommande::SetCmdDiscount(double discount)
{
    this->mDiscount = discount;
}

void NS_Composant::MappageCommande::SetDeliveryDate(String^ date)
{
    this->mDeliveryDate = date;
}

void NS_Composant::MappageCommande::SetIdCustomer(int id)
{
    this->mIdCustomer = id;
}

void NS_Composant::MappageCommande::SetBasket(Basket^ new_art)
{
    this->mListArticle = new_art;
}

void NS_Composant::MappageCommande::SetPayment(Payment^ new_pay)
{
    this->mListPayment = new_pay;
}

int NS_Composant::MappageCommande::GetChoice()
{
    return this->choice;
}

int NS_Composant::MappageCommande::GetIdCmd()
{
    return this->mIdCmd;
}

String^ NS_Composant::MappageCommande::GetEmissionDate()
{
    return this->mEmissionDate;
}

String^ NS_Composant::MappageCommande::GetCmdReference()
{
    return this->mReferenceCmd;
}

double NS_Composant::MappageCommande::GetCmdDiscount()
{
    return this->mDiscount;
}

String^ NS_Composant::MappageCommande::GetDeliveryDate()
{
    return this->mDeliveryDate;
}

int NS_Composant::MappageCommande::GetIdCustomer()
{
    return this->mIdCustomer;
}

NS_Composant::Basket^ NS_Composant::MappageCommande::GetBasket()
{
    return this->mListArticle;
}

NS_Composant::Payment^ NS_Composant::MappageCommande::GetPayment()
{
    return this->mListPayment;
}
