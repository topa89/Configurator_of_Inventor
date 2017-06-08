// Dlg_split.cpp: файл реализации
//

#include "stdafx.h"
#include "Val_Dlg.h"
#include "AssemblyConfig.h"
#include "Dlg_split.h"
#include "AssemblyTreeView.h"

#ifdef _DEBUG 
#define new DEBUG_NEW 
#endif 

#pragma once
#include <atlbase.h>
#import <RxInventor.tlb> \
rename_namespace("InventorNative") \
named_guids raw_dispinterfaces \
high_method_prefix("Method") \
rename("DeleteFile", "APIDeleteFile") \
rename("CopyFile", "APICopyFile") \
rename("MoveFile", "APIMoveFile") \
rename("SetEnvironmentVariable", "APISetEnvironmentVariable") \
rename("GetObject", "APIGetObject") \
exclude("_FILETIME", "IStream", "ISequentialStream", \
"_LARGE_INTEGER", "_ULARGE_INTEGER", "tagSTATSTG", \
"IEnumUnknown", "IPersistFile", "IPersist", "IPictureDisp")\

using namespace InventorNative;

CComPtr<Application> pInvApp;
//InventorNative::DocumentPtr pPartDoc;
InventorNative::PartDocumentPtr pPartDoc;
InventorNative::PartComponentDefinition *pPartComDef;
InventorNative::TransientGeometry *pTransGeom;
InventorNative::Transaction *pTrans;

InventorNative::PartDocumentPtr pPartDoc1;
InventorNative::PartComponentDefinition *pPartComDef1;
InventorNative::TransientGeometry *pTransGeom1;
InventorNative::Transaction *pTrans1;


InventorNative::PartDocumentPtr pPartDoc2;
InventorNative::PartComponentDefinition *pPartComDef2;
InventorNative::TransientGeometry *pTransGeom2;
InventorNative::Transaction *pTrans2;

InventorNative::PartDocumentPtr pPartDoc3;
InventorNative::PartComponentDefinition *pPartComDef3;
InventorNative::TransientGeometry *pTransGeom3;
InventorNative::Transaction *pTrans3;


InventorNative::AssemblyDocumentPtr pAsmDoc;
InventorNative::AssemblyComponentDefinitionPtr pAsmComDef;
InventorNative::TransientGeometry *pTransGeomAsm;
InventorNative::Matrix *oPositionMatrix;

TransactionManagerPtr pTransManager;
Document *Doc;

PlanarSketches *sketches;
Sketches3D   *sketches3D;
WorkPlanes *wp;
PartFeatures *ft;
WorkAxes *wax;
WorkPoints *wpt;
SketchPointPtr point[8];
SketchLinePtr lines[8];
SketchCirclesPtr circle[3];

// Dlg_split

IMPLEMENT_DYNCREATE(Dlg_split, CFormView)

Dlg_split::Dlg_split()
	: CFormView(IDD_DLG_SPLIT)
	//вал 1
	, val1_lengthmain(nullptr)
	, val1_length(nullptr)
	, val1_radius(nullptr)
	, val1_partradius(nullptr)
	//шестерня 1
	, gear1_radius(nullptr)
    , gear1_thickness(nullptr)
    , gear1_toothLength(nullptr)
    , gear1_intendation(nullptr)
	, gear1_Teeths(nullptr)
	//подшипник 1
	, bearing1_radius(nullptr)
	, bearing1_length(nullptr)

	//вал 2
	, val2_lengthmain(nullptr)
	, val2_length(nullptr)
	, val2_radius(nullptr)
	, val2_partradius(nullptr)
	//шестерня 2
	, gear2_radius(nullptr)
	, gear2_thickness(nullptr)
	, gear2_toothLength(nullptr)
	, gear2_intendation(nullptr)
	, gear2_Teeths(nullptr)
	//подшипник 2
	, bearing2_radius(nullptr)
	, bearing2_length(nullptr)
{

}

Dlg_split::~Dlg_split()
{
}

void Dlg_split::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//вал 1
	DDX_Text(pDX, IDC_EDIT1, *val1_lengthmain);
	DDX_Text(pDX, IDC_EDIT2, *val1_length);
	DDX_Text(pDX, IDC_EDIT3, *val1_radius);
	DDX_Text(pDX, IDC_EDIT4, *val1_partradius);
	//шестерня 1
	DDX_Text(pDX, IDC_EDIT5, *gear1_radius);
	DDX_Text(pDX, IDC_EDIT6, *gear1_thickness);
	DDX_Text(pDX, IDC_EDIT7, *gear1_toothLength);
	DDX_Text(pDX, IDC_EDIT8, *gear1_intendation);
	DDX_Text(pDX, IDC_EDIT9, *gear1_Teeths);
	//подшипник 1
	DDX_Text(pDX, IDC_EDIT10, *bearing1_radius);
	DDX_Text(pDX, IDC_EDIT11, *bearing1_length);

    //вал 2
	DDX_Text(pDX, IDC_EDIT12, *val2_lengthmain);
	DDX_Text(pDX, IDC_EDIT13, *val2_length);
	DDX_Text(pDX, IDC_EDIT14, *val2_radius);
	DDX_Text(pDX, IDC_EDIT15, *val2_partradius);
	//шестерня 2
	DDX_Text(pDX, IDC_EDIT16, *gear2_radius);
	DDX_Text(pDX, IDC_EDIT17, *gear2_thickness);
	DDX_Text(pDX, IDC_EDIT18, *gear2_toothLength);
	DDX_Text(pDX, IDC_EDIT19, *gear2_intendation);
	DDX_Text(pDX, IDC_EDIT20, *gear2_Teeths);
	//подшипник 2
	DDX_Text(pDX, IDC_EDIT21, *bearing2_radius);
	DDX_Text(pDX, IDC_EDIT22, *bearing2_length);
	
}

