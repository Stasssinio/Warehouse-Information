
// DLLView.cpp : implementation of the CDLLView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "DLL.h"
#endif

#include "DLLDoc.h"
#include "DLLView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDLLView

IMPLEMENT_DYNCREATE(CDLLView, CScrollView)

BEGIN_MESSAGE_MAP(CDLLView, CScrollView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CScrollView::OnFilePrintPreview)
	ON_WM_RBUTTONDOWN()
	ON_WM_CHAR()
END_MESSAGE_MAP()

// CDLLView construction/destruction

CDLLView::CDLLView() noexcept
{
	// TODO: add construction code here

}

CDLLView::~CDLLView()
{
}

BOOL CDLLView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CScrollView::PreCreateWindow(cs);
}

// CDLLView drawing

void CDLLView::OnDraw(CDC* p)
{
	CDLLDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
	if (pDoc->m_bShow)
	{
		CString s;
		p->TextOutW(1, 0, _T("Batch number: ") + pDoc->m_strBat);
		p->TextOutW(1, 30, _T("Name of detail: ") + pDoc->m_strName);
		p->TextOutW(1, 60, _T("Price: ") + pDoc->m_strPrice);
		switch (pDoc->m_nPay)
		{
		case 0: s = _T("No!");
			break;
		case 1: s = _T("Yes!");
		}
		p->TextOutW(1, 90, _T("Paid delivery: ") + s);
		s = "";
		p->TextOutW(1, 120, _T("Delivery man: ") + pDoc->m_strVal);
		p->TextOutW(1, 150, _T("Units: ") + pDoc->m_strUnit);
	}
}

void CDLLView::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();

	CSize sizeTotal;
	// TODO: calculate the total size of this view
	sizeTotal.cx = sizeTotal.cy = 330;
	SetScrollSizes(MM_TEXT, sizeTotal);
}


// CDLLView printing

BOOL CDLLView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CDLLView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CDLLView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CDLLView diagnostics

#ifdef _DEBUG
void CDLLView::AssertValid() const
{
	CScrollView::AssertValid();
}

void CDLLView::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}

CDLLDoc* CDLLView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDLLDoc)));
	return (CDLLDoc*)m_pDocument;
}
#endif //_DEBUG


// CDLLView message handlers


void CDLLView::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	CDLLDoc* pDoc = GetDocument();
	CPersonDialog dlg;
	dlg.m_nPay = 0;
	if (dlg.DoModal() == IDOK)
	{
		pDoc->m_strName = dlg.m_strName;
		pDoc->m_strBat = dlg.m_strBat;
		pDoc->m_strVal = dlg.m_strVal;
		pDoc->m_strPrice = dlg.m_strPrice;
		pDoc->m_strUnit = dlg.m_strUnit;
		pDoc->m_nPay = dlg.m_nPay;
		pDoc->m_bShow = TRUE;
		RedrawWindow();
	}
	CScrollView::OnRButtonDown(nFlags, point);
}


void CDLLView::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: Add your message handler code here and/or call default

	CScrollView::OnChar(nChar, nRepCnt, nFlags);
}
