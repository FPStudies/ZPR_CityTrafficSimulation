wget https://www.sfml-dev.org/files/SFML-2.5.1-windows-gcc-7.3.0-mingw-32-bit.zip -OutFile SFML-2.5.1-windows-gcc-7.3.0-mingw-32-bit.zip
move-item -path SFML-2.5.1-windows-gcc-7.3.0-mingw-32-bit.zip -destination ..\libraries\SFML-2.5.1-windows-gcc-7.3.0-mingw-32-bit.zip
cd ..\libraries
Expand-Archive -Path SFML-2.5.1-windows-gcc-7.3.0-mingw-32-bit.zip -DestinationPath .
Remove-Item SFML-2.5.1-windows-gcc-7.3.0-mingw-32-bit.zip