
// MainFrm.h : интерфейс класса CMainFrame
//
#include "CAcCtrl.h"
#include "Dlg_split.h"
#include "AssemblyTreeView.h"
#include "Val_Dlg.h"
#pragma once

class CMainFrame : public CFrameWnd
{
	
protected: // создать только из сериализации
	CMainFrame();
	DECLARE_DYNCREATE(CMainFrame)

// Атрибуты
public:

// Операции
public:

// Переопределение
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// Реализация
public:
	CAssemblyTreeView *pTree;
	Dlg_split *dlg_split;
	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:  // встроенные члены панели элементов управления
	CToolBar          m_wndToolBar;
	CStatusBar        m_wndStatusBar;
	CSplitterWnd      m_wndSplitter;
	CSplitterWnd      m_wndSplitter1;
	
// Созданные функции схемы сообщений
protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	DECLARE_MESSAGE_MAP()

	virtual BOOL OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext);
};


