
// AssemblyConfigDoc.cpp : ���������� ������ CAssemblyConfigDoc
//

#include "stdafx.h"
// SHARED_HANDLERS ����� ���������� � ������������ �������� ��������� ���������� ������� ATL, �������
// � ������; ��������� ��������� ������������ ��� ��������� � ������ �������.
#ifndef SHARED_HANDLERS
#include "AssemblyConfig.h"
#endif

#include "AssemblyConfigDoc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CAssemblyConfigDoc

IMPLEMENT_DYNCREATE(CAssemblyConfigDoc, CDocument)

BEGIN_MESSAGE_MAP(CAssemblyConfigDoc, CDocument)
END_MESSAGE_MAP()


// ��������/����������� CAssemblyConfigDoc

CAssemblyConfigDoc::CAssemblyConfigDoc()
{
	// TODO: �������� ��� ��� ������������ ������ ������������

}

CAssemblyConfigDoc::~CAssemblyConfigDoc()
{
}

BOOL CAssemblyConfigDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;
	r_val1 = 90, val1_rdop = 60, val1_len = 600, val1_mainLen = 300;
	r_val2 = 90, val2_rdop = 60, val2_len = 500, val2_mainLen = 200;
	r_bearing1 = 150, bearing1_length = 50;
	r_bearing2 = 150, bearing2_length = 50;
	r_gear1 = 150, gear1_toothLength = 250, gear1_thickness = 70, gear1_intendation = 10, gear1_Teeths = 20;
	r_gear2 = 200, gear2_toothLength = 250, gear2_thickness = 50, gear2_intendation = 10, gear2_Teeths = 20;
	// TODO: �������� ��� ��������� �������������
	// (��������� SDI ����� �������� ������������ ���� ��������)

	return TRUE;
}




// ������������ CAssemblyConfigDoc

void CAssemblyConfigDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: �������� ��� ����������
	}
	else
	{
		// TODO: �������� ��� ��������
	}
}

#ifdef SHARED_HANDLERS

// ��������� ��� �������
void CAssemblyConfigDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// �������� ���� ��� ��� ����������� ������ ���������
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// ��������� ������������ ������
void CAssemblyConfigDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// ������� ���������� ������ �� ������ ���������. 
	// ����� ����������� ������ ����������� ������ � ������� ";"

	// ��������:  strSearchContent = _T("�����;�������������;����;������ ole;");
	SetSearchContent(strSearchContent);
}

void CAssemblyConfigDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = NULL;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != NULL)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// ����������� CAssemblyConfigDoc

#ifdef _DEBUG
void CAssemblyConfigDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CAssemblyConfigDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// ������� CAssemblyConfigDoc
