// Cfile.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Calculator.h"
#include "Cfile.h"
#include "afxdialogex.h"
#include "scanner.h"

// Cfile �Ի���

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


// Cfile ��Ϣ�������


void Cfile::OnBnClickedOpenfile1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	// ���ù�����   
	TCHAR szFilter[] = _T("�ı��ļ�(*.txt)|*.txt|�����ļ�(*.*)|*.*||");
	// ������ļ��Ի���   
	CFileDialog fileDlg(TRUE, _T("txt"), NULL, 0, szFilter, this);
	CString strFilePath;

	// ��ʾ���ļ��Ի���   
	if (IDOK == fileDlg.DoModal())
	{
		// ���������ļ��Ի����ϵġ��򿪡���ť����ѡ����ļ�·����ʾ���༭����   
		strFilePath = fileDlg.GetPathName();
		m_filein_path = strFilePath;
		UpdateData(FALSE);
		//SetDlgItemText(IDC_OPEN_EDIT, strFilePath);
	}
}


void Cfile::OnBnClickedOpenfile2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	// ���ù�����   
	TCHAR szFilter[] = _T("�ı��ļ�(*.txt)|*.txt|�����ļ�(*.*)|*.*||");
	// ������ļ��Ի���   
	CFileDialog fileDlg(TRUE, _T("txt"), NULL, 0, szFilter, this);
	CString strFilePath;

	// ��ʾ���ļ��Ի���   
	if (IDOK == fileDlg.DoModal())
	{
		// ���������ļ��Ի����ϵġ��򿪡���ť����ѡ����ļ�·����ʾ���༭����   
		strFilePath = fileDlg.GetPathName();
		m_fileout_path = strFilePath;
		UpdateData(FALSE);
		//SetDlgItemText(IDC_OPEN_EDIT, strFilePath);
	}
}


void Cfile::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	Scanner scanner;


	//GetDlgItemText(IDC_fileout_EDIT, m_filein_path); �ڶ��ַ���
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
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}
