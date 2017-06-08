#pragma once


// DlgBearing2 dialog

class DlgBearing2 : public CDialogEx
{
	DECLARE_DYNAMIC(DlgBearing2)

public:
	DlgBearing2(CWnd* pParent = NULL);   // standard constructor
	virtual ~DlgBearing2();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOGBEARING2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	double m_dBearing2_R;
	double m_dBearing2_Height;
	afx_msg void OnBnClickedOk();
};
