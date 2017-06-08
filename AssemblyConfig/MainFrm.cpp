
// MainFrm.cpp : реализаци€ класса CMainFrame
//

#include "stdafx.h"

#include "AssemblyConfig.h"
#include "AssemblyTreeView.h"

#include "AssemblyConfigView.h"

#include "MainFrm.h"
#include "Dlg_split.h"
#include "Val_Dlg.h"
#include "AssemblyConfigDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	ON_WM_CREATE()
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // индикатор строки состо€ни€
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

// создание/уничтожение CMainFrame

CMainFrame::CMainFrame()
{
	// TODO: добавьте код инициализации члена
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP | CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("Ќе удалось создать панель инструментов\n");
		return -1;      // не удалось создать
	}

	if (!m_wndStatusBar.Create(this))
	{
		TRACE0("Ќе удалось создать строку состо€ни€\n");
		return -1;      // не удалось создать
	}
	m_wndStatusBar.SetIndicators(indicators, sizeof(indicators)/sizeof(UINT));

	// TODO: ”далите эти три строки, если не собираетесь закрепл€ть панель инструментов
	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndToolBar);

	


	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: изменить класс Window или стили посредством изменени€
	//  CREATESTRUCT cs

	return TRUE;
}

// диагностика CMainFrame

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}
#endif //_DEBUG


// обработчики сообщений CMainFrame



BOOL CMainFrame::OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext)
{
	// TODO: добавьте специализированный код или вызов базового класса
	// TODO: Add your specialized code here and/or call the base class

	if (!m_wndSplitter.CreateStatic(this, 1, 2))
	{
		TRACE0("Failed to CreateStaticSplitter\n");
		return FALSE;
	}

	if (!m_wndSplitter.CreateView(0, 1, RUNTIME_CLASS(CAssemblyConfigView), CSize(0, 0), pContext))
	{
		TRACE0("Failed to create first pane\n");
		return FALSE;
	}

	m_wndSplitter1.CreateStatic(&m_wndSplitter, 2, 1, WS_CHILD | WS_BORDER | WS_VISIBLE, m_wndSplitter.IdFromRowCol(0, 0));
	

	if (!m_wndSplitter1.CreateView(0, 0, RUNTIME_CLASS(CAssemblyTreeView), CSize(0, 0), pContext)) 
	{
		TRACE0("Failed to create first pane\n");
		return FALSE;
	}
	if (!m_wndSplitter1.CreateView(1, 0, RUNTIME_CLASS(Dlg_split), CSize(0, 0), pContext)) 
	{
		TRACE0("Failed to create first pane\n");
		return FALSE;
	}
	m_wndSplitter.SetColumnInfo(0, 480, 15);
	m_wndSplitter1.SetRowInfo(0, 230, 10);

	pTree = (CAssemblyTreeView*)m_wndSplitter1.GetPane(0, 0);
	dlg_split = (Dlg_split*)m_wndSplitter1.GetPane(1, 0);
	//new
	pTree->pSplit = dlg_split;
	//вал 1
	dlg_split->val1_lengthmain = &pTree->pDoc->val1_mainLen;
	dlg_split->val1_length = &pTree->pDoc->val1_len;
	dlg_split->val1_radius = &pTree->pDoc->r_val1;
	dlg_split->val1_partradius = &pTree->pDoc->val1_rdop;
	//шестерн€ 1
	dlg_split->gear1_radius = &pTree->pDoc->r_gear1;
	dlg_split->gear1_thickness = &pTree->pDoc->gear1_thickness;
	dlg_split->gear1_intendation = &pTree->pDoc->gear1_intendation;
	dlg_split->gear1_toothLength = &pTree->pDoc->gear1_toothLength;
	dlg_split->gear1_Teeths = &pTree->pDoc->gear1_Teeths;
	//подшипник 1
	dlg_split->bearing1_radius = &pTree->pDoc->r_bearing1;
	dlg_split->bearing1_length = &pTree->pDoc->bearing1_length;

	//вал 2
	dlg_split->val2_lengthmain = &pTree->pDoc->val2_mainLen;
	dlg_split->val2_length = &pTree->pDoc->val2_len;
	dlg_split->val2_radius = &pTree->pDoc->r_val2;
	dlg_split->val2_partradius = &pTree->pDoc->val2_rdop;
	//шестерн€ 2
	dlg_split->gear2_radius = &pTree->pDoc->r_gear2;
	dlg_split->gear2_thickness = &pTree->pDoc->gear1_thickness;
	dlg_split->gear2_intendation = &pTree->pDoc->gear2_intendation;
	dlg_split->gear2_toothLength = &pTree->pDoc->gear2_toothLength;
	dlg_split->gear2_Teeths = &pTree->pDoc->gear2_Teeths;
	//подшипник 2
	dlg_split->bearing2_radius = &pTree->pDoc->r_bearing2;
	dlg_split->bearing2_length = &pTree->pDoc->bearing2_length;
	//pTree->UpdateForms() = dlg_split->UpdateForms();
}
