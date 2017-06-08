#pragma once


// DlfGear1 dialog

class DlfGear1 : public CDialogEx
{
	DECLARE_DYNAMIC(DlfGear1)

public:
	DlfGear1(CWnd* pParent = NULL);   // standard constructor
	virtual ~DlfGear1();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOGGEAR1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	double m_dGear1_r;
	double m_dGear1_thickness;
	double m_iGear1_ntooth;
	double m_dGear1_widthTooth;
	double m_dGear1_intendation;
	afx_msg void OnBnClickedOk();
};
