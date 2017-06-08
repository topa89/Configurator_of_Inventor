#pragma once


// DlgVal2 dialog

class DlgVal2 : public CDialogEx
{
	DECLARE_DYNAMIC(DlgVal2)

public:
	DlgVal2(CWnd* pParent = NULL);   // standard constructor
	virtual ~DlgVal2();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOGVAL2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	double m_dVal2_mainR;
	double m_dVal2_MainLength;
	double m_dVal2_rDop;
	double m_dVal2_length;
	afx_msg void OnBnClickedOk();
};
