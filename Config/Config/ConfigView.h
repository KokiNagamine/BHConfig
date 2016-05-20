
// ConfigView.h : CConfigView クラスのインターフェイス
//

#pragma once


class CConfigView : public CView
{
protected: // シリアル化からのみ作成します。
	CConfigView();
	DECLARE_DYNCREATE(CConfigView)

// 属性
public:
	CConfigDoc* GetDocument() const;

// 操作
public:

// オーバーライド
public:
	virtual void OnDraw(CDC* pDC);  // このビューを描画するためにオーバーライドされます。
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 実装
public:
	virtual ~CConfigView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成された、メッセージ割り当て関数
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // ConfigView.cpp のデバッグ バージョン
inline CConfigDoc* CConfigView::GetDocument() const
   { return reinterpret_cast<CConfigDoc*>(m_pDocument); }
#endif

