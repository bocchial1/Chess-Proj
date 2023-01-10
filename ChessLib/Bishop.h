/**
 * @file Bishop.h
 * @author Alex Bocchi
 *
 * Base class for a bishop
 */

#ifndef CHESS_BISHOP_H
#define CHESS_BISHOP_H
#include "ChessPiece.h"
/**
 * Base class for a Bishop
 */
class Bishop : public ChessPiece {
private:
    /// The underlying fish image
    std::unique_ptr<wxImage> mBishopImage;

    /// The bitmap we can display for this fish
    std::unique_ptr<wxBitmap> mBishopBitmap;

public:
    /// constructor
    Bishop(wxPoint pos, std::wstring color);
    /// Destructor
    ~Bishop() {};

    void Draw(wxDC *dc) override;
    bool ValidMove(int x, int y) override;


};

#endif //CHESS_BISHOP_H
