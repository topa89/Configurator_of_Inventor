#pragma once
#include "AssemblyConfigDoc.h"
#include "Dlg_split.h"
// представление CAssemblyTreeView

class CAssemblyTreeView : public CTreeView
{
	DECLARE_DYNCREATE(CAssemblyTreeView)

protected:

	CAssemblyTreeView();           // защищенный конструктор, используемый при динамическом создании
	virtual ~CAssemblyTreeView();

public:
	int posTree = 0;
	HTREEITEM m_hRoot;
	HTREEITEM m_hRoot1;
	HTREEITEM m_hRoot2;

	/*
	HTREEITEM m_hComponent1;
	HTREEITEM m_hComponent2;
	HTREEITEM m_hComponent3;*/

	//CArray <HTREEITEM, HTREEITEM> m_Items;

	int m_iSelected = -1;
	double m_dR_val1 = 6;
	CStringArray m_ComponentNames;
	
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	DECLARE_MESSAGE_MAP()
public:
	void FillTree();
	double r_val1;
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	CAssemblyConfigDoc* pDoc;
	Dlg_split* pSplit;
};


