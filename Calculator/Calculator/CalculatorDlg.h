
// CalculatorDlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"


// CCalculatorDlg �Ի���
class CCalculatorDlg : public CDialogEx
{
// ����
public:
	CCalculatorDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CALCULATOR_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	// ����������ӵ��ַ�����
	CString m_cinstr;
	//�����~
	CString m_test;
	//��ذ�������
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
	//������Ӧ��������
	BOOL PreTranslateMessage(MSG* pMsg);
};
