// AssemblyTreeView.cpp: файл реализации
//



#include "stdafx.h"
#include "AssemblyConfig.h"
#include "AssemblyTreeView.h"

#include "Val_Dlg.h"
#include "Dlg_split.h"
#include "DlfGear1.h"
#include "DlgBearing1.h"
#include "DlgBearing2.h"
#include "DlgGear2.h"
#include "DlgVal2.h"

// CAssemblyTreeView

IMPLEMENT_DYNCREATE(CAssemblyTreeView, CTreeView)



/*int ErrorMessageBoxF1() {
	int errormsgbox = MessageBox(NULL, (LPCWSTR)L"Неверные параметры.", (LPCWSTR)L"Ошибка", MB_OK);
	return errormsgbox;
}*/

CAssemblyTreeView::CAssemblyTreeView()
{
	m_ComponentNames.RemoveAll();
	//m_ComponentNames.Add(L"Сборка");
	m_ComponentNames.Add(L"Вал");
	m_ComponentNames.Add(L"Шестерня");
	m_ComponentNames.Add(L"Подшипник");

	m_ComponentNames.Add(L"Вал");
	m_ComponentNames.Add(L"Шестерня");
	m_ComponentNames.Add(L"Подшипник");
}



CAssemblyTreeView::~CAssemblyTreeView()
{
}

BEGIN_MESSAGE_MAP(CAssemblyTreeView, CTreeView)
	
	ON_WM_CREATE()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()


// диагностика CAssemblyTreeView

#ifdef _DEBUG
void CAssemblyTreeView::AssertValid() const
{
	CTreeView::AssertValid();
}

#ifndef _WIN32_WCE
void CAssemblyTreeView::Dump(CDumpContext& dc) const
{
	CTreeView::Dump(dc);
}
#endif
#endif //_DEBUG


// обработчики сообщений CAssemblyTreeView


/*int ErrorMessageBoxF1() {
	int errormsgbox = MessageBox(NULL, (LPCWSTR)L"Неверные параметры.", (LPCWSTR)L"Ошибка", MB_OK);
	return errormsgbox;
}
*/

void CAssemblyTreeView::FillTree()
{
	CTreeCtrl& ctlTree = (CTreeCtrl&)GetTreeCtrl();

	ctlTree.DeleteAllItems();

	m_hRoot = ctlTree.InsertItem(L"Сборка", -1, -1, NULL, TVI_FIRST);
	ctlTree.SetItemData(m_hRoot, -1);

	ctlTree.SetItemState(m_hRoot, TVIS_BOLD, TVIS_BOLD);
	m_hRoot1 = ctlTree.InsertItem(L"Ведомая часть", -1, -1, m_hRoot, TVI_FIRST);
	ctlTree.SetItemData(m_hRoot1, -1);

	m_hRoot2 = ctlTree.InsertItem(L"Ведущая часть", -1, -1, m_hRoot, TVI_FIRST);
	ctlTree.SetItemData(m_hRoot2, -1);
	posTree = 0;
	HTREEITEM item;

	//for (int i = 0; i < m_ComponentNames.GetSize(); i++)
	for (int i = 0; i < 3; i++)
	{
		item = ctlTree.InsertItem(m_ComponentNames[i], -1, -1, m_hRoot1, TVI_LAST);
		ctlTree.SetItemData(item, i);
		if (i == m_iSelected)
			ctlTree.SetItemState(item, TVIS_BOLD, TVIS_BOLD);
		else
			ctlTree.SetItemState(item, 0, TVIS_BOLD);

	}

	for (int i = 3; i < m_ComponentNames.GetSize(); i++)
	{
		item = ctlTree.InsertItem(m_ComponentNames[i], -1, -1, m_hRoot2, TVI_LAST);
		ctlTree.SetItemData(item, i);
		if (i == m_iSelected)
			ctlTree.SetItemState(item, TVIS_BOLD, TVIS_BOLD);
		else
			ctlTree.SetItemState(item, 0, TVIS_BOLD);

	}
	ctlTree.Expand(m_hRoot, TVE_EXPAND);
	ctlTree.Expand(m_hRoot1, TVE_EXPAND);
	ctlTree.Expand(m_hRoot2, TVE_EXPAND);



	ctlTree.SetItemState(m_hRoot1, TVIS_BOLD, TVIS_BOLD);
	ctlTree.SetItemState(m_hRoot2, TVIS_BOLD, TVIS_BOLD);


	//ctlTree.Expand(m_hRoot, TVE_EXPAND);

	/*m_hRoot = ctlTree.InsertItem(L"Сборка", -1, -1, NULL, TVI_FIRST);
	ctlTree.SetItemData(m_hRoot, 0);

	m_hComponent1 = ctlTree.InsertItem(L"Компонент1", m_hRoot, TVI_LAST);
	ctlTree.SetItemData(m_hComponent1, 1);

	m_hComponent2 = ctlTree.InsertItem(L"Компонент2", m_hRoot, TVI_LAST);
	ctlTree.SetItemData(m_hComponent2, 2);

	m_hComponent3 = ctlTree.InsertItem(L"Компонент3", m_hRoot, TVI_LAST);
	ctlTree.SetItemData(m_hComponent3, 3);*/


}

int CAssemblyTreeView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	
	lpCreateStruct->style |= TVS_HASLINES | TVS_HASBUTTONS | TVS_LINESATROOT | TVS_SHOWSELALWAYS;
	
	if (CTreeView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  Добавьте специализированный код создания
	
	CTreeCtrl& ctlTree = (CTreeCtrl&)GetTreeCtrl();

	FillTree();
	
	pDoc = (CAssemblyConfigDoc*)GetDocument();


	return 0;
}


