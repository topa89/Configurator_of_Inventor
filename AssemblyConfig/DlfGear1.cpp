// DlfGear1.cpp : implementation file
//

#include "stdafx.h"
#include "AssemblyConfig.h"
#include "DlfGear1.h"
#include "afxdialogex.h"


// DlfGear1 dialog

IMPLEMENT_DYNAMIC(DlfGear1, CDialogEx)

DlfGear1::DlfGear1(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOGGEAR1, pParent)
	, m_dGear1_r(150)
	, m_dGear1_thickness(30)
	, m_iGear1_ntooth(20)
	, m_dGear1_widthTooth(250)
	, m_dGear1_intendation(10)
{
#ifndef _WIN32_WCE
	EnableActiveAccessibility();
#endif

}

DlfGear1::~DlfGear1()
{
}

void DlfGear1::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_dGear1_r);
	DDX_Text(pDX, IDC_EDIT2, m_dGear1_thickness);
	DDX_Text(pDX, IDC_EDIT5, m_iGear1_ntooth);
	DDX_Text(pDX, IDC_EDIT6, m_dGear1_widthTooth);
	DDX_Text(pDX, IDC_EDIT7, m_dGear1_intendation);
}


BEGIN_MESSAGE_MAP(DlfGear1, CDialogEx)
END_MESSAGE_MAP()


// DlfGear1 message handlers
