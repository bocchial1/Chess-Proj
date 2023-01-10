/**
 * @file Mainframe.h
 * @author Alex Bocchi
 *
 *
 * Top-level frame of the application
 */

#ifndef CHESS_PROJECT_MAINFRAME_H
#define CHESS_PROJECT_MAINFRAME_H

/**
 * Top-level (main) frame of the application
 */
class Mainframe : public wxFrame {
private:
    void OnExit(wxCommandEvent& event);
    void AboutApp(wxCommandEvent& event);

public:
    void Initialize();

};

#endif //CHESS_PROJECT_MAINFRAME_H