BEGIN_MESSAGE_MAP(Dlg_split, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &Dlg_split::OnBnClickedButton1)
END_MESSAGE_MAP()


// диагностика Dlg_split

#ifdef _DEBUG
void Dlg_split::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void Dlg_split::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// обработчики сообщений Dlg_split


void Dlg_split::OnBnClickedButton1()
{
	// TODO: добавьте свой код обработчика уведомлений
	BeginWaitCursor();


	// Get hold of the program id of Inventor.
	CLSID InvAppClsid;
	HRESULT hRes = CLSIDFromProgID(L"Inventor.Application", &InvAppClsid);
	if (FAILED(hRes)) {
		pInvApp = nullptr;
		return;// ReturnAndShowCOMError(hRes, L"ConnectToInventor,CLSIDFromProgID failed");
	}

	// See if Inventor is already running...
	CComPtr<IUnknown> pInvAppUnk = nullptr;
	hRes = ::GetActiveObject(InvAppClsid, NULL, &pInvAppUnk);
	if (FAILED(hRes)) {
		// Inventor is not already running, so try to start it...
		TRACE(L"Could not get hold of an active Inventor, will start a new session\n");
		hRes = CoCreateInstance(InvAppClsid, NULL, CLSCTX_LOCAL_SERVER, __uuidof(IUnknown), (void **)&pInvAppUnk);
		if (FAILED(hRes)) {
			pInvApp = nullptr;
			return;// ReturnAndShowCOMError(hRes, L"ConnectToInventor,CoCreateInstance failed");
		}
	}

	// Get the pointer to the Inventor application...
	hRes = pInvAppUnk->QueryInterface(__uuidof(Application), (void **)&pInvApp);
	if (FAILED(hRes)) {
		return;// ReturnAndShowCOMError(hRes, L"ConnectToInventor,QueryInterface failed");
	}
	
	
	CAssemblyConfigDoc* pDoc = (CAssemblyConfigDoc*)GetDocument();


	pInvApp->put_Visible(TRUE);

	Val(pDoc->r_val1/10,pDoc->val1_rdop/10,pDoc->val1_len/10,pDoc->val1_mainLen/10);

	Podshipnik(pDoc->r_bearing1/10, pDoc->bearing1_length/10, pDoc->val1_rdop / 10);
	//шестерня
	pPartDoc2 = pInvApp->Documents->MethodAdd(kPartDocumentObject, pInvApp->FileManager->MethodGetTemplateFile(kPartDocumentObject, kMetricSystemOfMeasure, kGOST_DraftingStandard), true);

	pPartDoc2->DisplayName = _T("Шестерня");

	pPartDoc2->get_ComponentDefinition(&pPartComDef2);

	pInvApp->get_TransientGeometry(&pTransGeom2);


	pTransManager = pInvApp->GetTransactionManager();

	Doc = CComQIPtr <Document>(pPartDoc2);

	pTransManager->raw_StartTransaction(Doc, _T(""), &pTrans2);

	pPartComDef2->get_Sketches(&sketches);
	pPartComDef2->get_Sketches3D(&sketches3D);
	pPartComDef2->get_WorkPlanes(&wp);
	pPartComDef2->get_Features(&ft);
	pPartComDef2->get_WorkAxes(&wax);
	pPartComDef2->get_WorkPoints(&wpt);

	//построение основной окружности с зубьями
	MainCircle(pDoc->r_gear1 / 10, pDoc->gear1_thickness / 10, pDoc->gear1_Teeths, pDoc->gear1_toothLength / 10, pDoc->r_val1 / 10);
	//выемки
	FrontCuts(pDoc->r_gear1 / 10, pDoc->gear1_thickness / 10, pDoc->gear1_intendation / 10);
	//выемки с другой стороны
	BackCuts(pDoc->r_gear1 / 10, pDoc->gear1_thickness / 10, pDoc->gear1_intendation / 10);
	//вписанные окружности
	
	OnDestroy();
	pPartDoc2->MethodSaveAs("C:\\Test_27\\Шестерня.ipt", true);

	Val(pDoc->r_val2 / 10, pDoc->val2_rdop/10, pDoc->val2_len / 10, pDoc->val2_mainLen/10);
	Podshipnik(pDoc->r_bearing2/10, pDoc->bearing2_length/10, pDoc->val2_rdop/10);



	//шестерня_2
	pPartDoc3 = pInvApp->Documents->MethodAdd(kPartDocumentObject, pInvApp->FileManager->MethodGetTemplateFile(kPartDocumentObject, kMetricSystemOfMeasure, kGOST_DraftingStandard), true);

	pPartDoc3->DisplayName = _T("Шестерня_2");

	pPartDoc3->get_ComponentDefinition(&pPartComDef3);

	pInvApp->get_TransientGeometry(&pTransGeom3);


	pTransManager = pInvApp->GetTransactionManager();

	Doc = CComQIPtr <Document>(pPartDoc3);

	pTransManager->raw_StartTransaction(Doc, _T(""), &pTrans3);

	pPartComDef3->get_Sketches(&sketches);
	pPartComDef3->get_Sketches3D(&sketches3D);
	pPartComDef3->get_WorkPlanes(&wp);
	pPartComDef3->get_Features(&ft);
	pPartComDef3->get_WorkAxes(&wax);
	pPartComDef3->get_WorkPoints(&wpt);


	//построение основной окружности с зубьями
	MainCircle_2(pDoc->r_gear2 / 10, pDoc->gear1_thickness / 10, pDoc->gear2_Teeths, pDoc->gear2_toothLength / 10, pDoc->r_val2 /10);
	//выемки
	FrontCuts_2(pDoc->r_gear2 / 10, pDoc->gear1_thickness / 10, pDoc->gear2_intendation / 10);
	//выемки с другой стороны
	BackCuts_2(pDoc->r_gear2 / 10, pDoc->gear1_thickness / 10, pDoc->gear2_intendation / 10);
	//вписанные окружности
	InscribedCircle(100 / 10, pDoc->gear1_thickness / 10);

	OnDestroy();
	pPartDoc3->MethodSaveAs("C:\\Test_27\\Шестерня_2.ipt", true);


	pAsmDoc = pInvApp->Documents->MethodAdd(kAssemblyDocumentObject, pInvApp->FileManager->MethodGetTemplateFile(kAssemblyDocumentObject, kMetricSystemOfMeasure, kGOST_DraftingStandard), true);
	pAsmDoc->DisplayName = _T("Сборка 1");
	pAsmDoc->get_ComponentDefinition(&pAsmComDef);
	pInvApp->get_TransientGeometry(&pTransGeomAsm);
	pTransGeomAsm->raw_CreateMatrix(&oPositionMatrix);

	ComponentOccurrencePtr Model1, Model2, Model3, Model4, Model5, Model6, Model7, Model8;
	Model1 = pAsmDoc->ComponentDefinition->Occurrences->MethodAdd("C:\\Test_27\\Вал.ipt", oPositionMatrix);
	Model2 = pAsmDoc->ComponentDefinition->Occurrences->MethodAdd("C:\\Test_27\\Подшипник.ipt", oPositionMatrix);
	Model3 = pAsmDoc->ComponentDefinition->Occurrences->MethodAdd("C:\\Test_27\\Подшипник.ipt", oPositionMatrix);
	Model4 = pAsmDoc->ComponentDefinition->Occurrences->MethodAdd("C:\\Test_27\\Шестерня.ipt", oPositionMatrix);
	Model5 = pAsmDoc->ComponentDefinition->Occurrences->MethodAdd("C:\\Test_27\\Вал_2.ipt", oPositionMatrix);
	Model6 = pAsmDoc->ComponentDefinition->Occurrences->MethodAdd("C:\\Test_27\\Подшипник_2.ipt", oPositionMatrix);
	Model7 = pAsmDoc->ComponentDefinition->Occurrences->MethodAdd("C:\\Test_27\\Подшипник_2.ipt", oPositionMatrix);
	Model8 = pAsmDoc->ComponentDefinition->Occurrences->MethodAdd("C:\\Test_27\\Шестерня_2.ipt", oPositionMatrix);

	SurfaceBody *SurfBody1, *SurfBody2, *SurfBody3, *SurfBody4, *SurfBody5, *SurfBody6, *SurfBody7, *SurfBody8;
	SurfaceBodies *SurfBodies1, *SurfBodies2, *SurfBodies3, *SurfBodies4, *SurfBodies5, *SurfBodies6, *SurfBodies7, *SurfBodies8;

	Model1->get_SurfaceBodies(&SurfBodies1);
	SurfBodies1->get_Item(1, &SurfBody1);

	Model2->get_SurfaceBodies(&SurfBodies2);
	SurfBodies2->get_Item(1, &SurfBody2);

	Model3->get_SurfaceBodies(&SurfBodies3);
	SurfBodies3->get_Item(1, &SurfBody3);

	Model4->get_SurfaceBodies(&SurfBodies4);
	SurfBodies4->get_Item(1, &SurfBody4);

	Model5->get_SurfaceBodies(&SurfBodies5);
	SurfBodies5->get_Item(1, &SurfBody5);

	Model6->get_SurfaceBodies(&SurfBodies6);
	SurfBodies6->get_Item(1, &SurfBody6);

	Model7->get_SurfaceBodies(&SurfBodies7);
	SurfBodies7->get_Item(1, &SurfBody7);

	Model8->get_SurfaceBodies(&SurfBodies8);
	SurfBodies8->get_Item(1, &SurfBody8);


	Edges *oEdges1, *oEdges2, *oEdges3, *oEdges4, *oEdges5, *oEdges6, *oEdges7, *oEdges8;
	EdgePtr oEdge1, oEdge2, oEdge3, oEdge4, oEdge5, oEdge6, oEdge7, oEdge8;

	SurfBody1->get_Edges(&oEdges1);
	oEdges1->get_Item(5, &oEdge1);
	
	SurfBody2->get_Edges(&oEdges2);
	oEdges2->get_Item(3, &oEdge2);

	SurfBody3->get_Edges(&oEdges3);
	oEdges3->get_Item(3, &oEdge3);

	SurfBody4->get_Edges(&oEdges4);
	oEdges4->get_Item(13, &oEdge4);

	SurfBody8->get_Edges(&oEdges8);
	oEdges8->get_Item(13, &oEdge8);


	MateConstraintPtr sPlane1, sPlane2, sPlane3, sPlane5, sPlane6, sPlane7, sPlane8, sPlane9, sPlanezap;

	sPlane1 = pAsmComDef->Constraints->MethodAddInsertConstraint(oEdge1, oEdge2, true, 0);//совмещение (встречно, с выравниванием), смещение

	
	SurfBody1->get_Edges(&oEdges1);
	oEdges1->get_Item(4, &oEdge1);
	

	sPlane2 = pAsmComDef->Constraints->MethodAddInsertConstraint(oEdge1, oEdge3, true, 0);

	sPlane3 = pAsmComDef->Constraints->MethodAddInsertConstraint(oEdge1, oEdge4, true, -(pDoc->val1_mainLen / 20 + pDoc->gear1_thickness / 20));
	
	
	//второй вал
	FacePtr oFace1, oFace5;
	Faces *oFaces1, *oFaces5;

	SurfBody1->get_Faces(&oFaces1);
	oFaces1->get_Item(1, &oFace1);

	SurfBody5->get_Faces(&oFaces5);
	oFaces5->get_Item(1, &oFace5);

	SurfBody1->get_Edges(&oEdges1);
	oEdges1->get_Item(1, &oEdge1);

	sPlane5 = pAsmComDef->Constraints->MethodAddTangentConstraint(oFace1, oFace5,false, 30);
	//sPlane3 = pAsmComDef->Constraints->MethodAddFlushConstraint(oFace1, oFace5, 50);

//подшипники на второй вал
	SurfBody5->get_Edges(&oEdges5);
	oEdges5->get_Item(5, &oEdge5);

	SurfBody6->get_Edges(&oEdges6);
	oEdges6->get_Item(3, &oEdge6);

	SurfBody7->get_Edges(&oEdges7);
	oEdges7->get_Item(3, &oEdge7);

	sPlane6 = pAsmComDef->Constraints->MethodAddInsertConstraint(oEdge5, oEdge6, true, 0);

	SurfBody5->get_Edges(&oEdges5);
	oEdges5->get_Item(4, &oEdge5);

	sPlane7 = pAsmComDef->Constraints->MethodAddInsertConstraint(oEdge5, oEdge7, true, 0);

	sPlane8 = pAsmComDef->Constraints->MethodAddInsertConstraint(oEdge5, oEdge8, true, -(pDoc->val2_mainLen / 20 +pDoc->gear1_thickness/20)); // шестерня


	

	//

	SurfBody8->get_Edges(&oEdges8);
	oEdges8->get_Item(52, &oEdge8);

	SurfBody4->get_Edges(&oEdges4);
	oEdges4->get_Item(50, &oEdge4);

	sPlane9 = pAsmComDef->Constraints->MethodAddMateConstraint(oEdge8, oEdge4, 0, kNoInference, kNoInference);
}



