
// ConfigView.cpp : CConfigView クラスの実装
//

#include "stdafx.h"
// SHARED_HANDLERS は、プレビュー、縮小版、および検索フィルター ハンドラーを実装している ATL プロジェクトで定義でき、
// そのプロジェクトとのドキュメント コードの共有を可能にします。
#ifndef SHARED_HANDLERS
#include "Config.h"
#endif

#include "ConfigDoc.h"
#include "ConfigView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CConfigView

IMPLEMENT_DYNCREATE(CConfigView, CView)

BEGIN_MESSAGE_MAP(CConfigView, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CConfigView コンストラクション/デストラクション

CConfigView::CConfigView()
{
	// TODO: 構築コードをここに追加します。

}

CConfigView::~CConfigView()
{
}

BOOL CConfigView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: この位置で CREATESTRUCT cs を修正して Window クラスまたはスタイルを
	//  修正してください。

	return CView::PreCreateWindow(cs);
}

// CConfigView 描画

void CConfigView::OnDraw(CDC* /*pDC*/)
{
	CConfigDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: この場所にネイティブ データ用の描画コードを追加します。
}

void CConfigView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CConfigView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CConfigView 診断

#ifdef _DEBUG
void CConfigView::AssertValid() const
{
	CView::AssertValid();
}

void CConfigView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CConfigDoc* CConfigView::GetDocument() const // デバッグ以外のバージョンはインラインです。
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CConfigDoc)));
	return (CConfigDoc*)m_pDocument;
}
#endif //_DEBUG


// CConfigView メッセージ ハンドラー
