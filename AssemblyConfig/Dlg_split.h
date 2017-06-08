#pragma once
#include "Val_Dlg.h"


// ������������� ����� Dlg_split

class Dlg_split : public CFormView
{
	DECLARE_DYNCREATE(Dlg_split)

protected:
	Dlg_split();           // ���������� �����������, ������������ ��� ������������ ��������
	virtual ~Dlg_split();
	double r_val11;

public:
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DLG_SPLIT };
#endif
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // ��������� DDX/DDV

	DECLARE_MESSAGE_MAP()
public:
	CVal_Dlg *val;
	afx_msg void OnBnClickedButton1();
	void Podshipnik(double radius, double h, double rval);
	
	void MainCircle(double radius, double thickness, int number_of_tooth, double widthTooth, double rval);
	void FrontCuts(double radius, double thickness, double intendation);
	void BackCuts(double radius, double thickness, double intendation);
	void InscribedCircle(double radius, double thickness);
	
	void Val(double radius, double rval, double length_all,double length_main );
	void FrontCuts_2(double radius, double thickness, double intendation);
	void BackCuts_2(double radius, double thickness, double intendation);
	void MainCircle_2(double radius, double thickness, int number_of_tooth, double widthTooth, double rval);
	void Gear(double radius, double thickness, double widthTooth, double itendation, double rval);

	bool check = true;
public:
	
	//��� 1
	double *val1_lengthmain;
	double *val1_length;
	double *val1_radius;
	double *val1_partradius;
	//�������� 1
	double *gear1_radius;
	double *gear1_thickness;//�������
	double *gear1_toothLength;
	double *gear1_intendation; //������������
	double *gear1_Teeths;
	//��������� 1
	double *bearing1_radius;
	double *bearing1_length;

	//��� 2
	double *val2_lengthmain;
	double *val2_length;
	double *val2_radius;
	double *val2_partradius;
	//�������� 2
	double *gear2_radius;
	double *gear2_thickness;//�������
	double *gear2_toothLength;
	double *gear2_intendation; //����������
	double *gear2_Teeths;
	//��������� 2
	double *bearing2_radius;
	double *bearing2_length;


};


