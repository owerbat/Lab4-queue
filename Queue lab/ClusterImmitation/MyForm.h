#pragma once
#include "Structs.h"
#include "..\Queue lab\TQueue.h"
#include <stdlib.h>

int FreeProcCount(Processor *arr, int _procCount) {
	int res = 0;
	for (int i = 0; i < _procCount; i++) {
		if (arr[i].free) {
			res++;
		}
	}
	return res;
}

namespace ClusterImmitation {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	private:

		Graphics^ gr;
		TQueue<Task> *qTask;
		int TactsCount;
		int FullQTaskCount;
		Processor *ProcArray;
		int CountOfInactiveTacts;
		double InactiveTactsPerProcessor;
		int IDCounter;
		int CountOfCurrentTasks;
		



	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Label^  label5;

	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Button^  button3;
			





	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//

			gr = CreateGraphics();
			qTask = new TQueue<Task>(10);

	
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^  textBox1;
	protected:
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::TextBox^  textBox4;
	private: System::Windows::Forms::Timer^  timer1;
	private: System::ComponentModel::IContainer^  components;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(170, 17);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(66, 22);
			this->textBox1->TabIndex = 0;
			this->textBox1->Text = L"16";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 17);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(142, 17);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Кол-во процессоров";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(12, 55);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(119, 17);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Вероятность (%)";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(170, 55);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(66, 22);
			this->textBox2->TabIndex = 2;
			this->textBox2->Text = L"50";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(12, 138);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(122, 17);
			this->label3->TabIndex = 5;
			this->label3->Text = L"Максимум тактов";
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(170, 135);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(66, 22);
			this->textBox3->TabIndex = 4;
			this->textBox3->Text = L"10";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(12, 95);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(115, 17);
			this->label4->TabIndex = 7;
			this->label4->Text = L"Максимум узлов";
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(170, 95);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(66, 22);
			this->textBox4->TabIndex = 6;
			this->textBox4->Text = L"8";
			// 
			// timer1
			// 
			this->timer1->Interval = 1000;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(89, 179);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 8;
			this->button1->Text = L"Готово";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(15, 224);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 9;
			this->button2->Text = L"Старт";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(161, 224);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(75, 23);
			this->button3->TabIndex = 10;
			this->button3->Text = L"Стоп";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(12, 311);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(99, 17);
			this->label5->TabIndex = 12;
			this->label5->Text = L"Текущий такт";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(12, 586);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(90, 17);
			this->label6->TabIndex = 13;
			this->label6->Text = L"Исключение";
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(78, 270);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(95, 23);
			this->button4->TabIndex = 14;
			this->button4->Text = L"Статистика";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(190, 311);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(16, 17);
			this->label7->TabIndex = 15;
			this->label7->Text = L"0";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1315, 612);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox1);
			this->Name = L"MyForm";
			this->Text = L" ";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		int ProcCount = Convert::ToInt32(textBox1->Text);
		
		TactsCount = 0;
		FullQTaskCount = 0;
		CountOfInactiveTacts = 0;
		InactiveTactsPerProcessor = 0.0;
		IDCounter = 0;
		CountOfCurrentTasks = 0;

		ProcArray = new Processor[ProcCount];
		for (int i = 0; i < ProcCount; i++) {
			ProcArray[i].free = true;
			ProcArray[i].ActiveTaskID = -1;
			ProcArray[i].CurrentStepCount = 0;
			ProcArray[i].MaxStepCount = 0;
			ProcArray[i].InactiveTactsCount = 0;
			ProcArray[i].id = i;
		}

		int x = 300, y = 10, width = 90, height = 65;
		int dx = 100, dy = 75;
		for (int i = 0; i < ProcCount; i++) {

			ProcArray[i].X = x;
			ProcArray[i].Y = y;

			gr->FillRectangle(Brushes::Gray, x, y, width, height);

			if (i % 8 == 7) {
				y += dy;
				x = 300;
			}
			else {
				x += dx;
			}
		}

		gr->FillRectangle(Brushes::White, 1164, 9, 92, 592);

	}
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
	timer1->Enabled = true;
}
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
	timer1->Enabled = false;
}
private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
	try {

		int CountOfProc = Convert::ToInt32(textBox1->Text);
		int probability = Convert::ToInt32(textBox2->Text);
		int MaxTaskProc = Convert::ToInt32(textBox4->Text);
		int MaxTaskTact = Convert::ToInt32(textBox3->Text);
		
		float TaskHeight = 590.0 / (qTask->getMaxsize());
		Pen ^blackpen = gcnew Pen(Brushes::Black, 2.0f);

		if (qTask->isfull()) {
			FullQTaskCount++;
		}

		int chance = rand() % 101;
		if ((chance >= (100 - probability)) && (!(qTask->isfull()))) {
			Task temp;
			temp.ID = IDCounter;
			IDCounter++;
			temp.ProcCount = rand() % (MaxTaskProc - 1) + 1;
			temp.StepCount = rand() % (MaxTaskTact - 1) + 1;
			temp.Color = rand() % 7;

			qTask->push(temp);
		}

		if (!(qTask->isempty())) {
			gr->FillRectangle(Brushes::White, 1164, 9, 92, 592);
			TQueue<Task> CopyQ(*qTask);
			for (int i = 0; i < qTask->getSize(); i++) {
				switch (CopyQ.top().Color) {
				case 0: gr->FillRectangle(Brushes::Red, 1165.0, (float)10 + TaskHeight * i, 90.0, TaskHeight); break;
				case 1: gr->FillRectangle(Brushes::Orange, 1165.0, (float)10 + TaskHeight * i, 90.0, TaskHeight); break;
				case 2: gr->FillRectangle(Brushes::Yellow, 1165.0, (float)10 + TaskHeight * i, 90.0, TaskHeight); break;
				case 3: gr->FillRectangle(Brushes::Green, 1165.0, (float)10 + TaskHeight * i, 90.0, TaskHeight); break;
				case 4: gr->FillRectangle(Brushes::Blue, 1165.0, (float)10 + TaskHeight * i, 90.0, TaskHeight); break;
				case 5: gr->FillRectangle(Brushes::DarkBlue, 1165.0, (float)10 + TaskHeight * i, 90.0, TaskHeight); break;
				case 6: gr->FillRectangle(Brushes::Purple, 1165.0, (float)10 + TaskHeight * i, 90.0, TaskHeight); break;
				default: gr->FillRectangle(Brushes::Black, 1165.0, (float)10 + TaskHeight * i, 90.0, TaskHeight); break;
				}

				gr->DrawRectangle(blackpen, 1165.0, (float)10 + TaskHeight * i, 90.0, TaskHeight);

				String^ drawString = System::Convert::ToString(CopyQ.pop().ID);
				System::Drawing::Font^ drawFont = gcnew System::Drawing::Font("Arial", 16);
				System::Drawing::SolidBrush^ drawBrush = gcnew System::Drawing::SolidBrush(System::Drawing::Color::Black);
				gr->DrawString(drawString, drawFont, drawBrush, System::Drawing::RectangleF(1165.0, (float)10 + TaskHeight * i, 90.0, TaskHeight));
			}
		}

		if (!(qTask->isempty())) {
			while (FreeProcCount(ProcArray, CountOfProc) >= (qTask->top().ProcCount)) {
				Task CurrentTask = qTask->pop();
				CountOfCurrentTasks++;

				for (int j = 0; j < CurrentTask.ProcCount; j++) {
					int CurrentID;
					for (int k = 0; k < CountOfProc; k++) {
						if (ProcArray[k].free) {
							CurrentID = k; 
							break;
						}
					}

					ProcArray[CurrentID].free = false;
					ProcArray[CurrentID].ActiveTaskID = CurrentTask.ID;
					ProcArray[CurrentID].CurrentStepCount = CurrentTask.StepCount;
					ProcArray[CurrentID].MaxStepCount = CurrentTask.StepCount;

					switch(CurrentTask.Color){
					case 0: gr->FillRectangle(Brushes::Red, ProcArray[CurrentID].X, ProcArray[CurrentID].Y, 90, 65); break;
					case 1: gr->FillRectangle(Brushes::Orange, ProcArray[CurrentID].X, ProcArray[CurrentID].Y, 90, 65); break;
					case 2: gr->FillRectangle(Brushes::Yellow, ProcArray[CurrentID].X, ProcArray[CurrentID].Y, 90, 65); break;
					case 3: gr->FillRectangle(Brushes::Green, ProcArray[CurrentID].X, ProcArray[CurrentID].Y, 90, 65); break;
					case 4: gr->FillRectangle(Brushes::Blue, ProcArray[CurrentID].X, ProcArray[CurrentID].Y, 90, 65); break;
					case 5: gr->FillRectangle(Brushes::DarkBlue, ProcArray[CurrentID].X, ProcArray[CurrentID].Y, 90, 65); break;
					case 6: gr->FillRectangle(Brushes::Purple, ProcArray[CurrentID].X, ProcArray[CurrentID].Y, 90, 65); break;
					default: break;
					}
				}
			}
		}

		for (int i = 0; i < CountOfProc; i++) {
			if (ProcArray[i].free) {
				ProcArray[i].InactiveTactsCount++;
				CountOfInactiveTacts++;
			}
			else {
				ProcArray[i].CurrentStepCount--;
				if (ProcArray[i].CurrentStepCount == 0) {
					ProcArray[i].free = true;
					ProcArray[i].ActiveTaskID = -1;
					ProcArray[i].MaxStepCount = 0;

					gr->FillRectangle(Brushes::Gray, ProcArray[i].X, ProcArray[i].Y, 90, 65);
				}
			}
		}
	
		TactsCount++;
		label7->Text = System::Convert::ToString(TactsCount);

		InactiveTactsPerProcessor = (double) CountOfInactiveTacts / CountOfProc;
		
	}
	catch (char *str) {
		System::String ^newStr = gcnew String(str);
		label6->Text = newStr;
	}
}
private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
	System::String ^str = "Всего тактов: " + System::Convert::ToString(TactsCount) + "\nТактов простоя (в среднем на процессор): " + System::Convert::ToString(InactiveTactsPerProcessor) + "\nОчередь заполнилась " + System::Convert::ToString(FullQTaskCount) + " раз(а)\nВыполнено задач: " + System::Convert::ToString(CountOfCurrentTasks);

	System::Windows::Forms::DialogResult result;
	result = MessageBox::Show(str,"Статистика");
}
};
}