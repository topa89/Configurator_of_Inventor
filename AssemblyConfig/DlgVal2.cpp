// DlgVal2.cpp : implementation file
//

#include "stdafx.h"
#include "AssemblyConfig.h"
#include "DlgVal2.h"
#include "afxdialogex.h"


// DlgVal2 dialog

IMPLEMENT_DYNAMIC(DlgVal2, CDialogEx)

DlgVal2::DlgVal2(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOGVAL2, pParent)
	, m_dVal2_mainR(120)
	, m_dVal2_MainLength(600)
	, m_dVal2_rDop(60)
	, m_dVal2_length(300)
{

}

DlgVal2::~DlgVal2()
{
}

void DlgVal2::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_dVal2_mainR);
	DDX_Text(pDX, IDC_EDIT4, m_dVal2_MainLength);
	DDX_Text(pDX, IDC_EDIT3, m_dVal2_rDop);
	DDX_Text(pDX, IDC_EDIT2, m_dVal2_length);
}


BEGIN_MESSAGE_MAP(DlgVal2, CDialogEx)
	ON_BN_CLICKED(IDOK, &DlgVal2::OnBnClickedOk)
END_MESSAGE_MAP()


// DlgVal2 message handlers


int ErrorMessageBoxF7() {
	int errormsgbox = MessageBox(NULL, (LPCWSTR)L"Неверные параметры длины вала.", (LPCWSTR)L"Ошибка", MB_OK);
	return errormsgbox;
}
int ErrorMessageBoxF8() {
	int errormsgbox = MessageBox(NULL, (LPCWSTR)L"Неверные параметры длины основного цилиндра.", (LPCWSTR)L"Ошибка", MB_OK);
	return errormsgbox;
}
int ErrorMessageBoxF9() {
	int errormsgbox = MessageBox(NULL, (LPCWSTR)L"Неверные параметры радиуса основного цилиндра.", (LPCWSTR)L"Ошибка", MB_OK);
	return errormsgbox;
}
int ErrorMessageBoxF10() {
	int errormsgbox = MessageBox(NULL, (LPCWSTR)L"Неверные параметры радиуса дополнительных цилиндров.", (LPCWSTR)L"Ошибка", MB_OK);
	return errormsgbox;
}
int ErrorMessageBoxF11() {
	int errormsgbox = MessageBox(NULL, (LPCWSTR)L"Радиус дополнительных цилиндров больше радиуса основного цилиндра.", (LPCWSTR)L"Ошибка", MB_OK);
	return errormsgbox;
}
int ErrorMessageBoxF12() {
	int errormsgbox = MessageBox(NULL, (LPCWSTR)L"Длина основного цилиндра больше длины всего вала.", (LPCWSTR)L"Ошибка", MB_OK);
	return errormsgbox;
}

void DlgVal2::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	if ((m_dVal2_mainR > 120) || (m_dVal2_mainR < 10)) ErrorMessageBoxF9();
	else if ((m_dVal2_MainLength>850) || (m_dVal2_MainLength<5)) ErrorMessageBoxF8();
	else if ((m_dVal2_rDop > 110) || (m_dVal2_rDop < 5)) ErrorMessageBoxF10();
	else if ((m_dVal2_length > 1000) || (m_dVal2_length < 10)) ErrorMessageBoxF7();
	else if ((m_dVal2_MainLength) >(m_dVal2_length)) ErrorMessageBoxF12();
	else if ((m_dVal2_rDop) > (m_dVal2_mainR)) ErrorMessageBoxF11();
	else
	{
		CDialogEx::OnOK();
	}
	
}
