/*-------------------------------------------------------
 * @File Form1	( NCHU 1001 Windows Programming Final Project)
 *-------------------------------------------------------
 * target : Minesweeper	 			
 * create : 100/12/22			
 * update : 101/1/2				
 *-------------------------------------------------------
 * @version 1.0
 * @author 李佳威 
		   江學明
		   林書緯 
 * @note Copyright(c) 2011 ., all rights reserved.
 *-------------------------------------------------------*/

#pragma once
#include "CMine.h" // The Mine Class
#include "About.h"
#include "viewHelp.h"

namespace Final_Project {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Form1 的摘要
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: 在此加入建構函式程式碼
			//
		}

	protected:
		/// <summary>
		/// 清除任何使用中的資源。
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MenuStrip^  menuStrip1;						//選單所需變數
	private: System::Windows::Forms::ToolStripMenuItem^  gameToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  newGameToolStripMenuItem;
	private: System::Windows::Forms::ToolStripSeparator^ firstToolStripSeparator;	
	private: System::Windows::Forms::ToolStripMenuItem^  beginnerToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  intermediateToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  advancedToolStripMenuItem;
	private: System::Windows::Forms::ToolStripSeparator^ secondToolStripSeparator;	
	private: System::Windows::Forms::ToolStripMenuItem^  exitToolStripMenuItem;

	private: System::Windows::Forms::ToolStripMenuItem^  helpToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  viewHelpToolStripMenuItem;
	private: System::Windows::Forms::ToolStripSeparator^ thirdToolStripSeparator;	
	private: System::Windows::Forms::ToolStripMenuItem^  aboutToolStripMenuItem;	//選單所需變數

	private: System::Windows::Forms::Timer^  timer1;								//計時器
	private: array<System::Windows::Forms::PictureBox^,2>^  pictureBox;				//自己定義的pictureBox陣列
	private: System::Windows::Forms::PictureBox^  pictureBoxTimer;					//時間的圖示
	private: System::Windows::Forms::PictureBox^  pictureBoxMine;					//地雷的圖示
	private: System::Windows::Forms::TextBox^  textBoxTimer;						//顯示時間的格子
	private: System::Windows::Forms::TextBox^  textBoxMineCount;					//顯示剩餘地雷數的格子
	private: static int level=0;
			 int time;					// Show time
			 array<CMine*, 2>^ matrix;	// Stores the mines of the game
			 bool gameStart;			// To identify if the game has started
			 bool gameOver;
			 bool rightButton;
			 int mineNo;				// Stores the mine number 
			 int dispMineNo;
			 int matrix_x;				// Store the coordinates of the box clicked
			 int matrix_y;
			 int line;					//行數
			 int row;					//列數


	private: System::ComponentModel::ComponentResourceManager^  resources; 
		/// <summary>
		/// 設計工具所需的變數。
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// 此為設計工具支援所需的方法 - 請使用程式碼編輯器
		/// 修改這個方法的內容。
		/// </summary>
		void InitializeComponent(void)
		{
			if(level==0){
				mineNo = 10; // the number of mine
				line = 9;
				row = 9;
			}else if(level==1){
				mineNo = 40; // the number of mine
				line = 16;
				row = 16;
			}else if(level==2){
				mineNo = 99; // the number of mine
				line = 30;
				row = 16;
			}
			
			matrix = gcnew array<CMine*, 2>(line, row);
			pictureBox = gcnew array<System::Windows::Forms::PictureBox^, 2>(line, row);		//初始化pictureBox的物件
			for(int i=0;i<line;i++){													//把原pictureBox的定義改成迴圈
				for(int j=0;j<row;j++){
					this->pictureBox[i,j] = (gcnew System::Windows::Forms::PictureBox());
					(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox[i,j]))->BeginInit();
				}
			}

			time = 1;
			dispMineNo = mineNo;
			matrix_x = 0;
			matrix_y = 0;

			gameStart = false;
			gameOver = false;
			rightButton = false;

			resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
			
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());								//選單所需變數
			this->gameToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->newGameToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->firstToolStripSeparator = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->beginnerToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->intermediateToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->advancedToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->secondToolStripSeparator = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->exitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());

			this->helpToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->viewHelpToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->thirdToolStripSeparator = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->aboutToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());			//選單所需變數

			this->timer1 = (gcnew System::Windows::Forms::Timer());
			this->pictureBoxTimer = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBoxMine = (gcnew System::Windows::Forms::PictureBox());
			this->textBoxTimer = (gcnew System::Windows::Forms::TextBox());
			this->textBoxMineCount = (gcnew System::Windows::Forms::TextBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBoxTimer))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBoxMine))->BeginInit();
			this->menuStrip1->SuspendLayout();			
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->gameToolStripMenuItem, 
				this->helpToolStripMenuItem});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(284, 24);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// gameToolStripMenuItem
			// 
			this->gameToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(7) {this->newGameToolStripMenuItem, 
				this->firstToolStripSeparator, this->beginnerToolStripMenuItem, this->intermediateToolStripMenuItem, this->advancedToolStripMenuItem, 
				this->secondToolStripSeparator, this->exitToolStripMenuItem});
			this->gameToolStripMenuItem->Name = L"gameToolStripMenuItem";
			this->gameToolStripMenuItem->Size = System::Drawing::Size(54, 20);
			this->gameToolStripMenuItem->Text = L"Game";
			// 
			// newGameToolStripMenuItem
			// 
			this->newGameToolStripMenuItem->Name = L"newGameToolStripMenuItem";
			this->newGameToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			this->newGameToolStripMenuItem->Text = L"New Game";
			this->newGameToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::newGameToolStripMenuItem_Click);			
			// 
			// firstToolStripSeparator
			// 
			this->firstToolStripSeparator->Name = L"firstToolStripSeparator";
			this->firstToolStripSeparator->Size = System::Drawing::Size(149, 6);
			// 
			// beginnerToolStripMenuItem
			// 
			if(level==0)
				this->beginnerToolStripMenuItem->Enabled = false;
			this->beginnerToolStripMenuItem->Name = L"beginnerToolStripMenuItem";
			this->beginnerToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			this->beginnerToolStripMenuItem->Text = L"Beginner";
			this->beginnerToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::beginnerToolStripMenuItem_Click);
			// 
			// intermediateToolStripMenuItem
			// 
			if(level==1)
				this->intermediateToolStripMenuItem->Enabled = false;
			this->intermediateToolStripMenuItem->Name = L"intermediateToolStripMenuItem";
			this->intermediateToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			this->intermediateToolStripMenuItem->Text = L"Intermediate";
			this->intermediateToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::intermediateToolStripMenuItem_Click);
			// 
			// advancedToolStripMenuItem
			// 
			if(level==2)
				this->advancedToolStripMenuItem->Enabled = false;
			this->advancedToolStripMenuItem->Name = L"advancedToolStripMenuItem";
			this->advancedToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			this->advancedToolStripMenuItem->Text = L"Advanced";
			this->advancedToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::advancedToolStripMenuItem_Click);
			// 
			// secondToolStripSeparator
			// 
			this->secondToolStripSeparator->Name = L"secondToolStripSeparator";
			this->secondToolStripSeparator->Size = System::Drawing::Size(149, 6);
			// 
			// exitToolStripMenuItem
			// 
			this->exitToolStripMenuItem->Name = L"exitToolStripMenuItem";
			this->exitToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			this->exitToolStripMenuItem->Text = L"Exit";
			this->exitToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::exitToolStripMenuItem_Click);
			// 
			// helpToolStripMenuItem
			// 
			this->helpToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {this->viewHelpToolStripMenuItem, 
				this->thirdToolStripSeparator, this->aboutToolStripMenuItem});
			this->helpToolStripMenuItem->Name = L"helpToolStripMenuItem";
			this->helpToolStripMenuItem->Size = System::Drawing::Size(47, 20);
			this->helpToolStripMenuItem->Text = L"Help";
			// 
			// viewHelpToolStripMenuItem
			// 
			this->viewHelpToolStripMenuItem->Name = L"viewHelpToolStripMenuItem";
			this->viewHelpToolStripMenuItem->Size = System::Drawing::Size(133, 22);
			this->viewHelpToolStripMenuItem->Text = L"View Help";
			this->viewHelpToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::viewHelpToolStripMenuItem_Click);
			// 
			// thirdToolStripSeparator
			// 
			this->thirdToolStripSeparator->Name = L"thirdToolStripSeparator";
			this->thirdToolStripSeparator->Size = System::Drawing::Size(149, 6);
			// 
			// aboutToolStripMenuItem
			// 
			this->aboutToolStripMenuItem->Name = L"aboutToolStripMenuItem";
			this->aboutToolStripMenuItem->Size = System::Drawing::Size(133, 22);
			this->aboutToolStripMenuItem->Text = L"About...";
			this->aboutToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::aboutToolStripMenuItem_Click);
			// 
			// timer1
			// 
			this->timer1->Enabled = false;
			this->timer1->Interval = 1000;
			this->timer1->Tick += gcnew System::EventHandler(this, &Form1::timer1_Tick);
			// 
			// pictureBox
			// 
			for(int i=0;i<line;i++){												//把原pictureBox的定義改成迴圈
				for(int j=0;j<row;j++){					
					this->pictureBox[i,j]->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"original")));
					this->pictureBox[i,j]->Location = System::Drawing::Point(40+20*i, 50+20*j);
					this->pictureBox[i,j]->Name = L"pictureBox"+i.ToString()+j.ToString();
					this->pictureBox[i,j]->Size = System::Drawing::Size(20, 20);
					this->pictureBox[i,j]->TabIndex = 2+i+j;
					this->pictureBox[i,j]->TabStop = false;
				}
			}
			// 
			// pictureBoxTimer
			// 
			this->pictureBoxTimer->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBoxTimer.BackgroundImage")));
			if(level==0)
				this->pictureBoxTimer->Location = System::Drawing::Point(30, 235);
			else if(level==1)
				this->pictureBoxTimer->Location = System::Drawing::Point(50, 375);
			else if(level==2)
				this->pictureBoxTimer->Location = System::Drawing::Point(90, 375);
			this->pictureBoxTimer->Size = System::Drawing::Size(30, 30);
			this->pictureBoxTimer->Name = L"pictureBoxTimer";
			this->pictureBoxTimer->TabIndex = 2;
			this->pictureBoxTimer->TabStop = false;
			// 
			// pictureBoxMine
			// 
			this->pictureBoxMine->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBoxMine.BackgroundImage")));
			if(level==0)
				this->pictureBoxMine->Location = System::Drawing::Point(200, 235);
			else if(level==1)
				this->pictureBoxMine->Location = System::Drawing::Point(315, 375);
			else if(level==2)
				this->pictureBoxMine->Location = System::Drawing::Point(555, 375);
			this->pictureBoxMine->Size = System::Drawing::Size(30, 30);
			this->pictureBoxMine->Name = L"pictureBoxMine";
			this->pictureBoxMine->TabIndex = 3;
			this->pictureBoxMine->TabStop = false;			
			// 
			// textBoxTimer
			// 
			this->textBoxTimer->Enabled = false;
			if(level==0)
				this->textBoxTimer->Location = System::Drawing::Point(75, 240);
			else if(level==1)
				this->textBoxTimer->Location = System::Drawing::Point(95, 380);
			else if(level==2)
				this->textBoxTimer->Location = System::Drawing::Point(135, 380);
			this->textBoxTimer->Size = System::Drawing::Size(35, 20);
			this->textBoxTimer->Name = L"textBoxTimer";
			this->textBoxTimer->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->textBoxTimer->TabIndex = 4;
			this->textBoxTimer->Text = "" + 0;
			// 
			// textBoxMineCount
			// 
			this->textBoxMineCount->Enabled = false;
			if(level==0)
				this->textBoxMineCount->Location = System::Drawing::Point(155, 240);
			else if(level==1)
				this->textBoxMineCount->Location = System::Drawing::Point(270, 380);
			else if(level==2)
				this->textBoxMineCount->Location = System::Drawing::Point(510, 380);
			this->textBoxMineCount->Size = System::Drawing::Size(35, 20);
			this->textBoxMineCount->Name = L"textBoxMineCount";
			this->textBoxMineCount->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->textBoxMineCount->TabIndex = 5;
			this->textBoxMineCount->Text = "" + mineNo;
			// 
			// Form1
			// 
			if(level==0){
				this->ClientSize = System::Drawing::Size(260, 270);
			}else if(level==1){
				this->ClientSize = System::Drawing::Size(400, 410);
			}else if(level==2){
				this->ClientSize = System::Drawing::Size(680, 410);
			}
			this->Controls->Add(this->menuStrip1);
			this->Controls->Add(this->textBoxMineCount);
			this->Controls->Add(this->textBoxTimer);
			this->Controls->Add(this->pictureBoxMine);
			this->Controls->Add(this->pictureBoxTimer);
			this->Name = L"Form1";
			this->Text = L"Minesweeper";
			this->MaximizeBox = false;														//讓使用者不能點"最大化"
			this->menuStrip1->ResumeLayout(false);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::Fixed3D;		//一種固定大小的Form
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->menuStrip1->PerformLayout();
			for(int i=0;i<line;i++){												//把原pictureBox的MouseEventHandler改成迴圈
				for(int j=0;j<row;j++){
					this->Controls->Add(this->pictureBox[i,j]);
					(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox[i,j]))->EndInit();
					this->pictureBox[i,j]->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::pictureBox_MouseDown);
				}
			}
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBoxTimer))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBoxMine))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();
		}
