#pragma once
#include "../../Services/h/ServiceCommande.h"
#include "../../Services/h/ServiceCustomer.h"
#include "../../Services/h/ServiceStaff.h"
#include "../../Services/h/ServiceStatistique.h"
#include "../../Services/h/ServiceStock.h"

namespace ProjetPoo {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Description résumée de Display
	/// </summary>
	public ref class Display : public System::Windows::Forms::Form
	{
	public:
		Display(void)
		{
			InitializeComponent();
			//
			//TODO: ajoutez ici le code du constructeur
			//
		}

	protected:
		/// <summary>
		/// Nettoyage des ressources utilisées.
		/// </summary>
		~Display()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TabControl^ tabControl1;
	protected:
	private: System::Windows::Forms::TabPage^ homeDispTab;
	private: System::Windows::Forms::TabPage^ artDispTab;
	private: System::Windows::Forms::TabPage^ cmdDispTab;
	private: System::Windows::Forms::TabPage^ custDispTab;
	private: System::Windows::Forms::TabPage^ staffDispTab;
	private: System::Windows::Forms::Button^ backButDisplay;
	private: System::Windows::Forms::DataGridView^ gridArtDisplay;

	private: System::Windows::Forms::TextBox^ vatBox;

	private: System::Windows::Forms::TextBox^ uhtPriceBox;
	private: System::Windows::Forms::Label^ vatLab;


	private: System::Windows::Forms::Label^ uhtPriceLab;

	private: System::Windows::Forms::TextBox^ descrpBox;

	private: System::Windows::Forms::TextBox^ nameBox;

	private: System::Windows::Forms::TextBox^ refBox;
	private: System::Windows::Forms::Label^ descrpLab;

	private: System::Windows::Forms::Label^ nameLab;

	private: System::Windows::Forms::Label^ refLab;
	private: System::Windows::Forms::TextBox^ catBox;

	private: System::Windows::Forms::Label^ catLab;

	//service
	private: NS_Service::ServiceCommande^ serviceCmd;
	private: NS_Service::ServiceStock^ serviceArt;
	private: NS_Service::ServiceCustomer^ serviceCust;
	private: NS_Service::ServiceStaff^ serviceStaff;
	private: System::Data::DataSet^ data;

	private: int index;
	private: String^ mode;
	private: System::Windows::Forms::Button^ billButDisp;


	private: System::Windows::Forms::TextBox^ delivDateBoxDisp;

	private: System::Windows::Forms::TextBox^ issueDateBoxDisp;

	private: System::Windows::Forms::Label^ delivDateLabDisp;

	private: System::Windows::Forms::Label^ issueDateLabDisp;
	private: System::Windows::Forms::DataGridView^ gridPayDisp;



	private: System::Windows::Forms::DataGridView^ gridCustCmdDisp;

	private: System::Windows::Forms::DataGridView^ gridBasketDisp;
	private: System::Windows::Forms::TextBox^ discBoxDisp;
	private: System::Windows::Forms::TextBox^ refBoxDisp;
	private: System::Windows::Forms::Label^ discLabDisp;
	private: System::Windows::Forms::Label^ refLabDisp;
	private: System::Windows::Forms::TabControl^ tabControl2;
	private: System::Windows::Forms::TabPage^ bAddrTabDisp;
	private: System::Windows::Forms::DataGridView^ gridAddrBillDisp;
	private: System::Windows::Forms::TabPage^ dAddrTabDisp;
	private: System::Windows::Forms::DataGridView^ gridAddrDelivDisp;
	private: System::Windows::Forms::TextBox^ bdateBoxCustDisp;
	private: System::Windows::Forms::TextBox^ fnameBoxCustDisp;
	private: System::Windows::Forms::TextBox^ lnameBoxCustDisp;
	private: System::Windows::Forms::Label^ bdateLabCustDisp;
	private: System::Windows::Forms::Label^ fnameLabCustDisp;
	private: System::Windows::Forms::Label^ lnameLabCustDisp;
	private: System::Windows::Forms::DataGridView^ gridSupDisp;
	private: System::Windows::Forms::DataGridView^ gridAddrStaffDisp;



	private: System::Windows::Forms::TextBox^ hdateStaffBoxDisp;

	private: System::Windows::Forms::TextBox^ mailStaffBoxDisp;

	private: System::Windows::Forms::TextBox^ fnameStaffBoxDisp;

	private: System::Windows::Forms::TextBox^ lnameStaffBoxDisp;
private: System::Windows::Forms::Label^ supStaffLabDisp;


private: System::Windows::Forms::Label^ hdateStaffLabDisp;

private: System::Windows::Forms::Label^ mailStaffLabDisp;

private: System::Windows::Forms::Label^ fnameStaffLabDisp;


private: System::Windows::Forms::Label^ lnameStaffLabDisp;
private: System::Windows::Forms::TextBox^ mailBoxCustDisp;
private: System::Windows::Forms::Label^ mailLabCustDisp;







	private:
		/// <summary>
		/// Variable nécessaire au concepteur.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Méthode requise pour la prise en charge du concepteur - ne modifiez pas
		/// le contenu de cette méthode avec l'éditeur de code.
		/// </summary>
		void InitializeComponent(void)
		{
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->homeDispTab = (gcnew System::Windows::Forms::TabPage());
			this->backButDisplay = (gcnew System::Windows::Forms::Button());
			this->artDispTab = (gcnew System::Windows::Forms::TabPage());
			this->catBox = (gcnew System::Windows::Forms::TextBox());
			this->catLab = (gcnew System::Windows::Forms::Label());
			this->gridArtDisplay = (gcnew System::Windows::Forms::DataGridView());
			this->vatBox = (gcnew System::Windows::Forms::TextBox());
			this->uhtPriceBox = (gcnew System::Windows::Forms::TextBox());
			this->vatLab = (gcnew System::Windows::Forms::Label());
			this->uhtPriceLab = (gcnew System::Windows::Forms::Label());
			this->descrpBox = (gcnew System::Windows::Forms::TextBox());
			this->nameBox = (gcnew System::Windows::Forms::TextBox());
			this->refBox = (gcnew System::Windows::Forms::TextBox());
			this->descrpLab = (gcnew System::Windows::Forms::Label());
			this->nameLab = (gcnew System::Windows::Forms::Label());
			this->refLab = (gcnew System::Windows::Forms::Label());
			this->cmdDispTab = (gcnew System::Windows::Forms::TabPage());
			this->discBoxDisp = (gcnew System::Windows::Forms::TextBox());
			this->refBoxDisp = (gcnew System::Windows::Forms::TextBox());
			this->discLabDisp = (gcnew System::Windows::Forms::Label());
			this->refLabDisp = (gcnew System::Windows::Forms::Label());
			this->billButDisp = (gcnew System::Windows::Forms::Button());
			this->delivDateBoxDisp = (gcnew System::Windows::Forms::TextBox());
			this->issueDateBoxDisp = (gcnew System::Windows::Forms::TextBox());
			this->delivDateLabDisp = (gcnew System::Windows::Forms::Label());
			this->issueDateLabDisp = (gcnew System::Windows::Forms::Label());
			this->gridPayDisp = (gcnew System::Windows::Forms::DataGridView());
			this->gridCustCmdDisp = (gcnew System::Windows::Forms::DataGridView());
			this->gridBasketDisp = (gcnew System::Windows::Forms::DataGridView());
			this->custDispTab = (gcnew System::Windows::Forms::TabPage());
			this->mailBoxCustDisp = (gcnew System::Windows::Forms::TextBox());
			this->mailLabCustDisp = (gcnew System::Windows::Forms::Label());
			this->tabControl2 = (gcnew System::Windows::Forms::TabControl());
			this->bAddrTabDisp = (gcnew System::Windows::Forms::TabPage());
			this->gridAddrBillDisp = (gcnew System::Windows::Forms::DataGridView());
			this->dAddrTabDisp = (gcnew System::Windows::Forms::TabPage());
			this->gridAddrDelivDisp = (gcnew System::Windows::Forms::DataGridView());
			this->bdateBoxCustDisp = (gcnew System::Windows::Forms::TextBox());
			this->fnameBoxCustDisp = (gcnew System::Windows::Forms::TextBox());
			this->lnameBoxCustDisp = (gcnew System::Windows::Forms::TextBox());
			this->bdateLabCustDisp = (gcnew System::Windows::Forms::Label());
			this->fnameLabCustDisp = (gcnew System::Windows::Forms::Label());
			this->lnameLabCustDisp = (gcnew System::Windows::Forms::Label());
			this->staffDispTab = (gcnew System::Windows::Forms::TabPage());
			this->gridSupDisp = (gcnew System::Windows::Forms::DataGridView());
			this->gridAddrStaffDisp = (gcnew System::Windows::Forms::DataGridView());
			this->hdateStaffBoxDisp = (gcnew System::Windows::Forms::TextBox());
			this->mailStaffBoxDisp = (gcnew System::Windows::Forms::TextBox());
			this->fnameStaffBoxDisp = (gcnew System::Windows::Forms::TextBox());
			this->lnameStaffBoxDisp = (gcnew System::Windows::Forms::TextBox());
			this->supStaffLabDisp = (gcnew System::Windows::Forms::Label());
			this->hdateStaffLabDisp = (gcnew System::Windows::Forms::Label());
			this->mailStaffLabDisp = (gcnew System::Windows::Forms::Label());
			this->fnameStaffLabDisp = (gcnew System::Windows::Forms::Label());
			this->lnameStaffLabDisp = (gcnew System::Windows::Forms::Label());
			this->tabControl1->SuspendLayout();
			this->homeDispTab->SuspendLayout();
			this->artDispTab->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->gridArtDisplay))->BeginInit();
			this->cmdDispTab->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->gridPayDisp))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->gridCustCmdDisp))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->gridBasketDisp))->BeginInit();
			this->custDispTab->SuspendLayout();
			this->tabControl2->SuspendLayout();
			this->bAddrTabDisp->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->gridAddrBillDisp))->BeginInit();
			this->dAddrTabDisp->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->gridAddrDelivDisp))->BeginInit();
			this->staffDispTab->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->gridSupDisp))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->gridAddrStaffDisp))->BeginInit();
			this->SuspendLayout();
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->homeDispTab);
			this->tabControl1->Controls->Add(this->artDispTab);
			this->tabControl1->Controls->Add(this->cmdDispTab);
			this->tabControl1->Controls->Add(this->custDispTab);
			this->tabControl1->Controls->Add(this->staffDispTab);
			this->tabControl1->Location = System::Drawing::Point(-5, 0);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(1468, 507);
			this->tabControl1->TabIndex = 0;
			// 
			// homeDispTab
			// 
			this->homeDispTab->Controls->Add(this->backButDisplay);
			this->homeDispTab->Location = System::Drawing::Point(4, 25);
			this->homeDispTab->Name = L"homeDispTab";
			this->homeDispTab->Padding = System::Windows::Forms::Padding(3);
			this->homeDispTab->Size = System::Drawing::Size(1460, 478);
			this->homeDispTab->TabIndex = 0;
			this->homeDispTab->Text = L"Home";
			this->homeDispTab->UseVisualStyleBackColor = true;
			this->homeDispTab->Click += gcnew System::EventHandler(this, &Display::homeDispTab_Click);
			// 
			// backButDisplay
			// 
			this->backButDisplay->Location = System::Drawing::Point(574, 141);
			this->backButDisplay->Name = L"backButDisplay";
			this->backButDisplay->Size = System::Drawing::Size(270, 86);
			this->backButDisplay->TabIndex = 0;
			this->backButDisplay->Text = L"Back";
			this->backButDisplay->UseVisualStyleBackColor = true;
			this->backButDisplay->Click += gcnew System::EventHandler(this, &Display::backButDisplay_Click);
			// 
			// artDispTab
			// 
			this->artDispTab->Controls->Add(this->catBox);
			this->artDispTab->Controls->Add(this->catLab);
			this->artDispTab->Controls->Add(this->gridArtDisplay);
			this->artDispTab->Controls->Add(this->vatBox);
			this->artDispTab->Controls->Add(this->uhtPriceBox);
			this->artDispTab->Controls->Add(this->vatLab);
			this->artDispTab->Controls->Add(this->uhtPriceLab);
			this->artDispTab->Controls->Add(this->descrpBox);
			this->artDispTab->Controls->Add(this->nameBox);
			this->artDispTab->Controls->Add(this->refBox);
			this->artDispTab->Controls->Add(this->descrpLab);
			this->artDispTab->Controls->Add(this->nameLab);
			this->artDispTab->Controls->Add(this->refLab);
			this->artDispTab->Location = System::Drawing::Point(4, 25);
			this->artDispTab->Name = L"artDispTab";
			this->artDispTab->Padding = System::Windows::Forms::Padding(3);
			this->artDispTab->Size = System::Drawing::Size(1460, 478);
			this->artDispTab->TabIndex = 1;
			this->artDispTab->Text = L"Article";
			this->artDispTab->UseVisualStyleBackColor = true;
			// 
			// catBox
			// 
			this->catBox->Location = System::Drawing::Point(66, 389);
			this->catBox->Name = L"catBox";
			this->catBox->ReadOnly = true;
			this->catBox->Size = System::Drawing::Size(106, 22);
			this->catBox->TabIndex = 12;
			// 
			// catLab
			// 
			this->catLab->AutoSize = true;
			this->catLab->Location = System::Drawing::Point(63, 370);
			this->catLab->Name = L"catLab";
			this->catLab->Size = System::Drawing::Size(62, 16);
			this->catLab->TabIndex = 11;
			this->catLab->Text = L"Category";
			// 
			// gridArtDisplay
			// 
			this->gridArtDisplay->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->gridArtDisplay->Location = System::Drawing::Point(760, 30);
			this->gridArtDisplay->MultiSelect = false;
			this->gridArtDisplay->Name = L"gridArtDisplay";
			this->gridArtDisplay->ReadOnly = true;
			this->gridArtDisplay->RowHeadersWidth = 51;
			this->gridArtDisplay->RowTemplate->Height = 24;
			this->gridArtDisplay->Size = System::Drawing::Size(665, 426);
			this->gridArtDisplay->TabIndex = 10;
			// 
			// vatBox
			// 
			this->vatBox->Location = System::Drawing::Point(500, 84);
			this->vatBox->Name = L"vatBox";
			this->vatBox->ReadOnly = true;
			this->vatBox->Size = System::Drawing::Size(70, 22);
			this->vatBox->TabIndex = 9;
			// 
			// uhtPriceBox
			// 
			this->uhtPriceBox->Location = System::Drawing::Point(357, 90);
			this->uhtPriceBox->Name = L"uhtPriceBox";
			this->uhtPriceBox->ReadOnly = true;
			this->uhtPriceBox->Size = System::Drawing::Size(49, 22);
			this->uhtPriceBox->TabIndex = 8;
			// 
			// vatLab
			// 
			this->vatLab->AutoSize = true;
			this->vatLab->Location = System::Drawing::Point(497, 65);
			this->vatLab->Name = L"vatLab";
			this->vatLab->Size = System::Drawing::Size(34, 16);
			this->vatLab->TabIndex = 7;
			this->vatLab->Text = L"VAT";
			// 
			// uhtPriceLab
			// 
			this->uhtPriceLab->AutoSize = true;
			this->uhtPriceLab->Location = System::Drawing::Point(349, 65);
			this->uhtPriceLab->Name = L"uhtPriceLab";
			this->uhtPriceLab->Size = System::Drawing::Size(69, 16);
			this->uhtPriceLab->TabIndex = 6;
			this->uhtPriceLab->Text = L"UHT price";
			// 
			// descrpBox
			// 
			this->descrpBox->Location = System::Drawing::Point(66, 261);
			this->descrpBox->Multiline = true;
			this->descrpBox->Name = L"descrpBox";
			this->descrpBox->ReadOnly = true;
			this->descrpBox->Size = System::Drawing::Size(664, 81);
			this->descrpBox->TabIndex = 5;
			// 
			// nameBox
			// 
			this->nameBox->Location = System::Drawing::Point(55, 192);
			this->nameBox->Name = L"nameBox";
			this->nameBox->ReadOnly = true;
			this->nameBox->Size = System::Drawing::Size(117, 22);
			this->nameBox->TabIndex = 4;
			// 
			// refBox
			// 
			this->refBox->Location = System::Drawing::Point(60, 93);
			this->refBox->Name = L"refBox";
			this->refBox->ReadOnly = true;
			this->refBox->Size = System::Drawing::Size(113, 22);
			this->refBox->TabIndex = 3;
			// 
			// descrpLab
			// 
			this->descrpLab->AutoSize = true;
			this->descrpLab->Location = System::Drawing::Point(58, 232);
			this->descrpLab->Name = L"descrpLab";
			this->descrpLab->Size = System::Drawing::Size(75, 16);
			this->descrpLab->TabIndex = 2;
			this->descrpLab->Text = L"Description";
			// 
			// nameLab
			// 
			this->nameLab->AutoSize = true;
			this->nameLab->Location = System::Drawing::Point(50, 159);
			this->nameLab->Name = L"nameLab";
			this->nameLab->Size = System::Drawing::Size(44, 16);
			this->nameLab->TabIndex = 1;
			this->nameLab->Text = L"Name";
			// 
			// refLab
			// 
			this->refLab->AutoSize = true;
			this->refLab->Location = System::Drawing::Point(55, 61);
			this->refLab->Name = L"refLab";
			this->refLab->Size = System::Drawing::Size(70, 16);
			this->refLab->TabIndex = 0;
			this->refLab->Text = L"Reference";
			// 
			// cmdDispTab
			// 
			this->cmdDispTab->Controls->Add(this->discBoxDisp);
			this->cmdDispTab->Controls->Add(this->refBoxDisp);
			this->cmdDispTab->Controls->Add(this->discLabDisp);
			this->cmdDispTab->Controls->Add(this->refLabDisp);
			this->cmdDispTab->Controls->Add(this->billButDisp);
			this->cmdDispTab->Controls->Add(this->delivDateBoxDisp);
			this->cmdDispTab->Controls->Add(this->issueDateBoxDisp);
			this->cmdDispTab->Controls->Add(this->delivDateLabDisp);
			this->cmdDispTab->Controls->Add(this->issueDateLabDisp);
			this->cmdDispTab->Controls->Add(this->gridPayDisp);
			this->cmdDispTab->Controls->Add(this->gridCustCmdDisp);
			this->cmdDispTab->Controls->Add(this->gridBasketDisp);
			this->cmdDispTab->Location = System::Drawing::Point(4, 25);
			this->cmdDispTab->Name = L"cmdDispTab";
			this->cmdDispTab->Padding = System::Windows::Forms::Padding(3);
			this->cmdDispTab->Size = System::Drawing::Size(1460, 478);
			this->cmdDispTab->TabIndex = 2;
			this->cmdDispTab->Text = L"Commande";
			this->cmdDispTab->UseVisualStyleBackColor = true;
			// 
			// discBoxDisp
			// 
			this->discBoxDisp->Location = System::Drawing::Point(885, 427);
			this->discBoxDisp->Name = L"discBoxDisp";
			this->discBoxDisp->ReadOnly = true;
			this->discBoxDisp->Size = System::Drawing::Size(100, 22);
			this->discBoxDisp->TabIndex = 11;
			// 
			// refBoxDisp
			// 
			this->refBoxDisp->Location = System::Drawing::Point(487, 398);
			this->refBoxDisp->Multiline = true;
			this->refBoxDisp->Name = L"refBoxDisp";
			this->refBoxDisp->ReadOnly = true;
			this->refBoxDisp->Size = System::Drawing::Size(236, 48);
			this->refBoxDisp->TabIndex = 10;
			// 
			// discLabDisp
			// 
			this->discLabDisp->AutoSize = true;
			this->discLabDisp->Location = System::Drawing::Point(813, 430);
			this->discLabDisp->Name = L"discLabDisp";
			this->discLabDisp->Size = System::Drawing::Size(59, 16);
			this->discLabDisp->TabIndex = 9;
			this->discLabDisp->Text = L"Discount";
			// 
			// refLabDisp
			// 
			this->refLabDisp->AutoSize = true;
			this->refLabDisp->Location = System::Drawing::Point(564, 373);
			this->refLabDisp->Name = L"refLabDisp";
			this->refLabDisp->Size = System::Drawing::Size(70, 16);
			this->refLabDisp->TabIndex = 8;
			this->refLabDisp->Text = L"Reference";
			// 
			// billButDisp
			// 
			this->billButDisp->Location = System::Drawing::Point(1183, 404);
			this->billButDisp->Name = L"billButDisp";
			this->billButDisp->Size = System::Drawing::Size(246, 64);
			this->billButDisp->TabIndex = 7;
			this->billButDisp->Text = L"Bill";
			this->billButDisp->UseVisualStyleBackColor = true;
			// 
			// delivDateBoxDisp
			// 
			this->delivDateBoxDisp->Location = System::Drawing::Point(261, 404);
			this->delivDateBoxDisp->Name = L"delivDateBoxDisp";
			this->delivDateBoxDisp->ReadOnly = true;
			this->delivDateBoxDisp->Size = System::Drawing::Size(166, 22);
			this->delivDateBoxDisp->TabIndex = 6;
			// 
			// issueDateBoxDisp
			// 
			this->issueDateBoxDisp->Location = System::Drawing::Point(22, 404);
			this->issueDateBoxDisp->Name = L"issueDateBoxDisp";
			this->issueDateBoxDisp->ReadOnly = true;
			this->issueDateBoxDisp->Size = System::Drawing::Size(202, 22);
			this->issueDateBoxDisp->TabIndex = 5;
			// 
			// delivDateLabDisp
			// 
			this->delivDateLabDisp->AutoSize = true;
			this->delivDateLabDisp->Location = System::Drawing::Point(297, 385);
			this->delivDateLabDisp->Name = L"delivDateLabDisp";
			this->delivDateLabDisp->Size = System::Drawing::Size(89, 16);
			this->delivDateLabDisp->TabIndex = 4;
			this->delivDateLabDisp->Text = L"Delivery Date";
			// 
			// issueDateLabDisp
			// 
			this->issueDateLabDisp->AutoSize = true;
			this->issueDateLabDisp->Location = System::Drawing::Point(73, 385);
			this->issueDateLabDisp->Name = L"issueDateLabDisp";
			this->issueDateLabDisp->Size = System::Drawing::Size(94, 16);
			this->issueDateLabDisp->TabIndex = 3;
			this->issueDateLabDisp->Text = L"Emission Date";
			// 
			// gridPayDisp
			// 
			this->gridPayDisp->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->gridPayDisp->Location = System::Drawing::Point(780, 261);
			this->gridPayDisp->MultiSelect = false;
			this->gridPayDisp->Name = L"gridPayDisp";
			this->gridPayDisp->ReadOnly = true;
			this->gridPayDisp->RowHeadersWidth = 51;
			this->gridPayDisp->RowTemplate->Height = 24;
			this->gridPayDisp->Size = System::Drawing::Size(649, 128);
			this->gridPayDisp->TabIndex = 2;
			// 
			// gridCustCmdDisp
			// 
			this->gridCustCmdDisp->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->gridCustCmdDisp->Location = System::Drawing::Point(780, 32);
			this->gridCustCmdDisp->MultiSelect = false;
			this->gridCustCmdDisp->Name = L"gridCustCmdDisp";
			this->gridCustCmdDisp->ReadOnly = true;
			this->gridCustCmdDisp->RowHeadersWidth = 51;
			this->gridCustCmdDisp->RowTemplate->Height = 24;
			this->gridCustCmdDisp->Size = System::Drawing::Size(649, 186);
			this->gridCustCmdDisp->TabIndex = 1;
			// 
			// gridBasketDisp
			// 
			this->gridBasketDisp->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->gridBasketDisp->Location = System::Drawing::Point(22, 21);
			this->gridBasketDisp->MultiSelect = false;
			this->gridBasketDisp->Name = L"gridBasketDisp";
			this->gridBasketDisp->ReadOnly = true;
			this->gridBasketDisp->RowHeadersWidth = 51;
			this->gridBasketDisp->RowTemplate->Height = 24;
			this->gridBasketDisp->Size = System::Drawing::Size(701, 323);
			this->gridBasketDisp->TabIndex = 0;
			// 
			// custDispTab
			// 
			this->custDispTab->Controls->Add(this->mailBoxCustDisp);
			this->custDispTab->Controls->Add(this->mailLabCustDisp);
			this->custDispTab->Controls->Add(this->tabControl2);
			this->custDispTab->Controls->Add(this->bdateBoxCustDisp);
			this->custDispTab->Controls->Add(this->fnameBoxCustDisp);
			this->custDispTab->Controls->Add(this->lnameBoxCustDisp);
			this->custDispTab->Controls->Add(this->bdateLabCustDisp);
			this->custDispTab->Controls->Add(this->fnameLabCustDisp);
			this->custDispTab->Controls->Add(this->lnameLabCustDisp);
			this->custDispTab->Location = System::Drawing::Point(4, 25);
			this->custDispTab->Name = L"custDispTab";
			this->custDispTab->Padding = System::Windows::Forms::Padding(3);
			this->custDispTab->Size = System::Drawing::Size(1460, 478);
			this->custDispTab->TabIndex = 3;
			this->custDispTab->Text = L"Customer";
			this->custDispTab->UseVisualStyleBackColor = true;
			// 
			// mailBoxCustDisp
			// 
			this->mailBoxCustDisp->Location = System::Drawing::Point(161, 357);
			this->mailBoxCustDisp->Name = L"mailBoxCustDisp";
			this->mailBoxCustDisp->ReadOnly = true;
			this->mailBoxCustDisp->Size = System::Drawing::Size(171, 22);
			this->mailBoxCustDisp->TabIndex = 8;
			// 
			// mailLabCustDisp
			// 
			this->mailLabCustDisp->AutoSize = true;
			this->mailLabCustDisp->Location = System::Drawing::Point(167, 338);
			this->mailLabCustDisp->Name = L"mailLabCustDisp";
			this->mailLabCustDisp->Size = System::Drawing::Size(41, 16);
			this->mailLabCustDisp->TabIndex = 7;
			this->mailLabCustDisp->Text = L"Email";
			// 
			// tabControl2
			// 
			this->tabControl2->Controls->Add(this->bAddrTabDisp);
			this->tabControl2->Controls->Add(this->dAddrTabDisp);
			this->tabControl2->Location = System::Drawing::Point(571, 6);
			this->tabControl2->Name = L"tabControl2";
			this->tabControl2->SelectedIndex = 0;
			this->tabControl2->Size = System::Drawing::Size(893, 478);
			this->tabControl2->TabIndex = 6;
			// 
			// bAddrTabDisp
			// 
			this->bAddrTabDisp->Controls->Add(this->gridAddrBillDisp);
			this->bAddrTabDisp->Location = System::Drawing::Point(4, 25);
			this->bAddrTabDisp->Name = L"bAddrTabDisp";
			this->bAddrTabDisp->Padding = System::Windows::Forms::Padding(3);
			this->bAddrTabDisp->Size = System::Drawing::Size(885, 449);
			this->bAddrTabDisp->TabIndex = 0;
			this->bAddrTabDisp->Text = L"Bill Address";
			this->bAddrTabDisp->UseVisualStyleBackColor = true;
			// 
			// gridAddrBillDisp
			// 
			this->gridAddrBillDisp->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->gridAddrBillDisp->Location = System::Drawing::Point(0, 0);
			this->gridAddrBillDisp->MultiSelect = false;
			this->gridAddrBillDisp->Name = L"gridAddrBillDisp";
			this->gridAddrBillDisp->ReadOnly = true;
			this->gridAddrBillDisp->RowHeadersWidth = 51;
			this->gridAddrBillDisp->RowTemplate->Height = 24;
			this->gridAddrBillDisp->Size = System::Drawing::Size(885, 447);
			this->gridAddrBillDisp->TabIndex = 0;
			// 
			// dAddrTabDisp
			// 
			this->dAddrTabDisp->Controls->Add(this->gridAddrDelivDisp);
			this->dAddrTabDisp->Location = System::Drawing::Point(4, 25);
			this->dAddrTabDisp->Name = L"dAddrTabDisp";
			this->dAddrTabDisp->Padding = System::Windows::Forms::Padding(3);
			this->dAddrTabDisp->Size = System::Drawing::Size(885, 449);
			this->dAddrTabDisp->TabIndex = 1;
			this->dAddrTabDisp->Text = L"Delivery Address";
			this->dAddrTabDisp->UseVisualStyleBackColor = true;
			// 
			// gridAddrDelivDisp
			// 
			this->gridAddrDelivDisp->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->gridAddrDelivDisp->Location = System::Drawing::Point(0, 0);
			this->gridAddrDelivDisp->MultiSelect = false;
			this->gridAddrDelivDisp->Name = L"gridAddrDelivDisp";
			this->gridAddrDelivDisp->ReadOnly = true;
			this->gridAddrDelivDisp->RowHeadersWidth = 51;
			this->gridAddrDelivDisp->RowTemplate->Height = 24;
			this->gridAddrDelivDisp->Size = System::Drawing::Size(885, 447);
			this->gridAddrDelivDisp->TabIndex = 0;
			// 
			// bdateBoxCustDisp
			// 
			this->bdateBoxCustDisp->Location = System::Drawing::Point(161, 280);
			this->bdateBoxCustDisp->Name = L"bdateBoxCustDisp";
			this->bdateBoxCustDisp->ReadOnly = true;
			this->bdateBoxCustDisp->Size = System::Drawing::Size(171, 22);
			this->bdateBoxCustDisp->TabIndex = 5;
			// 
			// fnameBoxCustDisp
			// 
			this->fnameBoxCustDisp->Location = System::Drawing::Point(161, 224);
			this->fnameBoxCustDisp->Name = L"fnameBoxCustDisp";
			this->fnameBoxCustDisp->ReadOnly = true;
			this->fnameBoxCustDisp->Size = System::Drawing::Size(171, 22);
			this->fnameBoxCustDisp->TabIndex = 4;
			// 
			// lnameBoxCustDisp
			// 
			this->lnameBoxCustDisp->Location = System::Drawing::Point(161, 164);
			this->lnameBoxCustDisp->Name = L"lnameBoxCustDisp";
			this->lnameBoxCustDisp->ReadOnly = true;
			this->lnameBoxCustDisp->Size = System::Drawing::Size(171, 22);
			this->lnameBoxCustDisp->TabIndex = 3;
			// 
			// bdateLabCustDisp
			// 
			this->bdateLabCustDisp->AutoSize = true;
			this->bdateLabCustDisp->Location = System::Drawing::Point(167, 261);
			this->bdateLabCustDisp->Name = L"bdateLabCustDisp";
			this->bdateLabCustDisp->Size = System::Drawing::Size(60, 16);
			this->bdateLabCustDisp->TabIndex = 2;
			this->bdateLabCustDisp->Text = L"Birthdate";
			// 
			// fnameLabCustDisp
			// 
			this->fnameLabCustDisp->AutoSize = true;
			this->fnameLabCustDisp->Location = System::Drawing::Point(167, 205);
			this->fnameLabCustDisp->Name = L"fnameLabCustDisp";
			this->fnameLabCustDisp->Size = System::Drawing::Size(66, 16);
			this->fnameLabCustDisp->TabIndex = 1;
			this->fnameLabCustDisp->Text = L"Firstname";
			// 
			// lnameLabCustDisp
			// 
			this->lnameLabCustDisp->AutoSize = true;
			this->lnameLabCustDisp->Location = System::Drawing::Point(167, 145);
			this->lnameLabCustDisp->Name = L"lnameLabCustDisp";
			this->lnameLabCustDisp->Size = System::Drawing::Size(66, 16);
			this->lnameLabCustDisp->TabIndex = 0;
			this->lnameLabCustDisp->Text = L"Lastname";
			// 
			// staffDispTab
			// 
			this->staffDispTab->Controls->Add(this->gridSupDisp);
			this->staffDispTab->Controls->Add(this->gridAddrStaffDisp);
			this->staffDispTab->Controls->Add(this->hdateStaffBoxDisp);
			this->staffDispTab->Controls->Add(this->mailStaffBoxDisp);
			this->staffDispTab->Controls->Add(this->fnameStaffBoxDisp);
			this->staffDispTab->Controls->Add(this->lnameStaffBoxDisp);
			this->staffDispTab->Controls->Add(this->supStaffLabDisp);
			this->staffDispTab->Controls->Add(this->hdateStaffLabDisp);
			this->staffDispTab->Controls->Add(this->mailStaffLabDisp);
			this->staffDispTab->Controls->Add(this->fnameStaffLabDisp);
			this->staffDispTab->Controls->Add(this->lnameStaffLabDisp);
			this->staffDispTab->Location = System::Drawing::Point(4, 25);
			this->staffDispTab->Name = L"staffDispTab";
			this->staffDispTab->Padding = System::Windows::Forms::Padding(3);
			this->staffDispTab->Size = System::Drawing::Size(1460, 478);
			this->staffDispTab->TabIndex = 4;
			this->staffDispTab->Text = L"Staff";
			this->staffDispTab->UseVisualStyleBackColor = true;
			this->staffDispTab->Click += gcnew System::EventHandler(this, &Display::staffDispTab_Click);
			// 
			// gridSupDisp
			// 
			this->gridSupDisp->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->gridSupDisp->Location = System::Drawing::Point(798, 341);
			this->gridSupDisp->Name = L"gridSupDisp";
			this->gridSupDisp->RowHeadersWidth = 51;
			this->gridSupDisp->RowTemplate->Height = 24;
			this->gridSupDisp->Size = System::Drawing::Size(636, 95);
			this->gridSupDisp->TabIndex = 10;
			// 
			// gridAddrStaffDisp
			// 
			this->gridAddrStaffDisp->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->gridAddrStaffDisp->Location = System::Drawing::Point(657, 21);
			this->gridAddrStaffDisp->Name = L"gridAddrStaffDisp";
			this->gridAddrStaffDisp->RowHeadersWidth = 51;
			this->gridAddrStaffDisp->RowTemplate->Height = 24;
			this->gridAddrStaffDisp->Size = System::Drawing::Size(777, 275);
			this->gridAddrStaffDisp->TabIndex = 9;
			// 
			// hdateStaffBoxDisp
			// 
			this->hdateStaffBoxDisp->Location = System::Drawing::Point(187, 341);
			this->hdateStaffBoxDisp->Name = L"hdateStaffBoxDisp";
			this->hdateStaffBoxDisp->ReadOnly = true;
			this->hdateStaffBoxDisp->Size = System::Drawing::Size(228, 22);
			this->hdateStaffBoxDisp->TabIndex = 8;
			// 
			// mailStaffBoxDisp
			// 
			this->mailStaffBoxDisp->Location = System::Drawing::Point(187, 254);
			this->mailStaffBoxDisp->Name = L"mailStaffBoxDisp";
			this->mailStaffBoxDisp->ReadOnly = true;
			this->mailStaffBoxDisp->Size = System::Drawing::Size(228, 22);
			this->mailStaffBoxDisp->TabIndex = 7;
			// 
			// fnameStaffBoxDisp
			// 
			this->fnameStaffBoxDisp->Location = System::Drawing::Point(187, 174);
			this->fnameStaffBoxDisp->Name = L"fnameStaffBoxDisp";
			this->fnameStaffBoxDisp->ReadOnly = true;
			this->fnameStaffBoxDisp->Size = System::Drawing::Size(147, 22);
			this->fnameStaffBoxDisp->TabIndex = 6;
			// 
			// lnameStaffBoxDisp
			// 
			this->lnameStaffBoxDisp->Location = System::Drawing::Point(187, 99);
			this->lnameStaffBoxDisp->Name = L"lnameStaffBoxDisp";
			this->lnameStaffBoxDisp->ReadOnly = true;
			this->lnameStaffBoxDisp->Size = System::Drawing::Size(147, 22);
			this->lnameStaffBoxDisp->TabIndex = 5;
			// 
			// supStaffLabDisp
			// 
			this->supStaffLabDisp->AutoSize = true;
			this->supStaffLabDisp->Location = System::Drawing::Point(701, 375);
			this->supStaffLabDisp->Name = L"supStaffLabDisp";
			this->supStaffLabDisp->Size = System::Drawing::Size(58, 16);
			this->supStaffLabDisp->TabIndex = 4;
			this->supStaffLabDisp->Text = L"Superior";
			// 
			// hdateStaffLabDisp
			// 
			this->hdateStaffLabDisp->AutoSize = true;
			this->hdateStaffLabDisp->Location = System::Drawing::Point(190, 322);
			this->hdateStaffLabDisp->Name = L"hdateStaffLabDisp";
			this->hdateStaffLabDisp->Size = System::Drawing::Size(74, 16);
			this->hdateStaffLabDisp->TabIndex = 3;
			this->hdateStaffLabDisp->Text = L"Hiring Date";
			// 
			// mailStaffLabDisp
			// 
			this->mailStaffLabDisp->AutoSize = true;
			this->mailStaffLabDisp->Location = System::Drawing::Point(190, 235);
			this->mailStaffLabDisp->Name = L"mailStaffLabDisp";
			this->mailStaffLabDisp->Size = System::Drawing::Size(41, 16);
			this->mailStaffLabDisp->TabIndex = 2;
			this->mailStaffLabDisp->Text = L"Email";
			// 
			// fnameStaffLabDisp
			// 
			this->fnameStaffLabDisp->AutoSize = true;
			this->fnameStaffLabDisp->Location = System::Drawing::Point(190, 155);
			this->fnameStaffLabDisp->Name = L"fnameStaffLabDisp";
			this->fnameStaffLabDisp->Size = System::Drawing::Size(66, 16);
			this->fnameStaffLabDisp->TabIndex = 1;
			this->fnameStaffLabDisp->Text = L"Firstname";
			// 
			// lnameStaffLabDisp
			// 
			this->lnameStaffLabDisp->AutoSize = true;
			this->lnameStaffLabDisp->Location = System::Drawing::Point(190, 76);
			this->lnameStaffLabDisp->Name = L"lnameStaffLabDisp";
			this->lnameStaffLabDisp->Size = System::Drawing::Size(66, 16);
			this->lnameStaffLabDisp->TabIndex = 0;
			this->lnameStaffLabDisp->Text = L"Lastname";
			// 
			// Display
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1465, 507);
			this->Controls->Add(this->tabControl1);
			this->Name = L"Display";
			this->Text = L"Display";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &Display::Display_Closed);
			this->Load += gcnew System::EventHandler(this, &Display::Display_Load);
			this->tabControl1->ResumeLayout(false);
			this->homeDispTab->ResumeLayout(false);
			this->artDispTab->ResumeLayout(false);
			this->artDispTab->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->gridArtDisplay))->EndInit();
			this->cmdDispTab->ResumeLayout(false);
			this->cmdDispTab->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->gridPayDisp))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->gridCustCmdDisp))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->gridBasketDisp))->EndInit();
			this->custDispTab->ResumeLayout(false);
			this->custDispTab->PerformLayout();
			this->tabControl2->ResumeLayout(false);
			this->bAddrTabDisp->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->gridAddrBillDisp))->EndInit();
			this->dAddrTabDisp->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->gridAddrDelivDisp))->EndInit();
			this->staffDispTab->ResumeLayout(false);
			this->staffDispTab->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->gridSupDisp))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->gridAddrStaffDisp))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void staffDispTab_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void Display_Closed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e) {
		this->Hide();
	}
	public: System::Windows::Forms::TabControl^ GetTabControl()
	{
		return this->tabControl1;
	}
	private: System::Void homeDispTab_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void backButDisplay_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Hide();
	}
	private: System::Void Display_Load(System::Object^ sender, System::EventArgs^ e) {
		this->serviceArt = gcnew NS_Service::ServiceStock();
		this->serviceCmd = gcnew NS_Service::ServiceCommande();
		this->serviceStaff = gcnew NS_Service::ServiceStaff();
		this->serviceCust = gcnew NS_Service::ServiceCustomer();
		this->data = gcnew DataSet();

		if (this->mode == "Customer")
		{
			this->loadDataCust();
		}
		else if (this->mode == "Staff")
		{
			this->loadDataStaff();
		}
		else if (this->mode == "Article")
		{
			this->loadDataArt();
		}
		else if (this->mode == "Order")
		{
			this->loadDataCmd();
		}
		

	}
	
	private: void loadDataArt() {
		this->data->Clear();
		this->gridArtDisplay->Refresh();
		array<String^>^ tableArt = gcnew array<String^>(2);
		tableArt[0] = "listeArt";
		tableArt[1] = "listeStock";
		this->data = this->serviceArt->Display(this->index, tableArt);
		this->gridArtDisplay->DataSource = this->data;
		this->gridArtDisplay->DataMember = tableArt[1];


		this->refBox->Text = this->data->Tables[tableArt[0]]->Rows[0]->ItemArray[0]->ToString();
		this->nameBox->Text = this->data->Tables[tableArt[0]]->Rows[0]->ItemArray[1]->ToString();
		this->descrpBox->Text = this->data->Tables[tableArt[0]]->Rows[0]->ItemArray[2]->ToString();
		this->uhtPriceBox->Text = this->data->Tables[tableArt[0]]->Rows[0]->ItemArray[3]->ToString() + " $";
		this->vatBox->Text = this->data->Tables[tableArt[0]]->Rows[0]->ItemArray[4]->ToString();
		this->catBox->Text = this->data->Tables[tableArt[0]]->Rows[0]->ItemArray[5]->ToString();

	}
	private: void loadDataCmd() {
		this->data->Clear();
		this->gridCustCmdDisp->Refresh();
		this->gridBasketDisp->Refresh();
		this->gridPayDisp->Refresh();
		array<String^>^ tableCmd = gcnew array<String^>(3);
		array<String^>^ tableCust = gcnew array<String^>(1);

		tableCmd[0] = "cmd";
		tableCmd[1] = "basket";
		tableCmd[2] = "pay";

		tableCust[0] = "cust";

		this->data = this->serviceCmd->Display(this->index, tableCmd);
		this->data->Merge(this->serviceCust->Display(Convert::ToInt32(this->data->Tables[tableCmd[0]]->Rows[0]->ItemArray[4]), tableCust));

		this->gridCustCmdDisp->DataSource = this->data;
		this->gridCustCmdDisp->DataMember = tableCust[0];
		this->gridCustCmdDisp->Columns[0]->Visible = false;

		this->gridBasketDisp->DataSource = this->data;
		this->gridBasketDisp->DataMember = tableCmd[1];

		this->gridPayDisp->DataSource = this->data;
		this->gridPayDisp->DataMember = tableCmd[2];

		this->refBoxDisp->Text = this->data->Tables[tableCmd[0]]->Rows[0]->ItemArray[0]->ToString();
		this->delivDateBoxDisp->Text = this->getDate(this->data->Tables[tableCmd[0]]->Rows[0]->ItemArray[1]->ToString());
		this->issueDateBoxDisp->Text = this->getDate(this->data->Tables[tableCmd[0]]->Rows[0]->ItemArray[2]->ToString());
		this->discBoxDisp->Text = this->data->Tables[tableCmd[0]]->Rows[0]->ItemArray[3]->ToString();

	}

	private: void loadDataCust() {
		this->data->Clear();
		this->gridAddrDelivDisp->Refresh();
		array<String^>^ tableCust = gcnew array<String^>(1);
		array<String^>^ tableAddr = gcnew array<String^>(1);
		array<String^>^ tmp_del = gcnew array<String^>(1);
		array<String^>^ tmp_bill = gcnew array<String^>(1);

		tableCust[0] = "cust";
		tableAddr[0] = "addr";
		tmp_del[0] = "address_del";
		tmp_bill[0] = "address_bill";

		this->data = this->serviceCust->Display(this->index, tableCust);
		this->data->Merge(this->serviceCust->DisplayAddr(this->index, tableAddr, tmp_del, tmp_bill));

		if (data->Tables[tmp_bill[0]] != nullptr)
		{
			this->gridAddrBillDisp->DataSource = this->data;
			this->gridAddrBillDisp->DataMember = tmp_bill[0];
		}
		
		if (data->Tables[tmp_del[0]] != nullptr)
		{
			this->gridAddrDelivDisp->DataSource = this->data;
			this->gridAddrDelivDisp->DataMember = tmp_del[0];
		}

		this->fnameBoxCustDisp->Text = this->data->Tables[tableCust[0]]->Rows[0]->ItemArray[1]->ToString();
		this->lnameBoxCustDisp->Text = this->data->Tables[tableCust[0]]->Rows[0]->ItemArray[2]->ToString();
		this->mailBoxCustDisp->Text = this->data->Tables[tableCust[0]]->Rows[0]->ItemArray[3]->ToString();
		this->bdateBoxCustDisp->Text = this->getDate(this->data->Tables[tableCust[0]]->Rows[0]->ItemArray[4]->ToString());
	}
	private: String^ getDate(String^ datetime) {
		array<String^>^ tmp = datetime->Split(' ');
		return tmp[0];
	}
	private: void loadDataStaff() {
		this->data->Clear();
		this->gridAddrStaffDisp->Refresh();
		array<String^>^ tableStaff = gcnew array<String^>(1);
		array<String^>^ tableAddr = gcnew array<String^>(1); 
		array<String^>^ tableSup = gcnew array<String^>(1);
		tableStaff[0] = "staff";
		tableAddr[0] = "address";
		tableSup[0] = "sup";

		this->data = this->serviceStaff->Display(this->index, tableStaff);
		
		this->data->Merge(this->serviceStaff->DisplayAddr(Convert::ToInt32(this->data->Tables[tableStaff[0]]->Rows[0]->ItemArray[5]), tableAddr));

		if (data->Tables[tableAddr[0]] != nullptr)
		{
			this->gridAddrStaffDisp->DataSource = this->data;
			this->gridAddrStaffDisp->DataMember = tableAddr[0];
		}
	
		
		if(!DBNull::Value->Equals(this->data->Tables[tableStaff[0]]->Rows[0]->ItemArray[4]))
		{
			this->data->Merge(this->serviceStaff->Display(Convert::ToInt32(this->data->Tables[tableStaff[0]]->Rows[0]->ItemArray[4]), tableSup));
		}

		if (data->Tables[tableSup[0]] != nullptr)
		{
			this->gridSupDisp->DataSource = this->data;
			this->gridSupDisp->DataMember = tableSup[0];
			this->gridSupDisp->Columns[4]->Visible = false;
			this->gridSupDisp->Columns[5]->Visible = false;
		}


		this->fnameStaffBoxDisp->Text = this->data->Tables[tableStaff[0]]->Rows[0]->ItemArray[0]->ToString();
		this->lnameStaffBoxDisp->Text = this->data->Tables[tableStaff[0]]->Rows[0]->ItemArray[1]->ToString();
		this->mailStaffBoxDisp->Text = this->data->Tables[tableStaff[0]]->Rows[0]->ItemArray[2]->ToString();
		this->hdateStaffBoxDisp->Text = this->getDate(this->data->Tables[tableStaff[0]]->Rows[0]->ItemArray[3]->ToString());
	}
	public: void SetIndex(int _index)
	{
		this->index = _index;
	}
	public: void SetMode(String^ _mode) {
		this->mode = _mode;
	}
};
}