void Dlg_split::Podshipnik(double radius, double h, double rval)
{

	pPartDoc1 = pInvApp->Documents->MethodAdd(kPartDocumentObject, pInvApp->FileManager->MethodGetTemplateFile(kPartDocumentObject, kMetricSystemOfMeasure, kGOST_DraftingStandard), true);

	pPartDoc1->DisplayName = _T("Подшипник");

	pPartDoc1->get_ComponentDefinition(&pPartComDef1);

	pInvApp->get_TransientGeometry(&pTransGeom1);

	pTransManager = pInvApp->GetTransactionManager();

	Doc = CComQIPtr <Document>(pPartDoc1);

	pTransManager->raw_StartTransaction(Doc, _T(""), &pTrans1);

	pPartComDef1->get_Sketches(&sketches);
	pPartComDef1->get_Sketches3D(&sketches3D);

	pPartComDef1->get_WorkPlanes(&wp);
	pPartComDef1->get_Features(&ft);
	pPartComDef1->get_WorkAxes(&wax);
	pPartComDef1->get_WorkPoints(&wpt);

	double PI = 3.1415926535;

	double d1 = rval;
	double d4 = radius;
	double d2 = (d4 - d1) / 6 * 3 + d1;
	double d3 = (d4 - d1) / 6 * 5 + d1;


	PlanarSketch *pSketch;
	sketches->raw_Add(wp->GetItem(3), false, &pSketch);

	Profile *pProfile;

	SketchCirclePtr circle[2];
	SketchCircles *skcircle;

	Profiles *skProfiles;

	pSketch->get_Profiles(&skProfiles);
	pSketch->get_SketchCircles(&skcircle);


	circle[0] = skcircle->MethodAddByCenterRadius(pTransGeom->MethodCreatePoint2d(0, 0), d1);
	circle[1] = skcircle->MethodAddByCenterRadius(pTransGeom->MethodCreatePoint2d(0, 0), d2);

	skProfiles->raw__AddForSolid(&pProfile);

	ExtrudeFeatures *ftExtrude;
	ft->get_ExtrudeFeatures(&ftExtrude);

	ExtrudeFeaturePtr oExtrudeDef = ftExtrude->MethodAddByDistanceExtent(pProfile, h, kPositiveExtentDirection, kJoinOperation);

	PlanarSketch *pSketch2;
	sketches->raw_Add(wp->GetItem(3), false, &pSketch2);

	Profile *pProfile2;

	SketchCirclePtr circle2[2];
	SketchCircles *skcircle2;

	Profiles *skProfiles2;

	pSketch2->get_SketchCircles(&skcircle2);
	pSketch2->get_Profiles(&skProfiles2);

	circle2[0] = skcircle2->MethodAddByCenterRadius(pTransGeom->MethodCreatePoint2d(0, 0), d3);
	circle2[1] = skcircle2->MethodAddByCenterRadius(pTransGeom->MethodCreatePoint2d(0, 0), d4);

	skProfiles2->raw__AddForSolid(&pProfile2);

	ExtrudeFeatures *ftExtrude2;
	ft->get_ExtrudeFeatures(&ftExtrude2);

	ExtrudeFeaturePtr oExtrudeDef2 = ftExtrude2->MethodAddByDistanceExtent(pProfile2, h, kPositiveExtentDirection, kJoinOperation);


	PlanarSketch *pSketch4;
	sketches->raw_Add(wp->GetItem(2), false, &pSketch4);

	SketchCirclePtr circle4[1];
	SketchCircles *skcircle4;


	pSketch4->get_SketchCircles(&skcircle4);

	circle4[0] = skcircle4->MethodAddByCenterRadius(pTransGeom->MethodCreatePoint2d(d2 + (d3 - d2) / 2, h / 2), (d3 - d2) / 2 * 1.12);

	Profile *pProfile4;
	Profiles *skProfile4;

	pSketch4->get_Profiles(&skProfile4);
	skProfile4->raw__AddForSolid(&pProfile4);

	pSketch4->get_Profiles(&skProfile4);

	RevolveFeatures *ftrevolve4;
	ft->get_RevolveFeatures(&ftrevolve4);

	RevolveFeaturePtr oftrevolveDef4 = ftrevolve4->MethodAddFull(pProfile4, wax->GetItem(3), kCutOperation);



	PlanarSketch *pSketch3;

	wp->MethodAddByPlaneAndOffset(wp->GetItem(2), 0, true);
	sketches->raw_Add(wp->GetItem(4), false, &pSketch3);

	SketchPointPtr point3[2];
	SketchLinePtr lines[1];
	SketchArcPtr arc[1];

	SketchPoints *skPoints3;
	SketchLines *skLines;
	SketchArcs *skarcs;

	Profiles *skProfile3;

	pSketch3->get_SketchPoints(&skPoints3);
	pSketch3->get_SketchLines(&skLines);
	pSketch3->get_SketchArcs(&skarcs);
	pSketch3->get_Profiles(&skProfile3);

	point3[0] = skPoints3->MethodAdd(pTransGeom->MethodCreatePoint2d((d3 - d2) / 2 + d2, h / 6 * 1), false);
	point3[1] = skPoints3->MethodAdd(pTransGeom->MethodCreatePoint2d((d3 - d2) / 2 + d2, h / 6 * 5), false);


	lines[0] = skLines->MethodAddByTwoPoints(point3[0], point3[1]);


	//arc[0] = skarcs->MethodAddByCenterStartEndPoint(pTransGeom->MethodCreatePoint2d(72, 7.5), point3[1], point3[0], false);

	arc[0] = skarcs->MethodAddByCenterStartEndPoint(pTransGeom->MethodCreatePoint2d((d3 - d2) / 2 + d2, h / 2), point3[1], point3[0], false);


	Profile *pProfile3;
	skProfile3->raw__AddForSolid(&pProfile3);

	RevolveFeatures *ftrevolve;
	ft->get_RevolveFeatures(&ftrevolve);
	RevolveFeaturePtr oftrevolveDef = ftrevolve->MethodAddFull(pProfile3, lines[0], kJoinOperation);


	ObjectCollection *pCollection;
	pInvApp->TransientObjects->raw_CreateObjectCollection(vtMissing, &pCollection);
	pCollection->MethodAdd(oftrevolveDef);
	CircularPatternFeatures *pCircPatFeat;

	ft->get_CircularPatternFeatures(&pCircPatFeat);


	CircularPatternFeature *circFeat = pCircPatFeat->MethodAdd(pCollection, wax->GetItem(3), true, 20, 2 * PI, true, kIdenticalCompute);
	
	if (check) {
		pPartDoc1->MethodSaveAs("C:\\Test_27\\Подшипник.ipt", true); check = false;
	}
	else {
		pPartDoc1->MethodSaveAs("C:\\Test_27\\Подшипник_2.ipt", true);
	}
}

