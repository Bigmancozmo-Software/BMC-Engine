# BMC Engine

A game engine, built from the ground up in C/C++ by Bigmancozmo.

<div>
  <span>
    <a href="LICENSE"><img alt="License Badge" src="https://img.shields.io/github/license/Bigmancozmo-Software/BMC-Engine?label=license&style=flat-square" /></a>
    <br/>
    <a href="https://github.com/Bigmancozmo-Software/BMC-Engine/issues"><img alt="GitHub Issues - Open" src="https://img.shields.io/github/issues/Bigmancozmo-Software/BMC-Engine?style=flat-square" /></a>
    <a href="https://github.com/Bigmancozmo-Software/BMC-Engine/issues"><img alt="GitHub Issues - Closed" src="https://img.shields.io/github/issues-closed/Bigmancozmo-Software/BMC-Engine?style=flat-square" /></a>
    <br/>
    <a href="https://github.com/Bigmancozmo-Software/BMC-Engine/pulls"><img alt="GitHub Pull Requests - Open" src="https://img.shields.io/github/issues-pr/Bigmancozmo-Software/BMC-Engine?style=flat-square" /></a>
    <a href="https://github.com/Bigmancozmo-Software/BMC-Engine/pulls"><img alt="GitHub Pull Requests - Closed" src="https://img.shields.io/github/issues-pr-closed/Bigmancozmo-Software/BMC-Engine?style=flat-square" /></a>
    <br/>
  </span>
</div>

## Compiling
This is only confirmed to work on Windows **for now.** We are working on testing other systems. It should work on Linux, but no guarantees!

### 1. Install CMake
Head [here](https://cmake.org/download/) to get CMake. Any version **newer than 3.8** should work.

### 2. Install Visual Studio
Installing Visual Studio is required for compiling -- you do **not** have to code in it.<br/>Go [here](https://visualstudio.microsoft.com/vs/) and install Visual Studio 2022 (Visual Studio 2019 should work, but it is **untested**).<br/>When in the **Visual Studio Installer,** you **must** enable `Desktop development with C++`.<br/>Click "Modify" in the bottom-right and wait for the changes to be made and/or Visual Studio to be installed.

### 3. Download Repository
<b>You cannot use `Code -> Download ZIP`!<br/>
In your `Command Prompt/Terminal`, enter the directory you want to download the code to, and run<br/>`git clone https://github.com/bigmancozmo-software/bmc-engine --recurse-submodules`.

### 4a. Compile with the Terminal
Open a new **Command Prompt/terminal** window in the source code directory.<br/>Then, run the following command:<br/>`cmake -S . -B build && cmake --build build --config RelWithDebInfo --target BMC-ENGINE`<br/>This should generate a folder called **build**. Go to `build/BMC-ENGINE/Release`. BMC Engine is compiled!<br/>
<sub>Hey! If you're getting errors on Linux, try running</sub><br/>
<sup>`sudo apt-get install --fix-missing -y libgl1-mesa-dev libwayland-dev wayland-protocols libxkbcommon-dev libxrandr-dev libxinerama-dev libx11-dev libxcursor-dev libxi-dev`</sup>

### 4b. Compile with Visual Studio
Open up **Visual Studio** and select `Open a local folder`. Then, select the source code folder. If done correctly, Visual Studio **should** recognize it as a CMake project, and allow you to write code and build the engine from there.
