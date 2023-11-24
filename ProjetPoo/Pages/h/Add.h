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
	/// Description résumée de Add
	/// </summary>
	public ref class Add : public System::Windows::Forms::Form
	{
	public:
		Add(void)
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
		~Add()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TabControl^ tabControl1;
	private: System::Windows::Forms::TabPage^ tabHomeAdd;
	private: System::Windows::Forms::TabPage^ tabArtAdd;
	protected:


	private: System::Windows::Forms::Button^ butBackAdd;
	private: System::Windows::Forms::TabPage^ tabCmdAdd;
	private: System::Windows::Forms::TabPage^ tabCustAdd;
	private: System::Windows::Forms::TabPage^ tabStaffAdd;
	private: System::Windows::Forms::Button^ addCustButAdd;

	private: System::Windows::Forms::TabControl^ tabControl2;
	private: System::Windows::Forms::TabPage^ delAddrTabAdd;
	private: System::Windows::Forms::TabPage^ bAddrTabAdd;
	private: System::Windows::Forms::MonthCalendar^ calenCustAdd;



	private: System::Windows::Forms::TextBox^ lnameCustBoxAdd;

	private: System::Windows::Forms::TextBox^ fnameCustBoxAdd;
	private: System::Windows::Forms::Label^ bdateCustLabAdd;




	private: System::Windows::Forms::Label^ lnameCustLabAdd;

	private: System::Windows::Forms::Label^ fnameCustLabAdd;



	//service
	private: NS_Service::ServiceCommande^ serviceCmd;
	private: NS_Service::ServiceStock^ serviceArt;
	private: NS_Service::ServiceCustomer^ serviceCust;
	private: NS_Service::ServiceStaff^ serviceStaff;
	private: System::Data::DataSet^ data;

	private: int index;
	private: String^ mode;
	private: int selectCust;
	private: bool samecust = false;
	private: String^ fname;
	private: String^ lname;
	private: System::Windows::Forms::DataGridView^ gridDelAddrAdd;
	private: System::Windows::Forms::DataGridView^ gridBillAddrAdd;
	private: System::Windows::Forms::TextBox^ mailCustBoxAdd;
	private: System::Windows::Forms::Label^ mailLabCustAdd;







	private: System::Windows::Forms::DataGridViewTextBoxColumn^ numAddrDelCustAdd;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ compAddrDelCustAdd;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ streetAddrDelCustAdd;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ pcodeDelCustAdd;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ numAddrBillCustAdd;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ complAddrBillCustAdd;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ streetAddrBillCustAdd;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ pcodeBillCustAdd;
	private: System::Windows::Forms::Button^ valStaffButAdd;
	private: System::Windows::Forms::Label^ addrStaffLabAdd;
	private: System::Windows::Forms::DataGridView^ gridAddrStaffAdd;
	private: System::Windows::Forms::ComboBox^ supStaffBoxAdd;
	private: System::Windows::Forms::MonthCalendar^ hdateStaffCalenAdd;
	private: System::Windows::Forms::TextBox^ pwdStaffBoxAdd;
	private: System::Windows::Forms::TextBox^ mailStaffBoxAdd;
	private: System::Windows::Forms::TextBox^ lnameStaffBoxAdd;
	private: System::Windows::Forms::TextBox^ fnameStaffBoxAdd;
	private: System::Windows::Forms::Label^ supStaffLabAdd;
	private: System::Windows::Forms::Label^ hdateStaffLabAdd;
	private: System::Windows::Forms::Label^ pwdStaffLabAdd;
	private: System::Windows::Forms::Label^ mailStaffLabAdd;
	private: System::Windows::Forms::Label^ lnameStaffLabAdd;
	private: System::Windows::Forms::Label^ fnameStaffLabAdd;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ NumAddrStaffTabAdd;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ CompAddrStaffTabAdd;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ StreetAddrStaffTabAdd;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ PCodeAddrStaffTabAdd;
private: System::Windows::Forms::Button^ valArtButAdd;

private: System::Windows::Forms::DataGridView^ gridStockAdd;

private: System::Windows::Forms::TextBox^ desrcpArtBoxAdd;

private: System::Windows::Forms::TextBox^ vatArtBoxAdd;

private: System::Windows::Forms::TextBox^ uhtArtBoxAdd;

private: System::Windows::Forms::TextBox^ nameArtBoxAdd;

private: System::Windows::Forms::TextBox^ refArtBoxAdd;
private: System::Windows::Forms::Label^ catArtLabAdd;


private: System::Windows::Forms::Label^ descrpArtLabAdd;

private: System::Windows::Forms::Label^ vatArtLabAdd;

private: System::Windows::Forms::Label^ uhtArtLabAdd;

private: System::Windows::Forms::Label^ nameArtLabAdd;

private: System::Windows::Forms::Label^ refArtLabAdd;
private: System::Windows::Forms::ComboBox^ catArtBoxAdd;
private: System::Windows::Forms::Label^ stockArtLabAdd;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ RefArtAdd;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ ThreshArtAdd;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ CostArtAdd;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ QteArtAdd;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ ColArtAdd;
private: System::Windows::Forms::TabControl^ tabControl3;
private: System::Windows::Forms::TabPage^ cmdTabAdd;

private: System::Windows::Forms::Button^ addArtCmdButAdd;
private: System::Windows::Forms::Button^ valCmdButAdd;



private: System::Windows::Forms::Label^ rqteCmdLabAdd;

private: System::Windows::Forms::Label^ qteCmdLabAdd;

private: System::Windows::Forms::Label^ ddateCmdLabAdd;
private: System::Windows::Forms::Label^ idateCmdLabAdd;
private: System::Windows::Forms::DataGridView^ gridDispAllStockCmdAdd;



private: System::Windows::Forms::DataGridView^ gridDispCustCmdAdd;

private: System::Windows::Forms::DataGridView^ gridDispStockCmdAdd;

private: System::Windows::Forms::TabPage^ payCmdTabAdd;
private: System::Windows::Forms::Label^ payCmdLabAdd;
private: System::Windows::Forms::DataGridView^ gridPayCmdAdd;



private: System::Windows::Forms::MonthCalendar^ calenDelDateCmdAdd;
private: System::Windows::Forms::MonthCalendar^ calenIDateCmdAdd;


private: System::Windows::Forms::TextBox^ rqteCmdBoxAdd;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ PayDatePayCmdAdd;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ PayBDatePayCmdAdd;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ MeansPayCmdAdd;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ AmountPayCmdAdd;
private: System::Windows::Forms::TextBox^ discCmdBoxAdd;
private: System::Windows::Forms::Label^ discCmdLabAdd;

private: System::Windows::Forms::TextBox^ qteCmdBoxAdd;



















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
			this->tabHomeAdd = (gcnew System::Windows::Forms::TabPage());
			this->butBackAdd = (gcnew System::Windows::Forms::Button());
			this->tabArtAdd = (gcnew System::Windows::Forms::TabPage());
			this->stockArtLabAdd = (gcnew System::Windows::Forms::Label());
			this->catArtBoxAdd = (gcnew System::Windows::Forms::ComboBox());
			this->valArtButAdd = (gcnew System::Windows::Forms::Button());
			this->gridStockAdd = (gcnew System::Windows::Forms::DataGridView());
			this->RefArtAdd = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->ThreshArtAdd = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->CostArtAdd = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->QteArtAdd = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->ColArtAdd = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->desrcpArtBoxAdd = (gcnew System::Windows::Forms::TextBox());
			this->vatArtBoxAdd = (gcnew System::Windows::Forms::TextBox());
			this->uhtArtBoxAdd = (gcnew System::Windows::Forms::TextBox());
			this->nameArtBoxAdd = (gcnew System::Windows::Forms::TextBox());
			this->refArtBoxAdd = (gcnew System::Windows::Forms::TextBox());
			this->catArtLabAdd = (gcnew System::Windows::Forms::Label());
			this->descrpArtLabAdd = (gcnew System::Windows::Forms::Label());
			this->vatArtLabAdd = (gcnew System::Windows::Forms::Label());
			this->uhtArtLabAdd = (gcnew System::Windows::Forms::Label());
			this->nameArtLabAdd = (gcnew System::Windows::Forms::Label());
			this->refArtLabAdd = (gcnew System::Windows::Forms::Label());
			this->tabCmdAdd = (gcnew System::Windows::Forms::TabPage());
			this->tabControl3 = (gcnew System::Windows::Forms::TabControl());
			this->cmdTabAdd = (gcnew System::Windows::Forms::TabPage());
			this->calenDelDateCmdAdd = (gcnew System::Windows::Forms::MonthCalendar());
			this->calenIDateCmdAdd = (gcnew System::Windows::Forms::MonthCalendar());
			this->rqteCmdBoxAdd = (gcnew System::Windows::Forms::TextBox());
			this->qteCmdBoxAdd = (gcnew System::Windows::Forms::TextBox());
			this->addArtCmdButAdd = (gcnew System::Windows::Forms::Button());
			this->valCmdButAdd = (gcnew System::Windows::Forms::Button());
			this->rqteCmdLabAdd = (gcnew System::Windows::Forms::Label());
			this->qteCmdLabAdd = (gcnew System::Windows::Forms::Label());
			this->ddateCmdLabAdd = (gcnew System::Windows::Forms::Label());
			this->idateCmdLabAdd = (gcnew System::Windows::Forms::Label());
			this->gridDispAllStockCmdAdd = (gcnew System::Windows::Forms::DataGridView());
			this->gridDispCustCmdAdd = (gcnew System::Windows::Forms::DataGridView());
			this->gridDispStockCmdAdd = (gcnew System::Windows::Forms::DataGridView());
			this->payCmdTabAdd = (gcnew System::Windows::Forms::TabPage());
			this->payCmdLabAdd = (gcnew System::Windows::Forms::Label());
			this->gridPayCmdAdd = (gcnew System::Windows::Forms::DataGridView());
			this->PayDatePayCmdAdd = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->PayBDatePayCmdAdd = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->MeansPayCmdAdd = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->AmountPayCmdAdd = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->tabCustAdd = (gcnew System::Windows::Forms::TabPage());
			this->mailCustBoxAdd = (gcnew System::Windows::Forms::TextBox());
			this->mailLabCustAdd = (gcnew System::Windows::Forms::Label());
			this->addCustButAdd = (gcnew System::Windows::Forms::Button());
			this->tabControl2 = (gcnew System::Windows::Forms::TabControl());
			this->delAddrTabAdd = (gcnew System::Windows::Forms::TabPage());
			this->gridDelAddrAdd = (gcnew System::Windows::Forms::DataGridView());
			this->numAddrDelCustAdd = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->compAddrDelCustAdd = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->streetAddrDelCustAdd = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->pcodeDelCustAdd = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->bAddrTabAdd = (gcnew System::Windows::Forms::TabPage());
			this->gridBillAddrAdd = (gcnew System::Windows::Forms::DataGridView());
			this->numAddrBillCustAdd = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->complAddrBillCustAdd = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->streetAddrBillCustAdd = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->pcodeBillCustAdd = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->calenCustAdd = (gcnew System::Windows::Forms::MonthCalendar());
			this->lnameCustBoxAdd = (gcnew System::Windows::Forms::TextBox());
			this->fnameCustBoxAdd = (gcnew System::Windows::Forms::TextBox());
			this->bdateCustLabAdd = (gcnew System::Windows::Forms::Label());
			this->lnameCustLabAdd = (gcnew System::Windows::Forms::Label());
			this->fnameCustLabAdd = (gcnew System::Windows::Forms::Label());
			this->tabStaffAdd = (gcnew System::Windows::Forms::TabPage());
			this->valStaffButAdd = (gcnew System::Windows::Forms::Button());
			this->addrStaffLabAdd = (gcnew System::Windows::Forms::Label());
			this->gridAddrStaffAdd = (gcnew System::Windows::Forms::DataGridView());
			this->NumAddrStaffTabAdd = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->CompAddrStaffTabAdd = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->StreetAddrStaffTabAdd = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->PCodeAddrStaffTabAdd = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->supStaffBoxAdd = (gcnew System::Windows::Forms::ComboBox());
			this->hdateStaffCalenAdd = (gcnew System::Windows::Forms::MonthCalendar());
			this->pwdStaffBoxAdd = (gcnew System::Windows::Forms::TextBox());
			this->mailStaffBoxAdd = (gcnew System::Windows::Forms::TextBox());
			this->lnameStaffBoxAdd = (gcnew System::Windows::Forms::TextBox());
			this->fnameStaffBoxAdd = (gcnew System::Windows::Forms::TextBox());
			this->supStaffLabAdd = (gcnew System::Windows::Forms::Label());
			this->hdateStaffLabAdd = (gcnew System::Windows::Forms::Label());
			this->pwdStaffLabAdd = (gcnew System::Windows::Forms::Label());
			this->mailStaffLabAdd = (gcnew System::Windows::Forms::Label());
			this->lnameStaffLabAdd = (gcnew System::Windows::Forms::Label());
			this->fnameStaffLabAdd = (gcnew System::Windows::Forms::Label());
			this->discCmdLabAdd = (gcnew System::Windows::Forms::Label());
			this->discCmdBoxAdd = (gcnew System::Windows::Forms::TextBox());
			this->tabControl1->SuspendLayout();
			this->tabHomeAdd->SuspendLayout();
			this->tabArtAdd->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->gridStockAdd))->BeginInit();
			this->tabCmdAdd->SuspendLayout();
			this->tabControl3->SuspendLayout();
			this->cmdTabAdd->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->gridDispAllStockCmdAdd))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->gridDispCustCmdAdd))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->gridDispStockCmdAdd))->BeginInit();
			this->payCmdTabAdd->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->gridPayCmdAdd))->BeginInit();
			this->tabCustAdd->SuspendLayout();
			this->tabControl2->SuspendLayout();
			this->delAddrTabAdd->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->gridDelAddrAdd))->BeginInit();
			this->bAddrTabAdd->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->gridBillAddrAdd))->BeginInit();
			this->tabStaffAdd->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->gridAddrStaffAdd))->BeginInit();
			this->SuspendLayout();
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->tabHomeAdd);
			this->tabControl1->Controls->Add(this->tabArtAdd);
			this->tabControl1->Controls->Add(this->tabCmdAdd);
			this->tabControl1->Controls->Add(this->tabCustAdd);
			this->tabControl1->Controls->Add(this->tabStaffAdd);
			this->tabControl1->Location = System::Drawing::Point(1, 0);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(1316, 523);
			this->tabControl1->TabIndex = 0;
			// 
			// tabHomeAdd
			// 
			this->tabHomeAdd->Controls->Add(this->butBackAdd);
			this->tabHomeAdd->Location = System::Drawing::Point(4, 25);
			this->tabHomeAdd->Name = L"tabHomeAdd";
			this->tabHomeAdd->Padding = System::Windows::Forms::Padding(3);
			this->tabHomeAdd->Size = System::Drawing::Size(1308, 494);
			this->tabHomeAdd->TabIndex = 0;
			this->tabHomeAdd->Text = L"Home";
			this->tabHomeAdd->UseVisualStyleBackColor = true;
			this->tabHomeAdd->Click += gcnew System::EventHandler(this, &Add::tabHomeAdd_Click);
			// 
			// butBackAdd
			// 
			this->butBackAdd->Location = System::Drawing::Point(549, 208);
			this->butBackAdd->Name = L"butBackAdd";
			this->butBackAdd->Size = System::Drawing::Size(194, 53);
			this->butBackAdd->TabIndex = 0;
			this->butBackAdd->Text = L"Back";
			this->butBackAdd->UseVisualStyleBackColor = true;
			this->butBackAdd->Click += gcnew System::EventHandler(this, &Add::button1_Click);
			// 
			// tabArtAdd
			// 
			this->tabArtAdd->Controls->Add(this->stockArtLabAdd);
			this->tabArtAdd->Controls->Add(this->catArtBoxAdd);
			this->tabArtAdd->Controls->Add(this->valArtButAdd);
			this->tabArtAdd->Controls->Add(this->gridStockAdd);
			this->tabArtAdd->Controls->Add(this->desrcpArtBoxAdd);
			this->tabArtAdd->Controls->Add(this->vatArtBoxAdd);
			this->tabArtAdd->Controls->Add(this->uhtArtBoxAdd);
			this->tabArtAdd->Controls->Add(this->nameArtBoxAdd);
			this->tabArtAdd->Controls->Add(this->refArtBoxAdd);
			this->tabArtAdd->Controls->Add(this->catArtLabAdd);
			this->tabArtAdd->Controls->Add(this->descrpArtLabAdd);
			this->tabArtAdd->Controls->Add(this->vatArtLabAdd);
			this->tabArtAdd->Controls->Add(this->uhtArtLabAdd);
			this->tabArtAdd->Controls->Add(this->nameArtLabAdd);
			this->tabArtAdd->Controls->Add(this->refArtLabAdd);
			this->tabArtAdd->Location = System::Drawing::Point(4, 25);
			this->tabArtAdd->Name = L"tabArtAdd";
			this->tabArtAdd->Padding = System::Windows::Forms::Padding(3);
			this->tabArtAdd->Size = System::Drawing::Size(1308, 494);
			this->tabArtAdd->TabIndex = 1;
			this->tabArtAdd->Text = L"Article";
			this->tabArtAdd->UseVisualStyleBackColor = true;
			// 
			// stockArtLabAdd
			// 
			this->stockArtLabAdd->AutoSize = true;
			this->stockArtLabAdd->Location = System::Drawing::Point(471, 6);
			this->stockArtLabAdd->Name = L"stockArtLabAdd";
			this->stockArtLabAdd->Size = System::Drawing::Size(48, 16);
			this->stockArtLabAdd->TabIndex = 14;
			this->stockArtLabAdd->Text = L"Stocks";
			// 
			// catArtBoxAdd
			// 
			this->catArtBoxAdd->FormattingEnabled = true;
			this->catArtBoxAdd->Location = System::Drawing::Point(49, 371);
			this->catArtBoxAdd->Name = L"catArtBoxAdd";
			this->catArtBoxAdd->Size = System::Drawing::Size(170, 24);
			this->catArtBoxAdd->TabIndex = 13;
			// 
			// valArtButAdd
			// 
			this->valArtButAdd->Location = System::Drawing::Point(1091, 426);
			this->valArtButAdd->Name = L"valArtButAdd";
			this->valArtButAdd->Size = System::Drawing::Size(202, 62);
			this->valArtButAdd->TabIndex = 12;
			this->valArtButAdd->Text = L"Validate";
			this->valArtButAdd->UseVisualStyleBackColor = true;
			this->valArtButAdd->Click += gcnew System::EventHandler(this, &Add::valArtButAdd_Click);
			// 
			// gridStockAdd
			// 
			this->gridStockAdd->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->gridStockAdd->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(5) {
				this->RefArtAdd,
					this->ThreshArtAdd, this->CostArtAdd, this->QteArtAdd, this->ColArtAdd
			});
			this->gridStockAdd->Location = System::Drawing::Point(474, 25);
			this->gridStockAdd->Name = L"gridStockAdd";
			this->gridStockAdd->RowHeadersWidth = 51;
			this->gridStockAdd->RowTemplate->Height = 24;
			this->gridStockAdd->Size = System::Drawing::Size(819, 370);
			this->gridStockAdd->TabIndex = 11;
			// 
			// RefArtAdd
			// 
			this->RefArtAdd->HeaderText = L"Reference";
			this->RefArtAdd->MinimumWidth = 6;
			this->RefArtAdd->Name = L"RefArtAdd";
			this->RefArtAdd->Width = 125;
			// 
			// ThreshArtAdd
			// 
			this->ThreshArtAdd->HeaderText = L"Replenishment Threshold";
			this->ThreshArtAdd->MinimumWidth = 6;
			this->ThreshArtAdd->Name = L"ThreshArtAdd";
			this->ThreshArtAdd->Width = 125;
			// 
			// CostArtAdd
			// 
			this->CostArtAdd->HeaderText = L"Production Cost";
			this->CostArtAdd->MinimumWidth = 6;
			this->CostArtAdd->Name = L"CostArtAdd";
			this->CostArtAdd->Width = 125;
			// 
			// QteArtAdd
			// 
			this->QteArtAdd->HeaderText = L"Quantity in Stock";
			this->QteArtAdd->MinimumWidth = 6;
			this->QteArtAdd->Name = L"QteArtAdd";
			this->QteArtAdd->Width = 125;
			// 
			// ColArtAdd
			// 
			this->ColArtAdd->HeaderText = L"Color";
			this->ColArtAdd->MinimumWidth = 6;
			this->ColArtAdd->Name = L"ColArtAdd";
			this->ColArtAdd->Width = 125;
			// 
			// desrcpArtBoxAdd
			// 
			this->desrcpArtBoxAdd->Location = System::Drawing::Point(14, 206);
			this->desrcpArtBoxAdd->Multiline = true;
			this->desrcpArtBoxAdd->Name = L"desrcpArtBoxAdd";
			this->desrcpArtBoxAdd->Size = System::Drawing::Size(442, 131);
			this->desrcpArtBoxAdd->TabIndex = 10;
			// 
			// vatArtBoxAdd
			// 
			this->vatArtBoxAdd->Location = System::Drawing::Point(366, 86);
			this->vatArtBoxAdd->Name = L"vatArtBoxAdd";
			this->vatArtBoxAdd->Size = System::Drawing::Size(75, 22);
			this->vatArtBoxAdd->TabIndex = 9;
			// 
			// uhtArtBoxAdd
			// 
			this->uhtArtBoxAdd->Location = System::Drawing::Point(221, 86);
			this->uhtArtBoxAdd->Name = L"uhtArtBoxAdd";
			this->uhtArtBoxAdd->Size = System::Drawing::Size(64, 22);
			this->uhtArtBoxAdd->TabIndex = 8;
			// 
			// nameArtBoxAdd
			// 
			this->nameArtBoxAdd->Location = System::Drawing::Point(25, 130);
			this->nameArtBoxAdd->Name = L"nameArtBoxAdd";
			this->nameArtBoxAdd->Size = System::Drawing::Size(94, 22);
			this->nameArtBoxAdd->TabIndex = 7;
			// 
			// refArtBoxAdd
			// 
			this->refArtBoxAdd->Location = System::Drawing::Point(25, 68);
			this->refArtBoxAdd->Name = L"refArtBoxAdd";
			this->refArtBoxAdd->Size = System::Drawing::Size(94, 22);
			this->refArtBoxAdd->TabIndex = 6;
			// 
			// catArtLabAdd
			// 
			this->catArtLabAdd->AutoSize = true;
			this->catArtLabAdd->Location = System::Drawing::Point(48, 352);
			this->catArtLabAdd->Name = L"catArtLabAdd";
			this->catArtLabAdd->Size = System::Drawing::Size(62, 16);
			this->catArtLabAdd->TabIndex = 5;
			this->catArtLabAdd->Text = L"Category";
			// 
			// descrpArtLabAdd
			// 
			this->descrpArtLabAdd->AutoSize = true;
			this->descrpArtLabAdd->Location = System::Drawing::Point(22, 187);
			this->descrpArtLabAdd->Name = L"descrpArtLabAdd";
			this->descrpArtLabAdd->Size = System::Drawing::Size(75, 16);
			this->descrpArtLabAdd->TabIndex = 4;
			this->descrpArtLabAdd->Text = L"Description";
			// 
			// vatArtLabAdd
			// 
			this->vatArtLabAdd->AutoSize = true;
			this->vatArtLabAdd->Location = System::Drawing::Point(363, 54);
			this->vatArtLabAdd->Name = L"vatArtLabAdd";
			this->vatArtLabAdd->Size = System::Drawing::Size(34, 16);
			this->vatArtLabAdd->TabIndex = 3;
			this->vatArtLabAdd->Text = L"VAT";
			// 
			// uhtArtLabAdd
			// 
			this->uhtArtLabAdd->AutoSize = true;
			this->uhtArtLabAdd->Location = System::Drawing::Point(218, 52);
			this->uhtArtLabAdd->Name = L"uhtArtLabAdd";
			this->uhtArtLabAdd->Size = System::Drawing::Size(70, 16);
			this->uhtArtLabAdd->TabIndex = 2;
			this->uhtArtLabAdd->Text = L"UHT Price";
			// 
			// nameArtLabAdd
			// 
			this->nameArtLabAdd->AutoSize = true;
			this->nameArtLabAdd->Location = System::Drawing::Point(22, 111);
			this->nameArtLabAdd->Name = L"nameArtLabAdd";
			this->nameArtLabAdd->Size = System::Drawing::Size(44, 16);
			this->nameArtLabAdd->TabIndex = 1;
			this->nameArtLabAdd->Text = L"Name";
			// 
			// refArtLabAdd
			// 
			this->refArtLabAdd->AutoSize = true;
			this->refArtLabAdd->Location = System::Drawing::Point(22, 49);
			this->refArtLabAdd->Name = L"refArtLabAdd";
			this->refArtLabAdd->Size = System::Drawing::Size(70, 16);
			this->refArtLabAdd->TabIndex = 0;
			this->refArtLabAdd->Text = L"Reference";
			// 
			// tabCmdAdd
			// 
			this->tabCmdAdd->Controls->Add(this->tabControl3);
			this->tabCmdAdd->Location = System::Drawing::Point(4, 25);
			this->tabCmdAdd->Name = L"tabCmdAdd";
			this->tabCmdAdd->Padding = System::Windows::Forms::Padding(3);
			this->tabCmdAdd->Size = System::Drawing::Size(1308, 494);
			this->tabCmdAdd->TabIndex = 2;
			this->tabCmdAdd->Text = L"Commande";
			this->tabCmdAdd->UseVisualStyleBackColor = true;
			// 
			// tabControl3
			// 
			this->tabControl3->Controls->Add(this->cmdTabAdd);
			this->tabControl3->Controls->Add(this->payCmdTabAdd);
			this->tabControl3->Location = System::Drawing::Point(7, 3);
			this->tabControl3->Name = L"tabControl3";
			this->tabControl3->SelectedIndex = 0;
			this->tabControl3->Size = System::Drawing::Size(1295, 493);
			this->tabControl3->TabIndex = 0;
			// 
			// cmdTabAdd
			// 
			this->cmdTabAdd->Controls->Add(this->discCmdBoxAdd);
			this->cmdTabAdd->Controls->Add(this->discCmdLabAdd);
			this->cmdTabAdd->Controls->Add(this->calenDelDateCmdAdd);
			this->cmdTabAdd->Controls->Add(this->calenIDateCmdAdd);
			this->cmdTabAdd->Controls->Add(this->rqteCmdBoxAdd);
			this->cmdTabAdd->Controls->Add(this->qteCmdBoxAdd);
			this->cmdTabAdd->Controls->Add(this->addArtCmdButAdd);
			this->cmdTabAdd->Controls->Add(this->valCmdButAdd);
			this->cmdTabAdd->Controls->Add(this->rqteCmdLabAdd);
			this->cmdTabAdd->Controls->Add(this->qteCmdLabAdd);
			this->cmdTabAdd->Controls->Add(this->ddateCmdLabAdd);
			this->cmdTabAdd->Controls->Add(this->idateCmdLabAdd);
			this->cmdTabAdd->Controls->Add(this->gridDispAllStockCmdAdd);
			this->cmdTabAdd->Controls->Add(this->gridDispCustCmdAdd);
			this->cmdTabAdd->Controls->Add(this->gridDispStockCmdAdd);
			this->cmdTabAdd->Location = System::Drawing::Point(4, 25);
			this->cmdTabAdd->Name = L"cmdTabAdd";
			this->cmdTabAdd->Padding = System::Windows::Forms::Padding(3);
			this->cmdTabAdd->Size = System::Drawing::Size(1287, 464);
			this->cmdTabAdd->TabIndex = 0;
			this->cmdTabAdd->Text = L"Commande";
			this->cmdTabAdd->UseVisualStyleBackColor = true;
			// 
			// calenDelDateCmdAdd
			// 
			this->calenDelDateCmdAdd->Location = System::Drawing::Point(312, 240);
			this->calenDelDateCmdAdd->Name = L"calenDelDateCmdAdd";
			this->calenDelDateCmdAdd->TabIndex = 12;
			// 
			// calenIDateCmdAdd
			// 
			this->calenIDateCmdAdd->Location = System::Drawing::Point(17, 240);
			this->calenIDateCmdAdd->Name = L"calenIDateCmdAdd";
			this->calenIDateCmdAdd->TabIndex = 11;
			// 
			// rqteCmdBoxAdd
			// 
			this->rqteCmdBoxAdd->Location = System::Drawing::Point(1043, 425);
			this->rqteCmdBoxAdd->Name = L"rqteCmdBoxAdd";
			this->rqteCmdBoxAdd->Size = System::Drawing::Size(100, 22);
			this->rqteCmdBoxAdd->TabIndex = 10;
			// 
			// qteCmdBoxAdd
			// 
			this->qteCmdBoxAdd->Location = System::Drawing::Point(898, 425);
			this->qteCmdBoxAdd->Name = L"qteCmdBoxAdd";
			this->qteCmdBoxAdd->Size = System::Drawing::Size(100, 22);
			this->qteCmdBoxAdd->TabIndex = 9;
			// 
			// addArtCmdButAdd
			// 
			this->addArtCmdButAdd->Location = System::Drawing::Point(1183, 413);
			this->addArtCmdButAdd->Name = L"addArtCmdButAdd";
			this->addArtCmdButAdd->Size = System::Drawing::Size(75, 23);
			this->addArtCmdButAdd->TabIndex = 8;
			this->addArtCmdButAdd->Text = L"Add";
			this->addArtCmdButAdd->UseVisualStyleBackColor = true;
			this->addArtCmdButAdd->Click += gcnew System::EventHandler(this, &Add::addArtCmdButAdd_Click);
			// 
			// valCmdButAdd
			// 
			this->valCmdButAdd->Location = System::Drawing::Point(626, 372);
			this->valCmdButAdd->Name = L"valCmdButAdd";
			this->valCmdButAdd->Size = System::Drawing::Size(173, 50);
			this->valCmdButAdd->TabIndex = 7;
			this->valCmdButAdd->Text = L"Validate";
			this->valCmdButAdd->UseVisualStyleBackColor = true;
			this->valCmdButAdd->Click += gcnew System::EventHandler(this, &Add::valCmdButAdd_Click);
			// 
			// rqteCmdLabAdd
			// 
			this->rqteCmdLabAdd->AutoSize = true;
			this->rqteCmdLabAdd->Location = System::Drawing::Point(1051, 406);
			this->rqteCmdLabAdd->Name = L"rqteCmdLabAdd";
			this->rqteCmdLabAdd->Size = System::Drawing::Size(68, 16);
			this->rqteCmdLabAdd->TabIndex = 6;
			this->rqteCmdLabAdd->Text = L"Reduction";
			// 
			// qteCmdLabAdd
			// 
			this->qteCmdLabAdd->AutoSize = true;
			this->qteCmdLabAdd->Location = System::Drawing::Point(916, 406);
			this->qteCmdLabAdd->Name = L"qteCmdLabAdd";
			this->qteCmdLabAdd->Size = System::Drawing::Size(55, 16);
			this->qteCmdLabAdd->TabIndex = 5;
			this->qteCmdLabAdd->Text = L"Quantity";
			// 
			// ddateCmdLabAdd
			// 
			this->ddateCmdLabAdd->AutoSize = true;
			this->ddateCmdLabAdd->Location = System::Drawing::Point(309, 215);
			this->ddateCmdLabAdd->Name = L"ddateCmdLabAdd";
			this->ddateCmdLabAdd->Size = System::Drawing::Size(89, 16);
			this->ddateCmdLabAdd->TabIndex = 4;
			this->ddateCmdLabAdd->Text = L"Delivery Date";
			// 
			// idateCmdLabAdd
			// 
			this->idateCmdLabAdd->AutoSize = true;
			this->idateCmdLabAdd->Location = System::Drawing::Point(40, 215);
			this->idateCmdLabAdd->Name = L"idateCmdLabAdd";
			this->idateCmdLabAdd->Size = System::Drawing::Size(71, 16);
			this->idateCmdLabAdd->TabIndex = 3;
			this->idateCmdLabAdd->Text = L"Issue Date";
			// 
			// gridDispAllStockCmdAdd
			// 
			this->gridDispAllStockCmdAdd->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->gridDispAllStockCmdAdd->Location = System::Drawing::Point(846, 186);
			this->gridDispAllStockCmdAdd->MultiSelect = false;
			this->gridDispAllStockCmdAdd->Name = L"gridDispAllStockCmdAdd";
			this->gridDispAllStockCmdAdd->ReadOnly = true;
			this->gridDispAllStockCmdAdd->RowHeadersWidth = 51;
			this->gridDispAllStockCmdAdd->RowTemplate->Height = 24;
			this->gridDispAllStockCmdAdd->Size = System::Drawing::Size(412, 210);
			this->gridDispAllStockCmdAdd->TabIndex = 2;
			// 
			// gridDispCustCmdAdd
			// 
			this->gridDispCustCmdAdd->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->gridDispCustCmdAdd->Location = System::Drawing::Point(837, 15);
			this->gridDispCustCmdAdd->MultiSelect = false;
			this->gridDispCustCmdAdd->Name = L"gridDispCustCmdAdd";
			this->gridDispCustCmdAdd->ReadOnly = true;
			this->gridDispCustCmdAdd->RowHeadersWidth = 51;
			this->gridDispCustCmdAdd->RowTemplate->Height = 24;
			this->gridDispCustCmdAdd->Size = System::Drawing::Size(431, 165);
			this->gridDispCustCmdAdd->TabIndex = 1;
			// 
			// gridDispStockCmdAdd
			// 
			this->gridDispStockCmdAdd->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->gridDispStockCmdAdd->Location = System::Drawing::Point(17, 15);
			this->gridDispStockCmdAdd->Name = L"gridDispStockCmdAdd";
			this->gridDispStockCmdAdd->RowHeadersWidth = 51;
			this->gridDispStockCmdAdd->RowTemplate->Height = 24;
			this->gridDispStockCmdAdd->Size = System::Drawing::Size(737, 186);
			this->gridDispStockCmdAdd->TabIndex = 0;
			// 
			// payCmdTabAdd
			// 
			this->payCmdTabAdd->Controls->Add(this->payCmdLabAdd);
			this->payCmdTabAdd->Controls->Add(this->gridPayCmdAdd);
			this->payCmdTabAdd->Location = System::Drawing::Point(4, 25);
			this->payCmdTabAdd->Name = L"payCmdTabAdd";
			this->payCmdTabAdd->Padding = System::Windows::Forms::Padding(3);
			this->payCmdTabAdd->Size = System::Drawing::Size(1287, 464);
			this->payCmdTabAdd->TabIndex = 1;
			this->payCmdTabAdd->Text = L"Payments";
			this->payCmdTabAdd->UseVisualStyleBackColor = true;
			// 
			// payCmdLabAdd
			// 
			this->payCmdLabAdd->AutoSize = true;
			this->payCmdLabAdd->Location = System::Drawing::Point(35, 12);
			this->payCmdLabAdd->Name = L"payCmdLabAdd";
			this->payCmdLabAdd->Size = System::Drawing::Size(67, 16);
			this->payCmdLabAdd->TabIndex = 1;
			this->payCmdLabAdd->Text = L"Payments";
			// 
			// gridPayCmdAdd
			// 
			this->gridPayCmdAdd->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->gridPayCmdAdd->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(4) {
				this->PayDatePayCmdAdd,
					this->PayBDatePayCmdAdd, this->MeansPayCmdAdd, this->AmountPayCmdAdd
			});
			this->gridPayCmdAdd->Location = System::Drawing::Point(23, 43);
			this->gridPayCmdAdd->Name = L"gridPayCmdAdd";
			this->gridPayCmdAdd->RowHeadersWidth = 51;
			this->gridPayCmdAdd->Size = System::Drawing::Size(1031, 340);
			this->gridPayCmdAdd->TabIndex = 0;
			// 
			// PayDatePayCmdAdd
			// 
			this->PayDatePayCmdAdd->HeaderText = L"Payment Date";
			this->PayDatePayCmdAdd->MinimumWidth = 6;
			this->PayDatePayCmdAdd->Name = L"PayDatePayCmdAdd";
			this->PayDatePayCmdAdd->Width = 125;
			// 
			// PayBDatePayCmdAdd
			// 
			this->PayBDatePayCmdAdd->HeaderText = L"Payment Balance Date";
			this->PayBDatePayCmdAdd->MinimumWidth = 6;
			this->PayBDatePayCmdAdd->Name = L"PayBDatePayCmdAdd";
			this->PayBDatePayCmdAdd->Width = 125;
			// 
			// MeansPayCmdAdd
			// 
			this->MeansPayCmdAdd->HeaderText = L"Mean of Payment";
			this->MeansPayCmdAdd->MinimumWidth = 6;
			this->MeansPayCmdAdd->Name = L"MeansPayCmdAdd";
			this->MeansPayCmdAdd->Width = 125;
			// 
			// AmountPayCmdAdd
			// 
			this->AmountPayCmdAdd->HeaderText = L"Amount Paid";
			this->AmountPayCmdAdd->MinimumWidth = 6;
			this->AmountPayCmdAdd->Name = L"AmountPayCmdAdd";
			this->AmountPayCmdAdd->Width = 125;
			// 
			// tabCustAdd
			// 
			this->tabCustAdd->Controls->Add(this->mailCustBoxAdd);
			this->tabCustAdd->Controls->Add(this->mailLabCustAdd);
			this->tabCustAdd->Controls->Add(this->addCustButAdd);
			this->tabCustAdd->Controls->Add(this->tabControl2);
			this->tabCustAdd->Controls->Add(this->calenCustAdd);
			this->tabCustAdd->Controls->Add(this->lnameCustBoxAdd);
			this->tabCustAdd->Controls->Add(this->fnameCustBoxAdd);
			this->tabCustAdd->Controls->Add(this->bdateCustLabAdd);
			this->tabCustAdd->Controls->Add(this->lnameCustLabAdd);
			this->tabCustAdd->Controls->Add(this->fnameCustLabAdd);
			this->tabCustAdd->Location = System::Drawing::Point(4, 25);
			this->tabCustAdd->Name = L"tabCustAdd";
			this->tabCustAdd->Padding = System::Windows::Forms::Padding(3);
			this->tabCustAdd->Size = System::Drawing::Size(1308, 494);
			this->tabCustAdd->TabIndex = 3;
			this->tabCustAdd->Text = L"Customer";
			this->tabCustAdd->UseVisualStyleBackColor = true;
			// 
			// mailCustBoxAdd
			// 
			this->mailCustBoxAdd->Location = System::Drawing::Point(220, 73);
			this->mailCustBoxAdd->Name = L"mailCustBoxAdd";
			this->mailCustBoxAdd->Size = System::Drawing::Size(108, 22);
			this->mailCustBoxAdd->TabIndex = 10;
			// 
			// mailLabCustAdd
			// 
			this->mailLabCustAdd->AutoSize = true;
			this->mailLabCustAdd->Location = System::Drawing::Point(217, 54);
			this->mailLabCustAdd->Name = L"mailLabCustAdd";
			this->mailLabCustAdd->Size = System::Drawing::Size(41, 16);
			this->mailLabCustAdd->TabIndex = 9;
			this->mailLabCustAdd->Text = L"Email";
			// 
			// addCustButAdd
			// 
			this->addCustButAdd->Location = System::Drawing::Point(1227, 465);
			this->addCustButAdd->Name = L"addCustButAdd";
			this->addCustButAdd->Size = System::Drawing::Size(75, 23);
			this->addCustButAdd->TabIndex = 8;
			this->addCustButAdd->Text = L"Add";
			this->addCustButAdd->UseVisualStyleBackColor = true;
			this->addCustButAdd->Click += gcnew System::EventHandler(this, &Add::addCustButAdd_Click);
			// 
			// tabControl2
			// 
			this->tabControl2->Controls->Add(this->delAddrTabAdd);
			this->tabControl2->Controls->Add(this->bAddrTabAdd);
			this->tabControl2->Location = System::Drawing::Point(358, 3);
			this->tabControl2->Name = L"tabControl2";
			this->tabControl2->SelectedIndex = 0;
			this->tabControl2->Size = System::Drawing::Size(944, 443);
			this->tabControl2->TabIndex = 6;
			// 
			// delAddrTabAdd
			// 
			this->delAddrTabAdd->Controls->Add(this->gridDelAddrAdd);
			this->delAddrTabAdd->Location = System::Drawing::Point(4, 25);
			this->delAddrTabAdd->Name = L"delAddrTabAdd";
			this->delAddrTabAdd->Padding = System::Windows::Forms::Padding(3);
			this->delAddrTabAdd->Size = System::Drawing::Size(936, 414);
			this->delAddrTabAdd->TabIndex = 0;
			this->delAddrTabAdd->Text = L"Delivery Address";
			this->delAddrTabAdd->UseVisualStyleBackColor = true;
			// 
			// gridDelAddrAdd
			// 
			this->gridDelAddrAdd->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->gridDelAddrAdd->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(4) {
				this->numAddrDelCustAdd,
					this->compAddrDelCustAdd, this->streetAddrDelCustAdd, this->pcodeDelCustAdd
			});
			this->gridDelAddrAdd->Location = System::Drawing::Point(2, 2);
			this->gridDelAddrAdd->Name = L"gridDelAddrAdd";
			this->gridDelAddrAdd->RowHeadersWidth = 51;
			this->gridDelAddrAdd->RowTemplate->Height = 24;
			this->gridDelAddrAdd->Size = System::Drawing::Size(931, 406);
			this->gridDelAddrAdd->TabIndex = 0;
			// 
			// numAddrDelCustAdd
			// 
			this->numAddrDelCustAdd->HeaderText = L"Number";
			this->numAddrDelCustAdd->MinimumWidth = 6;
			this->numAddrDelCustAdd->Name = L"numAddrDelCustAdd";
			this->numAddrDelCustAdd->Width = 125;
			// 
			// compAddrDelCustAdd
			// 
			this->compAddrDelCustAdd->HeaderText = L"Complement";
			this->compAddrDelCustAdd->MinimumWidth = 6;
			this->compAddrDelCustAdd->Name = L"compAddrDelCustAdd";
			this->compAddrDelCustAdd->Width = 125;
			// 
			// streetAddrDelCustAdd
			// 
			this->streetAddrDelCustAdd->HeaderText = L"Street";
			this->streetAddrDelCustAdd->MinimumWidth = 6;
			this->streetAddrDelCustAdd->Name = L"streetAddrDelCustAdd";
			this->streetAddrDelCustAdd->Width = 125;
			// 
			// pcodeDelCustAdd
			// 
			this->pcodeDelCustAdd->HeaderText = L"Postal Code";
			this->pcodeDelCustAdd->MinimumWidth = 6;
			this->pcodeDelCustAdd->Name = L"pcodeDelCustAdd";
			this->pcodeDelCustAdd->Width = 125;
			// 
			// bAddrTabAdd
			// 
			this->bAddrTabAdd->Controls->Add(this->gridBillAddrAdd);
			this->bAddrTabAdd->Location = System::Drawing::Point(4, 25);
			this->bAddrTabAdd->Name = L"bAddrTabAdd";
			this->bAddrTabAdd->Padding = System::Windows::Forms::Padding(3);
			this->bAddrTabAdd->Size = System::Drawing::Size(936, 414);
			this->bAddrTabAdd->TabIndex = 1;
			this->bAddrTabAdd->Text = L"Bill Address";
			this->bAddrTabAdd->UseVisualStyleBackColor = true;
			// 
			// gridBillAddrAdd
			// 
			this->gridBillAddrAdd->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->gridBillAddrAdd->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(4) {
				this->numAddrBillCustAdd,
					this->complAddrBillCustAdd, this->streetAddrBillCustAdd, this->pcodeBillCustAdd
			});
			this->gridBillAddrAdd->Location = System::Drawing::Point(2, 2);
			this->gridBillAddrAdd->Name = L"gridBillAddrAdd";
			this->gridBillAddrAdd->RowHeadersWidth = 51;
			this->gridBillAddrAdd->RowTemplate->Height = 24;
			this->gridBillAddrAdd->Size = System::Drawing::Size(928, 412);
			this->gridBillAddrAdd->TabIndex = 0;
			// 
			// numAddrBillCustAdd
			// 
			this->numAddrBillCustAdd->HeaderText = L"Number";
			this->numAddrBillCustAdd->MinimumWidth = 6;
			this->numAddrBillCustAdd->Name = L"numAddrBillCustAdd";
			this->numAddrBillCustAdd->Width = 125;
			// 
			// complAddrBillCustAdd
			// 
			this->complAddrBillCustAdd->HeaderText = L"Complement";
			this->complAddrBillCustAdd->MinimumWidth = 6;
			this->complAddrBillCustAdd->Name = L"complAddrBillCustAdd";
			this->complAddrBillCustAdd->Width = 125;
			// 
			// streetAddrBillCustAdd
			// 
			this->streetAddrBillCustAdd->HeaderText = L"Street";
			this->streetAddrBillCustAdd->MinimumWidth = 6;
			this->streetAddrBillCustAdd->Name = L"streetAddrBillCustAdd";
			this->streetAddrBillCustAdd->Width = 125;
			// 
			// pcodeBillCustAdd
			// 
			this->pcodeBillCustAdd->HeaderText = L"Postal Code";
			this->pcodeBillCustAdd->MinimumWidth = 6;
			this->pcodeBillCustAdd->Name = L"pcodeBillCustAdd";
			this->pcodeBillCustAdd->Width = 125;
			// 
			// calenCustAdd
			// 
			this->calenCustAdd->Location = System::Drawing::Point(28, 212);
			this->calenCustAdd->Name = L"calenCustAdd";
			this->calenCustAdd->TabIndex = 5;
			// 
			// lnameCustBoxAdd
			// 
			this->lnameCustBoxAdd->Location = System::Drawing::Point(63, 133);
			this->lnameCustBoxAdd->Name = L"lnameCustBoxAdd";
			this->lnameCustBoxAdd->Size = System::Drawing::Size(100, 22);
			this->lnameCustBoxAdd->TabIndex = 4;
			// 
			// fnameCustBoxAdd
			// 
			this->fnameCustBoxAdd->Location = System::Drawing::Point(63, 73);
			this->fnameCustBoxAdd->Name = L"fnameCustBoxAdd";
			this->fnameCustBoxAdd->Size = System::Drawing::Size(100, 22);
			this->fnameCustBoxAdd->TabIndex = 3;
			// 
			// bdateCustLabAdd
			// 
			this->bdateCustLabAdd->AutoSize = true;
			this->bdateCustLabAdd->Location = System::Drawing::Point(39, 187);
			this->bdateCustLabAdd->Name = L"bdateCustLabAdd";
			this->bdateCustLabAdd->Size = System::Drawing::Size(60, 16);
			this->bdateCustLabAdd->TabIndex = 2;
			this->bdateCustLabAdd->Text = L"Birthdate";
			// 
			// lnameCustLabAdd
			// 
			this->lnameCustLabAdd->AutoSize = true;
			this->lnameCustLabAdd->Location = System::Drawing::Point(60, 114);
			this->lnameCustLabAdd->Name = L"lnameCustLabAdd";
			this->lnameCustLabAdd->Size = System::Drawing::Size(66, 16);
			this->lnameCustLabAdd->TabIndex = 1;
			this->lnameCustLabAdd->Text = L"Lastname";
			// 
			// fnameCustLabAdd
			// 
			this->fnameCustLabAdd->AutoSize = true;
			this->fnameCustLabAdd->Location = System::Drawing::Point(60, 54);
			this->fnameCustLabAdd->Name = L"fnameCustLabAdd";
			this->fnameCustLabAdd->Size = System::Drawing::Size(66, 16);
			this->fnameCustLabAdd->TabIndex = 0;
			this->fnameCustLabAdd->Text = L"Firstname";
			// 
			// tabStaffAdd
			// 
			this->tabStaffAdd->Controls->Add(this->valStaffButAdd);
			this->tabStaffAdd->Controls->Add(this->addrStaffLabAdd);
			this->tabStaffAdd->Controls->Add(this->gridAddrStaffAdd);
			this->tabStaffAdd->Controls->Add(this->supStaffBoxAdd);
			this->tabStaffAdd->Controls->Add(this->hdateStaffCalenAdd);
			this->tabStaffAdd->Controls->Add(this->pwdStaffBoxAdd);
			this->tabStaffAdd->Controls->Add(this->mailStaffBoxAdd);
			this->tabStaffAdd->Controls->Add(this->lnameStaffBoxAdd);
			this->tabStaffAdd->Controls->Add(this->fnameStaffBoxAdd);
			this->tabStaffAdd->Controls->Add(this->supStaffLabAdd);
			this->tabStaffAdd->Controls->Add(this->hdateStaffLabAdd);
			this->tabStaffAdd->Controls->Add(this->pwdStaffLabAdd);
			this->tabStaffAdd->Controls->Add(this->mailStaffLabAdd);
			this->tabStaffAdd->Controls->Add(this->lnameStaffLabAdd);
			this->tabStaffAdd->Controls->Add(this->fnameStaffLabAdd);
			this->tabStaffAdd->Location = System::Drawing::Point(4, 25);
			this->tabStaffAdd->Name = L"tabStaffAdd";
			this->tabStaffAdd->Padding = System::Windows::Forms::Padding(3);
			this->tabStaffAdd->Size = System::Drawing::Size(1308, 494);
			this->tabStaffAdd->TabIndex = 4;
			this->tabStaffAdd->Text = L"Staff";
			this->tabStaffAdd->UseVisualStyleBackColor = true;
			// 
			// valStaffButAdd
			// 
			this->valStaffButAdd->Location = System::Drawing::Point(1095, 424);
			this->valStaffButAdd->Name = L"valStaffButAdd";
			this->valStaffButAdd->Size = System::Drawing::Size(189, 64);
			this->valStaffButAdd->TabIndex = 14;
			this->valStaffButAdd->Text = L"Validate";
			this->valStaffButAdd->UseVisualStyleBackColor = true;
			this->valStaffButAdd->Click += gcnew System::EventHandler(this, &Add::valStaffButAdd_Click);
			// 
			// addrStaffLabAdd
			// 
			this->addrStaffLabAdd->AutoSize = true;
			this->addrStaffLabAdd->Location = System::Drawing::Point(595, 27);
			this->addrStaffLabAdd->Name = L"addrStaffLabAdd";
			this->addrStaffLabAdd->Size = System::Drawing::Size(58, 16);
			this->addrStaffLabAdd->TabIndex = 13;
			this->addrStaffLabAdd->Text = L"Address";
			// 
			// gridAddrStaffAdd
			// 
			this->gridAddrStaffAdd->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->gridAddrStaffAdd->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(4) {
				this->NumAddrStaffTabAdd,
					this->CompAddrStaffTabAdd, this->StreetAddrStaffTabAdd, this->PCodeAddrStaffTabAdd
			});
			this->gridAddrStaffAdd->Location = System::Drawing::Point(582, 46);
			this->gridAddrStaffAdd->Name = L"gridAddrStaffAdd";
			this->gridAddrStaffAdd->RowHeadersWidth = 51;
			this->gridAddrStaffAdd->RowTemplate->Height = 24;
			this->gridAddrStaffAdd->Size = System::Drawing::Size(702, 366);
			this->gridAddrStaffAdd->TabIndex = 12;
			// 
			// NumAddrStaffTabAdd
			// 
			this->NumAddrStaffTabAdd->HeaderText = L"Number";
			this->NumAddrStaffTabAdd->MinimumWidth = 6;
			this->NumAddrStaffTabAdd->Name = L"NumAddrStaffTabAdd";
			this->NumAddrStaffTabAdd->Width = 125;
			// 
			// CompAddrStaffTabAdd
			// 
			this->CompAddrStaffTabAdd->HeaderText = L"Complement";
			this->CompAddrStaffTabAdd->MinimumWidth = 6;
			this->CompAddrStaffTabAdd->Name = L"CompAddrStaffTabAdd";
			this->CompAddrStaffTabAdd->Width = 125;
			// 
			// StreetAddrStaffTabAdd
			// 
			this->StreetAddrStaffTabAdd->HeaderText = L"Street";
			this->StreetAddrStaffTabAdd->MinimumWidth = 6;
			this->StreetAddrStaffTabAdd->Name = L"StreetAddrStaffTabAdd";
			this->StreetAddrStaffTabAdd->Width = 125;
			// 
			// PCodeAddrStaffTabAdd
			// 
			this->PCodeAddrStaffTabAdd->HeaderText = L"Postal Code";
			this->PCodeAddrStaffTabAdd->MinimumWidth = 6;
			this->PCodeAddrStaffTabAdd->Name = L"PCodeAddrStaffTabAdd";
			this->PCodeAddrStaffTabAdd->Width = 125;
			// 
			// supStaffBoxAdd
			// 
			this->supStaffBoxAdd->FormattingEnabled = true;
			this->supStaffBoxAdd->Location = System::Drawing::Point(362, 271);
			this->supStaffBoxAdd->Name = L"supStaffBoxAdd";
			this->supStaffBoxAdd->Size = System::Drawing::Size(149, 24);
			this->supStaffBoxAdd->TabIndex = 11;
			// 
			// hdateStaffCalenAdd
			// 
			this->hdateStaffCalenAdd->Location = System::Drawing::Point(42, 217);
			this->hdateStaffCalenAdd->Name = L"hdateStaffCalenAdd";
			this->hdateStaffCalenAdd->TabIndex = 10;
			// 
			// pwdStaffBoxAdd
			// 
			this->pwdStaffBoxAdd->Location = System::Drawing::Point(240, 133);
			this->pwdStaffBoxAdd->Name = L"pwdStaffBoxAdd";
			this->pwdStaffBoxAdd->Size = System::Drawing::Size(100, 22);
			this->pwdStaffBoxAdd->TabIndex = 9;
			// 
			// mailStaffBoxAdd
			// 
			this->mailStaffBoxAdd->Location = System::Drawing::Point(240, 52);
			this->mailStaffBoxAdd->Name = L"mailStaffBoxAdd";
			this->mailStaffBoxAdd->Size = System::Drawing::Size(100, 22);
			this->mailStaffBoxAdd->TabIndex = 8;
			// 
			// lnameStaffBoxAdd
			// 
			this->lnameStaffBoxAdd->Location = System::Drawing::Point(56, 133);
			this->lnameStaffBoxAdd->Name = L"lnameStaffBoxAdd";
			this->lnameStaffBoxAdd->Size = System::Drawing::Size(101, 22);
			this->lnameStaffBoxAdd->TabIndex = 7;
			// 
			// fnameStaffBoxAdd
			// 
			this->fnameStaffBoxAdd->Location = System::Drawing::Point(56, 52);
			this->fnameStaffBoxAdd->Name = L"fnameStaffBoxAdd";
			this->fnameStaffBoxAdd->Size = System::Drawing::Size(100, 22);
			this->fnameStaffBoxAdd->TabIndex = 6;
			// 
			// supStaffLabAdd
			// 
			this->supStaffLabAdd->AutoSize = true;
			this->supStaffLabAdd->Location = System::Drawing::Point(407, 252);
			this->supStaffLabAdd->Name = L"supStaffLabAdd";
			this->supStaffLabAdd->Size = System::Drawing::Size(58, 16);
			this->supStaffLabAdd->TabIndex = 5;
			this->supStaffLabAdd->Text = L"Superior";
			// 
			// hdateStaffLabAdd
			// 
			this->hdateStaffLabAdd->AutoSize = true;
			this->hdateStaffLabAdd->Location = System::Drawing::Point(53, 192);
			this->hdateStaffLabAdd->Name = L"hdateStaffLabAdd";
			this->hdateStaffLabAdd->Size = System::Drawing::Size(74, 16);
			this->hdateStaffLabAdd->TabIndex = 4;
			this->hdateStaffLabAdd->Text = L"Hiring Date";
			// 
			// pwdStaffLabAdd
			// 
			this->pwdStaffLabAdd->AutoSize = true;
			this->pwdStaffLabAdd->Location = System::Drawing::Point(237, 114);
			this->pwdStaffLabAdd->Name = L"pwdStaffLabAdd";
			this->pwdStaffLabAdd->Size = System::Drawing::Size(67, 16);
			this->pwdStaffLabAdd->TabIndex = 3;
			this->pwdStaffLabAdd->Text = L"Password";
			// 
			// mailStaffLabAdd
			// 
			this->mailStaffLabAdd->AutoSize = true;
			this->mailStaffLabAdd->Location = System::Drawing::Point(237, 33);
			this->mailStaffLabAdd->Name = L"mailStaffLabAdd";
			this->mailStaffLabAdd->Size = System::Drawing::Size(41, 16);
			this->mailStaffLabAdd->TabIndex = 2;
			this->mailStaffLabAdd->Text = L"Email";
			// 
			// lnameStaffLabAdd
			// 
			this->lnameStaffLabAdd->AutoSize = true;
			this->lnameStaffLabAdd->Location = System::Drawing::Point(53, 114);
			this->lnameStaffLabAdd->Name = L"lnameStaffLabAdd";
			this->lnameStaffLabAdd->Size = System::Drawing::Size(66, 16);
			this->lnameStaffLabAdd->TabIndex = 1;
			this->lnameStaffLabAdd->Text = L"Lastname";
			// 
			// fnameStaffLabAdd
			// 
			this->fnameStaffLabAdd->AutoSize = true;
			this->fnameStaffLabAdd->Location = System::Drawing::Point(53, 33);
			this->fnameStaffLabAdd->Name = L"fnameStaffLabAdd";
			this->fnameStaffLabAdd->Size = System::Drawing::Size(66, 16);
			this->fnameStaffLabAdd->TabIndex = 0;
			this->fnameStaffLabAdd->Text = L"Firstname";
			// 
			// discCmdLabAdd
			// 
			this->discCmdLabAdd->AutoSize = true;
			this->discCmdLabAdd->Location = System::Drawing::Point(673, 240);
			this->discCmdLabAdd->Name = L"discCmdLabAdd";
			this->discCmdLabAdd->Size = System::Drawing::Size(59, 16);
			this->discCmdLabAdd->TabIndex = 13;
			this->discCmdLabAdd->Text = L"Discount";
			// 
			// discCmdBoxAdd
			// 
			this->discCmdBoxAdd->Location = System::Drawing::Point(641, 259);
			this->discCmdBoxAdd->Name = L"discCmdBoxAdd";
			this->discCmdBoxAdd->Size = System::Drawing::Size(131, 22);
			this->discCmdBoxAdd->TabIndex = 14;
			// 
			// Add
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1322, 527);
			this->Controls->Add(this->tabControl1);
			this->Name = L"Add";
			this->Text = L"Add";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &Add::Add_Closed);
			this->Load += gcnew System::EventHandler(this, &Add::Add_Load);
			this->tabControl1->ResumeLayout(false);
			this->tabHomeAdd->ResumeLayout(false);
			this->tabArtAdd->ResumeLayout(false);
			this->tabArtAdd->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->gridStockAdd))->EndInit();
			this->tabCmdAdd->ResumeLayout(false);
			this->tabControl3->ResumeLayout(false);
			this->cmdTabAdd->ResumeLayout(false);
			this->cmdTabAdd->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->gridDispAllStockCmdAdd))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->gridDispCustCmdAdd))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->gridDispStockCmdAdd))->EndInit();
			this->payCmdTabAdd->ResumeLayout(false);
			this->payCmdTabAdd->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->gridPayCmdAdd))->EndInit();
			this->tabCustAdd->ResumeLayout(false);
			this->tabCustAdd->PerformLayout();
			this->tabControl2->ResumeLayout(false);
			this->delAddrTabAdd->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->gridDelAddrAdd))->EndInit();
			this->bAddrTabAdd->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->gridBillAddrAdd))->EndInit();
			this->tabStaffAdd->ResumeLayout(false);
			this->tabStaffAdd->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->gridAddrStaffAdd))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void Add_Closed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e) {
		this->Hide();
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Hide();
	}
	private: System::Void tabHomeAdd_Click(System::Object^ sender, System::EventArgs^ e) {
		
	}
	//ajout d'un client
	private: System::Void addCustButAdd_Click(System::Object^ sender, System::EventArgs^ e) {
		array<int>^ index_p = this->serviceCust->Add(this->fnameCustBoxAdd->Text->ToString(), this->lnameCustBoxAdd->Text->ToString(), this->mailCustBoxAdd->Text->ToString(), this->FormatDate(this->calenCustAdd->SelectionStart.ToShortDateString()));
		
		for (int i = 0; i < this->gridDelAddrAdd->Rows->Count - 1; i++)
		{
			if (
				this->gridDelAddrAdd->Rows[i]->Cells[0]->Value != nullptr
				&&
				this->gridDelAddrAdd->Rows[i]->Cells[2]->Value != nullptr
				&&
				this->gridDelAddrAdd->Rows[i]->Cells[3]->Value != nullptr
				&&
				this->gridDelAddrAdd->Rows[i]->Cells[4]->Value != nullptr
				)
			{
				if (this->gridDelAddrAdd->Rows[i]->Cells[1]->Value != nullptr)
				{
					array<String^>^ tmp_decoup = this->gridDelAddrAdd->Rows[i]->Cells[4]->Value->ToString()->Split(' ');
					this->serviceCust->AddAddress(
						Convert::ToInt32(this->gridDelAddrAdd->Rows[i]->Cells[0]->Value),
						this->gridDelAddrAdd->Rows[i]->Cells[1]->Value->ToString(),
						this->gridDelAddrAdd->Rows[i]->Cells[2]->Value->ToString(),
						Convert::ToInt32(this->gridDelAddrAdd->Rows[i]->Cells[3]->Value),
						Convert::ToInt32(tmp_decoup[0]),
						index_p[0],
						1
					);
				}
				else
				{
					array<String^>^ tmp_decoup = this->gridDelAddrAdd->Rows[i]->Cells[4]->Value->ToString()->Split(' ');
					String^ comp = DBNull::Value->ToString();
					this->serviceCust->AddAddress(
						Convert::ToInt32(this->gridDelAddrAdd->Rows[i]->Cells[0]->Value),
						comp,
						this->gridDelAddrAdd->Rows[i]->Cells[2]->Value->ToString(),
						Convert::ToInt32(this->gridDelAddrAdd->Rows[i]->Cells[3]->Value),
						Convert::ToInt32(tmp_decoup[0]),
						index_p[0],
						1
					);
				}
			}
			else
			{
				MessageBox::Show("One of the entry is not filled");
			}
		}
		
		for (int i = 0; i < this->gridBillAddrAdd->Rows->Count - 1; i++)
		{
			if (
				this->gridBillAddrAdd->Rows[i]->Cells[0]->Value != nullptr
				&&
				this->gridBillAddrAdd->Rows[i]->Cells[2]->Value != nullptr
				&&
				this->gridBillAddrAdd->Rows[i]->Cells[3]->Value != nullptr
				&&
				this->gridBillAddrAdd->Rows[i]->Cells[4]->Value != nullptr
				)
			{
				if (this->gridBillAddrAdd->Rows[i]->Cells[1]->Value != nullptr)
				{
					array<String^>^ tmp_decoup = this->gridBillAddrAdd->Rows[i]->Cells[4]->Value->ToString()->Split(' ');
					this->serviceCust->AddAddress(
						Convert::ToInt32(this->gridBillAddrAdd->Rows[i]->Cells[0]->Value),
						this->gridBillAddrAdd->Rows[i]->Cells[1]->Value->ToString(),
						this->gridBillAddrAdd->Rows[i]->Cells[2]->Value->ToString(),
						Convert::ToInt32(this->gridBillAddrAdd->Rows[i]->Cells[3]->Value),
						Convert::ToInt32(tmp_decoup[0]),
						index_p[0],
						0
					);
					
				}
				else
				{
					array<String^>^ tmp_decoup = this->gridBillAddrAdd->Rows[i]->Cells[4]->Value->ToString()->Split(' ');
					String^ comp = DBNull::Value->ToString();
					this->serviceCust->AddAddress(
						Convert::ToInt32(this->gridBillAddrAdd->Rows[i]->Cells[0]->Value),
						comp,
						this->gridBillAddrAdd->Rows[i]->Cells[2]->Value->ToString(),
						Convert::ToInt32(this->gridBillAddrAdd->Rows[i]->Cells[3]->Value),
						Convert::ToInt32(tmp_decoup[0]),
						index_p[0],
						0
					);
				}
			}
			else
			{
				MessageBox::Show("One of the entry is not filled");
			}
			
		}
		this->Hide();
	}
	//mettre au bon format les dates
	private: String^ FormatDate(String^ date_to_format)
	{
		array<String^>^ format_date = date_to_format->Split('/');
		String^ date_final = "";
		for (int i = 0; i < format_date->Length - 1; i++) {
			date_final += format_date[format_date->Length - i - 1];
			date_final += "/";
		}
		date_final += format_date[0];
		return date_final;
	}
	//chargement des services, des datagridviews et des combobox
	private: System::Void Add_Load(System::Object^ sender, System::EventArgs^ e) {
		this->serviceArt = gcnew NS_Service::ServiceStock();
		this->serviceCmd = gcnew NS_Service::ServiceCommande();
		this->serviceStaff = gcnew NS_Service::ServiceStaff();
		this->serviceCust = gcnew NS_Service::ServiceCustomer();
		this->data = gcnew DataSet();
		this->selectCust = -1;
		this->data->Clear();
		this->loadDataCust();
		this->loadDataStaff();
		this->loadDataArt();
		this->loadDataCmd();
		
	}


	private: void loadDataCust() {
		this->gridBillAddrAdd->Refresh();
		this->gridDelAddrAdd->Refresh();
		array<String^>^ table_cities = gcnew array<String^>(1);

		table_cities[0] = "citiesCust";

		this->data = this->serviceCust->GetCities(table_cities);
		DataGridViewComboBoxColumn^ cmb_del = gcnew DataGridViewComboBoxColumn();
		DataGridViewComboBoxColumn^ cmb_bill = gcnew DataGridViewComboBoxColumn();
		cmb_del->HeaderText = "Select City";
		cmb_bill->HeaderText = "Select City";
		cmb_del->Name = "cml_del";
		cmb_bill->Name = "cml_bill";
		for (int i = 0; i < this->data->Tables[table_cities[0]]->Rows->Count; i++)
		{
			cmb_del->Items->Add(
				this->data->Tables[table_cities[0]]->Rows[i]->ItemArray[0]->ToString() +
				" - " +
				this->data->Tables[table_cities[0]]->Rows[i]->ItemArray[1]->ToString()
			);
			cmb_bill->Items->Add(
				this->data->Tables[table_cities[0]]->Rows[i]->ItemArray[0]->ToString() +
				" - " +
				this->data->Tables[table_cities[0]]->Rows[i]->ItemArray[1]->ToString()
			);
		}
		gridDelAddrAdd->Columns->Add(cmb_del);
		gridBillAddrAdd->Columns->Add(cmb_bill);
	}
	private: void loadDataStaff() {
		this->gridAddrStaffAdd->Refresh();
		this->gridAddrStaffAdd->RowCount = 1;
		array<String^>^ table_cities = gcnew array<String^>(1);
		array<String^>^ table_sup = gcnew array<String^>(1);

		table_cities[0] = "citiesStaff";
		table_sup[0] = "supStaff";

		this->data->Merge(this->serviceCust->GetCities(table_cities));
		this->data->Merge(this->serviceStaff->DisplayAll(table_sup));

		DataGridViewComboBoxColumn^ cmb_staff = gcnew DataGridViewComboBoxColumn();

		this->supStaffBoxAdd->Text = "Select Sup";
		for (int i = 0; i < this->data->Tables[table_sup[0]]->Rows->Count; i++)
		{
			this->supStaffBoxAdd->Items->Add(
				this->data->Tables[table_sup[0]]->Rows[i]->ItemArray[0]->ToString() + 
				" - " + 
				this->data->Tables[table_sup[0]]->Rows[i]->ItemArray[1]->ToString() +
				" " +
				this->data->Tables[table_sup[0]]->Rows[i]->ItemArray[2]->ToString() 
			);
		}

		cmb_staff->HeaderText = "Select City";
		cmb_staff->Name = "cmb_staff";
		for (int i = 0; i < this->data->Tables[table_cities[0]]->Rows->Count; i++)
		{
			cmb_staff->Items->Add(
				this->data->Tables[table_cities[0]]->Rows[i]->ItemArray[0]->ToString() +
				" - " +
				this->data->Tables[table_cities[0]]->Rows[i]->ItemArray[1]->ToString()
			);
		}
		gridAddrStaffAdd->Columns->Add(cmb_staff);
	}
	private: void loadDataArt() {
		this->gridStockAdd->Refresh();
		array<String^>^ table_cat = gcnew array<String^>(1);

		table_cat[0] = "catArt";

		this->data->Merge(this->serviceArt->GetAllCat(table_cat));

		this->catArtBoxAdd->Text = "Select Category";
		for (int i = 0; i < this->data->Tables[table_cat[0]]->Rows->Count; i++)
		{
			this->catArtBoxAdd->Items->Add(
				this->data->Tables[table_cat[0]]->Rows[i]->ItemArray[0]->ToString() +
				" - " +
				this->data->Tables[table_cat[0]]->Rows[i]->ItemArray[1]->ToString()
			);
		}
	}
	private: void loadDataCmd() {
		this->gridDispAllStockCmdAdd->Refresh();
		this->gridDispCustCmdAdd->Refresh();
		this->gridDispStockCmdAdd->Refresh();
		this->gridPayCmdAdd->Refresh();


		array<String^>^ tableCust = gcnew array<String^>(1);
		array<String^>^ tableArt = gcnew array<String^>(1);
		array<String^>^ tableStock = gcnew array<String^>(2);

		tableArt[0] = "listeArt";
		tableStock[0] = "listeArtStock";
		tableStock[1] = "listeStock";
		tableCust[0] = "listeCust";

		this->data = this->serviceCust->DisplayAll(tableCust);
		this->data->Merge(this->serviceArt->DisplayAll(tableArt));
		this->data->Merge(this->serviceArt->Display(Convert::ToInt32(this->data->Tables[tableArt[0]]->Rows[0]->ItemArray[0]), tableStock));
		for (int i = 1; i < this->data->Tables[tableArt[0]]->Rows->Count; i++)
		{
			this->data->Tables[tableStock[1]]->Merge(this->serviceArt->Display(Convert::ToInt32(this->data->Tables[tableArt[0]]->Rows[i]->ItemArray[0]), tableStock)->Tables[tableStock[1]]);
		}

		this->gridDispAllStockCmdAdd->DataSource = this->data;
		this->gridDispAllStockCmdAdd->DataMember = tableStock[1];
		
		this->gridDispCustCmdAdd->DataSource = this->data;
		this->gridDispCustCmdAdd->DataMember = tableCust[0];
		
		this->gridDispStockCmdAdd->MultiSelect = false;
		DataGridViewColumn^ new_col0 = gcnew DataGridViewTextBoxColumn();
		DataGridViewColumn^ new_col1 = gcnew DataGridViewTextBoxColumn();
		DataGridViewColumn^ new_col2 = gcnew DataGridViewTextBoxColumn();
		DataGridViewColumn^ new_col3 = gcnew DataGridViewTextBoxColumn();
		DataGridViewColumn^ new_col4 = gcnew DataGridViewTextBoxColumn();
		DataGridViewColumn^ new_col5 = gcnew DataGridViewTextBoxColumn();
		DataGridViewColumn^ new_col6 = gcnew DataGridViewTextBoxColumn();
		DataGridViewColumn^ new_col7 = gcnew DataGridViewTextBoxColumn();
		new_col0->HeaderText = "Id";
		new_col1->HeaderText = "Color";
		new_col2->HeaderText = "Quantity Stock";
		new_col3->HeaderText = "Replenishment Threshold";
		new_col4->HeaderText = "Reference";
		new_col5->HeaderText = "Production Cost";
		new_col6->HeaderText = "Quantity";
		new_col7->HeaderText = "Reduction";
		new_col0->ReadOnly = true;
		new_col1->ReadOnly = true;
		new_col2->ReadOnly = true;
		new_col3->ReadOnly = true;
		new_col4->ReadOnly = true;
		new_col5->ReadOnly = true;
		this->gridDispStockCmdAdd->Columns->Add(new_col0);
		this->gridDispStockCmdAdd->Columns->Add(new_col1);
		this->gridDispStockCmdAdd->Columns->Add(new_col2);
		this->gridDispStockCmdAdd->Columns->Add(new_col3);
		this->gridDispStockCmdAdd->Columns->Add(new_col4);
		this->gridDispStockCmdAdd->Columns->Add(new_col5);
		this->gridDispStockCmdAdd->Columns->Add(new_col6);
		this->gridDispStockCmdAdd->Columns->Add(new_col7);
			
	}
	private: System::Void valStaffButAdd_Click(System::Object^ sender, System::EventArgs^ e) {
		array<String^>^ tmp_decoup = this->supStaffBoxAdd->Text->ToString()->Split(' ');
		array<int>^ index_p;
		array<String^>^ tmp_decoup2 = this->gridAddrStaffAdd->Rows[0]->Cells[4]->Value->ToString()->Split(' ');
		if (this->gridAddrStaffAdd->Rows[0]->Cells[1]->Value != nullptr)
		{
			index_p = this->serviceStaff->Add(this->fnameStaffBoxAdd->Text->ToString(),
				this->lnameStaffBoxAdd->Text->ToString(),
				this->mailStaffBoxAdd->Text->ToString(),
				this->FormatDate(this->hdateStaffCalenAdd->SelectionStart.ToShortDateString()),
				Convert::ToInt32(tmp_decoup[0]),
				Convert::ToInt32(this->gridAddrStaffAdd->Rows[0]->Cells[0]->Value->ToString()), 
				this->gridAddrStaffAdd->Rows[0]->Cells[1]->Value->ToString(),
				this->gridAddrStaffAdd->Rows[0]->Cells[2]->Value->ToString(), 
				Convert::ToInt32(this->gridAddrStaffAdd->Rows[0]->Cells[3]->Value->ToString()), 
				Convert::ToInt32(tmp_decoup2[0])
			);
		}
		else
		{
			String^ comp = DBNull::Value->ToString();
			index_p = this->serviceStaff->Add(this->fnameStaffBoxAdd->Text->ToString(),
				this->lnameStaffBoxAdd->Text->ToString(),
				this->mailStaffBoxAdd->Text->ToString(),
				this->FormatDate(this->hdateStaffCalenAdd->SelectionStart.ToShortDateString()),
				Convert::ToInt32(tmp_decoup[0]),
				Convert::ToInt32(this->gridAddrStaffAdd->Rows[0]->Cells[0]->Value->ToString()),
				comp,
				this->gridAddrStaffAdd->Rows[0]->Cells[2]->Value->ToString(),
				Convert::ToInt32(this->gridAddrStaffAdd->Rows[0]->Cells[3]->Value->ToString()),
				Convert::ToInt32(tmp_decoup2[0])
			);
		}
		if (this->pwdStaffBoxAdd->Text != nullptr && this->pwdStaffBoxAdd->Text->ToString() != "")
		{
			this->serviceStaff->AddUser(this->pwdStaffBoxAdd->Text->ToString(), index_p[0]);
		}
		this->Hide();
	}
	private: String^ FormatPrice(String^ price)
	{
		String^ rep = price;
		if (rep->Contains("."))
		{
			array<String^>^ tmp = rep->Split('.');
			rep = "";
			rep += tmp[0] + "," + tmp[1];
		}
		return rep;
	}
	private: System::Void valArtButAdd_Click(System::Object^ sender, System::EventArgs^ e) {
		int cat = Convert::ToInt32(this->catArtBoxAdd->Text->ToString()->Split(' ')[0]);
		int length_stock = this->gridStockAdd->RowCount;
		array<ColorStock^>^ stocks = gcnew array<ColorStock^>(length_stock - 1);
		for (int i = 0; i < length_stock - 1; i++)
		{
			ColorStock^ stock = gcnew ColorStock();
			stock->mReferenceProductColor = this->gridStockAdd->Rows[i]->Cells[0]->Value->ToString();
			stock->mReplenishmentThreshold = Convert::ToInt32(this->gridStockAdd->Rows[i]->Cells[1]->Value);
			stock->mProdCost = Convert::ToDouble(FormatPrice(this->gridStockAdd->Rows[i]->Cells[2]->Value->ToString()));
			stock->mQuantityStock = Convert::ToInt32(this->gridStockAdd->Rows[i]->Cells[3]->Value);
			stock->colName = this->gridStockAdd->Rows[i]->Cells[4]->Value->ToString();
			array<String^>^ table_col = gcnew array<String^>(1);
			table_col[0] = "col";
			int id_col = Convert::ToInt32(this->serviceArt->GetIdCol(stock->colName, table_col)->Tables[table_col[0]]->Rows->Count);
			if (id_col == 0)
			{
				id_col = this->serviceArt->AddColor(stock->colName)[0];
			}
			stock->mIdColor = id_col;
			stocks[i] = stock;
		}

		this->serviceArt->Add(
			this->refArtBoxAdd->Text->ToString(),
			this->nameArtBoxAdd->Text->ToString(),
			this->desrcpArtBoxAdd->Text->ToString(),
			Convert::ToDouble(this->FormatPrice(this->uhtArtBoxAdd->Text)),
			Convert::ToDouble(this->FormatPrice(this->vatArtBoxAdd->Text)),
			cat,
			stocks
		);
		this->Hide();
	}
	private: System::Void addArtCmdButAdd_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ qte;
		String^ reduc;
		if (this->rqteCmdBoxAdd->Text != "")
		{
			reduc = this->rqteCmdBoxAdd->Text;
		}
		else
		{
			reduc = "0";
		}
		if (this->qteCmdBoxAdd->Text != "")
		{
			qte = this->qteCmdBoxAdd->Text;
		}
		else
		{
			qte = "1";
		}
		if (this->gridDispCustCmdAdd->SelectedRows->Count == 1 && samecust == false)
		{
			if (this->gridDispAllStockCmdAdd->SelectedRows->Count == 1)
			{
				DataGridViewRow^ new_row = gcnew DataGridViewRow();
				for (int i = 0; i < this->gridDispAllStockCmdAdd->SelectedRows[0]->Cells->Count; i++)
				{
					DataGridViewCell^ new_cell0 = gcnew DataGridViewTextBoxCell();
					new_cell0->Value = this->gridDispAllStockCmdAdd->SelectedRows[0]->Cells[i]->Value;
					new_row->Cells->Add(new_cell0);
				}
				DataGridViewCell^ new_cell1 = gcnew DataGridViewTextBoxCell();
				DataGridViewCell^ new_cell2 = gcnew DataGridViewTextBoxCell();
				new_cell1->Value = qte;
				new_cell2->Value = reduc;
				new_row->Cells->Add(new_cell1);
				new_row->Cells->Add(new_cell2);
				this->gridDispStockCmdAdd->Rows->Add(new_row);
				this->selectCust = Convert::ToInt32(this->gridDispCustCmdAdd->SelectedRows[0]->Cells[0]->Value);
				this->samecust = true;
				this->fname = this->gridDispCustCmdAdd->SelectedRows[0]->Cells[1]->Value->ToString();
				this->lname = this->gridDispCustCmdAdd->SelectedRows[0]->Cells[2]->Value->ToString();
				this->gridDispAllStockCmdAdd->Rows->RemoveAt(this->gridDispAllStockCmdAdd->Rows->IndexOf(this->gridDispAllStockCmdAdd->SelectedRows[0]));
				this->gridDispStockCmdAdd->Refresh();
			}
		}
		else if (this->gridDispCustCmdAdd->SelectedRows->Count == 1 && Convert::ToInt32(this->gridDispCustCmdAdd->SelectedRows[0]->Cells[0]->Value) == this->selectCust)
		{
			if (this->gridDispAllStockCmdAdd->SelectedRows->Count == 1)
			{
				DataGridViewRow^ new_row = gcnew DataGridViewRow();
				for (int i = 0; i < this->gridDispAllStockCmdAdd->SelectedRows[0]->Cells->Count; i++)
				{
					DataGridViewCell^ new_cell0 = gcnew DataGridViewTextBoxCell();
					new_cell0->Value = this->gridDispAllStockCmdAdd->SelectedRows[0]->Cells[i]->Value;
					new_row->Cells->Add(new_cell0);
				}
				DataGridViewCell^ new_cell1 = gcnew DataGridViewTextBoxCell();
				DataGridViewCell^ new_cell2 = gcnew DataGridViewTextBoxCell();
				new_cell1->Value = qte;
				new_cell2->Value = reduc;
				new_row->Cells->Add(new_cell1);
				new_row->Cells->Add(new_cell2);
				this->gridDispStockCmdAdd->Rows->Add(new_row);
				this->gridDispAllStockCmdAdd->Rows->RemoveAt(this->gridDispAllStockCmdAdd->Rows->IndexOf(this->gridDispAllStockCmdAdd->SelectedRows[0]));
				this->gridDispStockCmdAdd->Refresh();
			}
		}
		else
		{
			MessageBox::Show("Select a customer and the same one each time");
		}
	}
	private: System::Void valCmdButAdd_Click(System::Object^ sender, System::EventArgs^ e) {
		if (this->gridPayCmdAdd->Rows->Count - 1 != 0)
		{
			array<Basket^>^ basket = gcnew array<Basket^>(this->gridDispStockCmdAdd->Rows->Count - 1);
			array<Payment^>^ payments = gcnew array<Payment^>(this->gridPayCmdAdd->Rows->Count - 1);
			for (int i = 0; i < this->gridPayCmdAdd->Rows->Count - 1; i++)
			{
				Payment^ payment = gcnew Payment();
				payment->mDatePayment = this->gridPayCmdAdd->Rows[i]->Cells[0]->Value->ToString();
				payment->mDatePaymentBalance = this->gridPayCmdAdd->Rows[i]->Cells[1]->Value->ToString();
				payment->mMeansPayment = this->gridPayCmdAdd->Rows[i]->Cells[2]->Value->ToString();
				payment->mSommePay = Convert::ToDouble(this->FormatPrice(this->gridPayCmdAdd->Rows[i]->Cells[3]->Value->ToString()));
				payments[i] = payment;
			}
			for (int i = 0; i < this->gridDispStockCmdAdd->Rows->Count - 1; i++)
			{
				Basket^ article = gcnew Basket();
				article->mIdStock = Convert::ToInt32(this->gridDispStockCmdAdd->Rows[i]->Cells[0]->Value);
				article->mPurchaseQuantity = Convert::ToInt32(this->gridDispStockCmdAdd->Rows[i]->Cells[6]->Value);
				article->mReductionQuantity = Convert::ToDouble(this->FormatPrice(this->gridDispStockCmdAdd->Rows[i]->Cells[7]->Value->ToString()));
				basket[i] = article;
			}
			array<String^>^ tableAddr = gcnew array<String^>(1);
			array<String^>^ tmp_del = gcnew array<String^>(1);
			array<String^>^ tmp_bill = gcnew array<String^>(1);

			tableAddr[0] = "addr";
			tmp_del[0] = "address_del";
			tmp_bill[0] = "address_bill";
			this->data->Merge(this->serviceCust->DisplayAddr(Convert::ToInt32(this->gridDispCustCmdAdd->SelectedRows[0]->Cells[0]->Value), tableAddr, tmp_del, tmp_bill));

			String^ annee = DateTime::Today.ToString()->Substring(6,10);
			annee = annee->Substring(0, 4);
			if (this->data->Tables->Contains(tmp_bill[0]) && this->data->Tables[tmp_bill[0]]->Rows->Count > 0)
			{
				String^ addr_bill = this->data->Tables[tmp_bill[0]]->Rows[0]->ItemArray[4]->ToString()->Substring(0, 3);
		
				String^ ref = fname->Substring(0, 2) +
					lname->Substring(0, 2) +
					annee +
					addr_bill;
				this->serviceCmd->Add(
					this->FormatDate(this->calenDelDateCmdAdd->SelectionStart.ToShortDateString()),
					this->FormatDate(this->calenIDateCmdAdd->SelectionStart.ToShortDateString()),
					Convert::ToDouble(this->FormatPrice(this->discCmdBoxAdd->Text)),
					ref,
					this->selectCust,
					basket,
					payments
				);
				this->Hide();
			}
			else
			{
				MessageBox::Show("This customer don't have any address where we can send the bill");
			}
		}
		else
		{
			MessageBox::Show("Please, enter at least one payment for this order");
		}
	}
};
}
