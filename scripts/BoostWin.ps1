wget https://dl.bintray.com/boostorg/release/1.72.0/source/boost_1_72_0.zip -OutFile boost_1_72_0.zip
move-item -path boost_1_72_0.zip -destination ..\libraries\boost_1_72_0.zip
cd ..\libraries
Expand-Archive -Path boost_1_72_0.zip -DestinationPath .
Remove-Item boost_1_72_0.zip