void  Dlg_split::MainCircle(double radius, double thickness, int number_of_teeth, double widthTooth, double rval)
{
	double tooth_length, tooth_bottom_width, tooth_top_width;
	tooth_length = radius + radius / 100 * widthTooth;
	tooth_bottom_width = radius / 100 * widthTooth;
	tooth_top_width = radius / 100 * (widthTooth * 0.4);

	PlanarSketch *pSketch;
	sketches->raw_Add(wp->GetItem(3), false, &pSketch);

	SketchPoints *skPoints;
	SketchLines *skLines;
	Profiles *skProfiles;
	SketchCircles *skcircles;

	pSketch->get_SketchCircles(&skcircles);
	pSketch->get_SketchPoints(&skPoints);
	pSketch->get_SketchLines(&skLines);
	pSketch->get_Profiles(&skProfiles);

	circle[0] = skcircles->MethodAddByCenterRadius(pTransGeom->MethodCreatePoint2d(0, 0), radius);
	circle[1] = skcircles->MethodAddByCenterRadius(pTransGeom->MethodCreatePoint2d(0, 0), rval);

	point[0] = skPoints->MethodAdd(pTransGeom->MethodCreatePoint2d(-tooth_top_width / 2, sqrt(pow(tooth_length, 2) - pow(tooth_top_width / 2, 2))), true);
	point[1] = skPoints->MethodAdd(pTransGeom->MethodCreatePoint2d(tooth_top_width / 2, sqrt(pow(tooth_length, 2) - pow(tooth_top_width / 2, 2))), true);
	point[2] = skPoints->MethodAdd(pTransGeom->MethodCreatePoint2d(tooth_bottom_width / 2, sqrt(pow(radius, 2) - pow(tooth_bottom_width / 2, 2))), true);
	point[3] = skPoints->MethodAdd(pTransGeom->MethodCreatePoint2d(-tooth_bottom_width / 2, sqrt(pow(radius, 2) - pow(tooth_bottom_width / 2, 2))), true);

	lines[0] = skLines->MethodAddByTwoPoints(point[0], point[1]);
	lines[1] = skLines->MethodAddByTwoPoints(point[1], point[2]);
	lines[2] = skLines->MethodAddByTwoPoints(point[2], point[3]);
	lines[3] = skLines->MethodAddByTwoPoints(point[3], point[0]);


	Profile *pProfile;
	skProfiles->raw__AddForSolid(&pProfile);

	ExtrudeFeatures *ftExtrude;
	ft->get_ExtrudeFeatures(&ftExtrude);

	ExtrudeFeaturePtr oExtrudeDef = ftExtrude->MethodAddByDistanceExtent(pProfile, thickness, kSymmetricExtentDirection, kJoinOperation);

	ObjectCollection *pCollection;
	pInvApp->TransientObjects->raw_CreateObjectCollection(vtMissing, &pCollection);
	pCollection->MethodAdd(oExtrudeDef);
	CircularPatternFeatures *pCircPatFeat;
	RectangularPatternFeatures *pRectPatFeat;

	ft->get_CircularPatternFeatures(&pCircPatFeat);
	ft->get_RectangularPatternFeatures(&pRectPatFeat);


	CircularPatternFeature *circFeat = pCircPatFeat->MethodAdd(pCollection, wax->GetItem(3), true, number_of_teeth, 2 * 3.14, true, kIdenticalCompute);
}

