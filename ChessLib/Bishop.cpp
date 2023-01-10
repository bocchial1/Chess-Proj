/**
 * @file Bishop.cpp
 * @author Alex Bocchi
 */
#include "pch.h"
#include "Bishop.h"

using namespace std;
const wstring WhiteBishopImageName = L"images/wht_bishop.png";
const wstring BlackBishopImageName = L"images/blk_bishop.png";

/**
 * Constructor
 * @param pos
 */
Bishop::Bishop(wxPoint pos, wstring color) : ChessPiece(pos)
{
    if (color == L"white") {
        mBishopImage = make_unique<wxImage>(WhiteBishopImageName, wxBITMAP_TYPE_ANY);
        mBishopBitmap = make_unique<wxBitmap>(*mBishopImage);
    }
    if (color == L"black") {
        mBishopImage = make_unique<wxImage>(BlackBishopImageName, wxBITMAP_TYPE_ANY);
        mBishopBitmap = make_unique<wxBitmap>(*mBishopImage);
    }
    SetColor(color);
}

/**
 * Draw Pawn
 * @param dc
 */
void Bishop::Draw(wxDC *dc)
{
    double wid = mBishopBitmap->GetWidth();
    double hit = mBishopBitmap->GetHeight();
    dc->DrawBitmap(*mBishopBitmap,
            int(GetPos().x + 37 - wid / 2),
            int(GetPos().y + 37 - hit / 2));
}

/**
 * Find valid move for Bishop
 * @param x
 * @param y
 * @return
 */
bool Bishop::ValidMove(int x, int y)
{
    wxPoint pos = GetPos();
    for (int i = 0;  i < 8; i++)
    {
        if (x == (pos.x + (75*i)) || x == (pos.x - (75*i)) ) {
            if (y == (pos.y + (75*i)) || y == (pos.y - (75*i))) {
                return true;
            }
        }
    }
    return false;
}

