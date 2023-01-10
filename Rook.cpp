/**
 * @file Rook.cpp
 * @author Alex Bocchi
 */


#include "pch.h"
#include "Rook.h"
using namespace std;
const wstring WhiteRookImageName = L"images/wht_rook.png";
const wstring BlackRookImageName = L"images/blk_rook.png";

/**
 * Constructor
 * @param pos
 */
Rook::Rook(wxPoint pos, wstring color) : ChessPiece(pos)
{
    if (color == L"white") {
        mRookImage = make_unique<wxImage>(WhiteRookImageName, wxBITMAP_TYPE_ANY);
        mRookBitmap = make_unique<wxBitmap>(*mRookImage);
    }
    if (color == L"black") {
        mRookImage = make_unique<wxImage>(BlackRookImageName, wxBITMAP_TYPE_ANY);
        mRookBitmap = make_unique<wxBitmap>(*mRookImage);
    }
    SetColor(color);
}

/**
 * Draw Pawn
 * @param dc
 */
void Rook::Draw(wxDC *dc)
{
    double wid = mRookBitmap->GetWidth();
    double hit = mRookBitmap->GetHeight();
    dc->DrawBitmap(*mRookBitmap,
            int(GetPos().x + 37 - wid / 2),
            int(GetPos().y + 37 - hit / 2));
}

/**
 * Find valid move for a Rook
 * @param x
 * @param y
 * @return
 */
bool Rook::ValidMove(int x, int y)
{
    wxPoint pos = GetPos();
    for (int i = 0; i < 8; i++)
    {
        if (x == (pos.x + (75*i)) || x == (pos.x - (75*i)))
        {
            if (y == pos.y)
            {
                return true;
            }
        }
        if (y == (pos.y + (75*i)) || y == (pos.y - (75*i)) ) {
            if (x == pos.x)
            {
                return true;
            }
        }
    }

    return false;
}