void Dlg_split::FrontCuts(double radius, double thickness, double intendation)
{
	PlanarSketch *pSketchVd;
	sketches->raw_Add(wp->MethodAddByPlaneAndOffset(wp->GetItem(3), thickness/2, true), true, &pSketchVd);

	SketchCircles *skcircles;
	Profiles *skProfilesVd;

	pSketchVd->get_SketchCircles(&skcircles);
	pSketchVd->get_Profiles(&skProfilesVd);

	circle[0] = skcircles->MethodAddByCenterRadius(pTransGeom->MethodCreatePoint2d(0, 0), radius / 100 * 80);
	circle[1] = skcircles->MethodAddByCenterRadius(pTransGeom->MethodCreatePoint2d(0, 0), radius / 100 * 70);

	Profile *pProfileVd;
	skProfilesVd->raw__AddForSolid(&pProfileVd);

	ExtrudeFeatures *ftExtrudeVd;
	ft->get_ExtrudeFeatures(&ftExtrudeVd);

	ExtrudeFeaturePtr oExtrudeDefVd = ftExtrudeVd->MethodAddByDistanceExtent(pProfileVd, intendation, kNegativeExtentDirection, kCutOperation);
}

void Dlg_split::BackCuts(double radius, double thickness, double intendation)
{
	PlanarSketch *pSketchVd2;
	sketches->raw_Add(wp->MethodAddByPlaneAndOffset(wp->GetItem(3), thickness / -2, true), true, &pSketchVd2);

	Profiles *skProfilesVd2;

	SketchCircles *skcircles;

	pSketchVd2->get_SketchCircles(&skcircles);
	pSketchVd2->get_Profiles(&skProfilesVd2);

	circle[0] = skcircles->MethodAddByCenterRadius(pTransGeom->MethodCreatePoint2d(0, 0), radius / 100 * 80);
	circle[1] = skcircles->MethodAddByCenterRadius(pTransGeom->MethodCreatePoint2d(0, 0), radius / 100 * 70);

	Profile *pProfileVd2;
	skProfilesVd2->raw__AddForSolid(&pProfileVd2);

	ExtrudeFeatures *ftExtrudeVd2;
	ft->get_ExtrudeFeatures(&ftExtrudeVd2);

	ExtrudeFeaturePtr oExtrudeDefVd2 = ftExtrudeVd2->MethodAddByDistanceExtent(pProfileVd2, intendation, kPositiveExtentDirection, kCutOperation);
}

