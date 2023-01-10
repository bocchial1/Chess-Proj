/**
 * @file Pawn.cpp
 * @author Alex Bocchi
 */
#include "pch.h"
#include "Pawn.h"
using namespace std;
const wstring WhitePawnImageName = L"images/white_pawn.png";
const wstring BlackPawnImageName = L"images/blk_pawn.png";
const int offset = 37;

/**
 * Constructor
 * @param pos
 */
Pawn::Pawn(wxPoint pos, wstring color) : ChessPiece(pos)
{
    if (color == L"white") {
        mPawnImage = make_unique<wxImage>(WhitePawnImageName, wxBITMAP_TYPE_ANY);
        mPawnBitmap = make_unique<wxBitmap>(*mPawnImage);
    }
    if (color == L"black") {
        mPawnImage = make_unique<wxImage>(BlackPawnImageName, wxBITMAP_TYPE_ANY);
        mPawnBitmap = make_unique<wxBitmap>(*mPawnImage);
    }
    SetColor(color);
}

/**
 * Draw Pawn
 * @param dc
 */
void Pawn::Draw(wxDC *dc)
{
    double wid = mPawnBitmap->GetWidth();
    double hit = mPawnBitmap->GetHeight();
    dc->DrawBitmap(*mPawnBitmap,
            int((GetPos().x + 37) - wid / 2),
            int((GetPos().y + 37) - hit / 2));
}

/**
 * Test for a valid move
 * @param x
 * @param y
 * @return return bool for valid
 */
bool Pawn::ValidMove(int x, int y)
{
    wxPoint pos = GetPos();
    if (GetColor() == L"black") {
        if (x==pos.x) {
            if (mFirstMove) {
                if (y>=(pos.y-150)) {
                    mFirstMove = false;
                    AddMove(wxPoint(x, y));
                    return true;
                }
            }
            else {
                if (y==(pos.y-75)) {
                    AddMove(wxPoint(x, y));
                    return true;
                }
            }
        }
    }
    if (GetColor() == L"white") {
        if (x==pos.x) {
            if (mFirstMove) {
                if (y <= (pos.y+150)) {
                    mFirstMove = false;
                    return true;
                }
            }
            else {
                if (y==(pos.y+75)) {
                    return true;
                }
            }
        }
    }
    return false;
}
