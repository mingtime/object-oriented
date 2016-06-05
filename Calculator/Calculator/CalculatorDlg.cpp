
// CalculatorDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Calculator.h"
#include "CalculatorDlg.h"
#include "afxdialogex.h"
#include "scanner.h"
#include "Calculation.h"
#include "Printner.h"
#include "Cfile.h"
#include <stack>
#include <queue>
#include <iostream>
using namespace std;
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CCalculatorDlg �Ի���



CCalculatorDlg::CCalculatorDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_CALCULATOR_DIALOG, pParent)
	, m_cinstr(_T(""))  //������ַ��������~
	,m_test(_T(""))   //�������������ַ���~~
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCalculatorDlg::DoDataExchange(CDataExchange* pDX)
{
	// ����MFCĬ�ϵ����ݽ���   

	CDialogEx::DoDataExchange(pDX);
	// ����ؼ�IDC_SUMMAND_EDIT�ͱ���m_editSummand֮������ݽ���   
	DDX_Text(pDX, IDC_CINSTR_EDIT, m_cinstr);
	DDX_Text(pDX, IDC_EDIT3, m_test);
	
}


//���еĲ���������������
BEGIN_MESSAGE_MAP(CCalculatorDlg, CDialogEx)  //��һƬ�����еĴ�����
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_EN_CHANGE(IDC_CINSTR_EDIT, &CCalculatorDlg::OnEnChangeSummandEdit)
	ON_BN_CLICKED(IDC_calculation, &CCalculatorDlg::OnBnClickedcalculation)
	ON_BN_CLICKED(IDC_add, &CCalculatorDlg::OnBnClickedadd)
	ON_BN_CLICKED(IDC_left_bracket, &CCalculatorDlg::OnBnClickedleftbracket)
	ON_BN_CLICKED(IDC_num1, &CCalculatorDlg::OnBnClickednum1)
	ON_BN_CLICKED(IDC_num2, &CCalculatorDlg::OnBnClickednum2)
	ON_BN_CLICKED(IDC_num3, &CCalculatorDlg::OnBnClickednum3)
	ON_BN_CLICKED(IDC_num4, &CCalculatorDlg::OnBnClickednum4)
	ON_BN_CLICKED(IDC_num5, &CCalculatorDlg::OnBnClickednum5)
	ON_BN_CLICKED(IDC_num6, &CCalculatorDlg::OnBnClickednum6)
	ON_BN_CLICKED(IDC_num7, &CCalculatorDlg::OnBnClickednum7)
	ON_BN_CLICKED(IDC_num8, &CCalculatorDlg::OnBnClickednum8)
	ON_BN_CLICKED(IDC_num9, &CCalculatorDlg::OnBnClickednum9)
	ON_BN_CLICKED(IDC_right_bracket, &CCalculatorDlg::OnBnClickedrightbracket)
	ON_BN_CLICKED(IDC_minus, &CCalculatorDlg::OnBnClickedminus)
	ON_BN_CLICKED(IDC_multiply, &CCalculatorDlg::OnBnClickedmultiply)
	ON_BN_CLICKED(IDC_division, &CCalculatorDlg::OnBnClickeddivision)
	ON_BN_CLICKED(IDC_deleteone, &CCalculatorDlg::OnBnClickeddeleteone)
	ON_BN_CLICKED(IDC_deleteall, &CCalculatorDlg::OnBnClickeddeleteall)
	ON_BN_CLICKED(IDCANCEL, &CCalculatorDlg::OnBnClickedCancel)
	ON_EN_CHANGE(IDC_EDIT3, &CCalculatorDlg::OnEnChangeEdit3)
	ON_BN_CLICKED(IDC_zero, &CCalculatorDlg::OnBnClickedzero)
	ON_BN_CLICKED(IDC_decimal, &CCalculatorDlg::OnBnClickeddecimal)
	ON_BN_CLICKED(IDC_file, &CCalculatorDlg::OnBnClickedfile)
END_MESSAGE_MAP()


// CCalculatorDlg ��Ϣ�������

