
// AssemblyConfigDoc.h : интерфейс класса CAssemblyConfigDoc
//


#pragma once


class CAssemblyConfigDoc : public CDocument
{
protected: // создать только из сериализации
	CAssemblyConfigDoc();
	DECLARE_DYNCREATE(CAssemblyConfigDoc)

// Атрибуты
public:

// Операции
public:
	int m_iSelected = -1;

	//1-й вал
	double r_val1, val1_rdop, val1_len, val1_mainLen;

	//2-й вал
	double r_val2, val2_rdop, val2_len, val2_mainLen;

	//1-й подшипник
	double r_bearing1, bearing1_length;

	//2-й подшипник
	double r_bearing2, bearing2_length;

	//1-я шестерня
	double r_gear1, gear1_toothLength, gear1_thickness, gear1_intendation, gear1_Teeths;

	//2-я шестерня
	double r_gear2, gear2_toothLength, gear2_thickness, gear2_intendation, gear2_Teeths;
	
// Переопределение
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// Реализация
public:
	virtual ~CAssemblyConfigDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Созданные функции схемы сообщений
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// Вспомогательная функция, задающая содержимое поиска для обработчика поиска
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