void Dlg_split::InscribedCircle(double radius, double thickness)
{
	PlanarSketch *pSketch2;
	sketches->raw_Add(wp->GetItem(3), false, &pSketch2);

	SketchCircles *skcircles2;
	Profiles *skProfiles2;

	pSketch2->get_SketchCircles(&skcircles2);

	double radius_of_inscribed_circle = radius / 100 * 30;
	//круги
	circle[0] = skcircles2->MethodAddByCenterRadius(pTransGeom->MethodCreatePoint2d(0, radius + radius * 0.60), radius_of_inscribed_circle / 2);

	Profile *pProfile2;
	pSketch2->get_Profiles(&skProfiles2);
	skProfiles2->raw__AddForSolid(&pProfile2);

	ExtrudeFeatures *ftExtrude2;
	ft->get_ExtrudeFeatures(&ftExtrude2);

	ExtrudeFeaturePtr oExtrudeDef2 = ftExtrude2->MethodAddByDistanceExtent(pProfile2, thickness, kSymmetricExtentDirection, kCutOperation);

	ObjectCollection *pCollectionForVt;
	pInvApp->TransientObjects->raw_CreateObjectCollection(vtMissing, &pCollectionForVt);
	pCollectionForVt->MethodAdd(oExtrudeDef2);
	CircularPatternFeatures *pCircPatFeatForVt;
	RectangularPatternFeatures *pRectPatFeatForVt;

	ft->get_CircularPatternFeatures(&pCircPatFeatForVt);
	ft->get_RectangularPatternFeatures(&pRectPatFeatForVt);

	int n = pCircPatFeatForVt->GetCount();
	int n1 = pRectPatFeatForVt->GetCount();

	n = pCollectionForVt->GetCount();

	CircularPatternFeature *circFeatForVt = pCircPatFeatForVt->MethodAdd(pCollectionForVt, wax->GetItem(3), true, 4, 2 * 3.14, true, kIdenticalCompute);
}

