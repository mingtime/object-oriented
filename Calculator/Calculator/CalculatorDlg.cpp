
// CalculatorDlg.cpp : 实现文件
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


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
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


// CCalculatorDlg 对话框



CCalculatorDlg::CCalculatorDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_CALCULATOR_DIALOG, pParent)
	, m_cinstr(_T(""))  //输入的字符串在这儿~
	,m_test(_T(""))   //这是输出结果的字符串~~
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCalculatorDlg::DoDataExchange(CDataExchange* pDX)
{
	// 处理MFC默认的数据交换   

	CDialogEx::DoDataExchange(pDX);
	// 处理控件IDC_SUMMAND_EDIT和变量m_editSummand之间的数据交换   
	DDX_Text(pDX, IDC_CINSTR_EDIT, m_cinstr);
	DDX_Text(pDX, IDC_EDIT3, m_test);
	
}


//所有的操作函数都在下面
BEGIN_MESSAGE_MAP(CCalculatorDlg, CDialogEx)  //这一片是所有的处理函数
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


// CCalculatorDlg 消息处理程序

BOOL CCalculatorDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
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

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CCalculatorDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
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
            //这里让图片绘制区域和窗口大小一致  
            mImage.Draw(GetDC()->GetSafeHdc(), CRect(0,0,rc.Width(),rc.Height()));  
        }  
		*/
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CCalculatorDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CCalculatorDlg::OnEnChangeSummandEdit()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}

/*
void CCalculatorDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码

}
*/

void CCalculatorDlg::OnBnClickedcalculation()   //等号
{
	// TODO: add m_cinstr with '='
	//等号处理
	UpdateData(TRUE);
	m_cinstr += '=';
	UpdateData(FALSE);

	Scanner scanner;
	Printner printf;    //创建Printf对象
	Calculation calculation;
	 double results;
	USES_CONVERSION;
	string input(W2A(m_cinstr));
	queue<string>que;
	que =scanner.Scan_m_cinstr(input);
	if (que.front() == "WRONG EXPERSSION")  //修改：针对位数超出范围进行错误提醒
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
	//加
	UpdateData();
	m_cinstr += '+';
	UpdateData(FALSE);
}

void CCalculatorDlg::OnBnClickedminus()  //减号
{
	// TODO: add m_cinstr with '-'
	UpdateData();
	m_cinstr += '-';
	UpdateData(FALSE);
}


void CCalculatorDlg::OnBnClickedmultiply()  //乘号
{
	// TODO: add m_cinstr with '*'
	UpdateData();
	m_cinstr += '*';
	UpdateData(FALSE);
}


void CCalculatorDlg::OnBnClickeddivision()  //除号
{
	// TODO: add m_cinstr with '/'
	UpdateData();
	m_cinstr += '/';
	UpdateData(FALSE);
}


void CCalculatorDlg::OnBnClickedleftbracket() //左括号
{
	// TODO: add m_cinstr with '('
	UpdateData();
	m_cinstr += '(';
	UpdateData(FALSE);
}

void CCalculatorDlg::OnBnClickedrightbracket()  //右括号
{
	// TODO:add m_cinstr with ')'
	UpdateData();
	m_cinstr += ')';
	UpdateData(FALSE);
}


void CCalculatorDlg::OnBnClickednum1()  //数字键“1”
{
	// TODO: add m_cinstr with '1'
	UpdateData();
	m_cinstr += '1';
	UpdateData(FALSE);
}


void CCalculatorDlg::OnBnClickednum2()  //数字键“2”
{
	// TODO: add m_cinstr with '2'
	UpdateData();
	m_cinstr += '2';
	UpdateData(FALSE);
}


void CCalculatorDlg::OnBnClickednum3()  //数字键“3”
{
	// TODO: add m_cinstr with '3'
	UpdateData();
	m_cinstr += '3';
	UpdateData(FALSE);
}


void CCalculatorDlg::OnBnClickednum4()  //数字键“4”
{
   
	// TODO: add m_cinstr with '4'
	UpdateData();
	m_cinstr += '4';
	UpdateData(FALSE);
}


void CCalculatorDlg::OnBnClickednum5()  //数字键“5”
{
	// TODO: add m_cinstr with '5'
	UpdateData();
	m_cinstr += '5';
	UpdateData(FALSE);
}


void CCalculatorDlg::OnBnClickednum6()  //数字键“6”
{
	// TODO: add m_cinstr with '6'
	UpdateData();
	m_cinstr += '6';
	UpdateData(FALSE);
}


void CCalculatorDlg::OnBnClickednum7()  //数字键“7”
{
	// TODO: add m_cinstr with '7'
	UpdateData();
	m_cinstr += '7';
	UpdateData(FALSE);
}


void CCalculatorDlg::OnBnClickednum8()  //数字键“8”
{
	// TODO: add m_cinstr with '8'
	UpdateData();
	m_cinstr += '8';
	UpdateData(FALSE);
}


void CCalculatorDlg::OnBnClickednum9()  //数字键“9”
{
	// TODO: add m_cinstr with '9'
	UpdateData();
	m_cinstr += '9';
	UpdateData(FALSE);
}

void CCalculatorDlg::OnBnClickedzero()  //数字键“0”
{
	// TODO: add m_cinstr with '0'
	UpdateData(TRUE);
	m_cinstr += '0';
	UpdateData(FALSE);
}


void CCalculatorDlg::OnBnClickeddecimal()  //小数点“.”
{
	// TODO: add m_cinstr with '.'
	UpdateData(TRUE);
	m_cinstr += '.';
	UpdateData(FALSE);
}


void CCalculatorDlg::OnBnClickeddeleteone()  //esc键
{
	// TODO: delete m_cinstr and m_test

	m_cinstr.Empty();
	m_test.Empty();
	UpdateData(FALSE);
}


void CCalculatorDlg::OnBnClickeddeleteall()   //backspace键位
{
	// TODO: delete m_cinstr with with one word
	m_cinstr = m_cinstr.Left(m_cinstr.GetLength() - 1); //提取左边的数值并将其长度减1 
	

	UpdateData(false);
}



void CCalculatorDlg::OnBnClickedfile()  //file键
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
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void CCalculatorDlg::OnEnChangeEdit3()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}

BOOL CCalculatorDlg::PreTranslateMessage(MSG* pMsg)
{
	//判是否为键盘消息
	if (WM_KEYFIRST == pMsg->message )
	{

		switch (pMsg->wParam)
		{
			//判断是否按下键盘esc键
		case (VK_ESCAPE):	
			m_cinstr.Empty();
			m_test.Empty();
			UpdateData(FALSE);
			return TRUE;
			break;
			
			//判断是否按下键盘backspace键
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
				// 右shift+数字键9
				
				OnBnClickedleftbracket();
			}
			break;

		 case '0':
			 if (GetAsyncKeyState(VK_SHIFT))
			 {
				 // 左shift+数字键9

				 OnBnClickedrightbracket();
			 }
			 break;
		}
					
	}
	return CDialog::PreTranslateMessage(pMsg);
}




