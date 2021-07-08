# Getting Started

## Current areas of interest
 - Looking at the ship files we can see that there are secions named "FactoryType String", these types of entries match up with an initialisation function that assigns a the same name to a value in a pair. If we can track where this pair is being used, we can see where the factory of that name is being used and potentially be able to uncover / name a bunch of code from it.
 - Currently the InitFactories function is an area of interest. Following the code in this we can find where the ship ConstData is being initialised in CreateShipConstData if we can look in the memory while the game is running and see what the ship struct looks like, we may be able to extend / change it.

## Ghidra
Ghidra - Currently using version 10
Download the git repo and open the project inside in ghidra.

 - Currently we are using ghidras versioning system for the file, be sure to checkout the file before making modifications, and checking in the file before doing any ASM modding since it's easy to get lost or do something wrong. Be sure to check the files in before pushing to git.

### Committing to git
Because its really hard to see what changes are committed with each commit into git, we've decided that a C/C++ export needs to be included in the git push so the changes are simple visible.
This export does take some time, but its well worth it when you can see your hard work shown in red and green.
Remember to tick the 'Create Header File' option. Doing this increases readability.

If you are proposing a new exe version, make sure to up-version the exe itself by changing the version number in the exe.
Also due to how static the exe work is, make a versioned exe export so anyone can download it whenever.
The naming convention for the exe is `tp_win32_ef_1.XX.exe`. One day we may get to version 2, years from now.

Debugger:

 1. Download the windows 10 SDK to get access to windbg.
 2. Go to your windbg folder:
	 - For 32 bit java: `C:\Program Files (x86)\Windows Kits\10\Debuggers\x86` 
	 - For 64 bit java: `C:\Program Files (x86)\Windows Kits\10\Debuggers\x64` 
 3. copy paste all files in that folder into your JDK bin folder.
 4. Open the debugger from the main Ghidra screen.
 5. Open the exe project you'll be working with, make sure the current version matches the exported exe version.
 6. Start the debugger using the WinDbg via GADP command.
 7. Select the location of the exe in your TP folder.
 8. Run the following commands (delete the brackets):
```
    .kill (kills current debugged process if there is any)
    .createdir "Location of Treasure Planet Folder" (sets the dir to create the debug session in)
    .create "Path to Treasure Planet Exe + Exe Name" (sets the exe to use when creating the debug session)
    g (go, till next breakpoint)
```

## Editing the Exe
1. Its all a guessing game, good luck.

### More on the Exe
This version of the Exe has the DRM disabled and will work with the steam version.
We couldn't use the steam version since steam runs an obfuscator over the exe when the steam wrapper is added.

This version of the exe also includes 200kB of extra space in the .mod memory partition which is there to add new strings / data / move around arrays we're intending to extend.

## Versions
### 1.01
 - VP limit set to 5000
 - Arc Fire / Star Mortar removed from AI weapon selection
 - Light, Med, Heavy Lancer added to AI weapon selection
 
