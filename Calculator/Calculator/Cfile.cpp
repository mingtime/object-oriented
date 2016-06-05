// Cfile.cpp : 实现文件
//

#include "stdafx.h"
#include "Calculator.h"
#include "Cfile.h"
#include "afxdialogex.h"
#include "scanner.h"

// Cfile 对话框

IMPLEMENT_DYNAMIC(Cfile, CDialogEx)

Cfile::Cfile(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_FILEIN, pParent)
	, m_filein_path(_T(""))
	, m_fileout_path(_T(""))
{

}

Cfile::~Cfile()
{
}

void Cfile::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_filein_EDIT, m_filein_path);
	DDX_Text(pDX, IDC_fileout_EDIT, m_fileout_path);
}


BEGIN_MESSAGE_MAP(Cfile, CDialogEx)
	ON_BN_CLICKED(IDC_OPENFILE1, &Cfile::OnBnClickedOpenfile1)
	ON_BN_CLICKED(IDC_OPENFILE2, &Cfile::OnBnClickedOpenfile2)
	ON_BN_CLICKED(IDOK, &Cfile::OnBnClickedOk)
	ON_EN_CHANGE(IDC_filein_EDIT, &Cfile::OnEnChangefileinEdit)
END_MESSAGE_MAP()


// Cfile 消息处理程序


void Cfile::OnBnClickedOpenfile1()
{
	// TODO: 在此添加控件通知处理程序代码
	// 设置过滤器   
	TCHAR szFilter[] = _T("文本文件(*.txt)|*.txt|所有文件(*.*)|*.*||");
	// 构造打开文件对话框   
	CFileDialog fileDlg(TRUE, _T("txt"), NULL, 0, szFilter, this);
	CString strFilePath;

	// 显示打开文件对话框   
	if (IDOK == fileDlg.DoModal())
	{
		// 如果点击了文件对话框上的“打开”按钮，则将选择的文件路径显示到编辑框里   
		strFilePath = fileDlg.GetPathName();
		m_filein_path = strFilePath;
		UpdateData(FALSE);
		//SetDlgItemText(IDC_OPEN_EDIT, strFilePath);
	}
}


void Cfile::OnBnClickedOpenfile2()
{
	// TODO: 在此添加控件通知处理程序代码
	// 设置过滤器   
	TCHAR szFilter[] = _T("文本文件(*.txt)|*.txt|所有文件(*.*)|*.*||");
	// 构造打开文件对话框   
	CFileDialog fileDlg(TRUE, _T("txt"), NULL, 0, szFilter, this);
	CString strFilePath;

	// 显示打开文件对话框   
	if (IDOK == fileDlg.DoModal())
	{
		// 如果点击了文件对话框上的“打开”按钮，则将选择的文件路径显示到编辑框里   
		strFilePath = fileDlg.GetPathName();
		m_fileout_path = strFilePath;
		UpdateData(FALSE);
		//SetDlgItemText(IDC_OPEN_EDIT, strFilePath);
	}
}


void Cfile::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	Scanner scanner;


	//GetDlgItemText(IDC_fileout_EDIT, m_filein_path); 第二种方法
	//MessageBox(m_filein_path);

	UpdateData(TRUE);
	USES_CONVERSION;

	string filenamein(W2A(m_filein_path));
	string filenameout(W2A(m_fileout_path));

	scanner.writein(filenamein, filenameout);

	//CDialogEx::OnOK();
}


void Cfile::OnEnChangefileinEdit()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}