void  Dlg_split::MainCircle_2(double radius, double thickness, int number_of_teeth, double widthTooth, double rval)
{
	float tooth_length, tooth_bottom_width, tooth_top_width;
	tooth_length = radius + radius / 100 * widthTooth;
	tooth_bottom_width = radius / 100 * widthTooth;
	tooth_top_width = radius / 100 * (widthTooth * 0.4);

	PlanarSketch *pSketch;
	sketches->raw_Add(wp->GetItem(3), false, &pSketch);

	SketchPoints *skPoints;
	SketchLines *skLines;
	Profiles *skProfiles;
	SketchCircles *skcircles;

	pSketch->get_SketchCircles(&skcircles);
	pSketch->get_SketchPoints(&skPoints);
	pSketch->get_SketchLines(&skLines);
	pSketch->get_Profiles(&skProfiles);

	circle[0] = skcircles->MethodAddByCenterRadius(pTransGeom->MethodCreatePoint2d(0, 0), radius);
	circle[1] = skcircles->MethodAddByCenterRadius(pTransGeom->MethodCreatePoint2d(0, 0), rval);

	point[0] = skPoints->MethodAdd(pTransGeom->MethodCreatePoint2d(-tooth_top_width / 2, sqrt(pow(tooth_length, 2) - pow(tooth_top_width / 2, 2))), true);
	point[1] = skPoints->MethodAdd(pTransGeom->MethodCreatePoint2d(tooth_top_width / 2, sqrt(pow(tooth_length, 2) - pow(tooth_top_width / 2, 2))), true);
	point[2] = skPoints->MethodAdd(pTransGeom->MethodCreatePoint2d(tooth_bottom_width / 2, sqrt(pow(radius, 2) - pow(tooth_bottom_width / 2, 2))), true);
	point[3] = skPoints->MethodAdd(pTransGeom->MethodCreatePoint2d(-tooth_bottom_width / 2, sqrt(pow(radius, 2) - pow(tooth_bottom_width / 2, 2))), true);

	lines[0] = skLines->MethodAddByTwoPoints(point[0], point[1]);
	lines[1] = skLines->MethodAddByTwoPoints(point[1], point[2]);
	lines[2] = skLines->MethodAddByTwoPoints(point[2], point[3]);
	lines[3] = skLines->MethodAddByTwoPoints(point[3], point[0]);


	Profile *pProfile;
	skProfiles->raw__AddForSolid(&pProfile);

	ExtrudeFeatures *ftExtrude;
	ft->get_ExtrudeFeatures(&ftExtrude);

	ExtrudeFeaturePtr oExtrudeDef = ftExtrude->MethodAddByDistanceExtent(pProfile, thickness, kSymmetricExtentDirection, kJoinOperation);

	ObjectCollection *pCollection;
	pInvApp->TransientObjects->raw_CreateObjectCollection(vtMissing, &pCollection);
	pCollection->MethodAdd(oExtrudeDef);
	CircularPatternFeatures *pCircPatFeat;
	RectangularPatternFeatures *pRectPatFeat;

	ft->get_CircularPatternFeatures(&pCircPatFeat);
	ft->get_RectangularPatternFeatures(&pRectPatFeat);



	CircularPatternFeature *circFeat = pCircPatFeat->MethodAdd(pCollection, wax->GetItem(3), true, number_of_teeth, 2 * 3.14, true, kIdenticalCompute);
}

void Dlg_split::FrontCuts_2(double radius, double thickness, double intendation)
{
	PlanarSketch *pSketchVd;
	sketches->raw_Add(wp->MethodAddByPlaneAndOffset(wp->GetItem(3), thickness / 2, true), true, &pSketchVd);

	SketchCircles *skcircles;
	Profiles *skProfilesVd;

	pSketchVd->get_SketchCircles(&skcircles);
	pSketchVd->get_Profiles(&skProfilesVd);

	circle[0] = skcircles->MethodAddByCenterRadius(pTransGeom->MethodCreatePoint2d(0, 0), radius / 100 * 90);
	circle[1] = skcircles->MethodAddByCenterRadius(pTransGeom->MethodCreatePoint2d(0, 0), radius / 100 * 70);

	Profile *pProfileVd;
	skProfilesVd->raw__AddForSolid(&pProfileVd);

	ExtrudeFeatures *ftExtrudeVd;
	ft->get_ExtrudeFeatures(&ftExtrudeVd);

	ExtrudeFeaturePtr oExtrudeDefVd = ftExtrudeVd->MethodAddByDistanceExtent(pProfileVd, intendation, kNegativeExtentDirection, kCutOperation);
}

void Dlg_split::BackCuts_2(double radius, double thickness, double intendation)
{
	PlanarSketch *pSketchVd2;
	sketches->raw_Add(wp->MethodAddByPlaneAndOffset(wp->GetItem(3), thickness / -2, true), true, &pSketchVd2);

	Profiles *skProfilesVd2;

	SketchCircles *skcircles;

	pSketchVd2->get_SketchCircles(&skcircles);
	pSketchVd2->get_Profiles(&skProfilesVd2);

	circle[0] = skcircles->MethodAddByCenterRadius(pTransGeom->MethodCreatePoint2d(0, 0), radius / 100 * 90);
	circle[1] = skcircles->MethodAddByCenterRadius(pTransGeom->MethodCreatePoint2d(0, 0), radius / 100 * 70);

	Profile *pProfileVd2;
	skProfilesVd2->raw__AddForSolid(&pProfileVd2);

	ExtrudeFeatures *ftExtrudeVd2;
	ft->get_ExtrudeFeatures(&ftExtrudeVd2);

	ExtrudeFeaturePtr oExtrudeDefVd2 = ftExtrudeVd2->MethodAddByDistanceExtent(pProfileVd2, intendation, kPositiveExtentDirection, kCutOperation);
}

