/**
 * @file ChessPiece.h
 * @author Alex Bocchi
 *
 * Chess Pieces - Each piece will be a generalization of this piece
 */

#ifndef CHESS_CHESSPIECE_H
#define CHESS_CHESSPIECE_H
/**
 * Chess Pieces - Each piece will be a generalization of this piece
 */
class ChessPiece {
private:
    /// Piece Name
    std::wstring mName;
    /// Position
    wxPoint mPos;
    /// Piece Color
    std::wstring mColor;
    /// Possible Moves
    std::vector<wxPoint> mMoves;

public:
    /// Constructor
    ChessPiece(wxPoint pos);
    /// Destructor
    ~ChessPiece() {};

    /**
     * Set Position of the chess piece
     * @param pos
     */
    void SetPos(wxPoint pos);

    /**
     * Get Pos of the Chess Piece
     * @return
     */
    wxPoint GetPos() {return mPos;}

    virtual void Draw(wxDC *dc) {};
    bool HitTest(int x, int y);
    virtual bool ValidMove(int x, int y) {return false;}
    /**
     * Set the color of the chess piece
     * @param color
     */
    void SetColor(std::wstring color) {mColor = color;}
    /**
     * Get the color of the chess piece
     * @return mColor
     */
    std::wstring GetColor() {return mColor;}
    /**
     * Add a possible move for the piece
     * @param move
     */
    void AddMove(wxPoint move) {mMoves.push_back(move);}


};

#endif //CHESS_CHESSPIECE_H
