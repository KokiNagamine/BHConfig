
// ConfigView.cpp : CConfigView �N���X�̎���
//

#include "stdafx.h"
// SHARED_HANDLERS �́A�v���r���[�A�k���ŁA����ь����t�B���^�[ �n���h���[���������Ă��� ATL �v���W�F�N�g�Œ�`�ł��A
// ���̃v���W�F�N�g�Ƃ̃h�L�������g �R�[�h�̋��L���\�ɂ��܂��B
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

// CConfigView �R���X�g���N�V����/�f�X�g���N�V����

CConfigView::CConfigView()
{
	// TODO: �\�z�R�[�h�������ɒǉ����܂��B

}

CConfigView::~CConfigView()
{
}

BOOL CConfigView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: ���̈ʒu�� CREATESTRUCT cs ���C������ Window �N���X�܂��̓X�^�C����
	//  �C�����Ă��������B

	return CView::PreCreateWindow(cs);
}

// CConfigView �`��

void CConfigView::OnDraw(CDC* /*pDC*/)
{
	CConfigDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: ���̏ꏊ�Ƀl�C�e�B�u �f�[�^�p�̕`��R�[�h��ǉ����܂��B
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


// CConfigView �f�f

#ifdef _DEBUG
void CConfigView::AssertValid() const
{
	CView::AssertValid();
}

void CConfigView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CConfigDoc* CConfigView::GetDocument() const // �f�o�b�O�ȊO�̃o�[�W�����̓C�����C���ł��B
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CConfigDoc)));
	return (CConfigDoc*)m_pDocument;
}
#endif //_DEBUG


// CConfigView ���b�Z�[�W �n���h���[
