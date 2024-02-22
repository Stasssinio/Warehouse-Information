
// DLL.h : main header file for the DLL application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CDLLApp:
// See DLL.cpp for the implementation of this class
//

class CDLLApp : public CWinApp
{
public:
	CDLLApp() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CDLLApp theApp;
