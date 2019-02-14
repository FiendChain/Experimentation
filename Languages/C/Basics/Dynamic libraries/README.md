https://stackoverflow.com/questions/16737347/shared-libraries-windows-vs-linux-method

rodigro:
Not actually with code relocation, that's a totally different issue. It is about a difference in architecture:

In Windows, a DLL is just like a executables (EXE). The main difference between an EXE and a DLL is that the EXE has an entry point (main/WinMain function) and so it can be used to start a process, while DLLs can only be loaded into a pre-existing process. But see (1)

In Linux, a .so work similar to a static library (.a). The main difference is that the .so file can be linked with a running program, while the .a file can only be linked when compiling the program.

A consequence of this approach is that in linux the same file can be used to build and run the program. But in Windows you need a proper library (LIB) to link the program. Actually the lib that corresponds to a DLL usually have nothing more than the names of the functions, to satisfy the linker, and the stubs to do the relocation. But see (2)

(1) Well, DLLs have entry point too, but it is not used as the main function, just as some sort of initialization/finalization hook.

(2) Some linkers are smart enough to be able, in some simple cases, to link to a DLL by using the DLL itself, without the need of an additional LIB file. I think that at least the MinGW linker can do that.