@echo  off

copy %1 /y
xcopy %2 /s /y
echo archivos copiados