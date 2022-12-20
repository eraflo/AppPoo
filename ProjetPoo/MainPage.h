#pragma once
#include "ServiceCommande.h"
#include "ServiceCustomer.h"
#include "ServiceStaff.h"
#include "ServiceStatistique.h"
#include "ServiceStock.h"

#include "Connexion.h"
#include "Add.h"
#include "Display.h"

namespace ProjetPoo {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Description résumée de MainPage
	/// </summary>
	public ref class MainPage : public System::Windows::Forms::Form
	{
	public:
		MainPage(void)
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
		~MainPage()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		/// <summary>
		/// Variable nécessaire au concepteur.
		/// </summary>
		System::ComponentModel::Container ^components;

		
	//service
	private: NS_Service::ServiceCommande^ serviceCmd;
	private: NS_Service::ServiceStock^ serviceArt;
	private: NS_Service::ServiceCustomer^ serviceCust;
	private: NS_Service::ServiceStaff^ serviceStaff;
	private: System::Data::DataSet^ data;
	private: System::String^ mode;

	private: System::Windows::Forms::TabControl^ TabMain;
	private: System::Windows::Forms::TabPage^ homaTabMain;
	private: System::Windows::Forms::TabPage^ manageTabMain;



	private: System::Windows::Forms::Button^ addBut;
	private: System::Windows::Forms::DataGridView^ gridCmd;

	private: System::Windows::Forms::DataGridView^ gridArt;

	private: System::Windows::Forms::DataGridView^ gridStaff;

	private: System::Windows::Forms::DataGridView^ gridCust;
	private: System::Windows::Forms::Button^ butDelMain;
	private: System::Windows::Forms::Button^ butModifMain;
	private: System::Windows::Forms::Button^ butDispMain;

	private: int nbLineSelected;

	//autres pages forms
	private: Connexion^ pageConnexion;
	private: Add^ pageAdd;



	private: Display^ pageDisp;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Méthode requise pour la prise en charge du concepteur - ne modifiez pas
		/// le contenu de cette méthode avec l'éditeur de code.
		/// </summary>
		void InitializeComponent(void)
		{
			this->TabMain = (gcnew System::Windows::Forms::TabControl());
			this->homaTabMain = (gcnew System::Windows::Forms::TabPage());
			this->addBut = (gcnew System::Windows::Forms::Button());
			this->manageTabMain = (gcnew System::Windows::Forms::TabPage());
			this->butDelMain = (gcnew System::Windows::Forms::Button());
			this->butModifMain = (gcnew System::Windows::Forms::Button());
			this->butDispMain = (gcnew System::Windows::Forms::Button());
			this->gridCmd = (gcnew System::Windows::Forms::DataGridView());
			this->gridArt = (gcnew System::Windows::Forms::DataGridView());
			this->gridStaff = (gcnew System::Windows::Forms::DataGridView());
			this->gridCust = (gcnew System::Windows::Forms::DataGridView());
			this->TabMain->SuspendLayout();
			this->homaTabMain->SuspendLayout();
			this->manageTabMain->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->gridCmd))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->gridArt))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->gridStaff))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->gridCust))->BeginInit();
			this->SuspendLayout();
			// 
			// TabMain
			// 
			this->TabMain->Controls->Add(this->homaTabMain);
			this->TabMain->Controls->Add(this->manageTabMain);
			this->TabMain->Location = System::Drawing::Point(3, 0);
			this->TabMain->Name = L"TabMain";
			this->TabMain->SelectedIndex = 0;
			this->TabMain->Size = System::Drawing::Size(1527, 625);
			this->TabMain->TabIndex = 0;
			this->TabMain->SelectedIndexChanged += gcnew System::EventHandler(this, &MainPage::manageTabEnter);
			// 
			// homaTabMain
			// 
			this->homaTabMain->Controls->Add(this->addBut);
			this->homaTabMain->Location = System::Drawing::Point(4, 25);
			this->homaTabMain->Name = L"homaTabMain";
			this->homaTabMain->Padding = System::Windows::Forms::Padding(3);
			this->homaTabMain->Size = System::Drawing::Size(1519, 596);
			this->homaTabMain->TabIndex = 0;
			this->homaTabMain->Text = L"Home";
			this->homaTabMain->UseVisualStyleBackColor = true;
			this->homaTabMain->Click += gcnew System::EventHandler(this, &MainPage::tabPage1_Click);
			// 
			// addBut
			// 
			this->addBut->Location = System::Drawing::Point(362, 30);
			this->addBut->Name = L"addBut";
			this->addBut->Size = System::Drawing::Size(217, 65);
			this->addBut->TabIndex = 0;
			this->addBut->Text = L"Add";
			this->addBut->UseVisualStyleBackColor = true;
			this->addBut->Click += gcnew System::EventHandler(this, &MainPage::button1_Click);
			// 
			// manageTabMain
			// 
			this->manageTabMain->Controls->Add(this->butDelMain);
			this->manageTabMain->Controls->Add(this->butModifMain);
			this->manageTabMain->Controls->Add(this->butDispMain);
			this->manageTabMain->Controls->Add(this->gridCmd);
			this->manageTabMain->Controls->Add(this->gridArt);
			this->manageTabMain->Controls->Add(this->gridStaff);
			this->manageTabMain->Controls->Add(this->gridCust);
			this->manageTabMain->Location = System::Drawing::Point(4, 25);
			this->manageTabMain->Name = L"manageTabMain";
			this->manageTabMain->Padding = System::Windows::Forms::Padding(3);
			this->manageTabMain->Size = System::Drawing::Size(1519, 596);
			this->manageTabMain->TabIndex = 1;
			this->manageTabMain->Text = L"Manage";
			this->manageTabMain->UseVisualStyleBackColor = true;
			// 
			// butDelMain
			// 
			this->butDelMain->Location = System::Drawing::Point(859, 30);
			this->butDelMain->Name = L"butDelMain";
			this->butDelMain->Size = System::Drawing::Size(159, 47);
			this->butDelMain->TabIndex = 6;
			this->butDelMain->Text = L"Delete";
			this->butDelMain->UseVisualStyleBackColor = true;
			this->butDelMain->Click += gcnew System::EventHandler(this, &MainPage::butDelMain_Click);
			// 
			// butModifMain
			// 
			this->butModifMain->Location = System::Drawing::Point(654, 30);
			this->butModifMain->Name = L"butModifMain";
			this->butModifMain->Size = System::Drawing::Size(159, 47);
			this->butModifMain->TabIndex = 5;
			this->butModifMain->Text = L"Modify";
			this->butModifMain->UseVisualStyleBackColor = true;
			this->butModifMain->Click += gcnew System::EventHandler(this, &MainPage::butModifMain_Click);
			// 
			// butDispMain
			// 
			this->butDispMain->Location = System::Drawing::Point(446, 30);
			this->butDispMain->Name = L"butDispMain";
			this->butDispMain->Size = System::Drawing::Size(159, 47);
			this->butDispMain->TabIndex = 4;
			this->butDispMain->Text = L"Display";
			this->butDispMain->UseVisualStyleBackColor = true;
			this->butDispMain->Click += gcnew System::EventHandler(this, &MainPage::butDispMain_Click);
			// 
			// gridCmd
			// 
			this->gridCmd->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->gridCmd->Location = System::Drawing::Point(795, 117);
			this->gridCmd->MultiSelect = false;
			this->gridCmd->Name = L"gridCmd";
			this->gridCmd->ReadOnly = true;
			this->gridCmd->RowHeadersWidth = 51;
			this->gridCmd->Size = System::Drawing::Size(357, 442);
			this->gridCmd->TabIndex = 3;
			this->gridCmd->SelectionChanged += gcnew System::EventHandler(this, &MainPage::lineChangedCmd);
			// 
			// gridArt
			// 
			this->gridArt->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->gridArt->Location = System::Drawing::Point(1172, 117);
			this->gridArt->MultiSelect = false;
			this->gridArt->Name = L"gridArt";
			this->gridArt->ReadOnly = true;
			this->gridArt->RowHeadersWidth = 51;
			this->gridArt->Size = System::Drawing::Size(335, 442);
			this->gridArt->TabIndex = 2;
			this->gridArt->SelectionChanged += gcnew System::EventHandler(this, &MainPage::lineChangedArt);
			// 
			// gridStaff
			// 
			this->gridStaff->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->gridStaff->Location = System::Drawing::Point(388, 117);
			this->gridStaff->MultiSelect = false;
			this->gridStaff->Name = L"gridStaff";
			this->gridStaff->ReadOnly = true;
			this->gridStaff->RowHeadersWidth = 51;
			this->gridStaff->Size = System::Drawing::Size(388, 442);
			this->gridStaff->TabIndex = 1;
			this->gridStaff->SelectionChanged += gcnew System::EventHandler(this, &MainPage::lineChangedStaff);
			// 
			// gridCust
			// 
			this->gridCust->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->gridCust->Location = System::Drawing::Point(14, 117);
			this->gridCust->MultiSelect = false;
			this->gridCust->Name = L"gridCust";
			this->gridCust->ReadOnly = true;
			this->gridCust->RowHeadersWidth = 51;
			this->gridCust->RowTemplate->Height = 24;
			this->gridCust->Size = System::Drawing::Size(355, 442);
			this->gridCust->TabIndex = 0;
			this->gridCust->SelectionChanged += gcnew System::EventHandler(this, &MainPage::lineChangedCust);
			// 
			// MainPage
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1526, 622);
			this->Controls->Add(this->TabMain);
			this->Name = L"MainPage";
			this->Text = L"MainPage";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &MainPage::MainPage_Closed);
			this->Load += gcnew System::EventHandler(this, &MainPage::MainPage_Load);
			this->TabMain->ResumeLayout(false);
			this->homaTabMain->ResumeLayout(false);
			this->manageTabMain->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->gridCmd))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->gridArt))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->gridStaff))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->gridCust))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void MainPage_Load(System::Object^ sender, System::EventArgs^ e) {
		this->serviceArt = gcnew NS_Service::ServiceStock();
		this->serviceCmd = gcnew NS_Service::ServiceCommande();
		this->serviceStaff = gcnew NS_Service::ServiceStaff();
		this->serviceCust = gcnew NS_Service::ServiceCustomer();
		this->data = gcnew DataSet();

		this->mode = "RIEN";
		
		
		this->pageConnexion = gcnew Connexion();
		this->pageConnexion->ShowDialog();
		this->Hide();
	}
	private: void loadData() {
		this->data->Clear();
		this->gridCust->Refresh();


		array<String^>^ tableCust = gcnew array<String^>(1);
		array<String^>^ tableStaff = gcnew array<String^>(1);
		array<String^>^ tableCmd = gcnew array<String^>(1);
		array<String^>^ tableArt = gcnew array<String^>(1);


		tableCust[0] = "listeCust";
		tableStaff[0] = "listeStaff";
		tableCmd[0] = "listeCmd";
		tableArt[0] = "listeArt";


		this->data = this->serviceCust->DisplayAll(tableCust);
		this->data->Merge(this->serviceStaff->DisplayAll(tableStaff));
		this->data->Merge(this->serviceCmd->DisplayAll(tableCmd));
		this->data->Merge(this->serviceArt->DisplayAll(tableArt));


		this->gridCust->DataSource = this->data;
		this->gridCust->DataMember = tableCust[0];
		this->gridCust->Columns["id_people"]->Visible = false;

		this->gridStaff->DataSource = this->data;
		this->gridStaff->DataMember = tableStaff[0];
		this->gridStaff->Columns["id_people"]->Visible = false;
		this->gridStaff->Columns["id_superior"]->Visible = false;
		this->gridStaff->Columns["id_address"]->Visible = false;

		this->gridCmd->DataSource = this->data;
		this->gridCmd->DataMember = tableCmd[0];
		this->gridCmd->Columns["id_cmd"]->Visible = false;

		this->gridArt->DataSource = this->data;
		this->gridArt->DataMember = tableArt[0];
		this->gridArt->Columns["id_article"]->Visible = false;
	}
	private: System::Void MainPage_Closed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e) {
		delete this->serviceArt;
		delete this->serviceCmd;
		delete this->serviceStaff;
		delete this->serviceCust;
	}
	private: System::Void tabPage1_Click(System::Object^ sender, System::EventArgs^ e) {

	}
	private: void DeselectLineDataGridView(System::Windows::Forms::DataGridView^ datagrid) {
		for (int i = 0; i < datagrid->Rows->Count; i++)
		{
			datagrid->Rows[i]->Selected = false;
		}
	}
	private: int IsSelected(System::Windows::Forms::DataGridView^ datagrid) {
		for (int i = 0; i < datagrid->Rows->Count; i++)
		{
			if (datagrid->Rows[i]->Selected == true)
			{
				return i;
			}
			
		}
		return 0;
	}
	private: System::Void lineChangedCmd(System::Object^ sender, System::EventArgs^ e) {
		this->mode = "Order";
		this->nbLineSelected = this->IsSelected(this->gridCmd);
		this->DeselectLineDataGridView(this->gridArt);
		this->DeselectLineDataGridView(this->gridCust);
		this->DeselectLineDataGridView(this->gridStaff);
	}
	private: System::Void lineChangedArt(System::Object^ sender, System::EventArgs^ e) {
		this->mode = "Article";
		this->nbLineSelected = this->IsSelected(this->gridArt);
		this->DeselectLineDataGridView(this->gridCmd);
		this->DeselectLineDataGridView(this->gridCust);
		this->DeselectLineDataGridView(this->gridStaff);
	}
	private: System::Void lineChangedStaff(System::Object^ sender, System::EventArgs^ e) {
		this->mode = "Staff";
		this->nbLineSelected = this->IsSelected(this->gridStaff);
		this->DeselectLineDataGridView(this->gridCmd);
		this->DeselectLineDataGridView(this->gridCust);
		this->DeselectLineDataGridView(this->gridArt);
	}
	private: System::Void lineChangedCust(System::Object^ sender, System::EventArgs^ e) {
		this->mode = "Customer";
		this->nbLineSelected = this->IsSelected(this->gridCust);
		this->DeselectLineDataGridView(this->gridCmd);
		this->DeselectLineDataGridView(this->gridArt);
		this->DeselectLineDataGridView(this->gridStaff);
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		this->pageAdd = gcnew Add();
		this->pageAdd->ShowDialog();
	}
	private: System::Void manageTabEnter(System::Object^ sender, System::EventArgs^ e) {
		switch (this->TabMain->SelectedIndex)
		{

		case 1:
		{
			//Your Changes
			this->loadData();
			break;
		}
		case 2:
		{
			//Your Changes 
			this->loadData();
			break;
		}
		}
	}
	private: System::Void butDispMain_Click(System::Object^ sender, System::EventArgs^ e) {
		//TODO : passage sur la page affichage
		this->pageDisp = gcnew Display();
		TabPage^ actualTabpage = gcnew TabPage();
		TabPage^ HomeTabpage = gcnew TabPage();
		HomeTabpage = this->pageDisp->GetTabControl()->TabPages[0];
		if (this->mode == "Customer")
		{
			actualTabpage = this->pageDisp->GetTabControl()->TabPages[3];
			this->pageDisp->SetIndex(Convert::ToInt32(this->gridCust->Rows[this->nbLineSelected]->Cells[0]->Value));
		}
		else if (this->mode == "Staff")
		{
			actualTabpage = this->pageDisp->GetTabControl()->TabPages[4];
			this->pageDisp->SetIndex(Convert::ToInt32(this->gridStaff->Rows[this->nbLineSelected]->Cells[0]->Value));
		}
		else if (this->mode == "Article")
		{
			actualTabpage = this->pageDisp->GetTabControl()->TabPages[1];
			this->pageDisp->SetIndex(Convert::ToInt32(this->gridArt->Rows[this->nbLineSelected]->Cells[0]->Value));
		}
		else if (this->mode == "Order")
		{
			actualTabpage = this->pageDisp->GetTabControl()->TabPages[2];
			this->pageDisp->SetIndex(Convert::ToInt32(this->gridCmd->Rows[this->nbLineSelected]->Cells[0]->Value));
		}
		this->pageDisp->SetMode(this->mode);
		this->pageDisp->GetTabControl()->TabPages->Clear();
		this->pageDisp->GetTabControl()->TabPages->Add(HomeTabpage);
		this->pageDisp->GetTabControl()->TabPages->Add(actualTabpage);
		this->pageDisp->Show();
		
	}
	private: System::Void butModifMain_Click(System::Object^ sender, System::EventArgs^ e) {
		//TODO : passage sur la page modif
		if (this->gridArt->SelectedRows->Count == 1)
		{

		}
		else if (this->gridCmd->SelectedRows->Count == 1)
		{

		}
		else if (this->gridStaff->SelectedRows->Count == 1)
		{

		}
		else if (this->gridCust->SelectedRows->Count == 1)
		{

		}
	}
	private: System::Void butDelMain_Click(System::Object^ sender, System::EventArgs^ e) {
		//TODO : suppression
		if (this->gridArt->SelectedRows->Count == 1)
		{

		}
		else if (this->gridCmd->SelectedRows->Count == 1)
		{

		}
		else if (this->gridStaff->SelectedRows->Count == 1)
		{

		}
		else if (this->gridCust->SelectedRows->Count == 1)
		{

		}
	}
};
}
