/**
 * @file ChessView.cpp
 * @author Alex Bocchi
 */

#include "pch.h"
#include "ids.h"
#include "ChessView.h"
#include <wx/dcbuffer.h>

/**
 * Initialize the chess view class
 * @param parent The parent window foe this class
*/
void ChessView::Initialize(wxFrame* parent)
{
    Create(parent, wxID_ANY);
    SetBackgroundStyle(wxBG_STYLE_PAINT);

    Bind(wxEVT_PAINT, &ChessView::OnPaint, this);
    parent->Bind(wxEVT_COMMAND_MENU_SELECTED, &ChessView::StartGame, this, IDM_STARTGAME);
    Bind(wxEVT_LEFT_DOWN, &ChessView::OnLeftDown, this);
    Bind(wxEVT_LEFT_UP, &ChessView::OnLeftUp, this);
    Bind(wxEVT_MOTION, &ChessView::OnMouseMove, this);
    Bind(wxEVT_LEFT_DCLICK, &ChessView::OnDoubleClick, this);
}

/**
 * Paint event, draws the window.
 * @param event Paint event object
 */
void ChessView::OnPaint(wxPaintEvent& event)
{
    wxAutoBufferedPaintDC dc(this);

    wxBrush background(*wxWHITE);
    dc.SetBackground(background);
    dc.Clear();

    mChessGame.OnDraw(&dc);
}

/**
* Handle the left double click event
 * @param event
*/
void ChessView::OnDoubleClick(wxMouseEvent& event)
{


}
/**
* Handle the mouse move event
* @param event
*/
void ChessView::OnMouseMove(wxMouseEvent &event)
{

}

/**
* Handle the left mouse button down event
* @param event
*/
void ChessView::OnLeftUp(wxMouseEvent &event)
{

}

/**
 * Handle the left mouse button down event
 * @param event
 */
void ChessView::OnLeftDown(wxMouseEvent &event)
{
    if (mChessGame.GetStart())
    {
        wxPoint Click = mChessGame.GetChessBoard()->HitTestSpaces(event.GetX(), event.GetY());
        if (Click.x>0 && Click.y>0) {
            if (!mGrabbed) {
                mGrabbedPiece = mChessGame.GetChessBoard()->HitTestPieces(event.GetX(), event.GetY());
                mGrabbed = true;
            }
            else {
                if (mGrabbedPiece->ValidMove(Click.x, Click.y)) {
                    mGrabbedPiece->SetPos(wxPoint(Click.x, Click.y));
                }
                mGrabbed = false;
                Refresh();
            }
        }
    }
}

/**
 * Start the game of chess Handler
 * @param event
 */
void ChessView::StartGame(wxCommandEvent& event)
{
    mChessGame.SetGameBoard();
    mChessGame.SetStart(true);
    Refresh();
}
