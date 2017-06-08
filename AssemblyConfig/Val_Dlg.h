#include "AssemblyConfigDoc.h"
#pragma once


// диалоговое окно CVal_Dlg

class CVal_Dlg : public CDialogEx
{
	DECLARE_DYNAMIC(CVal_Dlg)

public:
	CVal_Dlg(CWnd* pParent = NULL);   // стандартный конструктор
	virtual ~CVal_Dlg();


// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

	DECLARE_MESSAGE_MAP()
public:
	double m_dR_val1;
	afx_msg void OnBnClickedOk();
	

	double m_dVal1_length;
	
	double m_dVal1_rDop;
	double m_dVal1_mainLength;


};
