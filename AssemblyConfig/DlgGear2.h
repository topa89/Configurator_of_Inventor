#pragma once


// DlgGear2 dialog

class DlgGear2 : public CDialogEx
{
	DECLARE_DYNAMIC(DlgGear2)

public:
	DlgGear2(CWnd* pParent = NULL);   // standard constructor
	virtual ~DlgGear2();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOGGEAR2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	double m_dGear2_R;
	double m_dGear2_Height;
	double m_dGear2_WidthTooth;
	double m_dGear2_itendation;
	afx_msg void OnBnClickedOk();
	double m_iGear2_ntooth;
};