void Dlg_split::Val(double radius, double rval, double length_all, double length_main)
{
	CAssemblyConfigDoc* pDoc = (CAssemblyConfigDoc*)GetDocument();
	pPartDoc = pInvApp->Documents->MethodAdd(kPartDocumentObject, pInvApp->FileManager->MethodGetTemplateFile(kPartDocumentObject, kMetricSystemOfMeasure, kGOST_DraftingStandard), true);

	pPartDoc->DisplayName = _T("Вал");

	pPartDoc->get_ComponentDefinition(&pPartComDef);

	pInvApp->get_TransientGeometry(&pTransGeom);

	pTransManager = pInvApp->GetTransactionManager();

	Doc = CComQIPtr <Document>(pPartDoc);

	pTransManager->raw_StartTransaction(Doc, _T(""), &pTrans);

	pPartComDef->get_Sketches(&sketches);
	pPartComDef->get_Sketches3D(&sketches3D);

	pPartComDef->get_WorkPlanes(&wp);
	pPartComDef->get_Features(&ft);
	pPartComDef->get_WorkAxes(&wax);
	pPartComDef->get_WorkPoints(&wpt);
	
	//второй цилиндр
	PlanarSketch *pSketch_Val1_2;
	sketches->raw_Add(wp->GetItem(3), false, &pSketch_Val1_2);

	SketchLinePtr lines_2[1];
	SketchCirclePtr circles_2[1];
	SketchCircles * skCircles_2;
	SketchLines *skLines_2;
	Profiles *skProfiles_2;

	pSketch_Val1_2->get_SketchLines(&skLines_2);
	pSketch_Val1_2->get_SketchCircles(&skCircles_2);
	pSketch_Val1_2->get_Profiles(&skProfiles_2);

	circles_2[0] = skCircles_2->MethodAddByCenterRadius(pTransGeom->MethodCreatePoint2d(0, 0), radius);

	Profile *pProfile_2;
	skProfiles_2->raw__AddForSolid(&pProfile_2);

	ExtrudeFeatures *ftExtrude2;
	ft->get_ExtrudeFeatures(&ftExtrude2);

	ExtrudeFeaturePtr oExtrudeDef2 = ftExtrude2->MethodAddByDistanceExtent(pProfile_2, length_main, kSymmetricExtentDirection, kJoinOperation);



	//первый цилиндр
	PlanarSketch *pSketch_Val1_1;
	sketches->raw_Add(wp->MethodAddByPlaneAndOffset(wp->GetItem(3), (length_main)/2, true), true, &pSketch_Val1_1);

	SketchLinePtr lines_1[1];
	SketchCirclePtr circles_1[1];
	SketchCircles * skCircles_1;
	SketchLines *skLines_1;
	Profiles *skProfiles_1;

	pSketch_Val1_1->get_SketchLines(&skLines_1);
	pSketch_Val1_1->get_SketchCircles(&skCircles_1);
	pSketch_Val1_1->get_Profiles(&skProfiles_1);
	
	
	circles_1[0] = skCircles_1->MethodAddByCenterRadius(pTransGeom->MethodCreatePoint2d(0, 0), rval );

	Profile *pProfile_1;
	skProfiles_1->raw__AddForSolid(&pProfile_1);

	ExtrudeFeatures *ftExtrude_1;
	ft->get_ExtrudeFeatures(&ftExtrude_1);

	ExtrudeFeaturePtr oExtrudeDef_1 = ftExtrude_1->MethodAddByDistanceExtent(pProfile_1, (length_all - length_main) / 2, kPositiveExtentDirection, kJoinOperation);


	//третий цилиндр
	PlanarSketch *pSketch_Val1_3;
	sketches->raw_Add(wp->MethodAddByPlaneAndOffset(wp->GetItem(3), -(length_main) / 2, true), true, &pSketch_Val1_3);

	SketchLinePtr lines_3[1];
	SketchCirclePtr circles_3[1];
	SketchCircles * skCircles_3;
	SketchLines *skLines_3;
	Profiles *skProfiles_3;

	pSketch_Val1_3->get_SketchLines(&skLines_3);
	pSketch_Val1_3->get_SketchCircles(&skCircles_3);
	pSketch_Val1_3->get_Profiles(&skProfiles_3);

	circles_3[0] = skCircles_3->MethodAddByCenterRadius(pTransGeom->MethodCreatePoint2d(0, 0), rval);

	Profile *pProfile_3;
	skProfiles_3->raw__AddForSolid(&pProfile_3);

	ExtrudeFeatures *ftExtrude_3;
	ft->get_ExtrudeFeatures(&ftExtrude_3);

	ExtrudeFeaturePtr oExtrudeDef3 = ftExtrude_3->MethodAddByDistanceExtent(pProfile_3, (length_all - length_main) / 2, kNegativeExtentDirection, kJoinOperation);

	pTrans->MethodEnd();

	
	if (check) {
		pPartDoc->MethodSaveAs("C:\\Test_27\\Вал.ipt", true); 
	}
	else {
		pPartDoc->MethodSaveAs("C:\\Test_27\\Вал_2.ipt", true);

	}


}