BOOL CCalculatorDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CCalculatorDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CCalculatorDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
		/*
		CRect rc;  
        GetWindowRect(&rc);  
        CImage mImage;  
        if(mImage.Load(_T("1.jpg")) == S_OK)  
        {  
            //������ͼƬ��������ʹ��ڴ�Сһ��  
            mImage.Draw(GetDC()->GetSafeHdc(), CRect(0,0,rc.Width(),rc.Height()));  
        }  
		*/
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CCalculatorDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CCalculatorDlg::OnEnChangeSummandEdit()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}

/*
void CCalculatorDlg::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

}
*/

void CCalculatorDlg::OnBnClickedcalculation()   //�Ⱥ�
{
	// TODO: add m_cinstr with '='
	//�ȺŴ���
	UpdateData(TRUE);
	m_cinstr += '=';
	UpdateData(FALSE);

	Scanner scanner;
	Printner printf;    //����Printf����
	Calculation calculation;
	 double results;
	USES_CONVERSION;
	string input(W2A(m_cinstr));
	queue<string>que;
	que =scanner.Scan_m_cinstr(input);
	if (que.front() == "WRONG EXPERSSION")  //�޸ģ����λ��������Χ���д�������
	{
		//printf.ShowError();
		m_test=("WRONG EXPERSSION");
		UpdateData(FALSE);
	}
	else
	{
		results = calculation.CalculateResult(que);
		//printf.PrintfResult(results);
		//m_test =experssion.top().c_str();
		m_test.Format(_T("%f"), results);
		
		UpdateData(FALSE);
	}

}


void CCalculatorDlg::OnBnClickedadd()
{
	// TODO: add m_cinstr with '+'
	//��
	UpdateData();
	m_cinstr += '+';
	UpdateData(FALSE);
}

void CCalculatorDlg::OnBnClickedminus()  //����
{
	// TODO: add m_cinstr with '-'
	UpdateData();
	m_cinstr += '-';
	UpdateData(FALSE);
}


void CCalculatorDlg::OnBnClickedmultiply()  //�˺�
{
	// TODO: add m_cinstr with '*'
	UpdateData();
	m_cinstr += '*';
	UpdateData(FALSE);
}


void CCalculatorDlg::OnBnClickeddivision()  //����
{
	// TODO: add m_cinstr with '/'
	UpdateData();
	m_cinstr += '/';
	UpdateData(FALSE);
}


void CCalculatorDlg::OnBnClickedleftbracket() //������
{
	// TODO: add m_cinstr with '('
	UpdateData();
	m_cinstr += '(';
	UpdateData(FALSE);
}

void CCalculatorDlg::OnBnClickedrightbracket()  //������
{
	// TODO:add m_cinstr with ')'
	UpdateData();
	m_cinstr += ')';
	UpdateData(FALSE);
}


void CCalculatorDlg::OnBnClickednum1()  //���ּ���1��
{
	// TODO: add m_cinstr with '1'
	UpdateData();
	m_cinstr += '1';
	UpdateData(FALSE);
}


void CCalculatorDlg::OnBnClickednum2()  //���ּ���2��
{
	// TODO: add m_cinstr with '2'
	UpdateData();
	m_cinstr += '2';
	UpdateData(FALSE);
}


void CCalculatorDlg::OnBnClickednum3()  //���ּ���3��
{
	// TODO: add m_cinstr with '3'
	UpdateData();
	m_cinstr += '3';
	UpdateData(FALSE);
}


void CCalculatorDlg::OnBnClickednum4()  //���ּ���4��
{
   
	// TODO: add m_cinstr with '4'
	UpdateData();
	m_cinstr += '4';
	UpdateData(FALSE);
}


void CCalculatorDlg::OnBnClickednum5()  //���ּ���5��
{
	// TODO: add m_cinstr with '5'
	UpdateData();
	m_cinstr += '5';
	UpdateData(FALSE);
}


void CCalculatorDlg::OnBnClickednum6()  //���ּ���6��
{
	// TODO: add m_cinstr with '6'
	UpdateData();
	m_cinstr += '6';
	UpdateData(FALSE);
}


void CCalculatorDlg::OnBnClickednum7()  //���ּ���7��
{
	// TODO: add m_cinstr with '7'
	UpdateData();
	m_cinstr += '7';
	UpdateData(FALSE);
}


