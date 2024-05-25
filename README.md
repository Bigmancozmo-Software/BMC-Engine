# BMC Engine

A game engine, built from the ground up in C/C++ by Bigmancozmo.

<div>
  <span>
    <a href="LICENSE"><img alt="License Badge" src="https://img.shields.io/github/license/Bigmancozmo/Space-Menu?label=license&style=flat-square" /></a>
    <br/>
    <a href="https://github.com/Bigmancozmo/Space-Menu/issues"><img alt="GitHub Issues - Open" src="https://img.shields.io/github/issues/Bigmancozmo/Space-Menu?style=flat-square" /></a>
    <a href="https://github.com/Bigmancozmo/Space-Menu/issues"><img alt="GitHub Issues - Closed" src="https://img.shields.io/github/issues-closed/Bigmancozmo/Space-Menu?style=flat-square" /></a>
    <br/>
    <a href="https://github.com/Bigmancozmo/Space-Menu/pulls"><img alt="GitHub Pull Requests - Open" src="https://img.shields.io/github/issues-pr/Bigmancozmo/Space-Menu?style=flat-square" /></a>
    <a href="https://github.com/Bigmancozmo/Space-Menu/pulls"><img alt="GitHub Pull Requests - Closed" src="https://img.shields.io/github/issues-pr-closed/Bigmancozmo/Space-Menu?style=flat-square" /></a>
    <br/>
  </span>
</div>

## Compiling
This only works on Windows **for now.** We are working on other systems.

### 1. Install CMake
Head [here](https://cmake.org/download/) to get CMake. Any version **newer than 3.8** should work.

### 2. Install Visual Studio
Installing Visual Studio is required for compiling -- you do **not** have to code in it.<br/>Go [here](https://visualstudio.microsoft.com/vs/) and install Visual Studio 2022 (Visual Studio 2019 should work, but it is **untested**).<br/>When in the **Visual Studio Installer,** you **must** enable `Desktop development with C++`.<br/>Click "Modify" in the bottom-right and wait for the changes to be made and/or Visual Studio to be installed.

### 2. Download Repository
Go to the repository page (you should already be here) and click the green "Code" button. Then, click "Download ZIP." Once the file is downloaded, simply just extract the zip.

### 3. Compile
Open a new **Command Prompt** window in the source code directory.<br/>Then, run the following command:<br/>`cmake -S . -B build && cmake --build build --config Release --target BMC-ENGINE`<br/>This should generate a folder called **build**. Go to `build/BMC-ENGINE/Release`. BMC Engine is compiled!
