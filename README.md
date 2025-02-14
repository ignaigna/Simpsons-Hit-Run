# SRR2

> [!WARNING]  
> UWP SUPPORT IS NOT YET AVAILABLE

SRR2 is a refined version of _The Simpsons: Hit & Run_ with several enhancements, including C++17 support, x64 architecture, and VCPkg for easier third-party library installation. This project is based on the source code that leaked in 2021. The ultimate goal is to add more features, improvements, and eventually UWP support.

## Installation

> [!IMPORTANT]
> Assets are too large to include in the repository. You can obtain them from (TODO) and place them in the build folder.

### Quick Installation (Pre-built Version)

1. Download the latest build from the [Releases page](https://github.com/3UR/Simpsons-Hit-Run/releases/latest).
2. Locate a zip file similar to `SRR2-Release-x64-2025.02.11-12.07.28-73389fa.zip` and download it.
3. Extract the contents of the zip file to your desired location.
4. Navigate to the extracted folder and locate `SRR2.exe`.
5. Download the assets as mentioned in the note above and place them in the same directory as `SRR2.exe`.
6. You can now run the game. (Note: The game will crash without the required assets)

### Developer Installation (Building from Source)

#### Prerequisites

To work with the source code, ensure you have the following:

- Visual Studio (Install from Microsoft if not already present)
- C++ Language Support (In the Visual Studio installer, select the `Desktop development with C++` and `Universal Windows Platform development` options)
- VCPkg support (When selecting `Desktop development with C++`, ensure `vcpkg package manager` is checked on the right side)

#### Setup

1. Open a command prompt in your desired directory and run:

```cmd
git clone https://github.com/3UR/Simpsons-Hit-Run.git
```

2. Open `SRR2.sln` with Visual Studio.
3. In Visual Studio, go to `Tools -> Command Line -> Developer Command Prompt`.
4. In the opened Developer Command Prompt, run:

```cmd
vcpkg.exe install
```

(This will install all required dependencies. Wait for it to complete.) 5. After completion, you may need to run:

```cmd
vcpkg integrate install
```

#### Building

If the setup was successful, you should now be able to build any project in the solution. If you encounter issues, please [create an issue](https://github.com/3UR/Simpsons-Hit-Run/issues/new) on the GitHub repository.

When building the main game project `SRR2`, the output will be in the `build` folder (e.g., `bin-Win32-Debug`). Before running, ensure you've downloaded the assets and placed them in this folder. This also applies when using the Visual Studio debugger.

## Screenshots

**Builds using this source**

### Windows

![Screenshot 2025-02-10 092453](https://github.com/user-attachments/assets/7b5c9c6a-259d-4e5d-bd07-e429bd2f54bb)
