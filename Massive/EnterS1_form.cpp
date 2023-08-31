#include "EnterS1_form.h"
#include "MyForm.h"
#include "massiv.h"
System::Void Massiveforms::EnterS1_form::backToolStripMenuItem1_Click(System::Object^ sender, System::EventArgs^ e)
{
	MyForm^ form = gcnew MyForm;
	this->Hide();
	form->Show();
}

System::Void Massiveforms::EnterS1_form::EnterS1_form_Load(System::Object^ sender, System::EventArgs^ e)
{
}
Array_ S1;
Array_ S2;
System::Void Massiveforms::EnterS1_form::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
	MyForm^ form = gcnew MyForm;
	int n = System::Convert::ToInt32(textBox1->Text);
	if (form->Get_f())S2 += n;
	else S1 += n;
	textBox1->Clear();
}
Array_ Massiveforms::EnterS1_form::Get_S1()
{
	return S1;
}

Array_ Massiveforms::EnterS1_form::Get_S2()
{
	return S2;
}
void Massiveforms::EnterS1_form::Del(bool x)
{
	int len1 = S1.len();
	int len2 = S2.len();
	if (!x)for (int i = 0; i < len1; i++)S1.ShiftLeft(0);
	else for (int i = 0; i < len2; i++)S2.ShiftLeft(0);
}


