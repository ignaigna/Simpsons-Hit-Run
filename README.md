# SRR2

SRR2 is a modified fork of _The Simpsons: Hit & Run_ with lots of enhancements, including C++17 support, x64, and VCPkg for easier third-party library management. 

## Goal

We want to add as many new features as possible and improve upon existing features. While keeping UWP and Windows support.

## Issues

If you encounter issues, please [create an issue](https://github.com/3UR/Simpsons-Hit-Run/issues/new) on the GitHub repository.

## Installation

> [!IMPORTANT]
> Assets are too large to include in the repository. You can obtain them from (TODO) and place them in the build folder.

### Quick Installation (Pre-built)

1. Download the latest build from the [Releases page](https://github.com/3UR/Simpsons-Hit-Run/releases/latest).
2. Locate a zip file similar to `SRR2-Release-x64-2025.02.11-12.07.28-73389fa.zip` and download it.
3. Extract the contents of the zip file to your desired location.
4. Navigate to the extracted folder and locate `SRR2.exe`.
5. Download the assets as mentioned in the note above and place them in the same directory as `SRR2.exe`.
6. You can now run the game. (Note: The game will crash without the required assets)

### Developer Installation (Building from Source)

To work with the source code, ensure you have the following:

When working on the code you must have some things

- Visual Studio (Install from Microsoft if not already present)
- C++ Language Support (In the Visual Studio installer, select the `Desktop development with C++` and `Universal Windows Platform development` options)
- VCPkg support (When selecting `Desktop development with C++`, ensure `vcpkg package manager` is checked on the right side)

#### Setup

1. Open command prompt and navigate to a directory where you want to store the source and run `git clone https://github.com/3UR/Simpsons-Hit-Run`
2. When done you can open `SRR2.sln` with Visual Studio.
3. Once in Visual Studio press `Tools -> Command Line -> Developer Command Prompt`
4. A Developer Command Prompt will open enter the following `vcpkg.exe install`
5. Once that is done you may need to run `vcpkg integrate install`

#### Building

If the setup was successful, you should now be able to build any project in the solution. When building for UWP don't forget to change the config! e.g if it's `ReleaseWindows` make it `ReleaseUwp`.

## Media

> [!NOTE]
> All builds previewed in the media are built using the source on this repository.

### Windows

![Screenshot 2025-02-10 092453](https://github.com/user-attachments/assets/7b5c9c6a-259d-4e5d-bd07-e429bd2f54bb)

### UWP (Click the thumbnail these are videos)

[![YouTube Video](https://img.youtube.com/vi/l_Ii-4Wygn8/0.jpg)](https://www.youtube.com/watch?v=l_Ii-4Wygn8)