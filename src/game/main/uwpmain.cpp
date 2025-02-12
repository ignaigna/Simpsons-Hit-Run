//=============================================================================
// Copyright (C) 2025 Radical Entertainment Ltd.  All rights reserved.
//
// File:        uwpmain.cpp
//
// Description: This file contains the main enrty point to the game.
//
// History:     + Stolen and cleaned up from Penthouse -- Darwin Chau
//
//=============================================================================

//========================================
// System Includes
//========================================
// Standard Library
#include <string.h>
// Foundation Tech
#include <raddebug.hpp>
#include <radobject.hpp>

//========================================
// Project Includes
//========================================
#include <main/game.h>
#include <main/uwpplatform.h>
#include <main/singletons.h>
// TODO(3ur): IMPLEMENT ME
//#include <main/commandlineoptions.h>
#include <memory/memoryutilities.h>
#include <memory/srrmemory.h>

//========================================
// Forward Declarations
//========================================

// TODO(3ur): IMPLEMENT ME
//static void ProcessCommandLineArguments();


//=============================================================================
// Function:    main
//=============================================================================
//
// Description: Main entry point.
// 
// Parameters:  None.
//
// Returns:     None.
//
//=============================================================================
void main()
{
    //
    // Pick out and store command line settings.
    //
    CommandLineOptions::InitDefaults();
    ProcessCommandLineArguments();

    //
    // Have to get FTech setup first so that we can use all the memory services.
    //
    UwpPlatform::InitializeFoundation();
    
    srand (Game::GetRandomSeed ());


    // Now disable the default heap
    //
#ifndef RAD_RELEASE
    tName::SetAllocator (GMA_DEBUG);

    //g_HeapActivityTracker.EnableHeapAllocs (GMA_DEFAULT, false);
    //g_HeapActivityTracker.EnableHeapFrees (GMA_DEFAULT, false);
#endif

    HeapMgr()->PushHeap (GMA_PERSISTENT);

    //
    // Instantiate all the singletons before doing anything else.
    //
    CreateSingletons();

    //
    // Construct the platform object.
    //
    UwpPlatform* pPlatform = UwpPlatform::CreateInstance();
    rAssert( pPlatform != NULL );
    
    //
    // Create the game object.
    //
    Game* pGame = Game::CreateInstance( pPlatform );
    rAssert( pGame != NULL );
    
     
    //
    // Initialize the game.
    //
    pGame->Initialize();

    HeapMgr()->PopHeap (GMA_PERSISTENT);

    //
    // Run it!  Control will not return from here until the game is stopped.
    //
    pGame->Run();
    
    //
    // Terminate the game (this frees all resources allocated by the game).
    //
    pGame->Terminate();
    
    //
    // Destroy the game object.
    //
    Game::DestroyInstance();
    
    //
    // Destroy the game and platform (do it in this order in case the game's 
    // destructor references the platform.
    //
    UwpPlatform::DestroyInstance();
    
    //
    // Show some debug output
    //
#ifdef RAD_DEBUG
    radObject::DumpObjects();
#endif;

    //
    // Dump all the singletons.
    //
    DestroySingletons();
}


//=============================================================================
// Function:    ProcessCommandLineArguments
//=============================================================================
//
// Description: Pick out the command line options and store them.
// 
// Parameters:  None.
//
// Returns:     None.
//
//=============================================================================
void ProcessCommandLineArguments()
{
    // TODO(3ur): IMPLEMENT ME
}