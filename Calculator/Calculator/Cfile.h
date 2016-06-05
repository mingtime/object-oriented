#pragma once


// Cfile 对话框

class Cfile : public CDialogEx
{
	DECLARE_DYNAMIC(Cfile)

public:
	Cfile(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~Cfile();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_FILEIN };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString m_filein_path;
	afx_msg void OnBnClickedOpenfile1();
	CString m_fileout_path;
	afx_msg void OnBnClickedOpenfile2();
	afx_msg void OnBnClickedOk();
	afx_msg void OnEnChangefileinEdit();
};
