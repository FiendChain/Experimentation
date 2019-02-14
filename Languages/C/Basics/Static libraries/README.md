Static libraries are essentially archived object files
Its essentially like compiling the program with the .o files, with the provided header
However, a significant difference is that only the object files you use are included

https://unix.stackexchange.com/questions/330077/what-is-the-advantage-of-archiving-c-object-files-in-a-static-library-a-file

PSkocik:
The main feature of static libraries is the symbol index that allows you to link in only those archive members that provide missing symbols.

Grouping object files into a single file, or compression, are both secondary, and you can have thin archives that do neither. (Thin archives basically just reference files that exist outside of the archive).


Giacomo Catenazzi:
The advantage: you have just one file.

A static library is just an archive. You can put in and get out individual files as you like. When you link a program, only the appropriate files are extracted and linked.

Note: if you are using a Linux distribution with dpkg, you are using the same archiving tool for libraries and packages (and possibly nested in a -dev package).