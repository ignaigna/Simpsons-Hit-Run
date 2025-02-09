# SRR2

> [!WARNING]  
> THIS DOES NOT YET SUPPORT UWP (ALL OF THE GUIDES BELOW ARE FOR WINDOWS ONLY AND WILL CHANGE WHENEVER UWP SUPPORT IS FINISHED)

SRR2 is a cleaner version of *The Simpsons Hit & Run* with several changes, including C++ 17 support, x64 (WIP), and VCPkg for easier third party library installation. This is based on the source code that leaked in 2021, the end goal is to add more feature, improvements, and UWP support.

## Installation

> [!NOTE]
> Assets are too big to include in the repo, You can get them from (TODO) and drag and dropthem into the build folder.

### I dont want to mess around with code I just want a build

The latest build for Windows can be found in the [Releases](https://github.com/3UR/Simpsons-Hit-Run/releases) page.

So visit the releases page and download the latest build it will be named something like `SRR2-Debug-x86-2025.02.09-15.21.49-07cbce9.zip`, 
The zip you downloaded will have one file inside it named something like `SRR2-Debug-x86-2025.02.09-15.21.49-07cbce9` you will have to open this inside 7zip (or something else) too (dont ask why the workflow is WIP) once opened you should see `bin-Win32-Debug` this is where the main binaries are this can be extracted anywhere just make sure that you extract assets wherever you extract this.

tldr; download latest release, extract then extract assets over the build


### I want to work on the code and create my own builds

#### Developer Environment

When working on the code you must have some things

- Visual Studio (Install from Microsoft if not installed)
- C++ Language Support (Check the `Desktop development with C++` and `Universal Windows Platform development` options in the Visual Studio installer)
- VCPkg support (When checking `Desktop development with C++` make sure `vcpkg package manager` on the right side is selected)

#### Setup

Once you have the dev environment you will have to

1. Open command prompt where you want to clone the source code and run `git clone https://github.com/3UR/Simpsons-Hit-Run`
2. Open `SRR2.sln` with Visual Studio
3. Once in Visual Studio press `Tools -> Command Line -> Developer Command Prompt`
4. A Developer Command Prompt will open enter the following `vcpkg.exe install --triplet x86-windows` (Wait for this to finish it will install all required dependencies)
5. Once that is done you may need to run `vcpkg integrate install`

#### Building

After all of that if everything was successfull you should now be able to build any project in the SLN (If something went wrong above [Create an Issue](https://github.com/3UR/Simpsons-Hit-Run/issues/new?template=Blank+issue))

When building the main game project `SRR2` it will be outputted in the `build` folder `bin-Win32-Debug` for example, once it is built before running make sure you download the assets and drag and drop them into this folder (The same goes when using the visual studio debugger make sure the assets are there before running the build).

## Screenshots

**builds using this source**

### Windows

![Screenshot 2025-02-10 092453](https://github.com/user-attachments/assets/7b5c9c6a-259d-4e5d-bd07-e429bd2f54bb)
