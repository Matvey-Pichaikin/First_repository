#pragma once

#include "tree.h"

bool tree_is_created = false;
Node* tree = nullptr;

void display() {
	// Set color of background to White
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glLineWidth(2);


	tree->paint_tree(tree, start_left_x, start_right_x, start_down_y, start_up_y);

	glFlush();
}

namespace Binary_tree {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class My_Form : public System::Windows::Forms::Form
	{
	public:
		My_Form(void) {
			InitializeComponent();	
		}
	protected:
		~My_Form() {
			if (components) {
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ add_node;
	private: System::Windows::Forms::Button^ delete_node;

	private: System::Windows::Forms::TextBox^ text_box;
	private: System::Windows::Forms::Label^ label_1;

	protected:


	protected:
	private:
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void) {
			this->add_node = (gcnew System::Windows::Forms::Button());
			this->delete_node = (gcnew System::Windows::Forms::Button());
			this->text_box = (gcnew System::Windows::Forms::TextBox());
			this->label_1 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// add_node
			// 
			this->add_node->BackColor = System::Drawing::Color::LightGray;
			this->add_node->Cursor = System::Windows::Forms::Cursors::Hand;
			this->add_node->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->add_node->FlatAppearance->BorderSize = 2;
			this->add_node->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->add_node->Font = (gcnew System::Drawing::Font(L"Calibri", 19, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->add_node->Location = System::Drawing::Point(150, 140);
			this->add_node->Name = L"add_node";
			this->add_node->Size = System::Drawing::Size(300, 100);
			this->add_node->TabIndex = 0;
			this->add_node->Text = L"ƒобавить значение";
			this->add_node->UseVisualStyleBackColor = false;
			this->add_node->Click += gcnew System::EventHandler(this, &My_Form::add_node_Click);
			// 
			// delete_node
			// 
			this->delete_node->BackColor = System::Drawing::Color::LightGray;
			this->delete_node->Cursor = System::Windows::Forms::Cursors::Hand;
			this->delete_node->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->delete_node->FlatAppearance->BorderSize = 2;
			this->delete_node->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->delete_node->Font = (gcnew System::Drawing::Font(L"Calibri", 19, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->delete_node->Location = System::Drawing::Point(150, 270);
			this->delete_node->Name = L"delete_node";
			this->delete_node->Size = System::Drawing::Size(300, 100);
			this->delete_node->TabIndex = 1;
			this->delete_node->Text = L"”далить значение";
			this->delete_node->UseVisualStyleBackColor = false;
			this->delete_node->Click += gcnew System::EventHandler(this, &My_Form::delete_node_Click);
			// 
			// text_box
			// 
			this->text_box->BackColor = System::Drawing::Color::LightGray;
			this->text_box->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->text_box->Font = (gcnew System::Drawing::Font(L"Calibri", 19, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->text_box->Location = System::Drawing::Point(150, 80);
			this->text_box->Name = L"text_box";
			this->text_box->Size = System::Drawing::Size(300, 38);
			this->text_box->TabIndex = 3;
			this->text_box->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// label_1
			// 
			this->label_1->AutoSize = true;
			this->label_1->Cursor = System::Windows::Forms::Cursors::Default;
			this->label_1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->label_1->Font = (gcnew System::Drawing::Font(L"Calibri", 19, System::Drawing::FontStyle::Italic));
			this->label_1->Location = System::Drawing::Point(30, 10);
			this->label_1->Name = L"label_1";
			this->label_1->Size = System::Drawing::Size(549, 64);
			this->label_1->TabIndex = 4;
			this->label_1->Text = L"¬ведите значение, которое хотите добавить \nв дерево или удалить из дерева";
			this->label_1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// My_Form
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::MediumPurple;
			this->ClientSize = System::Drawing::Size(584, 426);
			this->Controls->Add(this->label_1);
			this->Controls->Add(this->text_box);
			this->Controls->Add(this->delete_node);
			this->Controls->Add(this->add_node);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->Name = L"My_Form";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Binary Tree";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: 
		System::Void add_node_Click(System::Object^ sender, System::EventArgs^ e) {
			if (this->text_box->Text != "") {
				try {
					String^ inputValue = this->text_box->Text->Replace(".", ","); 
					double value = Convert::ToDouble(inputValue);
					std::cout << "\"+\" Ёлемент с значением " << value << " добавлен!\n";
					this->text_box->Text = "";
					if (tree_is_created == false) {
						tree = new Node(value);  
						tree_is_created = true;
					}
					else {
						tree->insert(tree, value);
					}
				}
				catch (FormatException^) {
					MessageBox::Show(this, "¬веденное значение не €вл€етс€ числом!", "ќшибка!", MessageBoxButtons::OK, MessageBoxIcon::Error);
					this->text_box->Text = "";
				}
			}
		}

	private: 
		System::Void delete_node_Click(System::Object^ sender, System::EventArgs^ e) {
			if (this->text_box->Text != "") {
				try {
					String^ inputValue = this->text_box->Text->Replace(".", ","); 
					double value = Convert::ToDouble(inputValue);
					std::cout << "\"-\" Ёлемент с значением " << value << " удалЄн!\n";
					this->text_box->Text = "";
					tree->delete_node(tree, value);
				}
				catch (FormatException^) {
					MessageBox::Show(this, "¬веденное значение не €вл€етс€ числом!", "ќшибка!", MessageBoxButtons::OK, MessageBoxIcon::Error);
					this->text_box->Text = "";
				}
			}
		}
	};
}




