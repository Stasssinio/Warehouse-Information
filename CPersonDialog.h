#pragma once

const int LOWEST_SPIN_VALUE = 0;
const int HIGHEST_SPIN_VALUE = 100;

// CPersonDialog dialog

class CPersonDialog : public CDialog
{
	DECLARE_DYNAMIC(CPersonDialog)

public:
	CPersonDialog(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CPersonDialog();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
private:
	CSpinButtonCtrl m_nSpin;
public:
	CString m_strName;
	int m_nPay;
	CString m_strPrice;
	CString m_strBat;
	CString m_strVal;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedOk();
	CString m_strUnit;
	
};
