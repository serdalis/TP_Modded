# Getting Started

## Ghidra
Ghidra - Currently using version 10
Download the git repo and open the project inside in ghidra.

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
 8. Run the following commands:
    .kill 
    .createdir \<Location of Treasure Planet Folder\>
    .create \<Path to Treasure Planet Exe + Exe Name\>
    g

## Editing the Exe
1. Its all a guessing game, good luck.

 