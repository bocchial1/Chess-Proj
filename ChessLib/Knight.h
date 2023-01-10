/**
 * @file Knight.h
 * @author Alex Bocchi
 *
 * Base class for a Knight
 */

#ifndef CHESS_KNIGHT_H
#define CHESS_KNIGHT_H
#include "ChessPiece.h"
/**
 * Base class for a Knight
 */
class Knight : public ChessPiece {
private:
    /// The underlying fish image
    std::unique_ptr<wxImage> mKnightImage;

    /// The bitmap we can display for this fish
    std::unique_ptr<wxBitmap> mKnightBitmap;

public:
    /// constructor
    Knight(wxPoint pos, std::wstring color);
    /// Destructor
    ~Knight() {};

    void Draw(wxDC *dc) override;
    bool ValidMove(int x, int y) override;


};

#endif //CHESS_KNIGHT_H