#pragma endregion
private: 
		System::Void newGameToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			System::Windows::Forms::DialogResult r;
			if (gameStart && !gameOver){
				r = MessageBox::Show(this, "您確定放棄此局遊戲嗎？", "遊戲仍在進行中", MessageBoxButtons::YesNo, MessageBoxIcon::Exclamation);
				if (r == System::Windows::Forms::DialogResult::No)
					return;
			}
			this->Hide();
			Form1^ newForm = gcnew Form1();
			newForm->ShowDialog();	
			this->Close();
		}
		System::Void beginnerToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			System::Windows::Forms::DialogResult r;
			if (gameStart && !gameOver){
				r = MessageBox::Show(this, "您確定放棄此局遊戲嗎？", "遊戲仍在進行中", MessageBoxButtons::YesNo, MessageBoxIcon::Exclamation);
				if (r == System::Windows::Forms::DialogResult::No)
					return;
			}
			level=0;
			this->Hide();
			Form1^ newForm = gcnew Form1();
			newForm->ShowDialog();
			this->Close();
		}
		System::Void intermediateToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			System::Windows::Forms::DialogResult r;
			if (gameStart && !gameOver){
				r = MessageBox::Show(this, "您確定放棄此局遊戲嗎？", "遊戲仍在進行中", MessageBoxButtons::YesNo, MessageBoxIcon::Exclamation);
				if (r == System::Windows::Forms::DialogResult::No)
					return;
			}
			level=1;
			this->Hide();
			Form1^ newForm = gcnew Form1();
			newForm->ShowDialog();
			this->Close();
		}
		System::Void advancedToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			System::Windows::Forms::DialogResult r;
			if (gameStart && !gameOver){
				r = MessageBox::Show(this, "您確定放棄此局遊戲嗎？", "遊戲仍在進行中", MessageBoxButtons::YesNo, MessageBoxIcon::Exclamation);
				if (r == System::Windows::Forms::DialogResult::No)
					return;
			}
			level=2;
			this->Hide();
			Form1^ newForm = gcnew Form1();
			newForm->ShowDialog();
			this->Close();
		}
		System::Void exitToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			System::Windows::Forms::DialogResult r;
			if (gameStart && !gameOver){
				r = MessageBox::Show(this, "您確定放棄此局遊戲嗎？", "遊戲仍在進行中", MessageBoxButtons::YesNo, MessageBoxIcon::Exclamation);
				if (r == System::Windows::Forms::DialogResult::No)
					return;
			}
			this->Close();
		}
		System::Void viewHelpToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			viewHelp^ newForm = gcnew viewHelp();
			newForm->ShowDialog();	
		}
		System::Void aboutToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			About^ newForm = gcnew About();
			newForm->ShowDialog();	
		}



		System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
			textBoxTimer->Text=""+(++time);
		}
		System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
		}
		System::Void extendEmptyBoxes(int x, int y){
			matrix[x, y]->setClicked(true);
			switch (matrix[x, y]->getRoundMineNo()){
				case 0:
					pictureBox[x, y]->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"blank")));
					break;
				case 1:
					pictureBox[x, y]->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"1")));
					break;
				case 2:
					pictureBox[x, y]->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"2")));
					break;
				case 3:
					pictureBox[x, y]->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"3")));
					break;
				case 4:
					pictureBox[x, y]->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"4")));
					break;
				case 5:
					pictureBox[x, y]->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"5")));
					break;
				case 6:
					pictureBox[x, y]->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"6")));
					break;
				case 7:
					pictureBox[x, y]->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"7")));
					break;
				case 8:
					pictureBox[x, y]->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"8")));
					break;
			}

			if (matrix[x, y]->getRoundMineNo() == 0){
				if (x-1 >= 0) 
					if (!matrix[x-1, y]->isClicked()) extendEmptyBoxes(x-1, y);
				if (x+1 < line) 
					if (!matrix[x+1, y]->isClicked()) extendEmptyBoxes(x+1, y);
				if (y-1 >= 0)
					if (!matrix[x, y-1]->isClicked()) extendEmptyBoxes(x, y-1);
				if (y+1 < row)
					if (!matrix[x, y+1]->isClicked()) extendEmptyBoxes(x, y+1);
				if (x-1 >= 0 && y-1 >= 0)
					if (!matrix[x-1, y-1]->isClicked()) extendEmptyBoxes(x-1, y-1);
				if (x+1 < line && y+1 < row)
					if (!matrix[x+1, y+1]->isClicked()) extendEmptyBoxes(x+1, y+1);
				if (x-1 >= 0 && y+1 < row)
					if (!matrix[x-1, y+1]->isClicked()) extendEmptyBoxes(x-1, y+1);
				if (x+1 < line && y-1 >= 0)
					if (!matrix[x+1, y-1]->isClicked()) extendEmptyBoxes(x+1, y-1);
			}
		}
		System::Void pictureBox_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
			// 1 - If the game is over, do not do anything
			if (gameOver) return;

			// 2 - Recognize the mouse button
			if (e->Button == System::Windows::Forms::MouseButtons::Right)
				rightButton = true;
			else
				rightButton = false;
			// 3 - Recognize which picture box is clicked
			for(int i=0; i<line; i++)
				for(int j=0; j<row; j++)
					if (pictureBox[i,j] == sender){
						matrix_x = i;
						matrix_y = j;
					}

			// 4 - Game Initialize in FIRST click a box with LEFT button
			if (!gameStart && rightButton) return;
			if (!gameStart && !rightButton){
				this->timer1->Enabled = true;
				this->textBoxTimer->Text = "" + 1;
				// 4.1 - Initial the 1st box clicked
				// 仔細注意內建的踩地雷，即使地雷數極多，但按下第一格及其周圍八格"必定不會是地雷"
				for(int i = matrix_x-1; i <= matrix_x+1; i++){
					if (i<0 || i>=line) continue;
					for(int j = matrix_y-1; j <= matrix_y+1; j++){
						if (j<0 || j>=row) continue;
						matrix[i, j] = new CMine(false);
					}
				}
				// 4.2 - Set bomb randomly
				int i = 1;	// The number of bombs that had been set
				Random^ rndm = gcnew Random();
				while (i <= mineNo)
				{

					int rndm_x = rndm->Next(line); // 如果以陣列座標大小當作取亂數的範圍，減一就要拿掉，
					int rndm_y = rndm->Next(row); // 因為取出來的亂數必定小於blockX(blockY)
					if (matrix[rndm_x, rndm_y] == nullptr)
					{
						matrix[rndm_x, rndm_y] = new CMine(true);
						i++;
					}
				}
				// 4.3 - Set other boxes that are NOT bomb
				for (int i=0; i<line; i++){
					for (int j=0; j<row; j++){
						if (matrix[i,j] == nullptr)
							matrix[i,j] = new CMine(false);
					}
				}
				// 4.4 - Compute the total around mine number 

				for (int i=0; i<line; i++){
					for (int j=0; j<row; j++){
						if (matrix[i,j]->isMine()){						// 如果matrix[i,j]是地雷
							for(int k = i-1; k <= i+1; k++){				// 在周圍的方塊中roundMineNo加一
								if (k<0 || k>=line) continue;					// 若是在邊緣的方塊索引值超過則忽略
								for(int l = j-1; l <= j+1; l++){
									if (l<0 || l>=row) continue;
									matrix[k, l]->plusRoundMineNo();
								}
							}
						}
					}
				}

				gameStart = true;

			}
			// 5 - Mark the box clicked with right button
			if (gameStart && rightButton && !matrix[matrix_x, matrix_y]->isClicked()){
				matrix[matrix_x, matrix_y]->setMarked(!matrix[matrix_x, matrix_y]->isMarked());
				if (matrix[matrix_x, matrix_y]->isMarked()){
					pictureBox[matrix_x, matrix_y]->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"flag")));
					textBoxMineCount->Text = "" + --dispMineNo;
				}
				else{
					pictureBox[matrix_x, matrix_y]->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"original")));
					textBoxMineCount->Text = "" + ++dispMineNo;
				}
			}
			// 6 - Determine if the box clicked is a mine
			if (!rightButton && !matrix[matrix_x, matrix_y]->isClicked() && !matrix[matrix_x, matrix_y]->isMarked()){
				matrix[matrix_x, matrix_y]->setClicked(true);
				// 6.1 - In case it is a mine
				if (matrix[matrix_x, matrix_y]->isMine()){
					// End the game
					gameOver = true;
					// Show all mines
					for (int i=0; i<line; i++){
						for (int j=0; j<row; j++){
							if (matrix[i, j]->isMine() && !matrix[i, j]->isMarked()) // Show the rest mines that are NOT MARKED
								pictureBox[i, j]->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"bomb")));
							if (!matrix[i, j]->isMine() && matrix[i, j]->isMarked()) // Show "X" signs if the boxes which are NOT mines are WRONGLY MARKED
								pictureBox[i, j]->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"wrongflag")));
						}
					}
					// Show the box clicked as a exploded mine
					pictureBox[matrix_x, matrix_y]->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"out")));
					this->timer1->Enabled = false;
					MessageBox::Show(this, L"很抱歉，這場遊戲您輸了。\n您共花了："+time+"秒。","遊戲結束", MessageBoxButtons::OK, MessageBoxIcon::Error);
				}

				// 6.2 - In case it is NOT a mine
				else 
					extendEmptyBoxes(matrix_x, matrix_y);
			}

			// 7 - Evaluate if user wins the game
			int clickedBoxNo(0);					// Caculate the current number the boxes clicked
			for (int i=0; i<line; i++)
				for(int j=0; j<row; j++)
					if (matrix[i,j]->isClicked()) clickedBoxNo++;
			if (clickedBoxNo + mineNo == line*row){		// clickedBoxNo + mineNo == 9*9 means user won the game
				for (int i=0; i<line; i++){
					for (int j=0; j<row; j++){
						if (matrix[i, j]->isMine())	// Mark flags on all boxes that are mines
							pictureBox[i, j]->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"flag")));
					}
				}
				gameOver = true;					// End the game
				this->timer1->Enabled = false;
				this->textBoxMineCount->Text = "" + 0;
				MessageBox::Show(this, L"恭喜！這場遊戲您贏了。\n您共花了："+time+"秒。","遊戲結束", MessageBoxButtons::OK, MessageBoxIcon::Asterisk);
			}
		}
	};
}