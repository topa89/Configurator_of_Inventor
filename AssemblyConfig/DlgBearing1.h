#pragma once


// DlgBearing1 dialog

class DlgBearing1 : public CDialogEx
{
	DECLARE_DYNAMIC(DlgBearing1)

public:
	DlgBearing1(CWnd* pParent = NULL);   // standard constructor
	virtual ~DlgBearing1();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOGBEARING1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	double m_dBearing1_R;
	double m_dBearing1_Height;
	afx_msg void OnBnClickedOk();
};
