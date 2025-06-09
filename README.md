# RanV Engine
RanV engine is a project in which I am focussing on learning engine architecture and rendering. And why not starting with vulkan - sound like a god idea right? ...right?

At the moment the first base structure is created. Logging, event handling, input and window creation is built into the first basic version. Game.exe files are generated correctly and are separate from the engine itself. The editor can later use the runtime of the engine and take over the data processing with its own functions, but how far I will pursue the project is still up in the air.

# Project Setup
1. **Clone --recurse-submodules** using the web URL.
2. **Create** following folder structure in the root folder **vendor/bin/premake**
3. **Download** a preffered premake5 version here https://github.com/premake/premake-core/releases
4. **Unpack** the downloaded .zip, **extract** and **paste** the premake5.exe into the new created folder **vendor/bin/premake/**
5. **Run** 'GenerateProjects.bat' --- Premake will generate the vs-solution according to settings made in "premake5.lua".
6. **Set** "Sandbox" project **as startup**
7. **Rebuild** Sandbox (TWICE if needed) and it should work --- (it seams, premake sometimes cannot copy the RanV.dll to the Sandbox-App the first time, when creating the bin folder)

# Details
These files were created in the course of an engine series from the YouTube channel ‘The Cherno’.
Copying code is nothing special - I just want to show that I'm interested in many things and can familiarise myself with them quickly.
