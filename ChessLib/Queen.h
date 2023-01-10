/**
 * @file Queen.h
 * @author Alex Bocchi
 *
 * Base class for the Queen
 */

#ifndef CHESS_QUEEN_H
#define CHESS_QUEEN_H
#include "ChessPiece.h"
/**
 * Base class for the Queen
 */
class Queen : public ChessPiece {
private:
    /// The underlying fish image
    std::unique_ptr<wxImage> mQueenImage;

    /// The bitmap we can display for this fish
    std::unique_ptr<wxBitmap> mQueenBitmap;

public:
    /// constructor
    Queen(wxPoint pos, std::wstring color);
    /// Destructor
    ~Queen() {};

    void Draw(wxDC *dc) override;
    bool ValidMove(int x, int y) override ;


};

#endif //CHESS_QUEEN_H
