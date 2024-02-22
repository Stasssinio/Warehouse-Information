
// DLLView.h : interface of the CDLLView class
//

#pragma once
#include "CPersonDialog.h"

class CDLLView : public CScrollView
{
protected: // create from serialization only
	CDLLView() noexcept;
	DECLARE_DYNCREATE(CDLLView)

// Attributes
public:
	CDLLDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void OnInitialUpdate(); // called first time after construct
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~CDLLView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
};

#ifndef _DEBUG  // debug version in DLLView.cpp
inline CDLLDoc* CDLLView::GetDocument() const
   { return reinterpret_cast<CDLLDoc*>(m_pDocument); }
#endif

