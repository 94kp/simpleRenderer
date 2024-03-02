cls
DEL *.obj
DEL *.exe
cl.exe /c /EHsc *.cpp
link.exe *.obj
main.exe
PAUSE