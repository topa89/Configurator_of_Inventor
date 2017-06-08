
// AssemblyConfigView.cpp : реализация класса CAssemblyConfigView
//

#include "stdafx.h"
// SHARED_HANDLERS можно определить в обработчиках фильтров просмотра реализации проекта ATL, эскизов
// и поиска; позволяет совместно использовать код документа в данным проекте.
#ifndef SHARED_HANDLERS
#include "AssemblyConfig.h"
#endif
#include "AssemblyTreeView.h"
#include "AssemblyConfigDoc.h"
#include "AssemblyConfigView.h"
//#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAssemblyConfigView

IMPLEMENT_DYNCREATE(CAssemblyConfigView, CView)

BEGIN_MESSAGE_MAP(CAssemblyConfigView, CView)
	// Стандартные команды печати
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_CREATE()
	ON_COMMAND(ID_LOAD, &CAssemblyConfigView::OnLoad)
	ON_COMMAND(ID_HIDE, &CAssemblyConfigView::OnHide)
END_MESSAGE_MAP()

// создание/уничтожение CAssemblyConfigView
CAssemblyTreeView* treeView;
CAssemblyConfigView::CAssemblyConfigView()
{
	// TODO: добавьте код создания


}

CAssemblyConfigView::~CAssemblyConfigView()
{
}

BOOL CAssemblyConfigView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: изменить класс Window или стили посредством изменения
	//  CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// рисование CAssemblyConfigView

void CAssemblyConfigView::OnDraw(CDC* pDC)
{
	CAssemblyConfigDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	
	// TODO: добавьте здесь код отрисовки для собственных данных
	CRect rect;
	GetClientRect(&rect);

	m_ctrlModelView.SetWindowPos(this, 0, 0, rect.Width(), rect.Height(), NULL);

	m_ctrlModelView.RedrawWindow();



}


// печать CAssemblyConfigView

BOOL CAssemblyConfigView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// подготовка по умолчанию
	return DoPreparePrinting(pInfo);
}

void CAssemblyConfigView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: добавьте дополнительную инициализацию перед печатью
}

void CAssemblyConfigView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: добавьте очистку после печати
}


// диагностика CAssemblyConfigView

#ifdef _DEBUG
void CAssemblyConfigView::AssertValid() const
{
	CView::AssertValid();
}

void CAssemblyConfigView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CAssemblyConfigDoc* CAssemblyConfigView::GetDocument() const // встроена неотлаженная версия
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CAssemblyConfigDoc)));
	return (CAssemblyConfigDoc*)m_pDocument;
}
#endif //_DEBUG


// обработчики сообщений CAssemblyConfigView


int CAssemblyConfigView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  Добавьте специализированный код создания

	m_ctrlModelView.Create(NULL, WS_VISIBLE, CRect(0, 0, 1000, 800) , this, 0);
	//m_ctrlModelView.PutSourcePath(L"С:\\12.DWG");
	//m_ctrlModelView.Zoom_Extents();

	return 0;
}




void CAssemblyConfigView::OnLoad()
{
	// TODO: добавьте свой код обработчика команд
	//long res = 1000;
	
		//m_ctrlModelView.PutSourcePath(L"C:\\adb\\2.dwg");
	
}

bool bShow = 0;
void CAssemblyConfigView::OnHide()
{
	// TODO: добавьте свой код обработчика команд
	m_ctrlModelView.ShowWindow(bShow);
	bShow = !bShow;

}