void CCalculatorDlg::OnBnClickednum8()  //���ּ���8��
{
	// TODO: add m_cinstr with '8'
	UpdateData();
	m_cinstr += '8';
	UpdateData(FALSE);
}


void CCalculatorDlg::OnBnClickednum9()  //���ּ���9��
{
	// TODO: add m_cinstr with '9'
	UpdateData();
	m_cinstr += '9';
	UpdateData(FALSE);
}

void CCalculatorDlg::OnBnClickedzero()  //���ּ���0��
{
	// TODO: add m_cinstr with '0'
	UpdateData(TRUE);
	m_cinstr += '0';
	UpdateData(FALSE);
}


void CCalculatorDlg::OnBnClickeddecimal()  //С���㡰.��
{
	// TODO: add m_cinstr with '.'
	UpdateData(TRUE);
	m_cinstr += '.';
	UpdateData(FALSE);
}


void CCalculatorDlg::OnBnClickeddeleteone()  //esc��
{
	// TODO: delete m_cinstr and m_test

	m_cinstr.Empty();
	m_test.Empty();
	UpdateData(FALSE);
}


void CCalculatorDlg::OnBnClickeddeleteall()   //backspace��λ
{
	// TODO: delete m_cinstr with with one word
	m_cinstr = m_cinstr.Left(m_cinstr.GetLength() - 1); //��ȡ��ߵ���ֵ�����䳤�ȼ�1 
	

	UpdateData(false);
}



void CCalculatorDlg::OnBnClickedfile()  //file��
{
	// TODO: open a new way 

	Cfile file;
	file.DoModal();
}


void CCalculatorDlg::OnBnClickedCancel()
{
	// TODO: cancel
	CDialogEx::OnCancel();
}


void CCalculatorDlg::OnEnChangeOutstrEdit()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void CCalculatorDlg::OnEnChangeEdit3()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}

BOOL CCalculatorDlg::PreTranslateMessage(MSG* pMsg)
{
	//���Ƿ�Ϊ������Ϣ
	if (WM_KEYFIRST == pMsg->message )
	{

		switch (pMsg->wParam)
		{
			//�ж��Ƿ��¼���esc��
		case (VK_ESCAPE):	
			m_cinstr.Empty();
			m_test.Empty();
			UpdateData(FALSE);
			return TRUE;
			break;
			
			//�ж��Ƿ��¼���backspace��
		case  (VK_BACK):	
			OnBnClickeddeleteall();
			return TRUE;
			break;

		case (VK_RETURN):
			OnBnClickedcalculation(); 
			return TRUE;
			break;

		case (VK_NUMPAD1):		
			OnBnClickednum1();
			break;

		case (VK_NUMPAD2):			
			OnBnClickednum2();
			break;
		case (VK_NUMPAD3) :
			OnBnClickednum3();
			break;
		case (VK_NUMPAD4) :
			OnBnClickednum4();
			break;
		case (VK_NUMPAD5) :
			OnBnClickednum5();
			break;
		case (VK_NUMPAD6) :
			OnBnClickednum6();
			break;
		case (VK_NUMPAD7) :
			OnBnClickednum7();
			break;
		case (VK_NUMPAD8) :
			OnBnClickednum8();
			break;
		case (VK_NUMPAD9) :
			OnBnClickednum9();
			break;
		case (VK_NUMPAD0) :
			OnBnClickedzero();
			break;
		case(VK_MULTIPLY):
				OnBnClickedmultiply();
				break;
		case VK_ADD:
					OnBnClickedadd();
					break;
		case VK_SUBTRACT:
			OnBnClickedminus();
			break;
		case VK_DIVIDE:
			OnBnClickeddivision();
			break;
		case VK_DECIMAL:
			OnBnClickeddecimal();
			break;

		 case '9':
			if (GetAsyncKeyState(VK_SHIFT))
			{
				// ��shift+���ּ�9
				
				OnBnClickedleftbracket();
			}
			break;

		 case '0':
			 if (GetAsyncKeyState(VK_SHIFT))
			 {
				 // ��shift+���ּ�9

				 OnBnClickedrightbracket();
			 }
			 break;
		}
					
	}
	return CDialog::PreTranslateMessage(pMsg);
}




