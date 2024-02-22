
// DLLDoc.cpp : implementation of the CDLLDoc class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "DLL.h"
#endif

#include "DLLDoc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CDLLDoc

IMPLEMENT_DYNCREATE(CDLLDoc, CDocument)

BEGIN_MESSAGE_MAP(CDLLDoc, CDocument)
END_MESSAGE_MAP()


// CDLLDoc construction/destruction

CDLLDoc::CDLLDoc() noexcept
{
	// TODO: add one-time construction code here

}

CDLLDoc::~CDLLDoc()
{
}

BOOL CDLLDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;
	m_bShow = FALSE;
	return TRUE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}




// CDLLDoc serialization

void CDLLDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
		if (m_bShow)
		{
			ar << m_strName << m_strBat << m_strVal << m_strPrice << m_strUnit;
			ar << m_nPay;
			ar << m_bShow;
		}
	}
	else
	{
		// TODO: add loading code here
		ar >> m_strName >> m_strBat >> m_strVal >> m_strPrice >> m_strUnit;
		ar >> m_nPay;
		ar >> m_bShow;
	}
}

#ifdef SHARED_HANDLERS

// Support for thumbnails
void CDLLDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// Modify this code to draw the document's data
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

// Support for Search Handlers
void CDLLDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// Set search contents from document's data.
	// The content parts should be separated by ";"

	// For example:  strSearchContent = _T("point;rectangle;circle;ole object;");
	SetSearchContent(strSearchContent);
}

void CDLLDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = nullptr;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != nullptr)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CDLLDoc diagnostics

#ifdef _DEBUG
void CDLLDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDLLDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CDLLDoc commands
