
// DLLDoc.h : interface of the CDLLDoc class
//


#pragma once


class CDLLDoc : public CDocument
{
protected: // create from serialization only
	CDLLDoc() noexcept;
	DECLARE_DYNCREATE(CDLLDoc)

// Attributes
public:
	CString	m_strName, m_strBat, m_strVal, m_strPrice, m_strUnit;
	int m_nPay;
	BOOL m_bShow;
	CSpinButtonCtrl m_nSpin;

// Operations
public:

// Overrides
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// Implementation
public:
	virtual ~CDLLDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// Helper function that sets search content for a Search Handler
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
