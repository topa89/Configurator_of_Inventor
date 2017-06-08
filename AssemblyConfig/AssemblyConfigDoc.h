
// AssemblyConfigDoc.h : ��������� ������ CAssemblyConfigDoc
//


#pragma once


class CAssemblyConfigDoc : public CDocument
{
protected: // ������� ������ �� ������������
	CAssemblyConfigDoc();
	DECLARE_DYNCREATE(CAssemblyConfigDoc)

// ��������
public:

// ��������
public:
	int m_iSelected = -1;

	//1-� ���
	double r_val1, val1_rdop, val1_len, val1_mainLen;

	//2-� ���
	double r_val2, val2_rdop, val2_len, val2_mainLen;

	//1-� ���������
	double r_bearing1, bearing1_length;

	//2-� ���������
	double r_bearing2, bearing2_length;

	//1-� ��������
	double r_gear1, gear1_toothLength, gear1_thickness, gear1_intendation, gear1_Teeths;

	//2-� ��������
	double r_gear2, gear2_toothLength, gear2_thickness, gear2_intendation, gear2_Teeths;
	
// ���������������
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// ����������
public:
	virtual ~CAssemblyConfigDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ��������� ������� ����� ���������
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// ��������������� �������, �������� ���������� ������ ��� ����������� ������
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
