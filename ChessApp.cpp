/**
 * @file ChessApp.cpp
 * @author Alex Bocchi
 */

#include "pch.h"
#include "ChessApp.h"
#include <Mainframe.h>

bool ChessApp::OnInit()
{
    if (!wxApp::OnInit())
        return false;

    // Add image type handlers
    wxInitAllImageHandlers();

    auto frame = new Mainframe();
    frame->Initialize();
    frame->Show(true);

    return true;
}