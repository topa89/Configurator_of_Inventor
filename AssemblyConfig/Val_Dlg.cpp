// Val_Dlg.cpp: ���� ����������
//

#include "stdafx.h"
#include "AssemblyConfigDoc.h"
#include "AssemblyConfig.h"
#include "Val_Dlg.h"
#include "afxdialogex.h"
#include "AssemblyTreeView.h"


// ���������� ���� CVal_Dlg

IMPLEMENT_DYNAMIC(CVal_Dlg, CDialogEx)

CVal_Dlg::CVal_Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
	, m_dR_val1(120)
	, m_dVal1_length(600)
	, m_dVal1_rDop(60)
	, m_dVal1_mainLength(300)
{

}

CVal_Dlg::~CVal_Dlg()
{
}

void CVal_Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_dR_val1);
	DDX_Text(pDX, IDC_EDIT2, m_dVal1_length);
	DDX_Text(pDX, IDC_EDIT3, m_dVal1_rDop);
	DDX_Text(pDX, IDC_EDIT4, m_dVal1_mainLength);

}


BEGIN_MESSAGE_MAP(CVal_Dlg, CDialogEx)

	ON_BN_CLICKED(IDOK, &CVal_Dlg::OnBnClickedOk)

END_MESSAGE_MAP()


// ����������� ��������� CVal_Dlg




int ErrorMessageBoxF1() {
	int errormsgbox = MessageBox(NULL, (LPCWSTR)L"�������� ��������� ����� ����.", (LPCWSTR)L"������", MB_OK);
	return errormsgbox;
} 
int ErrorMessageBoxF2() {
	int errormsgbox = MessageBox(NULL, (LPCWSTR)L"�������� ��������� ����� ��������� ��������.", (LPCWSTR)L"������", MB_OK);
	return errormsgbox;
}
int ErrorMessageBoxF3() {
	int errormsgbox = MessageBox(NULL, (LPCWSTR)L"�������� ��������� ������� ��������� ��������.", (LPCWSTR)L"������", MB_OK);
	return errormsgbox;
}
int ErrorMessageBoxF4() {
	int errormsgbox = MessageBox(NULL, (LPCWSTR)L"�������� ��������� ������� �������������� ���������.", (LPCWSTR)L"������", MB_OK);
	return errormsgbox;
}
int ErrorMessageBoxF5() {
	int errormsgbox = MessageBox(NULL, (LPCWSTR)L"������ �������������� ��������� ������ ������� ��������� ��������.", (LPCWSTR)L"������", MB_OK);
	return errormsgbox;
}
int ErrorMessageBoxF6() {
	int errormsgbox = MessageBox(NULL, (LPCWSTR)L"����� ��������� �������� ������ ����� ����� ����.", (LPCWSTR)L"������", MB_OK);
	return errormsgbox;
}

void CVal_Dlg::OnBnClickedOk()
{
	// TODO: �������� ���� ��� ����������� �����������
	UpdateData(true);
	if ((m_dR_val1 > 120) || (m_dR_val1 < 10)) ErrorMessageBoxF3();
	else if ((m_dVal1_mainLength>850) || (m_dVal1_mainLength<5)) ErrorMessageBoxF2();
	else if ((m_dVal1_rDop > 110) || (m_dVal1_rDop < 5)) ErrorMessageBoxF4();
	else if ((m_dVal1_length > 1000)  || (m_dVal1_length < 10)) ErrorMessageBoxF1();
	else if ((m_dVal1_mainLength) > (m_dVal1_length)) ErrorMessageBoxF6();
	else if ((m_dVal1_rDop) > (m_dR_val1)) ErrorMessageBoxF5();
	else
	{
		CDialogEx::OnOK();
	}
}



