#pragma once
#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/dnn.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>


namespace CppCLR_WinformsProjekt {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Drawing::Imaging;
	using namespace System::Data::SqlClient;
	using namespace System::Runtime::InteropServices;
	using namespace System::IO;
	using namespace std;
	using namespace cv;		// Required namespace for OpenCV


	VideoCapture capture;
	Mat frame;
	Mat car;
	Mat orignalFrame;
	double crop[4];
	vector<Rect> found;
	Rect box;

	/// <summary>
	/// Zusammenfassung für Form1
	/// </summary>
	public ref class ANPR : public System::Windows::Forms::Form
	{
	
	private:
		System::String^ connString;
		SqlConnection^ connection;
		SqlCommand^ cmd;
		SqlDataAdapter^ adapter;
		DataSet^ dataSet;

	private: System::Windows::Forms::Panel^  sidePanel;
	private: System::Windows::Forms::Panel^  topPanel;
	private: System::Windows::Forms::Button^  parkingRecordsBtn;
	private: System::Windows::Forms::Button^  parkingOUTBtn;

	private: System::Windows::Forms::Button^  licensePlatesBtn;
	private: System::Windows::Forms::Button^  parkingINBtn;
	private: System::Windows::Forms::Panel^  buttonPanel;
	private: System::Windows::Forms::Panel^  linePanel;


	private: System::Windows::Forms::Label^  lblTitle;
	private: System::Windows::Forms::TabPage^  parkingTabPage;
	private: System::Windows::Forms::DataGridView^  parkingDataGridView;

	private: System::Windows::Forms::TabPage^  parkingINTabPage;

	private: System::Windows::Forms::Button^  parkingONBtn;


	private: System::Windows::Forms::PictureBox^  parkingINpictureBox;




	private: System::Windows::Forms::TabControl^  mainTabControl;
	private: System::Windows::Forms::TabPage^  licensePlateTabPage;
	private: System::Windows::Forms::TabPage^  parkingOUTTabPage;
	private: System::Windows::Forms::Label^  lblHeading;
	private: System::Windows::Forms::Label^  lblMadeWith;
	private: System::Windows::Forms::DataGridView^  licensePlatesDataGridView;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;
	private: System::Windows::Forms::PictureBox^  parkingInCarPictureBox;
	private: System::Windows::Forms::PictureBox^  parkingInPlatePictureBox;


	private: System::Windows::Forms::ComboBox^  parkingInSourceComboBox;



	public:
		
		ANPR(void)
		{
			InitializeComponent();
			//
			//TODO: Konstruktorcode hier hinzufügen.
			//

			
			// Initialization and instantiation
			connString = "Data Source = DESKTOP-S4CCM9R\\SQLEXPRESS; Initial Catalog = ANPR; Integrated Security=true";
			connection = gcnew SqlConnection(connString);
		}

	protected:
		/// <summary>
		/// Verwendete Ressourcen bereinigen.
		/// </summary>
		~ANPR()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Timer^  parkingInTimer;
	private: System::ComponentModel::IContainer^  components;



	private:
		
		/// <summary>
		/// Erforderliche Designervariable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Erforderliche Methode für die Designerunterstützung.
		/// Der Inhalt der Methode darf nicht mit dem Code-Editor geändert werden.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(ANPR::typeid));
			this->parkingInTimer = (gcnew System::Windows::Forms::Timer(this->components));
			this->sidePanel = (gcnew System::Windows::Forms::Panel());
			this->lblTitle = (gcnew System::Windows::Forms::Label());
			this->linePanel = (gcnew System::Windows::Forms::Panel());
			this->buttonPanel = (gcnew System::Windows::Forms::Panel());
			this->parkingOUTBtn = (gcnew System::Windows::Forms::Button());
			this->licensePlatesBtn = (gcnew System::Windows::Forms::Button());
			this->parkingINBtn = (gcnew System::Windows::Forms::Button());
			this->parkingRecordsBtn = (gcnew System::Windows::Forms::Button());
			this->topPanel = (gcnew System::Windows::Forms::Panel());
			this->parkingTabPage = (gcnew System::Windows::Forms::TabPage());
			this->parkingDataGridView = (gcnew System::Windows::Forms::DataGridView());
			this->parkingINTabPage = (gcnew System::Windows::Forms::TabPage());
			this->parkingInPlatePictureBox = (gcnew System::Windows::Forms::PictureBox());
			this->parkingInCarPictureBox = (gcnew System::Windows::Forms::PictureBox());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->parkingInSourceComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->parkingONBtn = (gcnew System::Windows::Forms::Button());
			this->parkingINpictureBox = (gcnew System::Windows::Forms::PictureBox());
			this->mainTabControl = (gcnew System::Windows::Forms::TabControl());
			this->licensePlateTabPage = (gcnew System::Windows::Forms::TabPage());
			this->licensePlatesDataGridView = (gcnew System::Windows::Forms::DataGridView());
			this->parkingOUTTabPage = (gcnew System::Windows::Forms::TabPage());
			this->lblHeading = (gcnew System::Windows::Forms::Label());
			this->lblMadeWith = (gcnew System::Windows::Forms::Label());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->sidePanel->SuspendLayout();
			this->parkingTabPage->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->parkingDataGridView))->BeginInit();
			this->parkingINTabPage->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->parkingInPlatePictureBox))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->parkingInCarPictureBox))->BeginInit();
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->parkingINpictureBox))->BeginInit();
			this->mainTabControl->SuspendLayout();
			this->licensePlateTabPage->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->licensePlatesDataGridView))->BeginInit();
			this->SuspendLayout();
			// 
			// parkingInTimer
			// 
			this->parkingInTimer->Interval = 5;
			this->parkingInTimer->Tick += gcnew System::EventHandler(this, &ANPR::parkingInTimer_Tick);
			// 
			// sidePanel
			// 
			this->sidePanel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->sidePanel->Controls->Add(this->lblTitle);
			this->sidePanel->Controls->Add(this->linePanel);
			this->sidePanel->Controls->Add(this->buttonPanel);
			this->sidePanel->Controls->Add(this->parkingOUTBtn);
			this->sidePanel->Controls->Add(this->licensePlatesBtn);
			this->sidePanel->Controls->Add(this->parkingINBtn);
			this->sidePanel->Controls->Add(this->parkingRecordsBtn);
			this->sidePanel->Dock = System::Windows::Forms::DockStyle::Left;
			this->sidePanel->Location = System::Drawing::Point(0, 0);
			this->sidePanel->Name = L"sidePanel";
			this->sidePanel->Size = System::Drawing::Size(147, 442);
			this->sidePanel->TabIndex = 1;
			// 
			// lblTitle
			// 
			this->lblTitle->AutoSize = true;
			this->lblTitle->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblTitle->ForeColor = System::Drawing::Color::White;
			this->lblTitle->Location = System::Drawing::Point(48, 25);
			this->lblTitle->Name = L"lblTitle";
			this->lblTitle->Size = System::Drawing::Size(51, 20);
			this->lblTitle->TabIndex = 0;
			this->lblTitle->Text = L"ANPR";
			// 
			// linePanel
			// 
			this->linePanel->BackColor = System::Drawing::SystemColors::AppWorkspace;
			this->linePanel->Location = System::Drawing::Point(0, 62);
			this->linePanel->Name = L"linePanel";
			this->linePanel->Size = System::Drawing::Size(147, 1);
			this->linePanel->TabIndex = 5;
			// 
			// buttonPanel
			// 
			this->buttonPanel->BackColor = System::Drawing::Color::Indigo;
			this->buttonPanel->ForeColor = System::Drawing::Color::Indigo;
			this->buttonPanel->Location = System::Drawing::Point(0, 103);
			this->buttonPanel->Name = L"buttonPanel";
			this->buttonPanel->Size = System::Drawing::Size(8, 35);
			this->buttonPanel->TabIndex = 4;
			// 
			// parkingOUTBtn
			// 
			this->parkingOUTBtn->FlatAppearance->BorderSize = 0;
			this->parkingOUTBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->parkingOUTBtn->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->parkingOUTBtn->ForeColor = System::Drawing::Color::White;
			this->parkingOUTBtn->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"parkingOUTBtn.Image")));
			this->parkingOUTBtn->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->parkingOUTBtn->Location = System::Drawing::Point(7, 217);
			this->parkingOUTBtn->Name = L"parkingOUTBtn";
			this->parkingOUTBtn->Size = System::Drawing::Size(140, 35);
			this->parkingOUTBtn->TabIndex = 3;
			this->parkingOUTBtn->Text = L"          Parking OUT";
			this->parkingOUTBtn->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->parkingOUTBtn->UseVisualStyleBackColor = true;
			this->parkingOUTBtn->Click += gcnew System::EventHandler(this, &ANPR::parkingOUTBtn_Click);
			// 
			// licensePlatesBtn
			// 
			this->licensePlatesBtn->FlatAppearance->BorderSize = 0;
			this->licensePlatesBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->licensePlatesBtn->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->licensePlatesBtn->ForeColor = System::Drawing::Color::White;
			this->licensePlatesBtn->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"licensePlatesBtn.Image")));
			this->licensePlatesBtn->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->licensePlatesBtn->Location = System::Drawing::Point(7, 141);
			this->licensePlatesBtn->Name = L"licensePlatesBtn";
			this->licensePlatesBtn->Size = System::Drawing::Size(140, 35);
			this->licensePlatesBtn->TabIndex = 2;
			this->licensePlatesBtn->Text = L"          License Plates";
			this->licensePlatesBtn->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->licensePlatesBtn->UseVisualStyleBackColor = true;
			this->licensePlatesBtn->Click += gcnew System::EventHandler(this, &ANPR::licensePlatesBtn_Click);
			// 
			// parkingINBtn
			// 
			this->parkingINBtn->FlatAppearance->BorderSize = 0;
			this->parkingINBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->parkingINBtn->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->parkingINBtn->ForeColor = System::Drawing::Color::White;
			this->parkingINBtn->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"parkingINBtn.Image")));
			this->parkingINBtn->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->parkingINBtn->Location = System::Drawing::Point(7, 179);
			this->parkingINBtn->Name = L"parkingINBtn";
			this->parkingINBtn->Size = System::Drawing::Size(140, 35);
			this->parkingINBtn->TabIndex = 1;
			this->parkingINBtn->Text = L"          Parking IN";
			this->parkingINBtn->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->parkingINBtn->UseVisualStyleBackColor = true;
			this->parkingINBtn->Click += gcnew System::EventHandler(this, &ANPR::parkingINBtn_Click);
			// 
			// parkingRecordsBtn
			// 
			this->parkingRecordsBtn->FlatAppearance->BorderSize = 0;
			this->parkingRecordsBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->parkingRecordsBtn->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->parkingRecordsBtn->ForeColor = System::Drawing::Color::White;
			this->parkingRecordsBtn->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"parkingRecordsBtn.Image")));
			this->parkingRecordsBtn->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->parkingRecordsBtn->Location = System::Drawing::Point(7, 103);
			this->parkingRecordsBtn->Name = L"parkingRecordsBtn";
			this->parkingRecordsBtn->Size = System::Drawing::Size(140, 35);
			this->parkingRecordsBtn->TabIndex = 0;
			this->parkingRecordsBtn->Text = L"          Parking Records";
			this->parkingRecordsBtn->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->parkingRecordsBtn->UseVisualStyleBackColor = true;
			this->parkingRecordsBtn->Click += gcnew System::EventHandler(this, &ANPR::parkingRecordsBtn_Click);
			// 
			// topPanel
			// 
			this->topPanel->BackColor = System::Drawing::Color::Indigo;
			this->topPanel->Dock = System::Windows::Forms::DockStyle::Top;
			this->topPanel->Location = System::Drawing::Point(147, 0);
			this->topPanel->Name = L"topPanel";
			this->topPanel->Size = System::Drawing::Size(596, 12);
			this->topPanel->TabIndex = 2;
			// 
			// parkingTabPage
			// 
			this->parkingTabPage->BackColor = System::Drawing::Color::White;
			this->parkingTabPage->Controls->Add(this->parkingDataGridView);
			this->parkingTabPage->Location = System::Drawing::Point(4, 22);
			this->parkingTabPage->Name = L"parkingTabPage";
			this->parkingTabPage->Size = System::Drawing::Size(570, 348);
			this->parkingTabPage->TabIndex = 2;
			this->parkingTabPage->Text = L"Parking Records";
			// 
			// parkingDataGridView
			// 
			this->parkingDataGridView->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->parkingDataGridView->Location = System::Drawing::Point(4, 3);
			this->parkingDataGridView->Name = L"parkingDataGridView";
			this->parkingDataGridView->Size = System::Drawing::Size(563, 346);
			this->parkingDataGridView->TabIndex = 0;
			// 
			// parkingINTabPage
			// 
			this->parkingINTabPage->BackColor = System::Drawing::Color::White;
			this->parkingINTabPage->Controls->Add(this->parkingInPlatePictureBox);
			this->parkingINTabPage->Controls->Add(this->parkingInCarPictureBox);
			this->parkingINTabPage->Controls->Add(this->groupBox1);
			this->parkingINTabPage->Controls->Add(this->parkingINpictureBox);
			this->parkingINTabPage->Location = System::Drawing::Point(4, 22);
			this->parkingINTabPage->Name = L"parkingINTabPage";
			this->parkingINTabPage->Padding = System::Windows::Forms::Padding(3);
			this->parkingINTabPage->Size = System::Drawing::Size(570, 348);
			this->parkingINTabPage->TabIndex = 1;
			this->parkingINTabPage->Text = L"Parking In";
			// 
			// parkingInPlatePictureBox
			// 
			this->parkingInPlatePictureBox->BackColor = System::Drawing::Color::WhiteSmoke;
			this->parkingInPlatePictureBox->Location = System::Drawing::Point(408, 204);
			this->parkingInPlatePictureBox->Name = L"parkingInPlatePictureBox";
			this->parkingInPlatePictureBox->Size = System::Drawing::Size(111, 52);
			this->parkingInPlatePictureBox->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->parkingInPlatePictureBox->TabIndex = 5;
			this->parkingInPlatePictureBox->TabStop = false;
			// 
			// parkingInCarPictureBox
			// 
			this->parkingInCarPictureBox->BackColor = System::Drawing::Color::WhiteSmoke;
			this->parkingInCarPictureBox->Location = System::Drawing::Point(373, 69);
			this->parkingInCarPictureBox->Name = L"parkingInCarPictureBox";
			this->parkingInCarPictureBox->Size = System::Drawing::Size(177, 106);
			this->parkingInCarPictureBox->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->parkingInCarPictureBox->TabIndex = 4;
			this->parkingInCarPictureBox->TabStop = false;
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->parkingInSourceComboBox);
			this->groupBox1->Controls->Add(this->parkingONBtn);
			this->groupBox1->Location = System::Drawing::Point(6, 24);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(350, 38);
			this->groupBox1->TabIndex = 3;
			this->groupBox1->TabStop = false;
			// 
			// parkingInSourceComboBox
			// 
			this->parkingInSourceComboBox->FormattingEnabled = true;
			this->parkingInSourceComboBox->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"Picture", L"Video", L"Camera" });
			this->parkingInSourceComboBox->Location = System::Drawing::Point(7, 10);
			this->parkingInSourceComboBox->Name = L"parkingInSourceComboBox";
			this->parkingInSourceComboBox->Size = System::Drawing::Size(262, 21);
			this->parkingInSourceComboBox->TabIndex = 2;
			// 
			// parkingONBtn
			// 
			this->parkingONBtn->Location = System::Drawing::Point(275, 8);
			this->parkingONBtn->Name = L"parkingONBtn";
			this->parkingONBtn->Size = System::Drawing::Size(69, 23);
			this->parkingONBtn->TabIndex = 1;
			this->parkingONBtn->Text = L"Start";
			this->parkingONBtn->UseVisualStyleBackColor = true;
			this->parkingONBtn->Click += gcnew System::EventHandler(this, &ANPR::parkingONBtn_Click);
			// 
			// parkingINpictureBox
			// 
			this->parkingINpictureBox->BackColor = System::Drawing::Color::WhiteSmoke;
			this->parkingINpictureBox->Location = System::Drawing::Point(6, 69);
			this->parkingINpictureBox->Name = L"parkingINpictureBox";
			this->parkingINpictureBox->Size = System::Drawing::Size(350, 242);
			this->parkingINpictureBox->TabIndex = 0;
			this->parkingINpictureBox->TabStop = false;
			// 
			// mainTabControl
			// 
			this->mainTabControl->Controls->Add(this->parkingTabPage);
			this->mainTabControl->Controls->Add(this->licensePlateTabPage);
			this->mainTabControl->Controls->Add(this->parkingINTabPage);
			this->mainTabControl->Controls->Add(this->parkingOUTTabPage);
			this->mainTabControl->Location = System::Drawing::Point(153, 43);
			this->mainTabControl->Name = L"mainTabControl";
			this->mainTabControl->SelectedIndex = 0;
			this->mainTabControl->Size = System::Drawing::Size(578, 374);
			this->mainTabControl->TabIndex = 0;
			this->mainTabControl->SelectedIndexChanged += gcnew System::EventHandler(this, &ANPR::mainTabControl_SelectedIndexChanged);
			// 
			// licensePlateTabPage
			// 
			this->licensePlateTabPage->BackColor = System::Drawing::Color::White;
			this->licensePlateTabPage->Controls->Add(this->licensePlatesDataGridView);
			this->licensePlateTabPage->Location = System::Drawing::Point(4, 22);
			this->licensePlateTabPage->Name = L"licensePlateTabPage";
			this->licensePlateTabPage->Size = System::Drawing::Size(570, 348);
			this->licensePlateTabPage->TabIndex = 3;
			this->licensePlateTabPage->Text = L"License Plates Records";
			// 
			// licensePlatesDataGridView
			// 
			this->licensePlatesDataGridView->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->licensePlatesDataGridView->Location = System::Drawing::Point(4, 4);
			this->licensePlatesDataGridView->Name = L"licensePlatesDataGridView";
			this->licensePlatesDataGridView->Size = System::Drawing::Size(563, 341);
			this->licensePlatesDataGridView->TabIndex = 0;
			// 
			// parkingOUTTabPage
			// 
			this->parkingOUTTabPage->BackColor = System::Drawing::Color::White;
			this->parkingOUTTabPage->Location = System::Drawing::Point(4, 22);
			this->parkingOUTTabPage->Name = L"parkingOUTTabPage";
			this->parkingOUTTabPage->Size = System::Drawing::Size(570, 348);
			this->parkingOUTTabPage->TabIndex = 4;
			this->parkingOUTTabPage->Text = L"Parking Out";
			// 
			// lblHeading
			// 
			this->lblHeading->AutoSize = true;
			this->lblHeading->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblHeading->Location = System::Drawing::Point(157, 19);
			this->lblHeading->Name = L"lblHeading";
			this->lblHeading->Size = System::Drawing::Size(68, 21);
			this->lblHeading->TabIndex = 3;
			this->lblHeading->Text = L"Heading";
			// 
			// lblMadeWith
			// 
			this->lblMadeWith->AutoSize = true;
			this->lblMadeWith->Location = System::Drawing::Point(377, 420);
			this->lblMadeWith->Name = L"lblMadeWith";
			this->lblMadeWith->Size = System::Drawing::Size(125, 13);
			this->lblMadeWith->TabIndex = 4;
			this->lblMadeWith->Text = L"Made with ❤ in Pakistan";
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// ANPR
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(743, 442);
			this->Controls->Add(this->lblMadeWith);
			this->Controls->Add(this->lblHeading);
			this->Controls->Add(this->topPanel);
			this->Controls->Add(this->sidePanel);
			this->Controls->Add(this->mainTabControl);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"ANPR";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"ANPR";
			this->Load += gcnew System::EventHandler(this, &ANPR::ANPR_Load);
			this->sidePanel->ResumeLayout(false);
			this->sidePanel->PerformLayout();
			this->parkingTabPage->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->parkingDataGridView))->EndInit();
			this->parkingINTabPage->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->parkingInPlatePictureBox))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->parkingInCarPictureBox))->EndInit();
			this->groupBox1->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->parkingINpictureBox))->EndInit();
			this->mainTabControl->ResumeLayout(false);
			this->licensePlateTabPage->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->licensePlatesDataGridView))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void ANPR_Load(System::Object^  sender, System::EventArgs^  e) {
		
		// Hide TabControl Header
		mainTabControl->Appearance = TabAppearance::FlatButtons;
		mainTabControl->ItemSize = System::Drawing::Size(0, 1);
		mainTabControl->SizeMode = TabSizeMode::Fixed;

		// Setting Heading Label
		lblHeading->Text = mainTabControl->SelectedTab->Text;

		// Loading Parking Records from DB to parkingDataGridView
		DataSet^ dataSet = getParkingRecords();
		parkingDataGridView->DataSource = dataSet->Tables[0];
		
		// Resizing cells of parkingDataGridView
		parkingDataGridView->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::DisplayedCells;
		parkingDataGridView->AutoSizeRowsMode = System::Windows::Forms::DataGridViewAutoSizeRowsMode::DisplayedCells;


	}
	private: System::Void parkingRecordsBtn_Click(System::Object^  sender, System::EventArgs^  e) {
		// Setting ButtonPanel for UI
		buttonPanel->Height = parkingRecordsBtn->Height;
		buttonPanel->Top = parkingRecordsBtn->Top;

		// Select TabPage on Button click
		mainTabControl->SelectTab("parkingTabPage");

		// Loading Parking Records from DB to parkingDataGridView
		DataSet^ dataSet = getParkingRecords();
		parkingDataGridView->DataSource = dataSet->Tables[0];
	}
	private: System::Void licensePlatesBtn_Click(System::Object^  sender, System::EventArgs^  e) {
		// Setting ButtonPanel for UI
		buttonPanel->Height = licensePlatesBtn->Height;
		buttonPanel->Top = licensePlatesBtn->Top;

		// Select TabPage on Button click
		mainTabControl->SelectTab("licensePlateTabPage");

		// Loading License Plates Records from DB to parkingDataGridView
		DataSet^ dataSet = getLicensePlatesRecords();
		licensePlatesDataGridView->DataSource = dataSet->Tables[0];
	}
	private: System::Void parkingINBtn_Click(System::Object^  sender, System::EventArgs^  e) {
		// Setting ButtonPanel for UI
		buttonPanel->Height = parkingINBtn->Height;
		buttonPanel->Top = parkingINBtn->Top;

		// Select TabPage on Button click
		mainTabControl->SelectTab("parkingINTabPage");

	}
	private: System::Void parkingOUTBtn_Click(System::Object^  sender, System::EventArgs^  e) {
		// Setting ButtonPanel for UI
		buttonPanel->Height = parkingOUTBtn->Height;
		buttonPanel->Top = parkingOUTBtn->Top;

		// Select TabPage on Button click
		mainTabControl->SelectTab("parkingOUTTabPage");
	}

	private: System::Void mainTabControl_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
		// Setting Heading Label
		lblHeading->Text = mainTabControl->SelectedTab->Text;
	}

	private: System::Void parkingONBtn_Click(System::Object^  sender, System::EventArgs^  e) {

		if (parkingONBtn->Text == "Start")
		{
			if (parkingInSourceComboBox->Text == "Picture")
			{

			}
			else if (parkingInSourceComboBox->Text == "Video")
			{
				openFileDialog1->Filter = "AVI files (*.avi)|*.txt|All files (*.*)|*.*";
				openFileDialog1->FilterIndex = 2;
				openFileDialog1->RestoreDirectory = true;
				openFileDialog1->FileName = "";


				if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
				{
					char *fileName = (char*)Marshal::StringToHGlobalAnsi(openFileDialog1->FileName).ToPointer();

					VideoCapture c(fileName);
					capture = c;
					parkingONBtn->Text = "Stop";
					parkingInTimer->Start();
				}
			}
			else if (parkingInSourceComboBox->Text == "Camera")
			{
				parkingONBtn->Text = "Stop";

				capture.open(0);

				if (!capture.isOpened())  // check if we succeeded
					MessageBox::Show("Video Capture failed", "Error", MessageBoxButtons::OK, MessageBoxIcon::Asterisk);
				else
				{
					parkingInTimer->Start();
				}
			}
			
			
		}
		else
		{
			if (parkingInSourceComboBox->Text == "Picture")
			{

			}
			else if (parkingInSourceComboBox->Text == "Video")
			{
				capture.release();
				
				parkingInTimer->Stop();
				parkingONBtn->Text = "Start";
			}
			else if (parkingInSourceComboBox->Text == "Camera")
			{
				capture.release();
				parkingInTimer->Stop();

				//addParkingIn();

				parkingONBtn->Text = "Start";
			}
			
		}
	}
	private: System::Void parkingInTimer_Tick(System::Object^  sender, System::EventArgs^  e) {
		capture.read(frame);
		Mat tempFrame = frame;
		// frame = finder(frame, "haarcascade_frontalface_alt.xml");
		if (!frame.empty())
		{
			frame = carFinder(frame);

			// 
			if (!found.empty())
			{
				
				box.width = crop[0];
				box.height = crop[1];
				box.x = crop[2];
				box.y = crop[3];

				Mat tempCar(frame, box);
				orignalFrame = tempFrame;

				
				System::Drawing::Bitmap^ bitmapImg2 = gcnew System::Drawing::Bitmap
				(tempCar.cols, tempCar.rows, tempCar.step,
					System::Drawing::Imaging::PixelFormat::Format24bppRgb, (System::IntPtr) tempCar.data);

				System::Drawing::Bitmap^ resultImg2 = gcnew System::Drawing::Bitmap
				(parkingINpictureBox->Width, parkingINpictureBox->Height);

				System::Drawing::Graphics^ g = System::Drawing::Graphics::FromImage(resultImg2);
				g->DrawImage(bitmapImg2, 0, 0, parkingINpictureBox->Width, parkingINpictureBox->Height);
				parkingInCarPictureBox->Image = resultImg2;
				parkingInCarPictureBox->Refresh();
			}
			
			System::Drawing::Bitmap^ bitmapImg = gcnew System::Drawing::Bitmap
			(frame.cols, frame.rows, frame.step,
				System::Drawing::Imaging::PixelFormat::Format24bppRgb, (System::IntPtr) frame.data);

			System::Drawing::Bitmap^ resultImg = gcnew System::Drawing::Bitmap
			(parkingINpictureBox->Width, parkingINpictureBox->Height);

			System::Drawing::Graphics^ g = System::Drawing::Graphics::FromImage(resultImg);
			g->DrawImage(bitmapImg, 0, 0, parkingINpictureBox->Width, parkingINpictureBox->Height);
			parkingINpictureBox->Image = resultImg;

			parkingINpictureBox->Refresh();
		}
		else 
		{
			capture.release();
			parkingInTimer->Stop();
			parkingONBtn->Text = "Start";


			// plate decdector
			//imshow("Orignal", orignalFrame);

			box.width = crop[0]*1.8;
			box.height = crop[1]*0.5;
			box.x = crop[2]*4.725;
			box.y = crop[3]*4.785;

			Mat bumper(orignalFrame, box);

			CascadeClassifier detector;

			bool loaded = detector.load("number plate.xml");
			// Parameters of detectMultiscale Cascade Classifier
			int groundThreshold = 1;
			double scaleStep = 1.1;
			cv::Size minimalObjectSize(10, 10);
			cv::Size maximalObjectSize(100, 100);
			// Vector of returned found
			// Convert input to greyscale 
			Mat image_grey;
			cvtColor(bumper, image_grey, CV_BGR2GRAY);
			// why not
			found.clear();
			// Detect found
			detector.detectMultiScale(image_grey, found, scaleStep, groundThreshold, 0 | 2, minimalObjectSize);
			// Draw circles on the detected found
			int i = 0;
			for (; i < found.size(); i++)
			{
				cv::Point pt1(found[i].x, found[i].y); // Display detected faces on main window - live stream from camera
				cv::Point pt2((found[i].x + found[i].height+15), (found[i].y + found[i].width-5));
				rectangle(bumper, pt1, pt2, Scalar(0, 255, 0), 2, 8, 0);

			}
			i--;
			box.width = found[i].width-11;
			box.height = found[i].height-20;
			box.x = found[i].x+17;
			box.y = found[i].y+11;
			Mat np(bumper,box);
			//resize(np, np, cv::Size(350, 175));
			//imwrite("img.jpg", np);

			//cv::resize(np, np, cv::Size(111, 52));
			
			System::Drawing::Bitmap^ bitmapImg3 = gcnew System::Drawing::Bitmap
			(np.cols, np.rows, np.step,
				System::Drawing::Imaging::PixelFormat::Format24bppRgb, (System::IntPtr) np.data);

			parkingInPlatePictureBox->Image = bitmapImg3;
			parkingInPlatePictureBox->Refresh();

			imwrite("final.jpg", np);

			// Hardcoded
			addParkingIn();
		}
		
	}
	private: Mat carFinder(Mat img)
	{
		
		resize(img, img, cv::Size(540, 360));
		// Load cascate classifier placed in sulution folder
		CascadeClassifier detector;

		bool loaded = detector.load("cars.xml");
		// Parameters of detectMultiscale Cascade Classifier
		int groundThreshold = 2;
		double scaleStep = 1.1;
		cv::Size minimalObjectSize(150, 150);
		cv::Size maximalObjectSize(100, 100);
		// Vector of returned found
		// Convert input to greyscale 
		Mat image_grey;
		cvtColor(img, image_grey, CV_BGR2GRAY);
		// why not
		found.clear();
		// Detect found
		detector.detectMultiScale(image_grey, found, scaleStep, groundThreshold, 0 | 2, minimalObjectSize);
		// Draw circles on the detected found
		int i = 0;
		for (; i < found.size(); i++)
		{
			cv::Point pt1(found[i].x, found[i].y); // Display detected faces on main window - live stream from camera
			cv::Point pt2((found[i].x + found[i].height), (found[i].y + found[i].width));
			rectangle(img, pt1, pt2, Scalar(0, 255, 0), 2, 8, 0);

		}
		if (!found.empty()) 
		{
			i--;
			crop[0] = found[i].width;
			crop[1] = found[i].height;
			crop[2] = found[i].x;
			crop[3] = found[i].y;
		}
		
		//imshow("img", img);
		return img;


	}



    /*
	private: void addLicensePlate()
	{
		System::String^ licensePlateNumber = this->LicencePlateNumbertxt->Text;

		try
		{
			connection->Open();
			cmd = gcnew SqlCommand();
			cmd->Connection = connection;
			cmd->CommandText = "AddLicensePlate";
			cmd->CommandType = CommandType::StoredProcedure;
			cmd->Parameters->Add("@LicensePlateNumber", SqlDbType::NVarChar)->Value = licensePlateNumber;
			cmd->ExecuteNonQuery();
			MessageBox::Show(licensePlateNumber + " sucessfully added.", "Sucessfully Added", MessageBoxButtons::OK, MessageBoxIcon::Information);
		}
		catch (System::Exception^ ex)
		{
			MessageBox::Show(ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Asterisk);
		}
		finally
		{
			connection->Close();
		}
	}
	*/
	private: System::Data::DataSet^ getParkingRecords()
	{
		cmd = gcnew SqlCommand();
		adapter = gcnew SqlDataAdapter();
		dataSet = gcnew DataSet();

		try
		{
			cmd->Connection = connection;
			cmd->CommandText = "GetAllParkingRecords";
			cmd->CommandType = CommandType::StoredProcedure;

			adapter->SelectCommand = cmd;
			adapter->Fill(dataSet);
			return dataSet;
		}
		catch (System::Exception^ ex)
		{
			MessageBox::Show(ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Asterisk);
		}
		finally
		{
			connection->Close();
		}

		return dataSet;
	}

	private: System::Data::DataSet^ getLicensePlatesRecords()
	{
		cmd = gcnew SqlCommand();
		adapter = gcnew SqlDataAdapter();
		dataSet = gcnew DataSet();

		try
		{
			cmd->Connection = connection;
			cmd->CommandText = "GetLicensePlates";
			cmd->CommandType = CommandType::StoredProcedure;

			adapter->SelectCommand = cmd;
			adapter->Fill(dataSet);
			return dataSet;
		}
		catch (System::Exception^ ex)
		{
			MessageBox::Show(ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Asterisk);
		}
		finally
		{
			connection->Close();
		}

		return dataSet;
	}

	private: void addParkingIn()
	{
		try
		{
			connection->Open();
			cmd = gcnew SqlCommand();
			cmd->Connection = connection;
			cmd->CommandText = "AddParkingInByLicensePlateNumber";
			cmd->CommandType = CommandType::StoredProcedure;
			cmd->Parameters->Add("@LicensePlateNumber", SqlDbType::NChar)->Value = "MN1084";

			Image^ theImage = parkingINpictureBox->Image;
			MemoryStream^ memoryStream = gcnew MemoryStream();

			theImage->Save(memoryStream, System::Drawing::Imaging::ImageFormat::Jpeg);

			cmd->Parameters->Add("@ParkingInImage", SqlDbType::VarBinary)->Value = memoryStream->ToArray();
			memoryStream->Close();
			cmd->ExecuteNonQuery();
			MessageBox::Show("Parked IN sucessfully.", "Parked IN", MessageBoxButtons::OK, MessageBoxIcon::Information);
		}
		catch (System::Exception^ ex)
		{
			MessageBox::Show(ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Asterisk);
		}
		finally
		{
			connection->Close();
		}
	}
	
	private: Mat finder(Mat img, string cass)
	{
		orignalFrame = img;
		
		resize(img, img, cv::Size(300, 200));
		// Load cascate classifier placed in sulution folder
		CascadeClassifier detector;
		string cascadeName = cass;
		bool loaded = detector.load(cascadeName);
		// Parameters of detectMultiscale Cascade Classifier
		int groundThreshold = 2;
		double scaleStep = 1.1;
		cv::Size minimalObjectSize(45, 45);
		cv::Size maximalObjectSize(130, 130);
		// Vector of returned found
		vector<Rect> found;
		// Convert input to greyscale 
		Mat image_grey;
		cvtColor(img, image_grey, CV_BGR2GRAY);
		// why not
		found.clear();
		// Detect found
		detector.detectMultiScale(image_grey, found, scaleStep, groundThreshold, 0 | 2, minimalObjectSize, maximalObjectSize);
		// Draw circles on the detected found
		for (int i = 0; i < found.size(); i++)
		{
			cv::Point pt1(found[i].x, found[i].y); // Display detected faces on main window - live stream from camera
			cv::Point pt2((found[i].x + found[i].height), (found[i].y + found[i].width));
			rectangle(img, pt1, pt2, Scalar(0, 255, 0), 2, 8, 0);

		}

		return img;

	}


	
};
}
