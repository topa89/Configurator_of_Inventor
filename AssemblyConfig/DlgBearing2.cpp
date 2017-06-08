// DlgBearing2.cpp : implementation file
//

#include "stdafx.h"
#include "AssemblyConfig.h"
#include "DlgBearing2.h"
#include "afxdialogex.h"


// DlgBearing2 dialog

IMPLEMENT_DYNAMIC(DlgBearing2, CDialogEx)

DlgBearing2::DlgBearing2(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOGBEARING2, pParent)
	, m_dBearing2_R(150)
	, m_dBearing2_Height(50)
{

}

DlgBearing2::~DlgBearing2()
{
}

void DlgBearing2::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_dBearing2_R);
	DDX_Text(pDX, IDC_EDIT2, m_dBearing2_Height);
}


BEGIN_MESSAGE_MAP(DlgBearing2, CDialogEx)
	ON_BN_CLICKED(IDOK, &DlgBearing2::OnBnClickedOk)
END_MESSAGE_MAP()


// DlgBearing2 message handlers

int ErrorMessageBoxF13() {
	int errormsgbox = MessageBox(NULL, (LPCWSTR)L"Неверные параметры радиуса подшипника.", (LPCWSTR)L"Ошибка", MB_OK);
	return errormsgbox;
}
int ErrorMessageBoxF14() {
	int errormsgbox = MessageBox(NULL, (LPCWSTR)L"Неверные параметры толщины подшипника.", (LPCWSTR)L"Ошибка", MB_OK);
	return errormsgbox;
}

void DlgBearing2::OnBnClickedOk()
{
	UpdateData(true);
	if ((m_dBearing2_R>220) || (m_dBearing2_R < 5)) ErrorMessageBoxF13();
	else if ((m_dBearing2_Height>300) || (m_dBearing2_Height < 5)) ErrorMessageBoxF14();	
	else
	{
		CDialogEx::OnOK();
	}
}
