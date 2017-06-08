
// MainFrm.h : ��������� ������ CMainFrame
//
#include "CAcCtrl.h"
#include "Dlg_split.h"
#include "AssemblyTreeView.h"
#include "Val_Dlg.h"
#pragma once

class CMainFrame : public CFrameWnd
{
	
protected: // ������� ������ �� ������������
	CMainFrame();
	DECLARE_DYNCREATE(CMainFrame)

// ��������
public:

// ��������
public:

// ���������������
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// ����������
public:
	CAssemblyTreeView *pTree;
	Dlg_split *dlg_split;
	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:  // ���������� ����� ������ ��������� ����������
	CToolBar          m_wndToolBar;
	CStatusBar        m_wndStatusBar;
	CSplitterWnd      m_wndSplitter;
	CSplitterWnd      m_wndSplitter1;
	
// ��������� ������� ����� ���������
protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	DECLARE_MESSAGE_MAP()

	virtual BOOL OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext);
};


