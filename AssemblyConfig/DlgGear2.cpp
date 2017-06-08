// DlgGear2.cpp : implementation file
//

#include "stdafx.h"
#include "AssemblyConfig.h"
#include "DlgGear2.h"
#include "afxdialogex.h"


// DlgGear2 dialog

IMPLEMENT_DYNAMIC(DlgGear2, CDialogEx)

DlgGear2::DlgGear2(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOGGEAR2, pParent)
	, m_dGear2_R(250)
	, m_dGear2_Height(70)
	, m_dGear2_WidthTooth(250)
	, m_dGear2_itendation(10)
	, m_iGear2_ntooth(0)
{

}

DlgGear2::~DlgGear2()
{
}

void DlgGear2::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_dGear2_R);
	DDX_Text(pDX, IDC_EDIT2, m_dGear2_Height);
	DDX_Text(pDX, IDC_EDIT3, m_dGear2_WidthTooth);
	DDX_Text(pDX, IDC_EDIT4, m_dGear2_itendation);
	DDX_Text(pDX, IDC_EDIT5, m_iGear2_ntooth);
}


BEGIN_MESSAGE_MAP(DlgGear2, CDialogEx)
	ON_BN_CLICKED(IDOK, &DlgGear2::OnBnClickedOk)
END_MESSAGE_MAP()


// DlgGear2 message handlers


void DlgGear2::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	CDialogEx::OnOK();
}
