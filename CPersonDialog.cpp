// CPersonDialog.cpp : implementation file
//

#include "pch.h"
#include "DLL.h"
#include "CPersonDialog.h"
#include "afxdialogex.h"


// CPersonDialog dialog

IMPLEMENT_DYNAMIC(CPersonDialog, CDialog)

CPersonDialog::CPersonDialog(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG1, pParent)
	, m_strName(_T(""))
	, m_nPay(0)
	, m_strPrice(_T(""))
	, m_strBat(_T(""))
	, m_strVal(_T(""))
	, m_strUnit(_T(""))
{

}

CPersonDialog::~CPersonDialog()
{
}

void CPersonDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_SPIN1, m_nSpin);
	DDX_Text(pDX, IDC_NAME, m_strName);
	DDX_Check(pDX, IDC_PAY_Y, m_nPay);
	DDX_Text(pDX, IDC_PRICE, m_strPrice);
	DDX_Text(pDX, IDC_BATCH, m_strBat);
	DDX_CBString(pDX, IDC_CARR, m_strVal);
	DDX_Text(pDX, IDC_UNIT, m_strUnit);
}


BEGIN_MESSAGE_MAP(CPersonDialog, CDialog)
	ON_BN_CLICKED(IDOK, &CPersonDialog::OnBnClickedOk)
END_MESSAGE_MAP()


// CPersonDialog message handlers


BOOL CPersonDialog::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  Add extra initialization here
	m_nSpin.SetRange(LOWEST_SPIN_VALUE, HIGHEST_SPIN_VALUE);
	m_nSpin.SetPos(LOWEST_SPIN_VALUE);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE
}


void CPersonDialog::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	UpdateData();
	if (m_strName.IsEmpty() || m_strPrice.IsEmpty() || m_strBat.IsEmpty() ||
		m_strUnit.IsEmpty())
	{
		MessageBox(_T("There are empty fields!"), _T("OOPS!!"), MB_ICONERROR);
	}
	CDialog::OnOK();
}
