/**
 * @file ChessGame.cpp
 * @author Alex Bocchi
 */

#include "pch.h"
#include "ChessGame.h"
#include "Pawn.h"
#include "King.h"
#include "Queen.h"
#include "Knight.h"
#include "Bishop.h"
#include "Rook.h"

using namespace std;

/**
 * Draw Chess
 *
 * For right now the chess board will be drawn as
 * a background but I would like to move it to
 * a "Chessboard" class
 *
 * Find a way to store each "LABELED" square
*/
void ChessGame::OnDraw(wxDC *dc)
{
    /// Draw the chess board
    const int NumRows = 8;
    const int NumCols = 8;
    wxPoint start = wxPoint(100, 0);
    bool alt = true;
    // draw a rectangle
    dc->SetBrush(*wxWHITE_BRUSH);
    dc->SetPen(wxPen(wxColor(0, 0, 0), 0)); // 10-pixels-thick pink outline

    for (int r = 0; r<NumRows; r++)
    {
        start.y += 75;
        start.x = 100;

        for (int c = 0; c<NumCols; c++)
        {
            dc->DrawRectangle(start.x + (75*c), start.y, 75, 75);
            mChessBoard->AddSpace(wxPoint(start.x + (75*c), start.y));
            if (alt)
            {
                dc->SetBrush(*wxMEDIUM_GREY_BRUSH);
                alt = false;
            }
            else
            {
                dc->SetBrush(*wxWHITE_BRUSH);
                alt = true;
            }
        }
        if (alt)
        {
            dc->SetBrush(*wxMEDIUM_GREY_BRUSH);
            alt = false;
        }
        else
        {
            dc->SetBrush(*wxWHITE_BRUSH);
            alt = true;
        }
    }
    ///SetGameBoard();
    if (mStart){
        mChessBoard->DrawPieces(dc);
    }

}

/**
 * Constructor
 */
ChessGame::ChessGame()
{
    mChessBoard = std::make_shared<ChessBoard>();
}

/**
 * Set Pieces on board
 */
void ChessGame::SetGameBoard()
{
    /**
     * Pawns
     */
    for (int i = 0; i<8 ; i++)
    {
        auto whitePawn = std::make_shared<Pawn>(wxPoint(100 + (75 * i), 150), L"white");
        mChessBoard->AddPiece(whitePawn);
    }
    for (int i = 0; i<8 ; i++)
    {
        auto blackPawn = std::make_shared<Pawn>(wxPoint(100 + (75 * i), 525), L"black");
        mChessBoard->AddPiece(blackPawn);
    }
    /**
     * Kings
     */
    auto whiteKing = std::make_shared<King>(wxPoint(325, 75), L"white");
    mChessBoard->AddPiece(whiteKing);
    auto blackKing = std::make_shared<King>(wxPoint(325, 600), L"black");
    mChessBoard->AddPiece(blackKing);
    /**
     * Queens
     */
    auto whiteQueen = std::make_shared<Queen>(wxPoint(400, 75), L"white");
    mChessBoard->AddPiece(whiteQueen);
    auto blackQueen = std::make_shared<Queen>(wxPoint(400, 600), L"black");
    mChessBoard->AddPiece(blackQueen);
    /**
     * Knights
     */
    for (int i = 0; i < 2; i++)
    {
        auto whiteKnight = std::make_shared<Knight>(wxPoint(175 + (i * 375), 75), L"white");
        mChessBoard->AddPiece(whiteKnight);
        auto blackKnight = std::make_shared<Knight>(wxPoint(175 + (i * 375), 600), L"black");
        mChessBoard->AddPiece(blackKnight);
    }
    /**
     * Bishops
     */
    for (int i = 0; i < 2; i++)
    {
        auto whiteBishop = std::make_shared<Bishop>(wxPoint(250 + (i * 225), 75), L"white");
        mChessBoard->AddPiece(whiteBishop);
        auto blackBishop = std::make_shared<Bishop>(wxPoint(250 + (i * 225), 600), L"black");
        mChessBoard->AddPiece(blackBishop);
    }
    /**
     * Rooks
     */
    for (int i = 0; i < 2; i++)
    {
        auto whiteRook = std::make_shared<Rook>(wxPoint(100 + (i * 525), 75), L"white");
        mChessBoard->AddPiece(whiteRook);
        auto blackRook = std::make_shared<Rook>(wxPoint(100 + (i * 525), 600), L"black");
        mChessBoard->AddPiece(blackRook);
    }
}