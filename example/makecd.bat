:: if you have psx-sdk installed, this batch file
:: uses its tools provided to creade a valid cd image
:: to use with the playstation if you want

::mkdir -p cd_root
::$(CC) $(CCFLAGS)-DEXAMPLES_VMODE=VMODE_PAL testapp.c -o testapp.elf
::elf2exe testapp.elf testapp.exe
copy main.exe cd_root
systemcnf main.exe > cd_root/system.cnf
mkisofs.exe -o main.hsf -V MAIN -sysid PLAYSTATION cd_root
mkpsxiso main.hsf main.bin C:\psx-sdk\share\licenses\infousa.dat
