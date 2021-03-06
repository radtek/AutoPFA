#pragma once
#include "TabSheet.h"
#include "PageNotShowOutAtt.h"
#include "afxcmn.h"
#include "afxwin.h"

// PagePipeOutControl 对话框

class PagePipeOutControl : public CDialog
{
	DECLARE_DYNAMIC(PagePipeOutControl)

public:
	PagePipeOutControl(PFAOutModel &outModel, CWnd* pParent = NULL);   // 标准构造函数
	virtual ~PagePipeOutControl();


	void UpData(); //保存
	BOOL Read(CStdioFile& file);//从文件读取信息
	BOOL Save(CStdioFile& file);//保存到文件

// 对话框数据
	enum { IDD = IDD_PAGE_PIPEOUTCONTROL };
	CTabSheet	m_tab;
	//StmOutMgr& m_OutMgr;

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual BOOL OnInitDialog();
	void InitData(CString InData,CString str[50]);

	DECLARE_MESSAGE_MAP()
	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
private:
	PageNotShowOutAtt m_pPageAtt;
	PFAOutModel& m_outModel;
	CString m_strPipeOrder;
	CString m_strPipeUnit;

	afx_msg void OnBnClickedAdd();
	afx_msg void OnBnClickedDelete();
	afx_msg void OnBtnDeleteAll();

	void LoadAllAtt( OutMgr& outMgr );
	void LoadShowAtt( OutMgr& outMgr );
	BOOL Find( CString strKey );

	CListCtrl m_lstArrShow;
	afx_msg void OnCbnSelchangeComboUnit();
	afx_msg void OnLvnItemchangedListShowout(NMHDR *pNMHDR, LRESULT *pResult);
	CComboBox m_comboUnit;
};
