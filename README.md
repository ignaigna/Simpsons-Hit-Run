# SRR2

SRR2 is a modified fork of _The Simpsons: Hit & Run_ with lots of enhancements, including C++17 support, x64, and VCPkg for easier third-party library management. 

## Fair Use Disclaimer

This repository and or build distributations contains a modified version of _The Simpsons: Hit & Run_, using its original source code and assets strictly for non-commercial, educational, and archival purposes under fair use. There is no intent to cause harm to the original work or its market.

- **Purpose:** Enhancement, preservation, and research.
- **Use of Copyrighted Material:** Assets and source code are used strictly for modifications and improvements.
- **No Commercial Intent:** This project is not sold, monetized, or distributed for profit. Donations are not accepted.
- **End-User Restrictions: (YOU)** You are not permitted to sell or commercially distribute this project in any form. Anyone attempting to do so will be blocked.

## Development Temporarily Paused

**Development paused temporarily;** 

I cannot actively review issues or pull requests because I accidentally broke my monitor (Xbox fell and hit the corner of the monitor 💔) 

I will try my best to commit frequently but it is hard when half of your monitor is broken and getting worse.

Right now I can somewhat still use my monitor so I have fixed UWP builds with GitHub actions see https://github.com/3UR/Simpsons-Hit-Run/releases/tag/SRR2-DebugUwp-x64-2025.02.22-22.32.00-5ca4479 for a working UWP build (**Sadly only works on Xbox Series** right now till I can start coding easily again. Please don't try to offer donations I don't need or want anything I will be back in 1-2 months! The only reason this is here is so people don't think "oh he quit" or "oh this is a abandoned project")


![image](https://github.com/user-attachments/assets/d1c109ba-5f38-4658-a396-cbccf77bface)
![image](https://github.com/user-attachments/assets/7f183076-30a5-448f-a58c-9f8a1c69c932)

## Goal

We want to add as many new features as possible and improve upon existing features. While keeping UWP and Windows support.

## Issues

If you encounter issues, please [create an issue](https://github.com/3UR/Simpsons-Hit-Run/issues/new) on the GitHub repository.

## Installation

### Quick Installation (Pre-built)

**NOTE:** If using Xbox below steps wont apply instead just download the latest `.appx` file from [Releases page](https://github.com/3UR/Simpsons-Hit-Run/releases/latest) it will be named something like `SRR2_UWP_1.0.4.0_x64_DebugUwp.appx` then deploy to Xbox via dev mode.

1. Download the latest build from the [Releases page](https://github.com/3UR/Simpsons-Hit-Run/releases/latest).
2. Locate a zip file similar to `SRR2-Release-x64-2025.02.11-12.07.28-73389fa.zip` and download it.
3. Extract the contents of the zip file to your desired location.
4. Navigate to the extracted folder and locate `SRR2.exe`.
5. You can now run the game. (Note: The game will crash without the required assets)

### Developer Installation (Building from Source)

To work with the source code, ensure you have the following:

When working on the code you must have some things

- Visual Studio (Install from Microsoft if not already present)
- C++ Language Support (In the Visual Studio installer, select the `Desktop development with C++` and `Universal Windows Platform development` options)
- VCPkg support (When selecting `Desktop development with C++`, ensure `vcpkg package manager` is checked on the right side)

#### Setup

1. Open command prompt and navigate to a directory where you want to store the source and run `git clone https://github.com/3UR/Simpsons-Hit-Run`
2. Run `git lfs pull` and make sure you have Git LFS installed.
3. When done you can open `SRR2.sln` with Visual Studio.
4. Once in Visual Studio press `Tools -> Command Line -> Developer Command Prompt`
5. A Developer Command Prompt will open enter the following `vcpkg.exe install`
6. Once that is done you may need to run `vcpkg integrate install`

#### Building

If the setup was successful, you should now be able to build any project in the solution. When building for UWP don't forget to change the config! e.g if it's `ReleaseWindows` make it `ReleaseUwp`.

## Media

> [!NOTE]
> All builds previewed in the media are built using the source on this repository.

### Windows

![Screenshot 2025-02-10 092453](https://github.com/user-attachments/assets/7b5c9c6a-259d-4e5d-bd07-e429bd2f54bb)

### Xbox

[_Watch HD on YouTube_](https://www.youtube.com/watch?v=l_Ii-4Wygn8)

https://github.com/user-attachments/assets/9793dccf-5dd6-4bbf-beb6-a6db33521a0b

[_Watch HD on YouTube_](https://www.youtube.com/watch?v=l_Ii-4Wygn8)

https://github.com/user-attachments/assets/ccfdb377-10ed-418b-a81b-932aad9938e1