/*
int ErrorMessageBoxF1() {
	int errormsgbox = MessageBox(NULL, (LPCWSTR)L"Неверные параметры.", (LPCWSTR)L"Ошибка", MB_OK);
	return errormsgbox;
}
*/

void CAssemblyTreeView::OnLButtonDown(UINT nFlags, CPoint point)
{
	CTreeView::OnLButtonDown(nFlags, point);
	// TODO: добавьте свой код обработчика сообщений или вызов стандартного
	CTreeCtrl& ctlTree = (CTreeCtrl&)GetTreeCtrl();

	m_iSelected = pDoc->m_iSelected;
	HTREEITEM hItem = ctlTree.GetSelectedItem();
	if (hItem)
	{
		posTree = m_iSelected;
		m_iSelected = ctlTree.GetItemData(hItem);
	}
		 
		
		FillTree();

        //ctlTree.SetItemState(hItem, TVIS_BOLD, TVIS_BOLD);
		if (m_iSelected == 3)
		{
			CVal_Dlg val_dlg;

			val_dlg.m_dR_val1 = pDoc->r_val1;
			val_dlg.m_dVal1_length = pDoc->val1_len;
			val_dlg.m_dVal1_mainLength = pDoc->val1_mainLen;
			val_dlg.m_dVal1_rDop = pDoc->val1_rdop;

			
			
				if (IDOK == val_dlg.DoModal())
				{


					pDoc->r_val1 = val_dlg.m_dR_val1;
					pDoc->val1_len = val_dlg.m_dVal1_length;
					pDoc->val1_mainLen = val_dlg.m_dVal1_mainLength;
					pDoc->val1_rdop = val_dlg.m_dVal1_rDop;

					
					
					pSplit->UpdateData(FALSE);
	
			}
		}
		else if (m_iSelected == 4)
		{
			DlfGear1 gear1;

			gear1.m_dGear1_r = pDoc->r_gear1;
			gear1.m_dGear1_thickness = pDoc->gear1_thickness;
			gear1.m_dGear1_widthTooth = pDoc->gear1_toothLength;
			gear1.m_dGear1_intendation = pDoc->gear1_intendation;
			gear1.m_iGear1_ntooth = pDoc->gear1_Teeths;

			if (IDOK == gear1.DoModal())
			{
				pDoc->r_gear1 = gear1.m_dGear1_r;
				pDoc->gear1_thickness = gear1.m_dGear1_thickness;
				pDoc->gear1_toothLength = gear1.m_dGear1_widthTooth;
				pDoc->gear1_intendation = gear1.m_dGear1_intendation;
				pDoc->gear1_Teeths = gear1.m_iGear1_ntooth;

				pSplit->UpdateData(FALSE);
			}
		}
		else if (m_iSelected == 1)
		{
			DlgGear2 gear2;
			gear2.m_dGear2_R = pDoc->r_gear2;
			gear2.m_dGear2_Height = pDoc->gear1_thickness;
			gear2.m_dGear2_itendation = pDoc->gear2_intendation;
			gear2.m_dGear2_WidthTooth = pDoc->gear2_toothLength;
			gear2.m_iGear2_ntooth = pDoc->gear2_Teeths;

			if (IDOK == gear2.DoModal())
			{
				pDoc->r_gear2 = gear2.m_dGear2_R;
				pDoc->gear1_thickness = gear2.m_dGear2_Height;
				pDoc->gear2_intendation = gear2.m_dGear2_itendation;
				pDoc->gear2_toothLength = gear2.m_dGear2_WidthTooth;
				pDoc->gear2_Teeths = gear2.m_iGear2_ntooth;

				pSplit->UpdateData(FALSE);
			}
		
		}

		else if (m_iSelected == 2)
		{
			DlgBearing2 bearing2;
			bearing2.m_dBearing2_R = pDoc->r_bearing2;
			bearing2.m_dBearing2_Height = pDoc->bearing2_length;

			if (IDOK == bearing2.DoModal())
			{
				pDoc->r_bearing2 = bearing2.m_dBearing2_R;
				pDoc->bearing2_length = bearing2.m_dBearing2_Height;

				pSplit->UpdateData(FALSE);
			}
		}

		else if (m_iSelected == 5)
		{
			DlgBearing1 bearing1;

			bearing1.m_dBearing1_R = pDoc->r_bearing1;
			bearing1.m_dBearing1_Height = pDoc->bearing1_length;

			if (IDOK == bearing1.DoModal())
			{
				pDoc->r_bearing1 = bearing1.m_dBearing1_R;
				pDoc->bearing1_length = bearing1.m_dBearing1_Height;
				
				pSplit->UpdateData(FALSE);
			}
		}

		else if (m_iSelected == 0)
		{
			DlgVal2 val2;

			val2.m_dVal2_mainR = pDoc->r_val2;
			val2.m_dVal2_length = pDoc->val2_len;
			val2.m_dVal2_MainLength = pDoc->val2_mainLen;
			val2.m_dVal2_rDop = pDoc->val2_rdop;

			if (IDOK == val2.DoModal())

			{
				pDoc->val2_rdop = val2.m_dVal2_rDop;
				pDoc->val2_len = val2.m_dVal2_length;
				pDoc->val2_mainLen = val2.m_dVal2_MainLength;
				pDoc->r_val2 = val2.m_dVal2_mainR;

				pSplit->UpdateData(FALSE);
			}
		}
}
