// DlgBearing1.cpp : implementation file
//

#include "stdafx.h"
#include "AssemblyConfig.h"
#include "DlgBearing1.h"
#include "afxdialogex.h"


// DlgBearing1 dialog

IMPLEMENT_DYNAMIC(DlgBearing1, CDialogEx)

DlgBearing1::DlgBearing1(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOGBEARING1, pParent)
	, m_dBearing1_R(150)
	, m_dBearing1_Height(50)
{

}

DlgBearing1::~DlgBearing1()
{
}

void DlgBearing1::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_dBearing1_R);
	DDX_Text(pDX, IDC_EDIT2, m_dBearing1_Height);
}


BEGIN_MESSAGE_MAP(DlgBearing1, CDialogEx)
	ON_BN_CLICKED(IDOK, &DlgBearing1::OnBnClickedOk)
END_MESSAGE_MAP()


// DlgBearing1 message handlers

int ErrorMessageBoxF15() {
	int errormsgbox = MessageBox(NULL, (LPCWSTR)L"Неверные параметры радиуса подшипника.", (LPCWSTR)L"Ошибка", MB_OK);
	return errormsgbox;
}
int ErrorMessageBoxF16() {
	int errormsgbox = MessageBox(NULL, (LPCWSTR)L"Неверные параметры толщины подшипника.", (LPCWSTR)L"Ошибка", MB_OK);
	return errormsgbox;
}

void DlgBearing1::OnBnClickedOk()
{
	UpdateData(true);
	if ((m_dBearing1_R>220) || (m_dBearing1_R < 5)) ErrorMessageBoxF15();
	else if ((m_dBearing1_Height>300) || (m_dBearing1_Height < 5)) ErrorMessageBoxF16();
	else
	{
		CDialogEx::OnOK();
	}
}

