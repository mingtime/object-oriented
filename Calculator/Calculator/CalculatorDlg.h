
// CalculatorDlg.h : 头文件
//

#pragma once
#include "afxwin.h"


// CCalculatorDlg 对话框
class CCalculatorDlg : public CDialogEx
{
// 构造
public:
	CCalculatorDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CALCULATOR_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	// 对输入的数加到字符串中
	CString m_cinstr;
	//输出的~
	CString m_test;
	//相关按键函数
	afx_msg void OnEnChangeSummandEdit();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedcalculation();
	afx_msg void OnBnClickedadd();
	afx_msg void OnBnClickedleftbracket();
	afx_msg void OnBnClickednum1();
	afx_msg void OnBnClickednum2();
	afx_msg void OnBnClickednum3();
	afx_msg void OnBnClickednum4();
	afx_msg void OnBnClickednum5();
	afx_msg void OnBnClickednum6();
	afx_msg void OnBnClickednum7();
	afx_msg void OnBnClickednum8();
	afx_msg void OnBnClickednum9();
	afx_msg void OnBnClickedrightbracket();
	afx_msg void OnBnClickedminus();
	afx_msg void OnBnClickedmultiply();
	afx_msg void OnBnClickeddivision();
	afx_msg void OnBnClickeddeleteone();
	afx_msg void OnBnClickedButton19();
	afx_msg void OnBnClickeddeleteall();
	afx_msg void OnBnClickedCancel();
	afx_msg void OnEnChangeOutstrEdit();
	afx_msg void OnEnChangeEdit3();
	afx_msg void OnBnClickedButton20();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedzero();
	afx_msg void OnBnClickeddecimal();
	afx_msg void OnBnClickedfile();
	//键盘响应函数声明
	BOOL PreTranslateMessage(MSG* pMsg);
};
